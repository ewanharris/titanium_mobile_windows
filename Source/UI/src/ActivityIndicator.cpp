/**
 * Titanium.UI.ActivityIndicator for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/ActivityIndicator.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/UI/Label.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml;
		using namespace Windows::UI::Xaml::Controls;

		ActivityIndicatorLayoutDelegate::ActivityIndicatorLayoutDelegate(Windows::UI::Xaml::Controls::ProgressRing^ ring)
			: WindowsViewLayoutDelegate()
			, ring__(ring)
		{
			TITANIUM_LOG_DEBUG("ActivityIndicatorLayoutDelegate::ctor");
		}

		void ActivityIndicatorLayoutDelegate::postInitialize()
		{
		}


		void ActivityIndicatorLayoutDelegate::show() TITANIUM_NOEXCEPT
		{
			ring__->IsActive = true;
			WindowsViewLayoutDelegate::show();
		}

		void ActivityIndicatorLayoutDelegate::hide() TITANIUM_NOEXCEPT
		{
			ring__->IsActive = false;
			WindowsViewLayoutDelegate::hide();
		}

		ActivityIndicator::ActivityIndicator(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::ActivityIndicator(js_context)
		{
			TITANIUM_LOG_DEBUG("ActivityIndicator::ctor Initialize");
		}

		void ActivityIndicator::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
		{
			Titanium::UI::ActivityIndicator::postCallAsConstructor(js_context, arguments);

			// use stack panel because ActivityIndicator needs label & ring
			panel__ = ref new StackPanel();
			panel__->Orientation = Orientation::Vertical;

			ring__ = ref new ProgressRing();
			ring__->IsActive = false;
			ring__->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Transparent);

			label__ = ref new TextBlock();
			label__->Text = "";

			label__->FontSize = TitaniumWindows::UI::Label::DefaultFontSize;

			// relative position from container should start from top & left
			panel__->VerticalAlignment   = VerticalAlignment::Top;
			panel__->HorizontalAlignment = HorizontalAlignment::Left;
			label__->HorizontalAlignment = HorizontalAlignment::Center;

			panel__->Children->Append(ring__);
			panel__->Children->Append(label__);

			Titanium::UI::ActivityIndicator::setLayoutDelegate<ActivityIndicatorLayoutDelegate>(ring__);
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			getViewLayoutDelegate<ActivityIndicatorLayoutDelegate>()->setComponent(panel__);
		}

		void ActivityIndicator::set_message(const std::string& message) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ActivityIndicator::set_message(message);
			label__->Text = TitaniumWindows::Utility::ConvertUTF8String(message);
		}

		void ActivityIndicator::JSExportInitialize() 
		{
			JSExport<ActivityIndicator>::SetClassVersion(1);
			JSExport<ActivityIndicator>::SetParent(JSExport<Titanium::UI::ActivityIndicator>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows