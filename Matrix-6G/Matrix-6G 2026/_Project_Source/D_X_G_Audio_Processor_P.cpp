#include "D_X_G_Audio_Processor_P.h"

#include "D_X_G_Editor_P.h"

Audio_Processor::Audio_Processor()
{}

void Audio_Processor::process_block(AudioBuffer<float>& audio, MidiBuffer& /*midi*/) {
    audio.clear();
}

AudioProcessorEditor* Audio_Processor::create_editor() {
    return new Editor{ *this/*, hub.get()*/ };
}

void Audio_Processor::store_plugin_specific_param_state(XmlElement& /*plugin_state*/) {
}

void Audio_Processor::restore_plugin_specific_param_state(XmlElement* /*plugin_state*/) {
}

Audio_Processor::~Audio_Processor() {
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Audio_Processor();
}
