#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	pgmDataBank{ new ProgramDataBank() },
	pgmDataOptions{ new ProgramDataOptions(this) },
	tooltipOptions{ new TooltipOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::aggregatedOutgoingBuffers_get() {
	return outgoingMidiBuffers->aggregatedOutgoingBuffers_get();
}

OutgoingMidiBuffers* UnexposedParameters::outgoingMidiBuffers_get() {
	return outgoingMidiBuffers.get();
}

ProgramDataBank* UnexposedParameters::programDataBank_get() {
	return pgmDataBank.get();
}

ProgramDataOptions* UnexposedParameters::programDataOptions_get() {
	return pgmDataOptions.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto pgmDataBankStateXml{ pgmDataBank->getStateXml() };
	if (pgmDataBankStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(pgmDataBankStateXml);
	auto pgmDataOptionsStateXml{ pgmDataOptions->getStateXml() };
	if (pgmDataOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(pgmDataOptionsStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto pgmDataBankState{ newState.getChildWithName(ID::state_VoicesBank) };
	pgmDataBank->replaceState(pgmDataBankState);
	auto pgmDataOptionsState{ newState.getChildWithName(ID::state_VoiceTransmissionOptions) };
	pgmDataOptions->replaceState(pgmDataOptionsState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	pgmDataBank = nullptr;
	pgmDataOptions = nullptr;
	outgoingMidiBuffers = nullptr;
}
