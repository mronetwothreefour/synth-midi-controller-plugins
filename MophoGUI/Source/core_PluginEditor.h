#pragma once

#include <JuceHeader.h>

#include "core_PluginProcessor.h"
#include "helpers/helper_CustomColors.h"
#include "helpers/helper_Fonts.h"
#include "helpers/helper_Identifiers.h"
#include "helpers/helper_MophoLookAndFeel.h"
#include "mainWindowDivisions/mainWinDiv_Logo.h"
#include "mainWindowDivisions/mainWinDiv_Oscillators.h"
#include "parameters/parameters_SynthParameters.h"

class PluginEditor : public AudioProcessorEditor
{
public:
    PluginEditor(PluginProcessor& processor);
    ~PluginEditor();

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

private:
    PluginProcessor& processor;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    std::unique_ptr<MainWindowDivision_Logo> div_Logo;

    KnobWithValueStringDisplay pitchOsc1;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
