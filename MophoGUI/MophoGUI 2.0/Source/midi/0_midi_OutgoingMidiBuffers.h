#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers :
	private Timer
{
	std::unique_ptr<MidiBuffer> outgoingMidiBuffer;
	std::unique_ptr<Array<MidiBuffer, CriticalSection>> bundledOutgoingBuffers;

public:
	OutgoingMidiBuffers();

	void addDataMessage(const std::vector<uint8>& messageVector);
	void addMidiBuffer(MidiBuffer& midiBuffer);

private:
	void bundleBuffersAddedWithin_10ms_ToPreventLoss(MidiBuffer& midiBuffer);
	void timerCallback() override;

public:
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	~OutgoingMidiBuffers();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiBuffers)
};