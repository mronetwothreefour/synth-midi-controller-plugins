#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers :
	private Timer
{
	std::unique_ptr<MidiBuffer> outgoingMidiBuffer;
	std::unique_ptr<Array<MidiBuffer, CriticalSection>> aggregatedOutgoingBuffers;

public:
	OutgoingMidiBuffers();

	void addDataMessage(const std::vector<uint8> messageVector);
	void addProgramChangeMessage(int channel, int programNumber);

private:
	void aggregateAllMidiBuffersWithinA10msChunkOfTime(MidiBuffer& midiBuffer);
	void timerCallback() override;

public:
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	~OutgoingMidiBuffers();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiBuffers)
};