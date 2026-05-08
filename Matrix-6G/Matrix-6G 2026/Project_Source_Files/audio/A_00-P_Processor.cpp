#include "A_00-P_Processor.h"

#include "G_01-P_Editor.h"

Processor::Processor()
{}

void Processor::process_block(AudioBuffer<float>& audio, MidiBuffer& /*midi*/) {
    audio.clear();
}

AudioProcessorEditor* Processor::create_editor() {
    return new Editor{ *this };
}

void Processor::store_parameters_in_memory(MemoryBlock& /*target_mem_block*/) {
}

void Processor::restore_parameters(const void* /*stored_param_data*/, int /*data_size*/) {
}

Processor::~Processor() {
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Processor();
}
