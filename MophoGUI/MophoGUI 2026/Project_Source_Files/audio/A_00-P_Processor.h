#pragma once

#include <JuceHeader.h>

#include "A_00-B_Processor.h"

class Processor :
    public Base_Processor
{

//==============================================================================
public: Processor();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void store_parameters_in_memory(MemoryBlock& target_mem_block) override;
public: void restore_parameters(const void* stored_param_data, int data_size) override;

public: ~Processor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Processor)
};
