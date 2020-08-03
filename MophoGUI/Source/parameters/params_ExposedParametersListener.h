#pragma once

#include <JuceHeader.h>

#include "../midiTools/helper_MidiTools.h"
#include "params_InfoForExposedParameters_Singleton.h"
#include "params_UnexposedParameters.h"
#include "params_SpecialValueOffsets.h"



class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener,
	public OutgoingMidiGenerator
{
public:
	AudioProcessorValueTreeState* exposedParams;

	void parameterChanged(const String& parameterID, float newValue) override {
		auto& midiParams{ MidiParameters_Singleton::get() };
		if (midiParams.paramChangeEchosAreNotBlocked()) {
			auto& info{ InfoForExposedParameters::get() };
			auto param{ info.indexFor(parameterID) };
			auto nrpn{ info.NRPNfor(param) };
			auto outputValue{ (uint8)roundToInt(newValue) };
			outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
			addParamChangedMessageToMidiBuffer(nrpn, outputValue);
			if ((param == 98 || param == 100) && outputValue == 1)
				arpeggiatorAndSequencerCannotBothBeOn(param);
		}
		else return;
	}

	explicit ExposedParametersListener(AudioProcessorValueTreeState* exposedParams) :
		exposedParams{ exposedParams },
		OutgoingMidiGenerator{ exposedParams }
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