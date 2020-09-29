#pragma once

#include <JuceHeader.h>

#include "params_MidiOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"



class UnexposedParameters
{
	std::unique_ptr<MidiOptions> midiOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	MidiOptions* midiOptions_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};