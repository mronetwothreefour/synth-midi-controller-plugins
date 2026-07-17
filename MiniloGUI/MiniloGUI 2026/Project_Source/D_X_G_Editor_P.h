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
class MiniloGUI2026AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MiniloGUI2026AudioProcessorEditor (MiniloGUI2026AudioProcessor&);
    ~MiniloGUI2026AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MiniloGUI2026AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MiniloGUI2026AudioProcessorEditor)
};
