#include "midi_OutgoingMidiBuffers.h"



OutgoingMidiBuffers::OutgoingMidiBuffers() :
	outgoingMidiBuffer{ new MidiBuffer() },
	aggregatedOutgoingBuffers{ new Array<MidiBuffer, CriticalSection>() }
{
}

void OutgoingMidiBuffers::addDataMessage(const std::vector<uint8> messageVector) {
	MidiBuffer localMidiBuffer;
	localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
	aggregateAllMidiBuffersWithinA10msChunkOfTime(localMidiBuffer);
}

void OutgoingMidiBuffers::addPatchSelectMessage(int channel, int patchNumber) {
	MidiBuffer localMidiBuffer;
	localMidiBuffer.addEvent(MidiMessage::programChange(channel, patchNumber), 0);
	aggregateAllMidiBuffersWithinA10msChunkOfTime(localMidiBuffer);
}

void OutgoingMidiBuffers::aggregateAllMidiBuffersWithinA10msChunkOfTime(MidiBuffer& midiBuffer) {
	outgoingMidiBuffer->addEvents(midiBuffer, 0, -1, 0);
	if (!isTimerRunning()) {
		aggregatedOutgoingBuffers->add(*outgoingMidiBuffer);
		outgoingMidiBuffer->clear();
		startTimer(10);
	}
}

void OutgoingMidiBuffers::timerCallback() {
	stopTimer();
}

Array<MidiBuffer, CriticalSection>* OutgoingMidiBuffers::aggregatedOutgoingBuffers_get() {
	return aggregatedOutgoingBuffers.get();
}

OutgoingMidiBuffers::~OutgoingMidiBuffers() {
	aggregatedOutgoingBuffers = nullptr;
	outgoingMidiBuffer = nullptr;
}
