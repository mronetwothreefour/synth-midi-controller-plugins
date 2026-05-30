#include "dXg_Audio_Processor_p.h"

#include "dXg_Editor_p.h"

Audio_Processor::Audio_Processor()
{}

void Audio_Processor::process_block(AudioBuffer<float>& audio, MidiBuffer& /*midi*/) {
    audio.clear();
}

AudioProcessorEditor* Audio_Processor::create_editor() {
    return new Editor{ *this };
}

void Audio_Processor::store_parameters_in_memory(MemoryBlock& /*target_mem_block*/) {
}

void Audio_Processor::restore_parameters(const void* /*stored_param_data*/, int /*data_size*/) {
}

Audio_Processor::~Audio_Processor() {
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Audio_Processor();
}
