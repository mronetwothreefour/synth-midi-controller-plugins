#pragma once

#include "D_X_G_Audio_Processor_A.h"

class Audio_Processor :
    public Audio_Processor_A
{

//==============================================================================
public: Audio_Processor();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void store_plugin_specific_param_state(XmlElement& plugin_state) override;
public: void restore_plugin_specific_param_state(XmlElement* plugin_state) override;

public: ~Audio_Processor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor)
};
