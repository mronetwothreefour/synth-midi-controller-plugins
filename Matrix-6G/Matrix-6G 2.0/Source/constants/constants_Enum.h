#pragma once

#include <JuceHeader.h>

namespace Matrix_6G_Constants
{
	const enum class BankTransmitType {
		push = 0,
		pull
	};


	const enum class BorderColor {
		blue = 0,
		grey,
		orange
	};


	const enum class ControlType {
		nullControl = -1,
		slider,
		sliderForPitch,
		sliderForOscBalance,
		comboBox
	};


	const enum class ImportExportType {
		exportVoice = 0,
		exportVoicesBank,
		importVoice,
		importVoicesBank
	};


	const enum class RangeType {
		unsignedValue = 0,
		signed_6_bitValue,
		signed_7_bitValue
	};


	const enum class SliderTextEditorType {
		oscPitch,
		signed_6_bitValue,
		signed_7_bitValue,
		unsignedValue
	};


	const enum class SysExMessageType {
		voiceData = 1,
		splitData,
		globalData,
		dataRequest,
		activateQuickEdit,
		parameterChange,
		switchMode = 13
	};


	const enum class SysExDatatrRequestType {
		voice = 1,
		split,
		global
	};


	const enum class VoicesBank {
		nullBank = -1, // needed by VoiceSlotRadioButton's default constructor
		analogSynths_A = 0,
		analogSynths_B,
		basses,
		brassAndWoodwinds,
		fxAndPercussion,
		keyboards_A,
		keyboards_B,
		leads,
		miscellaneous_A,
		miscellaneous_B,
		strings,
		custom_A,
		custom_B
	};
}
