#pragma once

#include <JuceHeader.h>


namespace MophoConstants
{
	const enum class AllowedChoicesType {
		standard = 0,
		oscShape,
		binary,
		lfoFreq,
		seqTrackStep
	};


	const enum class BankTransmitType {
		push = 0,
		pull
	};


	const enum class ControlType {
		nullControl = -1, // needed by ExposedParamControl's default constructor
		knob,
		knobForPitch,
		knobForOscShape,
		toggleButton,
		comboBox,
		seqTrackStep,
		voiceNameChar
	};


	const enum class EnvelopeType {
		env_3 = 0,
		lpf,
		vca
	};


	const enum class GlobalParamComboBoxType {
		midiClockSource = 0,
		pedalMode,
		voiceChanges,
		paramChangeSendType
	};


	const enum class GlobalParamDisplayLabelType {
		paramChangeReceiveType = 0,
		midiControllersStatus,
		sysExStatus,
		audioOutput,
		hardwareOutputBalance
	};


	const enum class GlobalParamKnobType {
		globalTranspose = 0,
		globalFineTune,
		hardwareReceiveChannel
	};


	const enum class GlobalParamToggleType {
		currentValueTooltip = 0,
		descriptionTooltip,
	};


	enum class ImportExportType {
		exportVoice = 0,
		exportVoicesBank,
		importVoice,
		importVoicesBank
	};


	enum class LFO_FreqCategory {
		unsynced = 0,
		pitched,
		synced
	};


	const enum class MIDI_ClockSource {
		internalClock = 0,
		internalClock_Send,
		externalClock,
		externalClock_Resend
	};


	const enum class OscWaveShape {
		off = 0,
		sawtooth,
		triangle,
		sawTriMix,
		pulse
	};


	const enum class ParamChangeReceiveType {
		all = 0,
		nrpnOnly,
		ccOnly,
		off
	};


	const enum class ParamChangeSendType {
		nrpn = 0,
		cc,
		off
	};


	const enum class SeqTrackNum {
		one = 1, two, three, four
	};


	const enum class SeqTrackProbabilityKnobType {
		rest = 0, 
		duplicate, 
		reset
	};


	const enum class SeqTrackStepNum {
		all = 0, one, two, three, four, five, six, seven, eight,
		nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen
	};


	const enum class SysExMessageType {
		voiceData = 2,
		editBufferData = 3,
		voiceDataRequest = 5,
		editBufferDataRequest = 6,
		globalParametersDataRequest = 14,
		globalParametersData = 15
	};


	const enum class VoicesBank {
		factory_1 = 0,
		factory_2,
		factory_3,
		custom_1,
		custom_2,
		custom_3
	};
}

