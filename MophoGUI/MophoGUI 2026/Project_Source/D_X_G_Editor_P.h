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
class MophoGUI2026AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MophoGUI2026AudioProcessorEditor (MophoGUI2026AudioProcessor&);
    ~MophoGUI2026AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MophoGUI2026AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MophoGUI2026AudioProcessorEditor)
};
