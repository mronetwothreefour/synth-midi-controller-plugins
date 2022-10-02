#include "up_1_facade_UnexposedParameters.h"

#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;

UnexposedParameters::UnexposedParameters() :
    tooltipsOptions{ new TooltipsOptions{} },
    outgoing_MIDI_Buffers{ new Outgoing_MIDI_Buffers{} },
    voicesBank{ new VoicesBank{} },
    voiceTransmissionOptions{ new VoiceTransmissionOptions{} }
{
}

Array<MidiBuffer, CriticalSection>* UnexposedParameters::getBundledOutgoingBuffers() {
    return outgoing_MIDI_Buffers->getBundledOutgoingBuffers();
}

Outgoing_MIDI_Buffers* UnexposedParameters::getOutgoing_MIDI_Buffers() {
    return outgoing_MIDI_Buffers.get();
}

TooltipsOptions* UnexposedParameters::getTooltipsOptions() {
    return tooltipsOptions.get();
}

VoicesBank* UnexposedParameters::getVoicesBank() {
    return voicesBank.get();
}

VoiceTransmissionOptions* UnexposedParameters::getVoiceTransmissionOptions() {
    return voiceTransmissionOptions.get();
}

std::unique_ptr<XmlElement> UnexposedParameters::getStateXml() {
    auto unexposedParamsStateXml{ std::make_unique<XmlElement>(ID::state_UnexposedParams) };

    auto tooltipOptionsStateXml{ tooltipsOptions->getStateXml() };
    if (tooltipOptionsStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(tooltipOptionsStateXml.release());

    auto voicesBankStateXml{ voicesBank->getStateXml() };
    if (voicesBankStateXml != nullptr)
        unexposedParamsStateXml->addChildElement(voicesBankStateXml.release());

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

        auto voicesBankState{ newState.getChildWithName(ID::state_VoicesBank) };
        if (voicesBankState.isValid())
            voicesBank->replaceState(voicesBankState);

        auto voiceTxOptionsState{ newState.getChildWithName(ID::state_VoiceTxOptions) };
        if (voiceTxOptionsState.isValid())
            voiceTransmissionOptions->replaceState(voiceTxOptionsState);
    }
}

UnexposedParameters::~UnexposedParameters() {
    tooltipsOptions = nullptr;
    voicesBank = nullptr;
    voiceTransmissionOptions = nullptr;
}
