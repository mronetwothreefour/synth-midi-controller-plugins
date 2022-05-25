#include "up_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



UnexposedParameters::UnexposedParameters() :
	outgoingMidiBuffers{ new OutgoingMidiBuffers() },
	tooltipsOptions{ new TooltipsOptions() },
	undoManager{ new UndoManager() }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::getBundledOutgoingBuffers() {
	return outgoingMidiBuffers->getBundledOutgoingBuffers();
}

OutgoingMidiBuffers* UnexposedParameters::getOutgoingMidiBuffers() {
	return outgoingMidiBuffers.get();
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
	return tooltipsOptions.get();
}

UndoManager* UnexposedParameters::getUndoManager() {
	return undoManager.get();
}

XmlElement UnexposedParameters::getStateXml() {
	XmlElement unexposedParamsStateXml{ ID::state_UnexposedParams };

	auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
	if (tooltipOptionsStateXml != nullptr)
		unexposedParamsStateXml.addChildElement(tooltipOptionsStateXml);

	return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
	auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
	if (tooltipOptionsState.isValid())
		tooltipsOptions->replaceState(tooltipOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
	undoManager = nullptr;
	tooltipsOptions = nullptr;
	outgoingMidiBuffers = nullptr;
}
