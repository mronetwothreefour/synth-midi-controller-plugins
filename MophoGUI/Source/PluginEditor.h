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

    std::unique_ptr<KnobWidget_OscPitch>    knob_Osc1Pitch;
    std::unique_ptr<KnobWidget_FineTune>    knob_Osc1FineTune;
    std::unique_ptr<KnobWidget_OscShape>    knob_Osc1Shape;
    std::unique_ptr<KnobWidget_OscGlide>    knob_Osc1Glide;
    std::unique_ptr<KnobWidget_SubOscLvl>   knob_SubOsc1Lvl;

    std::unique_ptr<KnobWidget_OscPitch>    knob_Osc2Pitch;
    std::unique_ptr<KnobWidget_FineTune>    knob_Osc2FineTune;
    std::unique_ptr<KnobWidget_OscShape>    knob_Osc2Shape;
    std::unique_ptr<KnobWidget_OscGlide>    knob_Osc2Glide;
    std::unique_ptr<KnobWidget_SubOscLvl>   knob_SubOsc2Lvl;

    std::unique_ptr<KnobWidget_OscSlop>     knob_OscSlop;
    std::unique_ptr<KnobWidget_OscMix>      knob_OscMix;
    std::unique_ptr<KnobWidget_BendRange>   knob_BendRange;
    std::unique_ptr<KnobWidget_NoiseLevel>  knob_NoiseLevel;
    std::unique_ptr<KnobWidget_ExtInLevel>  knob_ExtInLevel;

    std::unique_ptr<KnobWidget_LPFfreq>     knob_LPFfreq;
    std::unique_ptr<KnobWidget_LPFreso>     knob_LPFreso;
    std::unique_ptr<KnobWidget_LPFkeyAmt>   knob_LPFkeyAmt;
    std::unique_ptr<KnobWidget_LPFenvAmt>   knob_LPFenvAmt;
    std::unique_ptr<KnobWidget_VelAmount>   knob_LPFvelAmt;
    std::unique_ptr<KnobWidget_LPFfmAmt>    knob_LPFfmAmt;
    std::unique_ptr<KnobWidget_EnvDelay>    knob_LPFenvDelay;
    std::unique_ptr<KnobWidget_EnvAttack>   knob_LPFenvAttack;
    std::unique_ptr<KnobWidget_EnvDecay>    knob_LPFenvDecay;
    std::unique_ptr<KnobWidget_EnvSustain>  knob_LPFenvSustain;
    std::unique_ptr<KnobWidget_EnvRelease>  knob_LPFenvRelease;

    std::unique_ptr<KnobWidget_VCAlevel>    knob_VCAlevel;
    std::unique_ptr<KnobWidget_VCAenvAmt>   knob_VCAenvAmt;
    std::unique_ptr<KnobWidget_VelAmount>   knob_VCAvelAmt;
    std::unique_ptr<KnobWidget_PgmVolume>   knob_PgmVolume;
    std::unique_ptr<KnobWidget_EnvDelay>    knob_VCAenvDelay;
    std::unique_ptr<KnobWidget_EnvAttack>   knob_VCAenvAttack;
    std::unique_ptr<KnobWidget_EnvDecay>    knob_VCAenvDecay;
    std::unique_ptr<KnobWidget_EnvSustain>  knob_VCAenvSustain;
    std::unique_ptr<KnobWidget_EnvRelease>  knob_VCAenvRelease;

    std::unique_ptr<KnobWidget_Env3Amt>     knob_Env3Amt;
    std::unique_ptr<KnobWidget_VelAmount>   knob_Env3VelAmt;
    std::unique_ptr<KnobWidget_EnvDelay>    knob_Env3Delay;
    std::unique_ptr<KnobWidget_EnvAttack>   knob_Env3Attack;
    std::unique_ptr<KnobWidget_EnvDecay>    knob_Env3Decay;
    std::unique_ptr<KnobWidget_EnvSustain>  knob_Env3Sustain;
    std::unique_ptr<KnobWidget_EnvRelease>  knob_Env3Release;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    TooltipWindow tooltipWindow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
