#pragma once

#include <JuceHeader.h>

#include "core_0_PluginProcessor.h"



//class GUI_Layer_EnvelopePainters;
//class GUI_Layer_ExposedParamControls;
//class GUI_Layer_MainWindowButtons;
class MophoLookAndFeel;
//class TooltipsOptions;
//class UnexposedParameters;

class PluginEditor :
    public AudioProcessorEditor,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    std::unique_ptr<MophoLookAndFeel> lookAndFeel;

public:
    PluginEditor (PluginProcessor& processor);
    void paint (Graphics&) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
