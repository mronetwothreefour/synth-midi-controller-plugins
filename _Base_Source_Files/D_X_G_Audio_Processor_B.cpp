#include "D_X_G_Audio_Processor_B.h"

Audio_Processor_B::Audio_Processor_B() :
    AudioProcessor{ BusesProperties{} }
{}

const String Audio_Processor_B::getName() const { return JucePlugin_Name; }

bool Audio_Processor_B::acceptsMidi() const { return true; }

bool Audio_Processor_B::producesMidi() const { return true; }

bool Audio_Processor_B::isMidiEffect() const { return true; }

int Audio_Processor_B::getNumPrograms() { return 1; }

int Audio_Processor_B::getCurrentProgram() { return 0; }

void Audio_Processor_B::setCurrentProgram(int /*pgm_index*/) {}

const String Audio_Processor_B::getProgramName(int /*pgm_index*/) { return {}; }

void Audio_Processor_B::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Audio_Processor_B::processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) {
    process_block(audio, midi);
}

bool Audio_Processor_B::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const { return true; }

void Audio_Processor_B::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {}

double Audio_Processor_B::getTailLengthSeconds() const { return 0.0; }

void Audio_Processor_B::releaseResources() {}

bool Audio_Processor_B::hasEditor() const { return true; }

AudioProcessorEditor* Audio_Processor_B::createEditor() {
    return create_editor();
}

void Audio_Processor_B::getStateInformation(MemoryBlock& target_mem_block) {
    store_parameters_in_memory(target_mem_block);
}

void Audio_Processor_B::setStateInformation(const void* stored_param_data, int data_size) {
    restore_parameters(stored_param_data, data_size);
}

Audio_Processor_B::~Audio_Processor_B() {}
