/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "core_PluginProcessor.h"

//==============================================================================
/**
*/
class MophoGUI2_0AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MophoGUI2_0AudioProcessorEditor (MophoGUI2_0AudioProcessor&);
    ~MophoGUI2_0AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MophoGUI2_0AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MophoGUI2_0AudioProcessorEditor)
};
