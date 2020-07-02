#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class PluginEditor : public AudioProcessorEditor
{
    PluginProcessor& processor;

public:
    PluginEditor(PluginProcessor& processor);
    ~PluginEditor();

    void paint(Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
