#include "ep_4_handle_ExposedParamChanges.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

ExposedParamChangesHandler::ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	//randomize{ exposedParams->randomize.get() },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->addListener(this);
		//auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrig_.toString() + paramID) };
		//rndmTrigParamPtr->addListener(this);
	}
	//auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrig_AllUnlocked) };
	//rndmTrigAllParamPtr->addListener(this);
}

void ExposedParamChangesHandler::parameterValueChanged(int changedParamIndex, float /*newValue*/) {
	if (changedParamIndex < EP::numberOfExposedParams) {
		if (transmitOptions->paramChangesShouldBeTransmitted()) {
			SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers);
			auto currentVoiceNumber{ transmitOptions->currentVoiceNumber() };
			auto transmitTime{ transmitOptions->voiceTransmitTime() };
			callAfterDelay(transmitTime, [this, currentVoiceNumber] { outgoingBuffers->addProgramChangeMessage(currentVoiceNumber); });
		}
	}
	else {
		//if (changedParamIndex == EP::numberOfExposedParams)
		//	randomize->randomizeAllUnlockedParameters();
		//else {
		//	auto paramIndex{ uint8(changedParamIndex - (EP::numberOfExposedParams + 1)) };
		//	randomize->randomizeParameter(paramIndex);
		//}
	}
}

void ExposedParamChangesHandler::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void ExposedParamChangesHandler::timerCallback() {
}

ExposedParamChangesHandler::~ExposedParamChangesHandler() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->removeListener(this);
		//auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrig_.toString() + paramID) };
		//rndmTrigParamPtr->removeListener(this);
	}
	//auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrig_AllUnlocked) };
	//rndmTrigAllParamPtr->removeListener(this);
}
