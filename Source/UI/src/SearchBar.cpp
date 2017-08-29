/**
 * Titanium.UI.SearchBar for Windows
 *
 * Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/SearchBar.hpp"
#include "Titanium/UI/TableViewRow.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/WindowsMacros.hpp"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

namespace TitaniumWindows
{
	namespace UI
	{
		SearchBar::SearchBar(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::SearchBar(js_context)
		{
			TITANIUM_LOG_DEBUG("SearchBar::ctor Initialize");
			showCancel__ = true; // native default
		}

		SearchBar::~SearchBar()
		{
			TITANIUM_LOG_DEBUG("SearchBar::dtor");
		}


		static TextBox^ GetTextBox(DependencyObject^ root)
		{
			const auto count = Media::VisualTreeHelper::GetChildrenCount(root);
			for (int i = 0; i < count; i++) {
				const auto child = Media::VisualTreeHelper::GetChild(root, i);
				const auto textbox = dynamic_cast<TextBox^>(child);
				if (textbox) {
					return textbox;
				} else {
					return GetTextBox(child);
				}
			}
			return nullptr;
		}

		void SearchBar::updateCancelButtonVisibility(const bool& show) TITANIUM_NOEXCEPT
		{
			// if no one touches showCancel property, we don't want to use our hack
			// because native implementation should be faster and safer.
			if (!delete_button_dirty__) return;

			const auto visible = suggest_box__->Text->IsEmpty() ? false : show;
			if (delete_button__) {
				delete_button__->MaxHeight  = visible ? HUGE_VAL : 0;
				delete_button__->MaxWidth   = visible ? HUGE_VAL : 0;
				delete_button__->Visibility = visible ? Visibility::Visible : Visibility::Collapsed;
			}
		}

		void SearchBar::set_showCancel(const bool& show) TITANIUM_NOEXCEPT
		{
			Titanium::UI::SearchBar::set_showCancel(show);
			delete_button_dirty__ = true; // indicate we need to use our hack
			updateCancelButtonVisibility(show);
		}

		void SearchBar::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
		{
			Titanium::UI::SearchBar::postCallAsConstructor(js_context, arguments);
			border__ = ref new Windows::UI::Xaml::Controls::Border();
			suggest_box__  = ref new AutoSuggestBox();
			suggestItems__ = ref new Platform::Collections::Vector<Platform::String^>();
			suggest_box__->ItemsSource = suggestItems__;
			suggest_box__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
			suggest_box__->QueryIcon = ref new SymbolIcon(Symbol::Find);

			// Since VisualTreeHelper is only available after Loaded event is fired, we need to update the visual state then.
			suggest_box__->Loaded += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
				const auto textbox = GetTextBox(suggest_box__);
				if (textbox && Media::VisualTreeHelper::GetChildrenCount(textbox) > 0) {
					//
					// assuming the first component appeared in the TextBox is Grid that includes the button
					//
					const auto grid = dynamic_cast<Grid^>(Media::VisualTreeHelper::GetChild(textbox, 0));
					if (grid) {
						const auto count = Media::VisualTreeHelper::GetChildrenCount(grid);
						for (auto i = 0; i < count; i++) {
							//
							// assuming the first button appeared in the Grid is the "DeleteButton"
							//
							const auto button = dynamic_cast<Button^>(Media::VisualTreeHelper::GetChild(grid, i));
							if (button) {
								delete_button__ = button;
								return;
							}
						}
					}
				}
			});

			// Each time text has changed, you need to update the visibility of the DeleteButton
			suggest_box__->KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler([this](Platform::Object^, KeyRoutedEventArgs^) {
				updateCancelButtonVisibility(get_showCancel());
			});
			// Hide the DeleteButton whenever SearchBar lost focus, 
			suggest_box__->LostFocus += ref new Windows::UI::Xaml::RoutedEventHandler([this](Platform::Object^, RoutedEventArgs^) {
				updateCancelButtonVisibility(false);
			});
			// Resture DeleteButton status when we got focus
			suggest_box__->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler([this](Platform::Object^, RoutedEventArgs^) {
				updateCancelButtonVisibility(get_showCancel());
			});

			suggest_box__->KeyUp += ref new KeyEventHandler([this](Platform::Object^ sender, KeyRoutedEventArgs^ e) {

				updateCancelButtonVisibility(get_showCancel());
				if (e->Key == Windows::System::VirtualKey::Enter && querySubmitted__) {
					querySubmitted__(TitaniumWindows::Utility::ConvertString(suggest_box__->Text));
				}
				if (e->Key == Windows::System::VirtualKey::Enter) {
					const auto ctx = get_context();
					JSObject eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("value", ctx.CreateString(this->get_value()));

					this->fireEvent("return", eventArgs);
				}
			});

			suggest_box__->TextChanged += ref new TypedEventHandler<AutoSuggestBox^, AutoSuggestBoxTextChangedEventArgs^>([this](AutoSuggestBox^ sender, AutoSuggestBoxTextChangedEventArgs^ e) {

				const auto ctx = get_context();
				const auto value = TitaniumWindows::Utility::ConvertUTF8String(sender->Text);
				auto eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("value", ctx.CreateString(value));
				fireEvent("change", eventArgs);

				if (e->Reason == AutoSuggestionBoxTextChangeReason::UserInput && sender->Text->IsEmpty()) {
					const auto ctx = get_context();
					auto eventObj = ctx.CreateObject();
					eventObj.SetProperty("value", ctx.CreateString(""));
					fireEvent("cancel", eventObj);
				}

				if (suggestionRequested__) {
					if (e->Reason == AutoSuggestionBoxTextChangeReason::SuggestionChosen) {
						return;
					}
					if (sender->Text->IsEmpty() && querySubmitted__) {
						querySubmitted__("");
						return;
					}
					const auto items = suggestionRequested__(TitaniumWindows::Utility::ConvertString(sender->Text));
					suggest_box__->ItemsSource = nullptr;
					suggestItems__->Clear();
					for (const auto item : items) {
						suggestItems__->Append(TitaniumWindows::Utility::ConvertString(item));
					}
					suggest_box__->ItemsSource = suggestItems__;
				}
			});
			suggest_box__->SuggestionChosen += ref new TypedEventHandler<AutoSuggestBox^, AutoSuggestBoxSuggestionChosenEventArgs^>([this](AutoSuggestBox^ sender, AutoSuggestBoxSuggestionChosenEventArgs^ e) {
				if (querySubmitted__) {
					querySubmitted__(TitaniumWindows::Utility::ConvertString(e->SelectedItem->ToString()));
				}
			});

			border__->Child = suggest_box__;
			Titanium::UI::SearchBar::setLayoutDelegate<WindowsViewLayoutDelegate>();
			const auto layout = getViewLayoutDelegate<WindowsViewLayoutDelegate>();
			layout->setStyleComponent(suggest_box__);
			layout->setComponent(border__, nullptr, border__);
		}

		void SearchBar::JSExportInitialize() 
		{
			JSExport<SearchBar>::SetClassVersion(1);
			JSExport<SearchBar>::SetParent(JSExport<Titanium::UI::SearchBar>::Class());
		}

		std::string SearchBar::get_value() const TITANIUM_NOEXCEPT
		{

			return TitaniumWindows::Utility::ConvertUTF8String(suggest_box__->Text);
		}

		void SearchBar::set_value(const std::string& value) TITANIUM_NOEXCEPT
		{
			Titanium::UI::SearchBar::set_value(value);
			suggest_box__->Text = TitaniumWindows::Utility::ConvertUTF8String(value);
		}

		void SearchBar::set_hintText(const std::string& hintText) TITANIUM_NOEXCEPT
		{
			Titanium::UI::SearchBar::set_hintText(hintText);
			suggest_box__->PlaceholderText = TitaniumWindows::Utility::ConvertUTF8String(hintText);
		}

		std::string SearchBar::get_hintText() const TITANIUM_NOEXCEPT
		{
			return TitaniumWindows::Utility::ConvertUTF8String(suggest_box__->PlaceholderText);
		}

		void SearchBar::set_barColor(const std::string& color) TITANIUM_NOEXCEPT
		{
			Titanium::UI::SearchBar::set_barColor(color);
			getViewLayoutDelegate()->set_backgroundColor(color);
		}
	}  // namespace UI
}  // namespace TitaniumWindows