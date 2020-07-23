#pragma once

#include <JuceHeader.h>

#include "core_UndoManager_Singleton.h"
#include "helpers/helper_MidiHandler.h"
#include "parameters/params_ExposedParametersLayout.h"
#include "parameters/params_UnexposedParameters.h"



class PluginProcessor : 
    public AudioProcessor
{
    std::unique_ptr<AudioProcessorValueTreeState> exposedParams;
    std::unique_ptr<Array<MidiBuffer>> internalMidiBuffers;
    std::unique_ptr<MidiHandler> midiHandler;

public:
    PluginProcessor();
    ~PluginProcessor();

    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const String getProgramName(int index) override;
    void changeProgramName(int index, const String& newName) override;

    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    double getTailLengthSeconds() const override;

    bool hasEditor() const override;
    AudioProcessorEditor* createEditor() override;

    void getStateInformation(MemoryBlock& destData) override;
    std::unique_ptr<XmlElement> saveStateToXML();
    void setStateInformation(const void* data, int sizeInBytes) override;
    void restoreStateFromXml(XmlElement* sourceXml);

    void updateProgramNameOnHardware(String newName);
    void clearSequencerTrack(int trackNum);
    void sendProgramEditBufferDump();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
