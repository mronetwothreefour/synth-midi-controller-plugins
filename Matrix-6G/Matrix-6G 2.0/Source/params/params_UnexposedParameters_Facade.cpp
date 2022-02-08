#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	currentPatchOptions{ new CurrentPatchOptions(this) },
	masterOptions{ new MasterOptions() },
	matrixModSettings{ new MatrixModSettings(this) },
	patchTransmissionOptions{ new PatchTransmissionOptions() },
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	patchBanks{ new PatchBanks() },
	splitOptions{ new SplitOptions() },
	splitsBank{ new SplitsBank() },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

CurrentPatchOptions* UnexposedParameters::currentPatchOptions_get() {
	return currentPatchOptions.get();
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

PatchBanks* UnexposedParameters::patchBanks_get() {
	return patchBanks.get();
}

PatchTransmissionOptions* UnexposedParameters::patchTransmissionOptions_get() {
	return patchTransmissionOptions.get();
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

XmlElement UnexposedParameters::unexposedParams_getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto currentPatchOptionsStateXml{ currentPatchOptions->getStateXml() };
	if (currentPatchOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(currentPatchOptionsStateXml);
	auto matrixModSettingsStateXml{ matrixModSettings->getStateXml() };
	if (matrixModSettingsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(matrixModSettingsStateXml);
	auto patchBanksStateXml{ patchBanks->getStateXml() };
	if (patchBanksStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(patchBanksStateXml);
	auto patchTransmissionOptionsStateXml{ patchTransmissionOptions->getStateXml() };
	if (patchTransmissionOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(patchTransmissionOptionsStateXml);
	auto splitOptionsStateXml{ splitOptions->getStateXml() };
	if (splitOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(splitOptionsStateXml);
	auto splitsBankStateXml{ splitsBank->getStateXml() };
	if (splitsBankStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(splitsBankStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::unexposedParams_replaceState(const ValueTree& newState) {
	auto currentPatchOptionsState{ newState.getChildWithName(ID::state_CurrentPatchOptions) };
	currentPatchOptions->replaceState(currentPatchOptionsState);
	auto customPatchBanksState{ newState.getChildWithName(ID::state_CustomPatchBanks) };
	patchBanks->replaceState(customPatchBanksState);
	auto matrixModSettingsState{ newState.getChildWithName(ID::state_MatrixModSettings) };
	matrixModSettings->replaceState(matrixModSettingsState);
	auto patchTransmissionOptionsState{ newState.getChildWithName(ID::state_PatchTransmissionOptions) };
	patchTransmissionOptions->replaceState(patchTransmissionOptionsState);
	auto splitOptionsState{ newState.getChildWithName(ID::state_SplitOptions) };
	splitOptions->replaceState(splitOptionsState);
	auto splitsBankState{ newState.getChildWithName(ID::state_SplitsBank) };
	if (splitsBankState.isValid())
		splitsBank->replaceState(splitsBankState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	splitsBank = nullptr;
	splitOptions = nullptr;
	outgoingMidiBuffers = nullptr;
	patchTransmissionOptions = nullptr;
	matrixModSettings = nullptr;
	masterOptions = nullptr;
	currentPatchOptions = nullptr;
}
