#pragma once

#include <JuceHeader.h>

#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"



class UnexposedParameters
{
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipOptions> tooltipOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};