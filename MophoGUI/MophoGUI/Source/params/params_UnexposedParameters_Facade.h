#pragma once

#include <JuceHeader.h>

#include "params_GlobalAudioOptions.h"
#include "params_MidiOptions.h"
#include "params_TooltipOptions.h"
#include "../banks/banks_ProgramBanks.h"
#include "../banks/banks_ProgramNameStrings.h"
#include "../midi/midi_OutgoingMidiBuffers.h"



class UnexposedParameters
{
	std::unique_ptr<GlobalAudioOptions> globalAudioOptions;
	std::unique_ptr<MidiOptions> midiOptions;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<ProgramBanks> pluginProgramBanks;
	std::unique_ptr<ProgramNameStrings> programNameStrings;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	GlobalAudioOptions* globalAudioOptions_get();
	MidiOptions* midiOptions_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	ProgramBanks* programBanks_get();
	ProgramNameStrings* programNameStrings_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	XmlElement unexposedParams_getStateXml();
	void unexposedParams_replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};

