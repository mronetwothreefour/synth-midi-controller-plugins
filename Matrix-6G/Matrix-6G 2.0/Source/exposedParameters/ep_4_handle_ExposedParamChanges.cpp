#include "ep_4_handle_ExposedParamChanges.h"

#include "ep_3_facade_ExposedParameters.h"
#include "../constants/constants_ExposedParameters.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

ExposedParamChangesHandler::ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	randomize{ exposedParams->randomize.get() },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() }
{
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->addListener(this);
		auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrg_.toString() + paramID) };
		rndmTrigParamPtr->addListener(this);
	}
	auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrg_AllUnlocked) };
	rndmTrigAllParamPtr->addListener(this);
}

void ExposedParamChangesHandler::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex < EP::numberOfExposedParams) {
		auto paramIndex{ (uint8)changedParamIndex };
		if (transmitOptions->paramChangesShouldBeTransmitted()) {
			auto paramID{ info->IDfor(paramIndex) };
			auto paramPtr{ state->getParameter(paramID) };
			auto outputValue{ roundToInt(paramPtr->convertFrom0to1(newValue)) };
			if (info->rangeTypeFor(paramIndex) == RangeType::signed_6_bitValue)
				outputValue -= EP::offsetForSigned_6_BitRange;
			if (info->rangeTypeFor(paramIndex) == RangeType::signed_7_bitValue)
				outputValue -= EP::offsetForSigned_7_BitRange;
			if (outputValue > -1) {
				auto paramNum{ info->paramNumFor(paramIndex) };
				SysExMessages::addParamValueChangeMessageToOutgoingBuffers(paramNum, (uint8)outputValue, outgoingBuffers);
			}
		}
	}
	else {
		if (changedParamIndex == EP::numberOfExposedParams)
			randomize->randomizeAllUnlockedParameters();
		else {
			auto paramIndex{ uint8(changedParamIndex - (EP::numberOfExposedParams + 1)) };
			randomize->randomizeExposedParameter(paramIndex);
		}
	}
}

void ExposedParamChangesHandler::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

ExposedParamChangesHandler::~ExposedParamChangesHandler() {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		auto paramID{ info->IDfor(paramIndex) };
		auto paramPtr{ state->getParameter(paramID) };
		paramPtr->removeListener(this);
		auto rndmTrigParamPtr{ state->getParameter(ID::rndmTrg_.toString() + paramID) };
		rndmTrigParamPtr->removeListener(this);
	}
	auto rndmTrigAllParamPtr{ state->getParameter(ID::rndmTrg_AllUnlocked) };
	rndmTrigAllParamPtr->removeListener(this);
}
