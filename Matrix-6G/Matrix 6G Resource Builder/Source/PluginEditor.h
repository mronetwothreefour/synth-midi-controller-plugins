/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Matrix6gResourceBuilderAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Matrix6gResourceBuilderAudioProcessorEditor (Matrix6gResourceBuilderAudioProcessor&);
    ~Matrix6gResourceBuilderAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Matrix6gResourceBuilderAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Matrix6gResourceBuilderAudioProcessorEditor)
};
