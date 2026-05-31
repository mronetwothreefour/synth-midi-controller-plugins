#include "dXg_Audio_Processor_b.h"

Audio_Processor_Base::Audio_Processor_Base() :
    AudioProcessor{ BusesProperties{} }
{}

const String Audio_Processor_Base::getName() const { return JucePlugin_Name; }

bool Audio_Processor_Base::acceptsMidi() const { return true; }

bool Audio_Processor_Base::producesMidi() const { return true; }

bool Audio_Processor_Base::isMidiEffect() const { return true; }

int Audio_Processor_Base::getNumPrograms() { return 1; }

int Audio_Processor_Base::getCurrentProgram() { return 0; }

void Audio_Processor_Base::setCurrentProgram(int /*pgm_index*/) {}

const String Audio_Processor_Base::getProgramName(int /*pgm_index*/) { return {}; }

void Audio_Processor_Base::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Audio_Processor_Base::processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) {
    process_block(audio, midi);
}

bool Audio_Processor_Base::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const { return true; }

void Audio_Processor_Base::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {}

double Audio_Processor_Base::getTailLengthSeconds() const { return 0.0; }

void Audio_Processor_Base::releaseResources() {}

bool Audio_Processor_Base::hasEditor() const { return true; }

AudioProcessorEditor* Audio_Processor_Base::createEditor() {
    return create_editor();
}

void Audio_Processor_Base::getStateInformation(MemoryBlock& target_mem_block) {
    store_parameters_in_memory(target_mem_block);
}

void Audio_Processor_Base::setStateInformation(const void* stored_param_data, int data_size) {
    restore_parameters(stored_param_data, data_size);
}

Audio_Processor_Base::~Audio_Processor_Base() {}
