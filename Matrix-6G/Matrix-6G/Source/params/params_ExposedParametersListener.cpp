#include "params_ExposedParametersListener.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_UnexposedParameters_Facade.h"
#include "params_RangeTypes.h"
#include "../midi/midi_ParameterChangeMessage.h"



ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	midiOptions{ unexposedParams->midiOptions_get() }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->addParameterListener(info.IDfor(param), this);
}

void ExposedParametersListener::parameterChanged(const String& parameterID, float newValue) {
	if (midiOptions->paramChangeEchosAreNotBlocked()) {
		auto& info{ InfoForExposedParameters::get() };
		auto param{ info.indexForParamID(parameterID) };
		auto outputValue{ (int8)roundToInt(newValue) };
		if (info.rangeTypeFor(param) == RangeType::signed6bitValue)
			outputValue -= offsetFor5bitSignedValues;
		if (info.rangeTypeFor(param) == RangeType::signed7bitValue)
			outputValue -= offsetFor6bitSignedValues;
		if (info.isQuickEditable(param) && outputValue > -1) {
			auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			ParameterChangeMessage::sendNewValueForParameterToOutgoingMidiBuffers(outputValue, info.paramNumberFor(param), outgoingMidiBuffers);
		}
	}
	else return;
}

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);
}
