#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class PluginEditor :
    public AudioProcessorEditor,
    public Value::Listener
{
    PluginProcessor& processor;
    Value tooltipsDelayInMillisecondsValue;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor (PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void paint (Graphics&) override;
    void valueChanged(Value& value) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
