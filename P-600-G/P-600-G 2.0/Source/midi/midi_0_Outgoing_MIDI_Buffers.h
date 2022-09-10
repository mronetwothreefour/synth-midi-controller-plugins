#pragma once

#include <JuceHeader.h>

class Outgoing_MIDI_Buffers :
	private Timer
{
	std::unique_ptr<MidiBuffer> outgoingBuffer;
	std::unique_ptr<Array<MidiBuffer, CriticalSection>> bundledOutgoingBuffers;

public:
	Outgoing_MIDI_Buffers() :
		outgoingBuffer{ new MidiBuffer{} },
		bundledOutgoingBuffers{ new Array<MidiBuffer, CriticalSection>{} }
	{
	}

	void addDataMessage(const std::vector<uint8>& messageVector) {
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::createSysExMessage(messageVector.data(), (int)messageVector.size()), 0);
		bundleBuffersAddedWithin_10ms_ToPreventLoss(localMidiBuffer);
	}

	void addProgramChangeMessage(int programNum) {
		MidiBuffer localMidiBuffer;
		localMidiBuffer.addEvent(MidiMessage::programChange(1, programNum), 0);
		bundleBuffersAddedWithin_10ms_ToPreventLoss(localMidiBuffer);
	}

private:
	void bundleBuffersAddedWithin_10ms_ToPreventLoss(const MidiBuffer& midiBuffer) {
		outgoingBuffer->addEvents(midiBuffer, 0, -1, 0);
		if (!isTimerRunning()) {
			bundledOutgoingBuffers->add(*outgoingBuffer);
			outgoingBuffer->clear();
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

	~Outgoing_MIDI_Buffers() {
		bundledOutgoingBuffers = nullptr;
		outgoingBuffer = nullptr;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Outgoing_MIDI_Buffers)
};