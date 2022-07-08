#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"



class GUI_Layer_EnvelopePainters;
class GUI_Layer_ExposedParamControls;
class GUI_Layer_MainWindowButtons;
class MophoLookAndFeel;
class TooltipsOptions;
class UnexposedParameters;

class PluginEditor :
    public AudioProcessorEditor,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    TooltipsOptions* tooltips;
    std::unique_ptr<MophoLookAndFeel> lookAndFeel;
    std::unique_ptr<GUI_Layer_EnvelopePainters> layer_EnvelopePainters;
    std::unique_ptr<GUI_Layer_ExposedParamControls> layer_ExposedParamControls;
    std::unique_ptr<GUI_Layer_MainWindowButtons> layer_Buttons;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor (PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void paint (Graphics&) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
