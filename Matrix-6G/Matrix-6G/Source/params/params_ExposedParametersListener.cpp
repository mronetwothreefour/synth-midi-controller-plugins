#include "params_ExposedParametersListener.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "params_UnexposedParameters_Facade.h"
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
		auto outputValue{ (uint8)roundToInt(newValue) };
		ParameterChangeMessage::sendNewValueForParameterToUnexposedParamsForHandling(outputValue, param, unexposedParams);
	}
	else return;
}

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);
}
