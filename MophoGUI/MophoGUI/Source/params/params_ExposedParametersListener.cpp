#include "params_ExposedParametersListener.h"

#include "params_ExposedParamsInfo_Singleton.h"
#include "../midi/midi_ParameterChangeMessage.h"
#include "params_SpecialValueOffsets.h"
#include "params_UnexposedParameters_Facade.h"



ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	midiOptions{ unexposedParams->midiOptions_get() },
	arpeggiator{ 98 },
	sequencer{ 100 }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->addParameterListener(info.IDfor(param), this);
}

void ExposedParametersListener::parameterChanged(const String& parameterID, float newValue) {
	if (midiOptions->paramChangeEchosAreNotBlocked()) {
		auto& info{ InfoForExposedParameters::get() };
		auto param{ info.indexForParamID(parameterID) };
		auto nrpn{ info.NRPNfor(param) };
		auto outputValue{ (uint8)roundToInt(newValue) };
		outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
		ParameterChangeMessage::sendNewValueForNRPNtypeToUnexposedParamsForHandling(outputValue, nrpn, unexposedParams);
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

ExposedParametersListener::~ExposedParametersListener() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		exposedParams->removeParameterListener(info.IDfor(param), this);
}