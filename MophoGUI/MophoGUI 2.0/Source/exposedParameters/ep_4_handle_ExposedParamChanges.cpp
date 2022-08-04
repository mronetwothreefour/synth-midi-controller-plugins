#include "ep_4_handle_ExposedParamChanges.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MIDI.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

ExposedParamChangesHandler::ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	randomize{ exposedParams->randomize.get() },
	unexposedParams{ unexposedParams },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
	for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->addListener(this);
		auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrig_.toString() + paramID) };
		rndmTrigParamPtr->addListener(this);
	}
	auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrig_AllUnlocked) };
	rndmTrigAllParamPtr->addListener(this);
}

void ExposedParamChangesHandler::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex < EP::numberOfExposedParams) {
		if (transmitOptions->paramChangesShouldBeTransmitted()) {
			auto paramID{ info->IDfor((uint8)changedParamIndex) };
			auto nrpn{ info->NRPNfor((uint8)changedParamIndex) };
			auto paramPtr{ state->getParameter(paramID) };
			auto outputValue{ (uint8)roundToInt(paramPtr->convertFrom0to1(newValue)) };
			if (paramID == ID::ep_095_ClockTempo)
				outputValue += EP::clockTempoOffset;
			if (paramID.toString().contains("_AssignKnob_") && outputValue >= EP::firstKnobAssignParamIndex)
				outputValue += EP::knobAssignAndUnassignedParamsOffset;
			ParameterChangeMessage::sendNewValueForNRPNtypeToUnexposedParamsForHandling(outputValue, nrpn, unexposedParams);
			if ((paramID == ID::ep_098_ArpegOnOff || paramID == ID::ep_100_SeqOnOff) && outputValue == 1)
				arpeggiatorAndSequencerCannotBothBeOn(paramID);
		}
	}
	else {
		if (changedParamIndex == EP::numberOfExposedParams)
			randomize->randomizeAllUnlockedParameters();
		else {
			auto paramIndex{ uint8(changedParamIndex - (EP::numberOfExposedParams + 1)) };
			randomize->randomizeParameter(paramIndex);
		}
	}
}

void ExposedParamChangesHandler::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void ExposedParamChangesHandler::arpeggiatorAndSequencerCannotBothBeOn(const Identifier turnedOnParamID) {
	auto arpegParamPtr{ state->getParameter(ID::ep_098_ArpegOnOff) };
	auto sequencerParamPtr{ state->getParameter(ID::ep_100_SeqOnOff) };
	if (turnedOnParamID == ID::ep_098_ArpegOnOff && sequencerParamPtr != nullptr)
		if (sequencerParamPtr->getValue() != 0.0f)
			sequencerParamPtr->setValueNotifyingHost(0.0f);
	if (turnedOnParamID == ID::ep_100_SeqOnOff && arpegParamPtr != nullptr)
		if (arpegParamPtr->getValue() != 0.0f)
			arpegParamPtr->setValueNotifyingHost(0.0f);
}

ExposedParamChangesHandler::~ExposedParamChangesHandler() {
	for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->removeListener(this);
		auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrig_.toString() + paramID) };
		rndmTrigParamPtr->removeListener(this);
	}
	auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrig_AllUnlocked) };
	rndmTrigAllParamPtr->removeListener(this);
}
