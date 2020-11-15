#pragma once

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_UnexposedParameters_Facade.h"



struct QuickPatchEditing {
	static void sendActivateMessageToOutgoingMidiBuffers(OutgoingMidiBuffers* outgoingBuffers) {
		auto quickEditMessage{ createActivateQuickPatchEditingSysExMessage() };
		outgoingBuffers->aggregateOutgoingMidiBuffers(quickEditMessage);
	}

private:
	static MidiBuffer createActivateQuickPatchEditingSysExMessage() {
		auto messageVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::quickEditSelect) };
		messageVector[2] = (uint8)SysExMessageType::quickEditSelect;
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
		return localMidiBuffer;
	}
};