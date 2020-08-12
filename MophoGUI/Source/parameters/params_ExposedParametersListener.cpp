#include "params_ExposedParametersListener.h"

#include "params_InfoForExposedParameters_Singleton.h"
#include "params_SpecialValueOffsets.h"
#include "../midiTools/midi_ParameterChangeMessage.h"



ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers) :
	exposedParams{ exposedParams },
	outgoingBuffers{ outgoingBuffers },
	arpeggiator{ 98 },
	sequencer{ 100 }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->addParameterListener(info.IDfor(param), this);
}

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);
}

void ExposedParametersListener::parameterChanged(const String& parameterID, float newValue) {
	auto& midiParams{ MidiOptions::get() };
	if (midiParams.paramChangeEchosAreNotBlocked()) {
		auto& info{ InfoForExposedParameters::get() };
		auto param{ info.indexForParamID(parameterID) };
		auto nrpn{ info.NRPNfor(param) };
		auto outputValue{ (uint8)roundToInt(newValue) };
		outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
		ParameterChangeMessage::addNewValueForNRPNtypeToOutgoingMidiBuffers(outputValue, nrpn, outgoingBuffers);
		if ((param == arpeggiator || param == sequencer) && outputValue == 1)
			arpeggiatorAndSequencerCannotBothBeOn(param);
	}
	else return;
}

void ExposedParametersListener::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
	auto& info{ InfoForExposedParameters::get() };
	auto arpegParam{ exposedParams->getParameter(info.IDfor(arpeggiator)) };
	auto sequencerParam{ exposedParams->getParameter(info.IDfor(sequencer)) };
	if (paramTurnedOn == arpeggiator && sequencerParam != nullptr)
		if (sequencerParam->getValue() != 0.0f)
			sequencerParam->setValueNotifyingHost(0.0f);
	if (paramTurnedOn == sequencer && arpegParam != nullptr)
		if (arpegParam->getValue() != 0.0f)
			arpegParam->setValueNotifyingHost(0.0f);
}
