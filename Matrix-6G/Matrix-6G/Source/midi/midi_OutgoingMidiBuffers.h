#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers :
	private Timer
{
	std::unique_ptr<MidiBuffer> outgoingMidiBuffer;
	std::unique_ptr<Array<MidiBuffer, CriticalSection>> aggregatedOutgoingBuffers;

public:
	OutgoingMidiBuffers();

	// Combines all MidiBuffers that get created within a
	// 10 ms slice of time into a single MidiBuffer
	void aggregateOutgoingMidiBuffers(MidiBuffer& midiBuffer);

private:
	void timerCallback() override;

public:
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	~OutgoingMidiBuffers();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiBuffers)
};