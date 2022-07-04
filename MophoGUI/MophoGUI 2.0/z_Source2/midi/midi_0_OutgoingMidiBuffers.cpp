#include "midi_0_OutgoingMidiBuffers.h"



OutgoingMidiBuffers::OutgoingMidiBuffers() :
	outgoingMidiBuffer{ new MidiBuffer() },
	bundledOutgoingBuffers{ new Array<MidiBuffer, CriticalSection>() }
{
}

void OutgoingMidiBuffers::addDataMessage(const std::vector<uint8>& messageVector) {
	MidiBuffer localMidiBuffer;
	localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
	bundleBuffersAddedWithin_10ms_ToPreventLoss(localMidiBuffer);
}

void OutgoingMidiBuffers::addMidiBuffer(MidiBuffer& midiBuffer) {
	bundleBuffersAddedWithin_10ms_ToPreventLoss(midiBuffer);
}

void OutgoingMidiBuffers::bundleBuffersAddedWithin_10ms_ToPreventLoss(MidiBuffer& midiBuffer) {
	outgoingMidiBuffer->addEvents(midiBuffer, 0, -1, 0);
	if (!isTimerRunning()) {
		bundledOutgoingBuffers->add(*outgoingMidiBuffer);
		outgoingMidiBuffer->clear();
		startTimer(10);
	}
}

void OutgoingMidiBuffers::timerCallback() {
	stopTimer();
}

Array<MidiBuffer, CriticalSection>* OutgoingMidiBuffers::getBundledOutgoingBuffers() {
	return bundledOutgoingBuffers.get();
}

OutgoingMidiBuffers::~OutgoingMidiBuffers() {
	bundledOutgoingBuffers = nullptr;
	outgoingMidiBuffer = nullptr;
}
