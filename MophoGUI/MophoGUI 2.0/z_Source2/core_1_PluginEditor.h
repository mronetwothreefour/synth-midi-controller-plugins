#pragma once

#include <JuceHeader.h>



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
    std::unique_ptr<GUI_Layer_EnvelopePainters> layerForEnvelopePainters;
    std::unique_ptr<GUI_Layer_ExposedParamControls> layerForExposedParamControls;
    std::unique_ptr<GUI_Layer_MainWindowButtons> layerForButtons;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

public:
    void paint(Graphics& g) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

public:
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
