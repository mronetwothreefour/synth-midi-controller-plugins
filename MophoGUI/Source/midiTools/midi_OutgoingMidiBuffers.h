#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers :
	private Timer
{
	MidiBuffer outgoingMidiBuffer;

public:
	Array<MidiBuffer, CriticalSection> aggregatedOutgoingBuffers;

	OutgoingMidiBuffers() {
	}

	~OutgoingMidiBuffers() {
	}

	// Combines all MidiBuffers that get created within a
	// 10 ms slice of time into a single MidiBuffer
	void aggregateOutgoingMidiBuffers(MidiBuffer& midiBuffer) {
		outgoingMidiBuffer.addEvents(midiBuffer, 0, -1, 0);
		if (!isTimerRunning()) {
			aggregatedOutgoingBuffers.add(outgoingMidiBuffer);
			outgoingMidiBuffer.clear();
			startTimer(10);
		}
	}

private:
	void timerCallback() override {
		stopTimer();
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiBuffers)
};