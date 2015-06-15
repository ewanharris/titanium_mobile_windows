/**
 * Windows Native Wrapper for Windows.UI.Xaml.TriggerCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.TriggerBase.hpp"
#include "Windows.UI.Xaml.TriggerCollection.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		TriggerCollection::TriggerCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
			TITANIUM_LOG_DEBUG("TriggerCollection::ctor");
		}

		void TriggerCollection::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("TriggerCollection::postCallAsConstructor ", this);

		}

		::Windows::UI::Xaml::TriggerCollection^ TriggerCollection::unwrapWindows_UI_Xaml_TriggerCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::TriggerCollection^>(wrapped__);
		}

		::Windows::UI::Xaml::TriggerCollection^ TriggerCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_TriggerCollection();
		}

		void TriggerCollection::wrap(::Windows::UI::Xaml::TriggerCollection^ object)
		{
			wrapped__ = object;
		}

		void TriggerCollection::JSExportInitialize()
		{
			JSExport<TriggerCollection>::SetClassVersion(1);
			JSExport<TriggerCollection>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TriggerCollection, Size);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetView);
			TITANIUM_ADD_FUNCTION(TriggerCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(TriggerCollection, SetAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, Append);
			TITANIUM_ADD_FUNCTION(TriggerCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(TriggerCollection, Clear);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetMany);
			TITANIUM_ADD_FUNCTION(TriggerCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(TriggerCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(TriggerCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();


		}

		TITANIUM_FUNCTION(TriggerCollection, GetAt)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto method_result = unwrap()->GetAt(index);
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			result_wrapper->wrap(method_result);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::GetAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, GetView)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				auto method_result = unwrap()->GetView();
			for (uint32_t i = 0; i < method_result->Size; ++i) {
				
			auto method_result_tmp_wrapper = method_result_tmp.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			method_result_tmp_wrapper->wrap(method_result->GetAt(i));

			}

			auto result = get_context().CreateArray(result_vector);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::GetView with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, IndexOf)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0);
			auto object_value = static_cast<JSObject>(_0);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();

				auto _1 = arguments.at(1); 
			auto index = static_cast<uint32_t>(_1);

				auto method_result = unwrap()->IndexOf(value, &index);


				_1 = out_1;
				return result;
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::IndexOf with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, SetAt)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_value = static_cast<JSObject>(_1);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();

				unwrap()->SetAt(index, value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::SetAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, InsertAt)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_value = static_cast<JSObject>(_1);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();

				unwrap()->InsertAt(index, value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::InsertAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, RemoveAt)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0); 
			auto index = static_cast<uint32_t>(_0);

				unwrap()->RemoveAt(index);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::RemoveAt with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, Append)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_value = static_cast<JSObject>(_0);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();

				unwrap()->Append(value);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::Append with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, RemoveAtEnd)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->RemoveAtEnd();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::RemoveAtEnd with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, Clear)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->Clear();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::Clear with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, GetMany)
		{
			auto context = get_context();
			if (arguments.size() == 2) {
				auto _0 = arguments.at(0); 
			auto startIndex = static_cast<uint32_t>(_0);

				auto _1 = arguments.at(1);
			auto object_items = static_cast<JSObject>(_1);

			const auto array_items = static_cast<JSArray>(object_items);
			auto items_items = array_items.GetPrivateItems<Windows::UI::Xaml::TriggerBase>(); // std::vector<std::shared_ptr<Windows::UI::Xaml::TriggerBase>
			auto items = ref new ::Platform::Array<::Windows::UI::Xaml::TriggerBase^>(items_items.size());
			for (size_t i = 0; i < items_items.size(); ++i) {
				items[i] = items_items.at(i)->unwrapWindows_UI_Xaml_TriggerBase();
			}

				auto method_result = unwrap()->GetMany(startIndex, items);

			for (size_t i = 0; i < items->Length; ++i) {
				
			auto items_tmp_wrapper = items_tmp.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			items_tmp_wrapper->wrap(items[i]);
		
			}

			auto out_1 = get_context().CreateArray(out_1_vector);

				_1 = out_1;
				return result;
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::GetMany with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, ReplaceAll)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto object_items = static_cast<JSObject>(_0);

			const auto array_items = static_cast<JSArray>(object_items);
			auto items_items = array_items.GetPrivateItems<Windows::UI::Xaml::TriggerBase>(); // std::vector<std::shared_ptr<Windows::UI::Xaml::TriggerBase>
			auto items = ref new ::Platform::Array<::Windows::UI::Xaml::TriggerBase^>(items_items.size());
			for (size_t i = 0; i < items_items.size(); ++i) {
				items[i] = items_items.at(i)->unwrapWindows_UI_Xaml_TriggerBase();
			}

				unwrap()->ReplaceAll(items);
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::ReplaceAll with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, First)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				auto method_result = unwrap()->First();
			while (method_result->HasCurrent) {
				
			auto method_result_tmp_wrapper = method_result_tmp.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			method_result_tmp_wrapper->wrap(method_result->Current);

        		method_result->MoveNext();
			}

			auto result = get_context().CreateArray(result_vector);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched TriggerCollection::First with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium