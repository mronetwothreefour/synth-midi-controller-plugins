#pragma once

#include <JuceHeader.h>

#include "D_X_G_Audio_Processor_B.h"

class Audio_Processor_P :
    public Audio_Processor_B
{

//==============================================================================
public: Audio_Processor_P();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void store_parameters_in_memory(MemoryBlock& target_mem_block) override;
public: void restore_parameters(const void* stored_param_data, int data_size) override;

public: ~Audio_Processor_P() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor_P)
};
