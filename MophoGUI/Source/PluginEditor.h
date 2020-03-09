#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"

class PluginEditor : public AudioProcessorEditor
{
public:
    PluginEditor(PluginProcessor& p);
    ~PluginEditor();

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

private:
    PluginProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
