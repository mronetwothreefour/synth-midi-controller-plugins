#pragma once

#include <JuceHeader.h>

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



struct ParameterChangeMessage {
	static void sendNewValueForParameterToOutgoingMidiBuffers(uint8 newValue, uint8 param, OutgoingMidiBuffers* outgoingBuffers) {
		jassert(newValue < 128 && param < 100);
		auto paramChangeMessage{ createParamChangeSysExMessage(newValue, param) };
		outgoingBuffers->addDataMessageToOutgoingMidiBuffers(paramChangeMessage);
	}

private:
	static std::vector<uint8> createParamChangeSysExMessage(uint8 newValue, uint8 param) {
		auto messageVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::paramChange) };
		messageVector[2] = (uint8)SysExMessageType::paramChange;
		messageVector[3] = param;
		messageVector[4] = newValue;
		return messageVector;
	}
};