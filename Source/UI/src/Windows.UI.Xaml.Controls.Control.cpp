/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Control
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Controls.ControlTemplate.hpp"
#include "Windows.UI.Xaml.Media.Brush.hpp"
#include "Windows.UI.Xaml.Media.FontFamily.hpp"
#include "Windows.UI.Xaml.Controls.Control.hpp"

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

		Control::Control(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkElement(js_context)
		{
		}

		void Control::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::Control^ Control::unwrapWindows_UI_Xaml_Controls_Control() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::Control^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::Control^ Control::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_Control();
		}

		void Control::wrap(::Windows::UI::Xaml::Controls::Control^ object)
		{
			wrapped__ = object;
		}

		void Control::JSExportInitialize()
		{
			JSExport<Control>::SetClassVersion(1);
			JSExport<Control>::SetParent(JSExport<Windows::UI::Xaml::FrameworkElement>::Class());

			TITANIUM_ADD_PROPERTY(Control, FontStyle);
			TITANIUM_ADD_PROPERTY(Control, FontStretch);
			TITANIUM_ADD_PROPERTY(Control, FontSize);
			TITANIUM_ADD_PROPERTY(Control, FontFamily);
			TITANIUM_ADD_PROPERTY(Control, FontWeight);
			TITANIUM_ADD_PROPERTY(Control, CharacterSpacing);
			TITANIUM_ADD_PROPERTY(Control, BorderThickness);
			TITANIUM_ADD_PROPERTY(Control, BorderBrush);
			TITANIUM_ADD_PROPERTY(Control, Background);
			TITANIUM_ADD_PROPERTY(Control, VerticalContentAlignment);
			TITANIUM_ADD_PROPERTY(Control, Template);
			TITANIUM_ADD_PROPERTY(Control, TabNavigation);
			TITANIUM_ADD_PROPERTY(Control, TabIndex);
			TITANIUM_ADD_PROPERTY(Control, Padding);
			TITANIUM_ADD_PROPERTY(Control, IsTabStop);
			TITANIUM_ADD_PROPERTY(Control, IsEnabled);
			TITANIUM_ADD_PROPERTY(Control, HorizontalContentAlignment);
			TITANIUM_ADD_PROPERTY(Control, Foreground);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FocusState);
			TITANIUM_ADD_PROPERTY(Control, DefaultStyleKey);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BackgroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BorderBrushProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, BorderThicknessProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, CharacterSpacingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, DefaultStyleKeyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FocusStateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontFamilyProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontSizeProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontStretchProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontStyleProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, FontWeightProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, ForegroundProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, HorizontalContentAlignmentProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, IsEnabledProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, IsTabStopProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, PaddingProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TabIndexProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TabNavigationProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, TemplateProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Control, VerticalContentAlignmentProperty);
			TITANIUM_ADD_FUNCTION(Control, ApplyTemplate);
			TITANIUM_ADD_FUNCTION(Control, Focus);
		}

		TITANIUM_PROPERTY_SETTER(Control, FontStyle)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStyle>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStyle = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStyle)
		{
			auto value = unwrap()->FontStyle;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, FontStretch)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Text::FontStretch>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->FontStretch = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStretch)
		{
			auto value = unwrap()->FontStretch;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, FontSize)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);


			unwrap()->FontSize = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontSize)
		{
			auto value = unwrap()->FontSize;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<double>(value));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, FontFamily)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_FontFamily();


			unwrap()->FontFamily = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontFamily)
		{
			auto value = unwrap()->FontFamily;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::FontFamily>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::FontFamily>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, FontWeight)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Text::FontWeight(0);
			// Assign fields explicitly since we cheated on constructor args
			auto Weight = object_value.GetProperty("Weight");
			value.Weight = static_cast<int32_t>(Weight);


			unwrap()->FontWeight = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontWeight)
		{
			auto value = unwrap()->FontWeight;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Weight", context.CreateNumber(static_cast<int32_t>(value.Weight)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, CharacterSpacing)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->CharacterSpacing = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, CharacterSpacing)
		{
			auto value = unwrap()->CharacterSpacing;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, BorderThickness)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Thickness(0, 0, 0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto Left = object_value.GetProperty("Left");
			value.Left = static_cast<int32_t>(Left);
			auto Top = object_value.GetProperty("Top");
			value.Top = static_cast<int32_t>(Top);
			auto Right = object_value.GetProperty("Right");
			value.Right = static_cast<int32_t>(Right);
			auto Bottom = object_value.GetProperty("Bottom");
			value.Bottom = static_cast<int32_t>(Bottom);


			unwrap()->BorderThickness = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderThickness)
		{
			auto value = unwrap()->BorderThickness;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, BorderBrush)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Brush();


			unwrap()->BorderBrush = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderBrush)
		{
			auto value = unwrap()->BorderBrush;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, Background)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Brush();


			unwrap()->Background = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Background)
		{
			auto value = unwrap()->Background;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, VerticalContentAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::VerticalAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->VerticalContentAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, VerticalContentAlignment)
		{
			auto value = unwrap()->VerticalContentAlignment;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, Template)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Controls::ControlTemplate>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Controls_ControlTemplate();


			unwrap()->Template = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Template)
		{
			auto value = unwrap()->Template;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::ControlTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Controls::ControlTemplate>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, TabNavigation)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::Input::KeyboardNavigationMode>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TabNavigation = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabNavigation)
		{
			auto value = unwrap()->TabNavigation;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, TabIndex)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);


			unwrap()->TabIndex = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabIndex)
		{
			auto value = unwrap()->TabIndex;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, Padding)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Thickness(0, 0, 0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto Left = object_value.GetProperty("Left");
			value.Left = static_cast<int32_t>(Left);
			auto Top = object_value.GetProperty("Top");
			value.Top = static_cast<int32_t>(Top);
			auto Right = object_value.GetProperty("Right");
			value.Right = static_cast<int32_t>(Right);
			auto Bottom = object_value.GetProperty("Bottom");
			value.Bottom = static_cast<int32_t>(Bottom);


			unwrap()->Padding = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Padding)
		{
			auto value = unwrap()->Padding;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Left", context.CreateNumber(static_cast<int32_t>(value.Left)));
			result.SetProperty("Top", context.CreateNumber(static_cast<int32_t>(value.Top)));
			result.SetProperty("Right", context.CreateNumber(static_cast<int32_t>(value.Right)));
			result.SetProperty("Bottom", context.CreateNumber(static_cast<int32_t>(value.Bottom)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, IsTabStop)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsTabStop = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsTabStop)
		{
			auto value = unwrap()->IsTabStop;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, IsEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsEnabled)
		{
			auto value = unwrap()->IsEnabled;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, HorizontalContentAlignment)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::HorizontalAlignment>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->HorizontalContentAlignment = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, HorizontalContentAlignment)
		{
			auto value = unwrap()->HorizontalContentAlignment;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, Foreground)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Brush();


			unwrap()->Foreground = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, Foreground)
		{
			auto value = unwrap()->Foreground;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Brush>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Brush>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FocusState)
		{
			auto value = unwrap()->FocusState;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Control, DefaultStyleKey)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapPlatform_Object();


			unwrap()->DefaultStyleKey = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Control, DefaultStyleKey)
		{
			auto value = unwrap()->DefaultStyleKey;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, BackgroundProperty)
		{
			auto value = unwrap()->BackgroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderBrushProperty)
		{
			auto value = unwrap()->BorderBrushProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, BorderThicknessProperty)
		{
			auto value = unwrap()->BorderThicknessProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, CharacterSpacingProperty)
		{
			auto value = unwrap()->CharacterSpacingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, DefaultStyleKeyProperty)
		{
			auto value = unwrap()->DefaultStyleKeyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FocusStateProperty)
		{
			auto value = unwrap()->FocusStateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontFamilyProperty)
		{
			auto value = unwrap()->FontFamilyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontSizeProperty)
		{
			auto value = unwrap()->FontSizeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStretchProperty)
		{
			auto value = unwrap()->FontStretchProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontStyleProperty)
		{
			auto value = unwrap()->FontStyleProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, FontWeightProperty)
		{
			auto value = unwrap()->FontWeightProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, ForegroundProperty)
		{
			auto value = unwrap()->ForegroundProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, HorizontalContentAlignmentProperty)
		{
			auto value = unwrap()->HorizontalContentAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsEnabledProperty)
		{
			auto value = unwrap()->IsEnabledProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, IsTabStopProperty)
		{
			auto value = unwrap()->IsTabStopProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, PaddingProperty)
		{
			auto value = unwrap()->PaddingProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabIndexProperty)
		{
			auto value = unwrap()->TabIndexProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, TabNavigationProperty)
		{
			auto value = unwrap()->TabNavigationProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, TemplateProperty)
		{
			auto value = unwrap()->TemplateProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Control, VerticalContentAlignmentProperty)
		{
			auto value = unwrap()->VerticalContentAlignmentProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(Control, ApplyTemplate)
		{
			auto context = get_context();
			auto method_result = unwrap()->ApplyTemplate();

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

		TITANIUM_FUNCTION(Control, Focus)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::FocusState>(static_cast<int32_t>(_0)); // TODO Look up enum in metadata to know what type it's value is? 


			auto context = get_context();
			auto method_result = unwrap()->Focus(value);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
