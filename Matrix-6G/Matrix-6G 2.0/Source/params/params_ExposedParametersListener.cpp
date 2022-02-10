#include "params_ExposedParametersListener.h"

#include "params_Constants.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "params_UnexposedParameters_Facade.h"
#include "params_RangeTypes.h"
#include "../midi/midi_RawDataTools.h"

using namespace constants;



ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->addParameterListener(info.IDfor(param), this);
}

void ExposedParametersListener::parameterChanged(const String& parameterID, float newValue) {
	if (voiceTransmissionOptions->paramChangeEchosAreNotBlocked()) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramIndex{ info.indexForParamID(parameterID) };
		auto outputValue{ (int8)roundToInt(newValue) };
		if (info.rangeTypeFor(paramIndex) == RangeType::signed6bitValue)
			outputValue -= params::offsetForSigned6bitRange;
		if (info.rangeTypeFor(paramIndex) == RangeType::signed7bitValue)
			outputValue -= params::offsetForSigned7bitRange;
		if (info.isQuickEditable(paramIndex) && outputValue > -1) {
			auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			auto paramNumber{ info.paramNumberFor(paramIndex) };
			auto paramChangeMessage{ RawSysExDataVector::createParamChangeMessage(outputValue, paramNumber) };
			outgoingMidiBuffers->addDataMessage(paramChangeMessage);
		}
	}
	else return;
}

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);
}
