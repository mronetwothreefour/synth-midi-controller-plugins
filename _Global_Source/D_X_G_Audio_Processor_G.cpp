#include "D_X_G_Audio_Processor_G.h"

Audio_Processor_G::Audio_Processor_G() :
    AudioProcessor{ BusesProperties{} }/*,
    hub{ new Data_Hub_P{ this } }*/
{}

const String Audio_Processor_G::getName() const { return JucePlugin_Name; }

bool Audio_Processor_G::acceptsMidi() const { return true; }

bool Audio_Processor_G::producesMidi() const { return true; }

bool Audio_Processor_G::isMidiEffect() const { return true; }

int Audio_Processor_G::getNumPrograms() { return 1; }

int Audio_Processor_G::getCurrentProgram() { return 0; }

void Audio_Processor_G::setCurrentProgram(int /*pgm_index*/) {}

const String Audio_Processor_G::getProgramName(int /*pgm_index*/) { return {}; }

void Audio_Processor_G::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Audio_Processor_G::processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) {
    process_block(audio, midi);
}

bool Audio_Processor_G::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const { return true; }

void Audio_Processor_G::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {}

double Audio_Processor_G::getTailLengthSeconds() const { return 0.0; }

void Audio_Processor_G::releaseResources() {}

bool Audio_Processor_G::hasEditor() const { return true; }

AudioProcessorEditor* Audio_Processor_G::createEditor() {
    return create_editor();
}

void Audio_Processor_G::getStateInformation(MemoryBlock& /*target_mem_block*/) {
    //XmlElement plugin_state{ ID::xml_state_plugin };
    //auto exposed_state{ hub->get_exposed_state()->copyState().createXml() };
    //exposed_state->setTagName(ID::xml_state_exposed.toString());
    //if (exposed_state)
    //    plugin_state.addChildElement(exposed_state.release());
    //plugin_state.setAttribute(ID::xml_att_scale_factor, hub->get_scale_factor());
    //store_plugin_specific_param_state(plugin_state);
    //copyXmlToBinary(plugin_state, target_mem_block);
}

void Audio_Processor_G::setStateInformation(const void* /*stored_param_data*/, int /*data_size*/) {
    //auto plugin_state{ getXmlFromBinary(stored_param_data, data_size) };
    //if (plugin_state) {
    //    auto exposed_state{ plugin_state->getChildByName(ID::xml_state_exposed.toString()) };
    //    if (exposed_state) {
    //        //transmitOptions->setParamChangesShouldBeTransmitted(false);
    //        hub->get_exposed_state()->replaceState(ValueTree::fromXml(*exposed_state));
    //        //transmitOptions->setParamChangesShouldBeTransmitted(true);
    //    }
    //    auto& scale_factor = hub->get_scale_factor();
    //    scale_factor = (float)plugin_state->getDoubleAttribute(ID::xml_att_scale_factor.toString(), 1.0);
    //    restore_plugin_specific_param_state(plugin_state.get());
    //}
}

Audio_Processor_G::~Audio_Processor_G() {
    //hub = nullptr;
}
