#pragma once

#include <JuceHeader.h>



class GUI_Layer_ExposedParamControls;
class MophoLookAndFeel;
class UnexposedParameters;

class PluginEditor :
    public AudioProcessorEditor,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<MophoLookAndFeel> lookAndFeel;
    std::unique_ptr<GUI_Layer_ExposedParamControls> layerForExposedParamControls;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

public:
    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

public:
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
