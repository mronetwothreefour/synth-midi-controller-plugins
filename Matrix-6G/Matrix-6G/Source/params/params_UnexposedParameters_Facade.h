#pragma once

#include <JuceHeader.h>

#include "params_MidiOptions.h"



class UnexposedParameters
{
	std::unique_ptr<MidiOptions> midiOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	MidiOptions* midiOptions_get();
	UndoManager* undoManager_get();
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};