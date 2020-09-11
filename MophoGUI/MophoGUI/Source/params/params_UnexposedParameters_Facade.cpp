#include "params_UnexposedParameters_Facade.h"



UnexposedParameters::UnexposedParameters() :
	globalAudioOptions{ new GlobalAudioOptions() },
	midiOptions{ new MidiOptions() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	pluginProgramBanks{ new PluginProgramBanks() },
	programNameStrings{ new ProgramNameStrings() },
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

PluginProgramBanks* UnexposedParameters::pluginProgramBanks_get() {
	return pluginProgramBanks.get();
}

ProgramNameStrings* UnexposedParameters::programNameStrings_get() {
	return programNameStrings.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

XmlElement UnexposedParameters::tooltipOptions_getStateXml() {
	return tooltipOptions->getStateXml();
}

void UnexposedParameters::tooltipOptions_replaceState(const ValueTree& newState) {
	tooltipOptions->replaceState(newState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	midiOptions = nullptr;
	globalAudioOptions = nullptr;
}
