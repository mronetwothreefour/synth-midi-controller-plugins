#pragma once

#include <JuceHeader.h>

#include "up_tree_GlobalOptions.h"
#include "up_tree_TooltipsOptions.h"
#include "up_tree_VoiceTransmissionOptions.h"
#include "../midi/0_midi_OutgoingMidiBuffers.h"



class UnexposedParameters
{
	std::unique_ptr<GlobalOptions> globalOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<TooltipsOptions> tooltipsOptions;
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<VoiceTransmissionOptions> voiceTransmissionOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* getBundledOutgoingBuffers();
	GlobalOptions* getGlobalOptions();
	OutgoingMidiBuffers* getOutgoingMidiBuffers();
	TooltipsOptions* getTooltipsOptions();
	UndoManager* getUndoManager();
	VoiceTransmissionOptions* getVoiceTransmissionOptions();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)

};