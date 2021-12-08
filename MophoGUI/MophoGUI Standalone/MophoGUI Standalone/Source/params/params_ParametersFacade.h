#pragma once

#include <JuceHeader.h>

#include "params_GlobalAudioOptions.h"
#include "params_MidiOptions.h"
#include "params_TooltipOptions.h"
//#include "../banks/banks_ProgramBanks.h"
//#include "../midi/midi_OutgoingMidiBuffers.h"



class ParametersFacade
{
	std::unique_ptr<GlobalAudioOptions> globalAudioOptions;
	std::unique_ptr<MidiOptions> midiOptions;
	//std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	//std::unique_ptr<ProgramBanks> pluginProgramBanks;
	std::unique_ptr<TooltipOptions> tooltipOptions;
	std::unique_ptr<UndoManager> undoManager;

public:
	ParametersFacade();
	//Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	GlobalAudioOptions* globalAudioOptions_get();
	MidiOptions* midiOptions_get();
	//OutgoingMidiBuffers* outgoingMidiBuffers_get();
	//ProgramBanks* programBanks_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~ParametersFacade();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParametersFacade)
};

