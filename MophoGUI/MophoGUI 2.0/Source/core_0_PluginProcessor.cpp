#include "core_0_PluginProcessor.h"

#include "core_1_PluginEditor.h"
#include "exposedParameters/ep_3_facade_ExposedParameters.h"
#include "exposedParameters/ep_4_handle_ExposedParamChanges.h"
#include "midi/midi_1_handle_IncomingMessage_NRPN.h"
#include "midi/midi_1_handle_IncomingMessage_SysEx.h"
#include "unexposedParameters/up_1_facade_UnexposedParameters.h"

PluginProcessor::PluginProcessor() :
    AudioProcessor{ BusesProperties{} },
    exposedParams{ new ExposedParameters{ this } },
    unexposedParams{ new UnexposedParameters{} },
    bundledOutgoingBuffers{ unexposedParams->getBundledOutgoingBuffers() },
    exposedParamChangesHandler{ new ExposedParamChangesHandler{ exposedParams.get(), unexposedParams.get() } },
    incomingMessageHandler_NRPN{ new IncomingMessageHandler_NRPN{ exposedParams.get(), unexposedParams.get() } },
    incomingMessageHandler_SysEx{ new IncomingMessageHandler_SysEx{ exposedParams.get(), unexposedParams.get() } },
    voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() }
{
}

const String PluginProcessor::getName() const {
    return JucePlugin_Name;
}

bool PluginProcessor::acceptsMidi() const {
    return true;
}

bool PluginProcessor::producesMidi() const {
    return true;
}

bool PluginProcessor::isMidiEffect() const {
    return true;
}

int PluginProcessor::getNumPrograms() {
    return 1;
}

int PluginProcessor::getCurrentProgram() {
    return 0;
}

void PluginProcessor::setCurrentProgram(int /*index*/) {
}

const String PluginProcessor::getProgramName(int /*index*/) {
    return {};
}

void PluginProcessor::changeProgramName(int /*index*/, const String& /*newName*/) {
}

void PluginProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    buffer.clear();

    if (midiMessages.isEmpty() == false) {
        MidiBuffer midiMessagesToPassThrough;
        midiMessagesToPassThrough = incomingMessageHandler_SysEx->pullMessageForMophoOutOfBuffer(midiMessages);
        midiMessagesToPassThrough = incomingMessageHandler_NRPN->pullFullyFormedMessageOutOfBuffer(midiMessagesToPassThrough);
        midiMessages.swapWith(midiMessagesToPassThrough);
    }

    if (bundledOutgoingBuffers->isEmpty() == false) {
        for (auto event : bundledOutgoingBuffers->removeAndReturn(0)) {
            midiMessages.addEvent(event.getMessage(), event.samplePosition);
        }
    }
}

bool PluginProcessor::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const {
    return true;
}

void PluginProcessor::prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/) {
}

double PluginProcessor::getTailLengthSeconds() const {
    return 0.0;
}

void PluginProcessor::releaseResources() {
}

bool PluginProcessor::hasEditor() const {
    return true;
}

AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor (*this, exposedParams.get(), unexposedParams.get());
}

void PluginProcessor::getStateInformation(MemoryBlock& /*destData*/) {
}

void PluginProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/) {
}

PluginProcessor::~PluginProcessor() {
    exposedParamChangesHandler = nullptr;
    incomingMessageHandler_SysEx = nullptr;
    incomingMessageHandler_NRPN = nullptr;
    exposedParams->undoManager.clearUndoHistory();
    exposedParams = nullptr;
    unexposedParams = nullptr;
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}

