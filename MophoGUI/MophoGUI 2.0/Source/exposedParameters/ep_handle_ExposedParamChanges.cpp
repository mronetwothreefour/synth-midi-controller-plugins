#include "ep_handle_ExposedParamChanges.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MIDI.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
//#include "../randomization/randomization_ParamRandomizationMethods.h" todo: handle randomization triggers
#include "../exposedParameters/ep_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ExposedParamChangesHandler::ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() }
{
	for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ exposedParams->info.IDfor(paramIndex) };
		auto paramPtr{ exposedParams->state.getParameter(paramID) };
		paramPtr->addListener(this);
//		exposedParams->addParameterListener(ID::rndmTrigFor_.toString() + paramID, this);
	}
//	exposedParams->addParameterListener(ID::rndmTrigFor_AllUnlocked.toString(), this);
}

void ExposedParamChangesHandler::parameterValueChanged(int changedParamIndex, float newValue) {
	// todo: randomization triggers
	//if (parameterID.startsWith(ID::rndmTrigFor_.toString())) {
	//	ParamRandomizationMethods paramRandomizationMethods{ exposedParams, unexposedParams };
	//	if (parameterID == ID::rndmTrigFor_AllUnlocked.toString())
	//		paramRandomizationMethods.randomizeAllUnlockedParameters();
	//	else {
	//		auto targetParamID{ parameterID.fromFirstOccurrenceOf("For_", false, false) };
	//		paramRandomizationMethods.randomizeParameter(targetParamID);
	//	}
	//}
	//else {
		if (voiceTransmit->paramChangesShouldBeTransmitted()) {
			auto paramID{ exposedParams->info.IDfor((uint8)changedParamIndex) };
			auto nrpn{ exposedParams->info.NRPNfor((uint8)changedParamIndex) };
			auto paramPtr{ exposedParams->state.getParameter(paramID) };
			auto outputValue{ (uint8)roundToInt(paramPtr->convertFrom0to1(newValue)) };
			if (paramID == ID::ep_095_ClockTempo)
				outputValue += EP::clockTempoOffset;
			if (paramID.toString().contains("_AssignKnob_") && outputValue >= EP::firstKnobAssignParamIndex)
				outputValue += EP::knobAssignAndUnassignedParamsOffset;
			ParameterChangeMessage::sendNewValueForNRPNtypeToUnexposedParamsForHandling(outputValue, nrpn, unexposedParams);
			if ((paramID == ID::ep_098_ArpegOnOff || paramID == ID::ep_100_SeqOnOff) && outputValue == 1)
				arpeggiatorAndSequencerCannotBothBeOn(paramID);
		}
	//}
}

void ExposedParamChangesHandler::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void ExposedParamChangesHandler::arpeggiatorAndSequencerCannotBothBeOn(Identifier turnedOnParamID) {
	auto arpegParamPtr{ exposedParams->state.getParameter(ID::ep_098_ArpegOnOff) };
	auto sequencerParamPtr{ exposedParams->state.getParameter(ID::ep_100_SeqOnOff) };
	if (turnedOnParamID == ID::ep_098_ArpegOnOff && sequencerParamPtr != nullptr)
		if (sequencerParamPtr->getValue() != 0.0f)
			sequencerParamPtr->setValueNotifyingHost(0.0f);
	if (turnedOnParamID == ID::ep_100_SeqOnOff && arpegParamPtr != nullptr)
		if (arpegParamPtr->getValue() != 0.0f)
			arpegParamPtr->setValueNotifyingHost(0.0f);
}

ExposedParamChangesHandler::~ExposedParamChangesHandler() {
	//exposedParams->removeParameterListener(ID::rndmTrigFor_AllUnlocked.toString(), this);
	for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ exposedParams->info.IDfor(paramIndex) };
		auto paramPtr{ exposedParams->state.getParameter(paramID) };
		paramPtr->removeListener(this);
		//exposedParams->removeParameterListener(ID::rndmTrigFor_.toString() + paramID, this);
	}
}
