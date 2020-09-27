#pragma once

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



struct ParameterChangeMessage {
	static void sendNewValueForParameterToUnexposedParamsForHandling(uint8 newValue, uint8 param, UnexposedParameters* unexposedParams) {
		jassert(newValue < 128 && param < 100);
		auto paramChangeMessage{ createParamChangeSysExMessage(newValue, param) };
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingBuffers->aggregateOutgoingMidiBuffers(paramChangeMessage);
	}

private:
	static MidiBuffer createParamChangeSysExMessage(uint8 newValue, uint8 param) {
		auto messageVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
		messageVector.push_back((uint8)SysExMessageType::paramChange);
		messageVector.push_back(param);
		messageVector.push_back(newValue);
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
		return localMidiBuffer;
	}
};