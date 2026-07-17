/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "D_X_G_Audio_Processor_P.h"

//==============================================================================
/**
*/
class Matrix6G2026AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Matrix6G2026AudioProcessorEditor (Matrix6G2026AudioProcessor&);
    ~Matrix6G2026AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Matrix6G2026AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Matrix6G2026AudioProcessorEditor)
};
