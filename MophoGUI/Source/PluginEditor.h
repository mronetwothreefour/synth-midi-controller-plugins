#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"
#include "helpers/MophoLookAndFeel.h"

#include "widgets/KnobWidgets.h"

class PluginEditor : public AudioProcessorEditor
{
public:
    PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams);
    ~PluginEditor();

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

private:
    PluginProcessor& processor;

    std::unique_ptr<KnobWidget_OscPitch> knob_Osc1Pitch;
    std::unique_ptr<KnobWidget_FineTune> knob_Osc1FineTune;
    std::unique_ptr<KnobWidget_OscShape> knob_Osc1Shape;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
