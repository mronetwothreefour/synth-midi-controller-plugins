#pragma once

#include <JuceHeader.h>

#include "core_PluginProcessor.h"



class PluginEditor :
    public juce::AudioProcessorEditor
{
    PluginProcessor& processor;

public:
    PluginEditor (PluginProcessor&);
    void paint (juce::Graphics&) override;
    void resized() override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
