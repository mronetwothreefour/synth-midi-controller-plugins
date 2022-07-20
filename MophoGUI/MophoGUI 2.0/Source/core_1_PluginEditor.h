#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class PluginEditor :
    public AudioProcessorEditor
{
    PluginProcessor& processor;

public:
    PluginEditor (PluginProcessor& processor);
    void paint (Graphics&) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
