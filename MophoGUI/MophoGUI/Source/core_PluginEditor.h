#pragma once

#include <JuceHeader.h>



class GUILookAndFeel;
class UnexposedParameters;

class PluginEditor : 
    public AudioProcessorEditor,
    private ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics&) override;
    void resized() override;

private: void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
public: ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
