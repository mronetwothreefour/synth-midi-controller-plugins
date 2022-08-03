/*
=============================================================================
 THE CODE FOR MOPHOGUI IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL
 WARRANTIES, WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND
 FITNESS FOR PURPOSE, ARE DISCLAIMED.
=============================================================================

The code in the Source folder of this project is open-source and you are free
to use it however you see fit under the GPL v3 license. However, please credit
Mister 1-2-3-4 Programming if you make use of substantial chunks of this code
in your own project(s), and do not redistribute it without permission. Also,
if you find this code useful, please consider making a donation to support
further development at https://programming.mr1234.com/

Proper functioning of this plugin required a few unofficial modifications
to the Juce framework code, specifically to the constructor for ItemComponent
in juce_PopupMenu.cpp and to createSysExEvent() in juce_VST3Common.h.
You can see these changes in my fork off of the Juce repo at
https://github.com/mronetwothreefour/JUCE

The build configurations make use of the preprocessor definition
HOST_DOES_NOT_ADD_F0_AND_F7. This needs to be true for the plugin to work
properly in Reaper, and false for the plugin to work properly in Juce's
AudioPluginHost. Either version will function properly in Cubase. These
are the only hosts known to be compatible with MophoGUI.vst3 at this time.
*/

#pragma once

#include <JuceHeader.h>

class ExposedParamChangesHandler;
class ExposedParameters;
class IncomingMessageHandler_NRPN;
class IncomingMessageHandler_SysEx;
class UnexposedParameters;
class VoiceTransmissionOptions;

class PluginProcessor :
    public AudioProcessor
{
    std::unique_ptr<UnexposedParameters> unexposedParams;
    std::unique_ptr<ExposedParameters> exposedParams;
    Array<MidiBuffer, CriticalSection>* bundledOutgoingBuffers;
    std::unique_ptr<ExposedParamChangesHandler> exposedParamChangesHandler;
    std::unique_ptr<IncomingMessageHandler_NRPN> incomingMessageHandler_NRPN;
    std::unique_ptr<IncomingMessageHandler_SysEx> incomingMessageHandler_SysEx;
    VoiceTransmissionOptions* transmitOptions;

public:
    PluginProcessor();

    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void changeProgramName(int index, const String& newName) override;

    void processBlock(AudioBuffer<float>&, MidiBuffer&) override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    double getTailLengthSeconds() const override;

    bool hasEditor() const override;
    AudioProcessorEditor* createEditor() override;

    void getStateInformation(MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    ~PluginProcessor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};
