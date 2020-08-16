#include "midi_OutgoingMidiBuffers.h"

OutgoingMidiBuffers::OutgoingMidiBuffers() :
	outgoingMidiBuffer{ new MidiBuffer() },
	aggregatedOutgoingBuffers{ new Array<MidiBuffer, CriticalSection>() }
{
}

void OutgoingMidiBuffers::aggregateOutgoingMidiBuffers(MidiBuffer& midiBuffer) {
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
