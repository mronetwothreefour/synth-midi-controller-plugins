#include "params_ExposedParametersListener.h"

#include "params_Constants.h"
#include "params_ExposedParamsInfo_Singleton.h"
#include "params_Identifiers.h"
#include "params_SpecialValueOffsets.h"
#include "params_UnexposedParameters_Facade.h"
#include "../midi/midi_ParameterChangeMessage.h"
#include "../randomization/randomization_ParamRandomizationMethods.h"

using namespace constants;



ExposedParametersListener::ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() }
{
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info.IDfor(paramIndex).toString() };
		exposedParams->addParameterListener(paramID, this);
		exposedParams->addParameterListener(ID::rndmTrigFor_.toString() + paramID, this);
	}
	exposedParams->addParameterListener(ID::rndmTrigFor_AllUnlocked.toString(), this);
}

void ExposedParametersListener::parameterChanged(const String& parameterID, float newValue) {
	auto& info{ InfoForExposedParameters::get() };
	if (parameterID.startsWith(ID::rndmTrigFor_.toString())) {
		ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
		if (parameterID == ID::rndmTrigFor_AllUnlocked.toString())
			paramRandomizationMethods.randomizeAllUnlockedParameters();
		else {
			auto targetParamID{ parameterID.fromFirstOccurrenceOf("For_", false, false) };
			paramRandomizationMethods.randomizeParameter(targetParamID);
		}
	}
	else {
		if (voiceTransmissionOptions->paramChangeEchoesAreNotBlocked()) {
			auto param{ info.indexForParamID(parameterID) };
			auto nrpn{ info.NRPNfor(param) };
			auto outputValue{ (uint8)roundToInt(newValue) };
			outputValue = SpecialValueOffsets::addWhenWritingToData(param, outputValue);
			ParameterChangeMessage::sendNewValueForNRPNtypeToUnexposedParamsForHandling(outputValue, nrpn, unexposedParams);
			if ((param == params::arpeggiator || param == params::sequencer) && outputValue == 1)
				arpeggiatorAndSequencerCannotBothBeOn(param);
		}
	}
}

void ExposedParametersListener::arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn) {
	auto& info{ InfoForExposedParameters::get() };
	auto arpegParam{ exposedParams->getParameter(info.IDfor(params::arpeggiator)) };
	auto sequencerParam{ exposedParams->getParameter(info.IDfor(params::sequencer)) };
	if (paramTurnedOn == params::arpeggiator && sequencerParam != nullptr)
		if (sequencerParam->getValue() != 0.0f)
			sequencerParam->setValueNotifyingHost(0.0f);
	if (paramTurnedOn == params::sequencer && arpegParam != nullptr)
		if (arpegParam->getValue() != 0.0f)
			arpegParam->setValueNotifyingHost(0.0f);
}

ExposedParametersListener::~ExposedParametersListener() {
	exposedParams->removeParameterListener(ID::rndmTrigFor_AllUnlocked.toString(), this);
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 paramIndex = 0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info.IDfor(paramIndex).toString() };
		exposedParams->removeParameterListener(paramID, this);
		exposedParams->removeParameterListener(ID::rndmTrigFor_.toString() + paramID, this);
	}
}