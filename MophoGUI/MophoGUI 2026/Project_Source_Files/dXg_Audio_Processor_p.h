#pragma once

#include <JuceHeader.h>

#include "dXg_Audio_Processor_b.h"

class Audio_Processor :
    public Audio_Processor_Base
{

//==============================================================================
public: Audio_Processor();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void store_parameters_in_memory(MemoryBlock& target_mem_block) override;
public: void restore_parameters(const void* stored_param_data, int data_size) override;

public: ~Audio_Processor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor)
};
