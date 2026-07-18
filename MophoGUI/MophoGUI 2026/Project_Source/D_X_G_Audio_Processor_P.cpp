#include "D_X_G_Audio_Processor_P.h"

#include "D_X_G_Editor_P.h"

Audio_Processor_P::Audio_Processor_P()
{}

void Audio_Processor_P::process_block(AudioBuffer<float>& audio, MidiBuffer& /*midi*/) {
    audio.clear();
}

AudioProcessorEditor* Audio_Processor_P::create_editor() {
    return new Editor_P{ *this/*, hub.get()*/ };
}

void Audio_Processor_P::store_plugin_specific_param_state(XmlElement& /*plugin_state*/) {
}

void Audio_Processor_P::restore_plugin_specific_param_state(XmlElement* /*plugin_state*/) {
}

Audio_Processor_P::~Audio_Processor_P() {
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Audio_Processor_P();
}
