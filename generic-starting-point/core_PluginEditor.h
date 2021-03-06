#pragma once

#include <JuceHeader.h>



class PluginEditor : 
    public juce::AudioProcessorEditor
{
    PluginProcessor& processor;

public:
    explicit PluginEditor(PluginProcessor& processor);
    void paint(Graphics& g) override;
    void resized() override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
