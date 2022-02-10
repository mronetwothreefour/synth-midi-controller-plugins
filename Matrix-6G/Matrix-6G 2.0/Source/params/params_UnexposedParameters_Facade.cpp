#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	currentVoiceOptions{ new CurrentVoiceOptions(this) },
	masterOptions{ new MasterOptions() },
	matrixModSettings{ new MatrixModSettings(this) },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	splitOptions{ new SplitOptions() },
	splitsBank{ new SplitsBank() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() },
	voicesBanks{ new VoicesBanks() },
	voiceTransmissionOptions{ new VoiceTransmissionOptions() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

CurrentVoiceOptions* UnexposedParameters::currentVoiceOptions_get() {
	return currentVoiceOptions.get();
}

MasterOptions* UnexposedParameters::masterOptions_get() {
	return masterOptions.get();
}

MatrixModSettings* UnexposedParameters::matrixModSettings_get() {
	return matrixModSettings.get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

SplitOptions* UnexposedParameters::splitOptions_get() {
	return splitOptions.get();
}

SplitsBank* UnexposedParameters::splitsBank_get() {
	return splitsBank.get();
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

XmlElement UnexposedParameters::unexposedParams_getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto currentPatchOptionsStateXml{ currentVoiceOptions->getStateXml() };
	if (currentPatchOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(currentPatchOptionsStateXml);
	auto matrixModSettingsStateXml{ matrixModSettings->getStateXml() };
	if (matrixModSettingsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(matrixModSettingsStateXml);
	auto splitOptionsStateXml{ splitOptions->getStateXml() };
	if (splitOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(splitOptionsStateXml);
	auto splitsBankStateXml{ splitsBank->getStateXml() };
	if (splitsBankStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(splitsBankStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	auto voicesBanksStateXml{ voicesBanks->getStateXml() };
	if (voicesBanksStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voicesBanksStateXml);
	auto voiceTransmissionOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
	if (voiceTransmissionOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(voiceTransmissionOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::unexposedParams_replaceState(const ValueTree& newState) {
	auto currentVoiceOptionsState{ newState.getChildWithName(ID::state_CurrentVoiceOptions) };
	currentVoiceOptions->replaceState(currentVoiceOptionsState);
	auto customVoicesBanksState{ newState.getChildWithName(ID::state_CustomVoicesBanks) };
	voicesBanks->replaceState(customVoicesBanksState);
	auto matrixModSettingsState{ newState.getChildWithName(ID::state_MatrixModSettings) };
	matrixModSettings->replaceState(matrixModSettingsState);
	auto splitOptionsState{ newState.getChildWithName(ID::state_SplitOptions) };
	splitOptions->replaceState(splitOptionsState);
	auto splitsBankState{ newState.getChildWithName(ID::state_SplitsBank) };
	if (splitsBankState.isValid())
		splitsBank->replaceState(splitsBankState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
	auto voiceTransmissionOptionsState{ newState.getChildWithName(ID::state_PatchTransmissionOptions) };
	voiceTransmissionOptions->replaceState(voiceTransmissionOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	voiceTransmissionOptions = nullptr;
	voicesBanks = nullptr;
	undoManager = nullptr;
	tooltipOptions = nullptr;
	splitsBank = nullptr;
	splitOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	matrixModSettings = nullptr;
	masterOptions = nullptr;
	currentVoiceOptions = nullptr;
}
