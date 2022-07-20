#include "up_1_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

UnexposedParameters::UnexposedParameters() :
    tooltipsOptions{ new TooltipsOptions{} }
{
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
    return tooltipsOptions.get();
}

std::unique_ptr<XmlElement> UnexposedParameters::getStateXml() {
    auto unexposedParamsStateXml{ std::make_unique<XmlElement>(ID::state_UnexposedParams) };

    auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
    if (tooltipOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(tooltipOptionsStateXml.release());

    return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
    if (newState.isValid()) {
        auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
        if (tooltipOptionsState.isValid())
            tooltipsOptions->replaceState(tooltipOptionsState);
    }
}

UnexposedParameters::~UnexposedParameters() {
    tooltipsOptions = nullptr;
}
