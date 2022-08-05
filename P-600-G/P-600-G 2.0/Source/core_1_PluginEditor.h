#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class PluginEditor :
    public AudioProcessorEditor,
    private Timer
{
    PluginProcessor& processor;

public:
    PluginEditor(PluginProcessor& processor);
    void paint(Graphics& g) override;

private:
    void timerCallback() override;

public:
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
