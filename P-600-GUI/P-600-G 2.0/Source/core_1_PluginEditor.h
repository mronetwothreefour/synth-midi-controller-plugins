#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"

class GUI_Layer_CurrentVoiceNumber;
class GUI_Layer_ExposedParamControls;
class GUI_Layer_MainWindowButtons;
class P_600_LookAndFeel;

class PluginEditor :
    public AudioProcessorEditor,
    public Value::Listener,
    private Timer
{
    PluginProcessor& processor;
    std::unique_ptr<GUI_Layer_ExposedParamControls> layer_ExposedParamControls;
    std::unique_ptr<GUI_Layer_MainWindowButtons> layer_MainWindowButtons;
    std::unique_ptr<GUI_Layer_CurrentVoiceNumber> layer_CurrentVoiceNumber;
    std::unique_ptr<P_600_LookAndFeel> lookAndFeel;
    std::unique_ptr<TooltipWindow> tooltipWindow;
    Value tooltipsDelayInMillisecondsAsValue;

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
