#pragma once

#include <JuceHeader.h>

#include "params_ProgramDataOptions.h"
#include "params_TooltipOptions.h"
#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../pgmData/pgmData_ProgramDataBank.h"



class UnexposedParameters
{
	std::unique_ptr<UndoManager> undoManager;
	std::unique_ptr<OutgoingMidiBuffers> outgoingMidiBuffers;
	std::unique_ptr<ProgramDataBank> pgmDataBank;
	std::unique_ptr<ProgramDataOptions> pgmDataOptions;
	std::unique_ptr<TooltipOptions> tooltipOptions;

public:
	UnexposedParameters();
	Array<MidiBuffer, CriticalSection>* aggregatedOutgoingBuffers_get();
	OutgoingMidiBuffers* outgoingMidiBuffers_get();
	ProgramDataBank* programDataBank_get();
	ProgramDataOptions* programDataOptions_get();
	TooltipOptions* tooltipOptions_get();
	UndoManager* undoManager_get();
	XmlElement getStateXml();
	void replaceState(const ValueTree& newState);
	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};