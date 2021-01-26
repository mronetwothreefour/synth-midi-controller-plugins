#include "params_ExposedParametersListener.h"

#include "params_Constants.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "params_UnexposedParameters_Facade.h"
#include "params_RangeTypes.h"
#include "../midi/midi_SysExHelpers.h"

using namespace constants;



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
			outputValue -= matrixParams::offsetForSigned6bitRange;
		if (info.rangeTypeFor(param) == RangeType::signed7bitValue)
			outputValue -= matrixParams::offsetForSigned7bitRange;
		if (info.isQuickEditable(param) && outputValue > -1) {
			auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			auto paramChangeMessage{ RawSysExDataVector::createParamChangeMessage(outputValue, param) };
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
