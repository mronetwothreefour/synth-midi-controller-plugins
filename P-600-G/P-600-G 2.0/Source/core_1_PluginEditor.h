#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class PluginEditor :
    public AudioProcessorEditor,
    public Value::Listener,
    private Timer
{
    PluginProcessor& processor;
    std::unique_ptr<TooltipWindow> tooltipWindow;
    Value tooltipsDelayInMillisecondsValue;

public:
    PluginEditor(PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;

private:
    void timerCallback() override;

public:
    void valueChanged(Value& value) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
