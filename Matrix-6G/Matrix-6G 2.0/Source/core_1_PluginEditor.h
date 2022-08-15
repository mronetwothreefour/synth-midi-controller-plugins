#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class GUI_Layer_EnvelopePainters;
class GUI_Layer_ExposedParamControls;
class GUI_Layer_TrackingGraphPainter;
class MatrixLookAndFeel;

class PluginEditor :
    public AudioProcessorEditor,
    public Value::Listener,
    private Timer
{
    PluginProcessor& processor;
    std::unique_ptr<GUI_Layer_EnvelopePainters> layer_EnvelopePainters;
    std::unique_ptr<GUI_Layer_TrackingGraphPainter> layer_TrackingGraphPainter;
    std::unique_ptr<GUI_Layer_ExposedParamControls> layer_ExposedParamControls;
    std::unique_ptr<MatrixLookAndFeel> lookAndFeel;
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
