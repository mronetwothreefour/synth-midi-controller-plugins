#pragma once

#include <JuceHeader.h>

//#include "D_X_G_Data_Hub_P.h"

class Audio_Processor_A :
    public AudioProcessor
{
//protected: std::unique_ptr<Data_Hub_P> hub;

//==============================================================================
public: Audio_Processor_A();

public: const String getName() const override;

public: bool acceptsMidi() const override;
public: bool producesMidi() const override;
public: bool isMidiEffect() const override;

public: int getNumPrograms() override;
public: int getCurrentProgram() override;
public: void setCurrentProgram(int pgm_index) override;
public: const String getProgramName(int pgm_index) override;
public: void changeProgramName(int pgm_index, const String& new_name) override;

public: virtual void process_block(AudioBuffer<float>& audio, MidiBuffer& midi)=0;
public: void processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
public: void prepareToPlay(double sample_rate, int samples_per_block) override;
public: double getTailLengthSeconds() const override;
public: void releaseResources() override;

public: bool hasEditor() const override;
public: virtual AudioProcessorEditor* create_editor()=0;
public: AudioProcessorEditor* createEditor() override;

public: void getStateInformation(MemoryBlock& target_mem_block) override;
public: virtual void store_plugin_specific_param_state(XmlElement& plugin_state)=0;
public: void setStateInformation(const void* stored_param_data, int data_size) override;
public: virtual void restore_plugin_specific_param_state(XmlElement* plugin_state)=0;

public: ~Audio_Processor_A() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor_A)
};
