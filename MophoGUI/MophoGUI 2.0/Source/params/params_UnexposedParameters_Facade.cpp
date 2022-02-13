#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	globalOptions{ new GlobalOptions() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	voicesBanks{ new VoicesBanks() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() },
	voiceTransmissionOptions{ new VoiceTransmissionOptions() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

GlobalOptions* UnexposedParameters::globalOptions_get() {
	return globalOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

VoicesBanks* UnexposedParameters::voicesBanks_get() {
	return voicesBanks.get();
}

VoiceTransmissionOptions* UnexposedParameters::voiceTransmissionOptions_get() {
	return voiceTransmissionOptions.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto voicesBanksStateXml{ voicesBanks->getStateXml() };
	if (voicesBanksStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voicesBanksStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	auto voiceTransmissionOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
	if (voiceTransmissionOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voiceTransmissionOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto voicesBanksState{ newState.getChildWithName(ID::state_VoicesBanks) };
	voicesBanks->replaceState(voicesBanksState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
	auto voiceTransmissionOptionsState{ newState.getChildWithName(ID::state_VoiceTransmissionOptions) };
	voiceTransmissionOptions->replaceState(voiceTransmissionOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	voiceTransmissionOptions = nullptr;
	voicesBanks = nullptr;
	undoManager = nullptr;
	tooltipOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	globalOptions = nullptr;
}
