#pragma once

#include <JuceHeader.h>

class Processor :
    public AudioProcessor
{
//==============================================================================
public: Processor();

public: const String getName() const override;

public: bool acceptsMidi() const override;
public: bool producesMidi() const override;
public: bool isMidiEffect() const override;

public: int getNumPrograms() override;
public: int getCurrentProgram() override;
public: void setCurrentProgram(int pgm_index) override;
public: const String getProgramName(int pgm_index) override;
public: void changeProgramName(int pgm_index, const String& new_name) override;

public: void processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
public: void prepareToPlay(double sample_rate, int samples_per_block) override;
public: double getTailLengthSeconds() const override;
public: void releaseResources() override;

public: bool hasEditor() const override;
public: AudioProcessorEditor* createEditor() override;

public: void getStateInformation(MemoryBlock& param_storage_block) override;
public: void setStateInformation(const void* stored_param_data, int data_size) override;

public: ~Processor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Processor)
};
