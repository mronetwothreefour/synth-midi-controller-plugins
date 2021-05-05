#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	globalAudioOptions{ new GlobalAudioOptions() },
	midiOptions{ new MidiOptions() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	pluginProgramBanks{ new ProgramBanks() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

GlobalAudioOptions* UnexposedParameters::globalAudioOptions_get() {
	return globalAudioOptions.get();
}

MidiOptions* UnexposedParameters::midiOptions_get() {
	return midiOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

ProgramBanks* UnexposedParameters::programBanks_get() {
	return pluginProgramBanks.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

XmlElement UnexposedParameters::unexposedParams_getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto pluginProgramBanksStateXml{ pluginProgramBanks->getStateXml() };
	if (pluginProgramBanksStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(pluginProgramBanksStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::unexposedParams_replaceState(const ValueTree& newState) {
	auto pluginProgramBanksState{ newState.getChildWithName(ID::state_ProgramBanks) };
	pluginProgramBanks->replaceState(pluginProgramBanksState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	midiOptions = nullptr;
	globalAudioOptions = nullptr;
}
