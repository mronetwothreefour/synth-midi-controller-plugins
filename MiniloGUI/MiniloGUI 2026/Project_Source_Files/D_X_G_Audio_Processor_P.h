#pragma once

#include <JuceHeader.h>

#include "D_X_G_Audio_Processor_B.h"

class Audio_Processor_P :
    public Audio_Processor_B
{

//==============================================================================
public: Audio_Processor_P();

public: void process_block(AudioBuffer<float>& audio, MidiBuffer& midi) override;
public: AudioProcessorEditor* create_editor() override;
public: void add_plugin_specific_param_state_to_xml(XmlElement& plugin_state_xml) override;
public: void restore_plugin_specific_param_state(XmlElement* plugin_state_xml) override;

public: ~Audio_Processor_P() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Audio_Processor_P)
};
