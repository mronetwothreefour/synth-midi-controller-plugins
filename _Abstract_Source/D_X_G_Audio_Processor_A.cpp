#include "D_X_G_Audio_Processor_A.h"

#include "C_NAME_P.h"

Audio_Processor_A::Audio_Processor_A() :
    AudioProcessor{ BusesProperties{} },
    hub{ new Data_Hub{ this } }
{}

const String Audio_Processor_A::getName() const { return JucePlugin_Name; }

bool Audio_Processor_A::acceptsMidi() const { return true; }

bool Audio_Processor_A::producesMidi() const { return true; }

bool Audio_Processor_A::isMidiEffect() const { return true; }

int Audio_Processor_A::getNumPrograms() { return 1; }

int Audio_Processor_A::getCurrentProgram() { return 0; }

void Audio_Processor_A::setCurrentProgram(int /*pgm_index*/) {}

const String Audio_Processor_A::getProgramName(int /*pgm_index*/) { return {}; }

void Audio_Processor_A::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Audio_Processor_A::processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) {
    process_block(audio, midi);
}

bool Audio_Processor_A::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const { return true; }

void Audio_Processor_A::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {}

double Audio_Processor_A::getTailLengthSeconds() const { return 0.0; }

void Audio_Processor_A::releaseResources() {}

bool Audio_Processor_A::hasEditor() const { return true; }

AudioProcessorEditor* Audio_Processor_A::createEditor() {
    return create_editor();
}

void Audio_Processor_A::getStateInformation(MemoryBlock& target_mem_block) {
    XmlElement plugin_state{ NAME::state_plugin_xml };
    auto app_params_state = hub->get_app_params().get_current_state();
    if (app_params_state)
        plugin_state.addChildElement(app_params_state.release());
    auto exposed_state = hub->get_exposed_params_state()->copyState().createXml();
    exposed_state->setTagName(NAME::state_exp_xml);
    if (exposed_state)
        plugin_state.addChildElement(exposed_state.release());
    store_plugin_specific_param_state(plugin_state);
    copyXmlToBinary(plugin_state, target_mem_block);
}

void Audio_Processor_A::setStateInformation(const void* stored_param_data, int data_size) {
    auto plugin_state{ getXmlFromBinary(stored_param_data, data_size) };
    if (plugin_state) {
        auto app_params_state = plugin_state->getChildByName(NAME::state_app_xml);
        if (app_params_state) {
            auto app_params_tree = ValueTree::fromXml(*app_params_state);
            hub->get_app_params().replace_state(app_params_tree);
        }
        auto exposed_state{ plugin_state->getChildByName(NAME::state_exp_xml) };
        if (exposed_state) {
            //transmitOptions->setParamChangesShouldBeTransmitted(false);
            hub->get_exposed_params_state()->replaceState(ValueTree::fromXml(*exposed_state));
            //transmitOptions->setParamChangesShouldBeTransmitted(true);
        }
        restore_plugin_specific_param_state(plugin_state.get());
    }
}

Audio_Processor_A::~Audio_Processor_A() {
    hub = nullptr;
}
