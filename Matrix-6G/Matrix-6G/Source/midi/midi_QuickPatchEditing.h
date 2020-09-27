#pragma once

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



struct QuickPatchEditing {
	static void sendActivateMessageToUnexposedParamsForHandling(UnexposedParameters* unexposedParams) {
		auto quickEditMessage{ createActivateQuickPatchEditingSysExMessage() };
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingBuffers->aggregateOutgoingMidiBuffers(quickEditMessage);
	}

private:
	static MidiBuffer createActivateQuickPatchEditingSysExMessage() {
		auto messageVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes() };
		messageVector.push_back((uint8)SysExMessageType::quickEditSelect);
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
		return localMidiBuffer;
	}
};