#include "A_0_Processor.h"

#include "G_0_Editor.h"

Processor::Processor() :
    AudioProcessor{ BusesProperties{} }
{
}

const String Processor::getName() const {
    return JucePlugin_Name;
}

bool Processor::acceptsMidi() const {
    return true;
}

bool Processor::producesMidi() const {
    return true;
}

bool Processor::isMidiEffect() const {
    return true;
}

int Processor::getNumPrograms() {
    return 1;
}

int Processor::getCurrentProgram() {
    return 0;
}

void Processor::setCurrentProgram(int /*pgm_index*/) {}

const String Processor::getProgramName(int /*pgm_index*/) {
    return {};
}


void Processor::changeProgramName(int /*pgm_index*/, const String& /*new_name*/) {}

void Processor::processBlock(AudioBuffer<float>& audio, MidiBuffer& /*midi*/) {
    audio.clear();
}

bool Processor::isBusesLayoutSupported(const BusesLayout& /*layouts*/) const {
    return true;
}

void Processor::prepareToPlay(double /*sample_rate*/, int /*samples_per_block*/) {
}

double Processor::getTailLengthSeconds() const {
    return 0.0;
}

void Processor::releaseResources() {}

bool Processor::hasEditor() const {
    return true;
}

AudioProcessorEditor* Processor::createEditor() {
    return new Editor{ *this };
}

void Processor::getStateInformation(MemoryBlock& /*block_to_store_in*/) {
}

void Processor::setStateInformation(const void* /*stored_param_data*/, int /*data_size*/) {
}

Processor::~Processor() {
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Processor();
}
