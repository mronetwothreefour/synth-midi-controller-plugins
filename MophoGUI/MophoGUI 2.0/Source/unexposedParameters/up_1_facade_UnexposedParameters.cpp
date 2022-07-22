#include "up_1_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

UnexposedParameters::UnexposedParameters() :
    globalOptions{ new GlobalOptions{} },
    outgoingMidiBuffers{ new OutgoingMidiBuffers{} },
    tooltipsOptions{ new TooltipsOptions{} },
    voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::getBundledOutgoingBuffers() {
    return outgoingMidiBuffers->getBundledOutgoingBuffers();
}

GlobalOptions* UnexposedParameters::getGlobalOptions() {
    return globalOptions.get();
}

OutgoingMidiBuffers* UnexposedParameters::getOutgoingMidiBuffers() {
    return outgoingMidiBuffers.get();
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
    globalOptions = nullptr;
    outgoingMidiBuffers = nullptr;
    tooltipsOptions = nullptr;
    voiceTransmissionOptions = nullptr;
}
