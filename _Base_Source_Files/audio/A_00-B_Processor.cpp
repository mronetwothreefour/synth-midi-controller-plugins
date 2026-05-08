#include "A_00-B_Processor.h"

Base_Processor::Base_Processor() :
    AudioProcessor{ BusesProperties{} }
{}

const String Base_Processor::getName() const { return JucePlugin_Name; }

bool Base_Processor::acceptsMidi() const { return true; }

bool Base_Processor::producesMidi() const { return true; }

bool Base_Processor::isMidiEffect() const { return true; }

int Base_Processor::getNumPrograms() { return 1; }

int Base_Processor::getCurrentProgram() { return 0; }

void Base_Processor::setCurrentProgram(int /*pgm_index*/) {}

const String Base_Processor::getProgramName(int /*pgm_index*/) { return {}; }

void Base_Processor::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Base_Processor::processBlock(AudioBuffer<float>& audio, MidiBuffer& midi) {
    process_block(audio, midi);
}

bool Base_Processor::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const { return true; }

void Base_Processor::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {}

double Base_Processor::getTailLengthSeconds() const { return 0.0; }

void Base_Processor::releaseResources() {}

bool Base_Processor::hasEditor() const { return true; }

AudioProcessorEditor* Base_Processor::createEditor() {
    return create_editor();
}

void Base_Processor::getStateInformation(MemoryBlock& target_mem_block) {
    store_parameters_in_memory(target_mem_block);
}

void Base_Processor::setStateInformation(const void* stored_param_data, int data_size) {
    restore_parameters(stored_param_data, data_size);
}

Base_Processor::~Base_Processor() {}
