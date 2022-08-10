#include "up_1_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;

UnexposedParameters::UnexposedParameters() :
    tooltipsOptions{ new TooltipsOptions{} },
    voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
    return tooltipsOptions.get();
}

VoiceTransmissionOptions* UnexposedParameters::getVoiceTransmissionOptions() {
    return voiceTransmissionOptions.get();
}

std::unique_ptr<XmlElement> UnexposedParameters::getStateXml() {
    auto unexposedParamsStateXml{ std::make_unique<XmlElement>(ID::state_UnexposedParams) };

    auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
    if (tooltipOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(tooltipOptionsStateXml.release());

    auto voiceTxOptionsStateXml{ voiceTransmissionOptions->getStateXml() };
    if (voiceTxOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(voiceTxOptionsStateXml.release());

    return unexposedParamsStateXml;
}

void UnexposedParameters::replaceState(const ValueTree& newState) {
    if (newState.isValid()) {
        auto tooltipOptionsState{ newState.getChildWithName(ID::state_TooltipsOptions) };
        if (tooltipOptionsState.isValid())
            tooltipsOptions->replaceState(tooltipOptionsState);
    }

    auto voiceTxOptionsState{ newState.getChildWithName(ID::state_VoiceTxOptions) };
    if (voiceTxOptionsState.isValid())
        voiceTransmissionOptions->replaceState(voiceTxOptionsState);
}

UnexposedParameters::~UnexposedParameters() {
    tooltipsOptions = nullptr;
    voiceTransmissionOptions = nullptr;
}
