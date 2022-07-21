#pragma once

#include <JuceHeader.h>

class OutgoingMidiBuffers :
	private Timer
{
	std::unique_ptr<MidiBuffer> outgoingMidiBuffer;
	std::unique_ptr<Array<MidiBuffer, CriticalSection>> bundledOutgoingBuffers;

public:
	OutgoingMidiBuffers() :
		outgoingMidiBuffer{ new MidiBuffer{} },
		bundledOutgoingBuffers{ new Array<MidiBuffer, CriticalSection>{} }
	{
	}

	void addDataMessage(const std::vector<uint8>& messageVector) {
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
		bundleBuffersAddedWithin_10ms_ToPreventLoss(localMidiBuffer);
	}

	void addMidiBuffer(const MidiBuffer& midiBuffer) {
		bundleBuffersAddedWithin_10ms_ToPreventLoss(midiBuffer);
	}

private:
	void bundleBuffersAddedWithin_10ms_ToPreventLoss(const MidiBuffer& midiBuffer) {
		outgoingMidiBuffer->addEvents(midiBuffer, 0, -1, 0);
		if (!isTimerRunning()) {
			bundledOutgoingBuffers->add(*outgoingMidiBuffer);
			outgoingMidiBuffer->clear();
			startTimer(10);
		}
	}

	void timerCallback() override {
		stopTimer();
	}

public:
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers() {
		return bundledOutgoingBuffers.get();
	}

	~OutgoingMidiBuffers() {
		bundledOutgoingBuffers = nullptr;
		outgoingMidiBuffer = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiBuffers)
};