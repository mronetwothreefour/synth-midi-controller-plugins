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
class P600GAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    P600GAudioProcessorEditor (P600GAudioProcessor&);
    ~P600GAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    P600GAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (P600GAudioProcessorEditor)
};
