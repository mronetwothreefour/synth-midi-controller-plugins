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


	const enum class ChoiceNameType {
		concise = 0,
		verbose
	};


	const enum class ControlType {
		nullControl = -1,
		slider,
		sliderForPitch,
		sliderForOscBalance,
		comboBox
	};


	const enum class GlobalParamComboBoxType {
		omniModeOffOn = 0,
		controllersOffOn,
		voiceChangesOffOn,
		sysExOffOn,
		spilloverOffOn,
		midiEchoOffOn,
		midiMonoOffOn,
		activeSensingOffOn,
		localControlOffOn,
		vibratoWaveType,
		vibratoSpeedModSource,
		vibratoAmpModSource,
		splitStereoOffOn,
		voiceMapOffOn,
		voiceMapEchoOffOn,
		squickOffOn,
		descriptionTipsOffOn,
		currentValueTipsOffOn
	};


	const enum class GlobalParamSliderType {
		basicChannel = 0,
		pedal_1_ControllerNum,
		pedal_2_ControllerNum,
		lever_2_ControllerNum,
		lever_3_ControllerNum,
		vibratoSpeed,
		vibratoAmplitude,
		vibratoSpeedModAmount,
		vibratoAmpModAmount,
		globalTune,
		displayBrightness
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
		oscPitch = 0,
		signed_6_bitValue,
		signed_7_bitValue,
		unsignedValue
	};


	const enum class SplitParamComboBoxType {
		zoneVoiceAssignment = 0,
		lowerZone_MIDI_IsEnabled,
		upperZone_MIDI_IsEnabled
	};


	const enum class SplitParamSliderType {
		zoneVolumeBalance = 0,
		lowerZoneLimit,
		lowerZoneVoiceNum,
		lowerZoneTranspose,
		upperZoneLimit,
		upperZoneVoiceNum,
		upperZoneTranspose
	};


	const enum class SplitZone {
		lower = 0,
		upper
	};


	const enum class SplitZoneVoiceAssignment {
		lower_2_Upper_4 = 0,
		lower_4_Upper_2,
		lower_6_Upper_0,
		lower_0_Upper_6
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


	const enum class VibratoModSource {
		off = 0,
		lever_2,
		pedal_1
	};


	const enum class VibratoWaveType {
		triangle = 0,
		upSawtooth,
		downSawtooth,
		square,
		random,
		noise
	};


	const enum class VoiceMapSliderType {
		null = -1,
		in,
		out
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
