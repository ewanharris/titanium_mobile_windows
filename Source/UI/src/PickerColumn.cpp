/**
* Titanium.UI.PickerColumn for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/PickerColumn.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/UI/PickerRow.hpp"
#include "TitaniumWindows/WindowsMacros.hpp"
#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Platform::Collections;
		using namespace Windows::UI::Xaml;

		PickerColumn::PickerColumn(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::PickerColumn(js_context)
		{
			TITANIUM_LOG_DEBUG("PickerColumn::ctor ", this);
		}

		PickerColumn::~PickerColumn() 
		{
			TITANIUM_LOG_DEBUG("PickerColumn::dtor ", this);
		}

		void PickerColumn::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::PickerColumn::postCallAsConstructor(js_context, arguments);
			picker__ = ref new Windows::UI::Xaml::Controls::ComboBox();
		}

		std::shared_ptr<Titanium::UI::PickerRow> PickerColumn::get_selectedRow() const TITANIUM_NOEXCEPT
		{
			const auto index = picker__->SelectedIndex;
			if (index >= 0 && rows__.size() > static_cast<std::uint32_t>(index)) {
				return rows__.at(index);
			} else {
				return nullptr;
			}
		}

		void PickerColumn::addRow(const std::shared_ptr<Titanium::UI::PickerRow>& r) TITANIUM_NOEXCEPT
		{
			Titanium::UI::PickerColumn::addRow(r);

			const auto row = std::dynamic_pointer_cast<TitaniumWindows::UI::PickerRow>(r);
			picker__->Items->Append(row->getComboBoxItem());
		}

		void PickerColumn::removeRow(const std::shared_ptr<Titanium::UI::PickerRow>& r) TITANIUM_NOEXCEPT
		{
			Titanium::UI::PickerColumn::removeRow(r);

			const auto row = std::dynamic_pointer_cast<TitaniumWindows::UI::PickerRow>(r);
			std::uint32_t index;
			if (picker__->Items->IndexOf(row->getComboBoxItem(), &index)) {
				picker__->Items->RemoveAt(index);
			}
		}

		void PickerColumn::afterPropertiesSet() TITANIUM_NOEXCEPT
		{
			refreshRows();
		}

		void PickerColumn::refreshRows() TITANIUM_NOEXCEPT
		{
			picker__->Items->Clear();

			for (const auto r : rows__) {
				const auto row = std::dynamic_pointer_cast<TitaniumWindows::UI::PickerRow>(r);
				picker__->Items->Append(row->getComboBoxItem());
			}
		}

		void PickerColumn::JSExportInitialize()
		{
			JSExport<PickerColumn>::SetClassVersion(1);
			JSExport<PickerColumn>::SetParent(JSExport<Titanium::UI::PickerColumn>::Class());
		}

	} // namespace UI
} // namespace TitaniumWindows
