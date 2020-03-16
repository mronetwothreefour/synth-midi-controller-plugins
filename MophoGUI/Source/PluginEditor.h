#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"
#include "helpers/MophoLookAndFeel.h"
#include "parameters/PrivateParameters.h"
#include "widgets/KnobWidgets.h"

class PluginEditor : public AudioProcessorEditor
{
public:
    PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters);
    ~PluginEditor();

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

private:
    PluginProcessor& processor;

    PrivateParameters* privateParams;

    std::unique_ptr<KnobWidget_OscPitch> knob_Osc1Pitch;
    std::unique_ptr<KnobWidget_FineTune> knob_Osc1FineTune;
    std::unique_ptr<KnobWidget_OscShape> knob_Osc1Shape;
    std::unique_ptr<KnobWidget_OscGlide> knob_Osc1Glide;
    std::unique_ptr<KnobWidget_SubOscLvl> knob_SubOsc1Lvl;
    std::unique_ptr<KnobWidget_OscPitch> knob_Osc2Pitch;
    std::unique_ptr<KnobWidget_FineTune> knob_Osc2FineTune;
    std::unique_ptr<KnobWidget_OscShape> knob_Osc2Shape;
    std::unique_ptr<KnobWidget_OscGlide> knob_Osc2Glide;
    std::unique_ptr<KnobWidget_SubOscLvl> knob_SubOsc2Lvl;
    std::unique_ptr<KnobWidget_OscSlop> knob_OscSlop;
    std::unique_ptr<KnobWidget_OscMix> knob_OscMix;
    std::unique_ptr<KnobWidget_BendRange> knob_BendRange;
    std::unique_ptr<KnobWidget_NoiseLevel> knob_NoiseLevel;
    std::unique_ptr<KnobWidget_ExtInLevel> knob_ExtInLevel;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    TooltipWindow tooltipWindow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
