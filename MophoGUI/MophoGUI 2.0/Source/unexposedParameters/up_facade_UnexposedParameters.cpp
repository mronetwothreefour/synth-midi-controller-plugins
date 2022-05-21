#include "up_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace mophoConstants;



UnexposedParameters::UnexposedParameters() :
	undoManager{ new UndoManager() }
{
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
	tooltipsOptions = nullptr;
	undoManager = nullptr;
}
