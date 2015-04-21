/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.TextBox
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Input.InputScope.hpp"
#include "Windows.UI.Xaml.Media.SolidColorBrush.hpp"
#include "Windows.UI.Xaml.DataTemplate.hpp"
#include "Windows.UI.Xaml.Controls.TextBox.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{

		TextBox::TextBox(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Control(js_context)
		{
		}

		void TextBox::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::TextBox^ TextBox::unwrapWindows_UI_Xaml_Controls_TextBox() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::TextBox^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Controls::TextBox^ TextBox::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_TextBox();
		}

		void TextBox::wrap(::Windows::UI::Xaml::Controls::TextBox^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void TextBox::JSExportInitialize()
		{
			JSExport<TextBox>::SetClassVersion(1);
			JSExport<TextBox>::SetParent(JSExport<Windows::UI::Xaml::Controls::Control>::Class());

			TITANIUM_ADD_PROPERTY(TextBox, PreventKeyboardDisplayOnProgrammaticFocus);
			TITANIUM_ADD_PROPERTY(TextBox, PlaceholderText);
			TITANIUM_ADD_PROPERTY(TextBox, IsColorFontEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, HeaderTemplate);
			TITANIUM_ADD_PROPERTY(TextBox, Header);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionHighlightColor);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionStart);
			TITANIUM_ADD_PROPERTY(TextBox, SelectionLength);
			TITANIUM_ADD_PROPERTY(TextBox, SelectedText);
			TITANIUM_ADD_PROPERTY(TextBox, MaxLength);
			TITANIUM_ADD_PROPERTY(TextBox, IsTextPredictionEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, IsSpellCheckEnabled);
			TITANIUM_ADD_PROPERTY(TextBox, IsReadOnly);
			TITANIUM_ADD_PROPERTY(TextBox, InputScope);
			TITANIUM_ADD_PROPERTY(TextBox, AcceptsReturn);
			TITANIUM_ADD_PROPERTY(TextBox, Text);
			TITANIUM_ADD_PROPERTY(TextBox, TextWrapping);
			TITANIUM_ADD_PROPERTY(TextBox, TextAlignment);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, AcceptsReturnProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, InputScopeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsReadOnlyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsSpellCheckEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsTextPredictionEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, MaxLengthProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, TextWrappingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, HeaderProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, HeaderTemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, IsColorFontEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, PlaceholderTextProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, PreventKeyboardDisplayOnProgrammaticFocusProperty);
			TITANIUM_ADD_PROPERTY_READONLY(TextBox, SelectionHighlightColorProperty);
			TITANIUM_ADD_FUNCTION(TextBox, Select);
			TITANIUM_ADD_FUNCTION(TextBox, SelectAll);
			TITANIUM_ADD_FUNCTION(TextBox, GetRectFromCharacterIndex);
		}

		TITANIUM_PROPERTY_SETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocus)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->PreventKeyboardDisplayOnProgrammaticFocus = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocus)
		{
			auto value = unwrap()->PreventKeyboardDisplayOnProgrammaticFocus;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, PlaceholderText)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);


			unwrap()->PlaceholderText = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PlaceholderText)
		{
			auto value = unwrap()->PlaceholderText;
			auto context = get_context();
 			auto result = context.CreateString(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsColorFontEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsColorFontEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsColorFontEnabled)
		{
			auto value = unwrap()->IsColorFontEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, HeaderTemplate)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_DataTemplate();


			unwrap()->HeaderTemplate = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderTemplate)
		{
			auto value = unwrap()->HeaderTemplate;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, Header)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			unwrap()->Header = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, Header)
		{
			auto value = unwrap()->Header;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionHighlightColor)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_SolidColorBrush();


			unwrap()->SelectionHighlightColor = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionHighlightColor)
		{
			auto value = unwrap()->SelectionHighlightColor;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::SolidColorBrush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::SolidColorBrush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionStart)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->SelectionStart = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionStart)
		{
			auto value = unwrap()->SelectionStart;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectionLength)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->SelectionLength = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionLength)
		{
			auto value = unwrap()->SelectionLength;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, SelectedText)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);


			unwrap()->SelectedText = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectedText)
		{
			auto value = unwrap()->SelectedText;
			auto context = get_context();
 			auto result = context.CreateString(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, MaxLength)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->MaxLength = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, MaxLength)
		{
			auto value = unwrap()->MaxLength;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsTextPredictionEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsTextPredictionEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsTextPredictionEnabled)
		{
			auto value = unwrap()->IsTextPredictionEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsSpellCheckEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsSpellCheckEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsSpellCheckEnabled)
		{
			auto value = unwrap()->IsSpellCheckEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, IsReadOnly)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsReadOnly = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsReadOnly)
		{
			auto value = unwrap()->IsReadOnly;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, InputScope)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Input::InputScope>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Input_InputScope();


			unwrap()->InputScope = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, InputScope)
		{
			auto value = unwrap()->InputScope;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Input::InputScope>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Input::InputScope>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, AcceptsReturn)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->AcceptsReturn = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, AcceptsReturn)
		{
			auto value = unwrap()->AcceptsReturn;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, Text)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);


			unwrap()->Text = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, Text)
		{
			auto value = unwrap()->Text;
			auto context = get_context();
 			auto result = context.CreateString(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, TextWrapping)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextWrapping>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextWrapping = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextWrapping)
		{
			auto value = unwrap()->TextWrapping;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(TextBox, TextAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::TextAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TextAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextAlignment)
		{
			auto value = unwrap()->TextAlignment;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, AcceptsReturnProperty)
		{
			auto value = unwrap()->AcceptsReturnProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, InputScopeProperty)
		{
			auto value = unwrap()->InputScopeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsReadOnlyProperty)
		{
			auto value = unwrap()->IsReadOnlyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsSpellCheckEnabledProperty)
		{
			auto value = unwrap()->IsSpellCheckEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsTextPredictionEnabledProperty)
		{
			auto value = unwrap()->IsTextPredictionEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, MaxLengthProperty)
		{
			auto value = unwrap()->MaxLengthProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextAlignmentProperty)
		{
			auto value = unwrap()->TextAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextProperty)
		{
			auto value = unwrap()->TextProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, TextWrappingProperty)
		{
			auto value = unwrap()->TextWrappingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderProperty)
		{
			auto value = unwrap()->HeaderProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, HeaderTemplateProperty)
		{
			auto value = unwrap()->HeaderTemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, IsColorFontEnabledProperty)
		{
			auto value = unwrap()->IsColorFontEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PlaceholderTextProperty)
		{
			auto value = unwrap()->PlaceholderTextProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, PreventKeyboardDisplayOnProgrammaticFocusProperty)
		{
			auto value = unwrap()->PreventKeyboardDisplayOnProgrammaticFocusProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextBox, SelectionHighlightColorProperty)
		{
			auto value = unwrap()->SelectionHighlightColorProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(TextBox, Select)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto start = static_cast<int32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto length = static_cast<int32_t>(_1);


			unwrap()->Select(start, length);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBox, SelectAll)
		{
			unwrap()->SelectAll();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TextBox, GetRectFromCharacterIndex)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto charIndex = static_cast<int32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsBoolean(), "Expected boolean");
			auto trailingEdge = static_cast<bool>(_1);


			auto context = get_context();
			auto method_result = unwrap()->GetRectFromCharacterIndex(charIndex, trailingEdge);

			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(method_result.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(method_result.Y)));
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(method_result.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(method_result.Height)));


			return result; 
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
