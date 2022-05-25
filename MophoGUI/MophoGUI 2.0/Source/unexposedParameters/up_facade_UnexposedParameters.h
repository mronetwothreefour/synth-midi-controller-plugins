#pragma once

#include <JuceHeader.h>

#include "up_tree_TooltipsOptions.h"
#include "../midi/0_midi_OutgoingMidiBuffers.h"



class UnexposedParameters
{
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	OutgoingMidiBuffers* getOutgoingMidiBuffers();
	TooltipsOptions* getTooltipsOptions();
	UndoManager* getUndoManager();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)

};