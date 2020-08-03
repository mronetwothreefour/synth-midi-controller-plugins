#pragma once

#include <JuceHeader.h>

#include "../midiTools/midi_ParameterChangeMessage.h"
#include "params_InfoForExposedParameters_Singleton.h"
#include "params_UnexposedParameters.h"
#include "params_SpecialValueOffsets.h"



class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener
{
	AudioProcessorValueTreeState* exposedParams;

	void parameterChanged(const String& parameterID, float newValue) override {
		auto& midiParams{ MidiParameters_Singleton::get() };
		if (midiParams.paramChangeEchosAreNotBlocked()) {
			auto& info{ InfoForExposedParameters::get() };
			auto param{ info.indexFor(parameterID) };
			auto nrpn{ info.NRPNfor(param) };
			auto outputValue{ (uint8)roundToInt(newValue) };
			outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
			ParameterChangeMessage::sendNewValueForNRPNtype(outputValue, nrpn);
			if ((param == 98 || param == 100) && outputValue == 1)
				arpeggiatorAndSequencerCannotBothBeOn(param);
		}
		else return;
	}

	void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
		auto& info{ InfoForExposedParameters::get() };
		auto arpegParam{ exposedParams->getParameter(info.IDfor(98)) };
		auto sequencerParam{ exposedParams->getParameter(info.IDfor(100)) };
		if (paramTurnedOn == 98 && sequencerParam != nullptr)
			if (sequencerParam->getValue() != 0.0f)
				sequencerParam->setValueNotifyingHost(0.0f);
		if (paramTurnedOn == 100 && arpegParam != nullptr)
			if (arpegParam->getValue() != 0.0f)
				arpegParam->setValueNotifyingHost(0.0f);
	}

public:
	explicit ExposedParametersListener(AudioProcessorValueTreeState* exposedParams) :
		exposedParams{ exposedParams }
	{
		auto& info{ InfoForExposedParameters::get() };
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
			exposedParams->addParameterListener(info.IDfor(param), this);
	}

	~ExposedParametersListener() {
		auto& info{ InfoForExposedParameters::get() };
		for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
			exposedParams->removeParameterListener(info.IDfor(param), this);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};