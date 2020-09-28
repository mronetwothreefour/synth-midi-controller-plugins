#pragma once

#include <JuceHeader.h>



class Logo;

class PluginEditor :
    public juce::AudioProcessorEditor
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<Logo> logo;

public:
    explicit PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(juce::Graphics&) override;
    void resized() override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
