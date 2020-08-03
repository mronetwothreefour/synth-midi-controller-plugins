#pragma once

#include <JuceHeader.h>



class InternalMidiBuffers :
	private Timer
{
	MidiBuffer internalMidiBuffer;

	InternalMidiBuffers() {
	}

	~InternalMidiBuffers() {
	}

	void timerCallback() override {
		stopTimer();
	}

public:
	Array<MidiBuffer> aggregatedBuffers;

	InternalMidiBuffers(InternalMidiBuffers&&) = delete;
	InternalMidiBuffers& operator=(InternalMidiBuffers&&) = delete;

	static InternalMidiBuffers& get() noexcept {
		static InternalMidiBuffers aggregatedBuffers;
		return aggregatedBuffers;
	}

	// Combines all MidiBuffers that get created within a
	// 10 ms slice of time into a single MidiBuffer
	void combineMidiBuffers(MidiBuffer& midiBuffer) {
		internalMidiBuffer.addEvents(midiBuffer, 0, -1, 0);
		if (!isTimerRunning()) {
			aggregatedBuffers.add(internalMidiBuffer);
			internalMidiBuffer.clear();
			startTimer(10);
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InternalMidiBuffers)
};