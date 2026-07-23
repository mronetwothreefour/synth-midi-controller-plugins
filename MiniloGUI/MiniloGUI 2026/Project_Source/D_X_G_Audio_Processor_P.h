#pragma once

#include "D_X_G_Audio_Processor_G.h"

class Audio_Processor_P :
    public Audio_Processor_G
{

//==============================================================================
public: Audio_Processor_P();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void store_plugin_specific_param_state(XmlElement& plugin_state) override;
public: void restore_plugin_specific_param_state(XmlElement* plugin_state) override;

public: ~Audio_Processor_P() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor_P)
};
