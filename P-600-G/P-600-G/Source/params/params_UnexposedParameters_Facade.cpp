#include "params_UnexposedParameters_Facade.h"

#include "params_Identifiers.h"



UnexposedParameters::UnexposedParameters() :
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
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

ProgramDataOptions* UnexposedParameters::programDataOptions_get() {
	return pgmDataOptions.get();
}

TooltipOptions* UnexposedParameters::tooltipOptions_get() {
	return tooltipOptions.get();
}

UndoManager* UnexposedParameters::undoManager_get() {
	return undoManager.get();
}

XmlElement UnexposedParameters::unexposedParams_getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };
	auto pgmDataOptionsStateXml{ pgmDataOptions->getStateXml() };
	if (pgmDataOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(pgmDataOptionsStateXml);
	auto tooltipOptionsStateXml{ tooltipOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);
	return unexposedParamsStateXml;
}

void UnexposedParameters::unexposedParams_replaceState(const ValueTree& newState) {
	auto pgmDataOptionsState{ newState.getChildWithName(ID::state_PgmDataOptions) };
	pgmDataOptions->replaceState(pgmDataOptionsState);
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipOptions) };
	tooltipOptions->replaceState(tooltipOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipOptions = nullptr;
	pgmDataOptions = nullptr;
	outgoingMidiBuffers = nullptr;
}
