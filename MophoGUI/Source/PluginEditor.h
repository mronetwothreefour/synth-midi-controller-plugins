#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"
#include "helpers/MophoLookAndFeel.h"
#include "parameters/PrivateParameters.h"
#include "editorSections/OscillatorsSection.h"
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

    std::unique_ptr<OscillatorsSection> sectionOsc;

    //std::unique_ptr<KnobWidget_LPFfreq>     knob_LPFfreq;
    //std::unique_ptr<KnobWidget_LPFreso>     knob_LPFreso;
    //std::unique_ptr<KnobWidget_LPFkeyAmt>   knob_LPFkeyAmt;
    //std::unique_ptr<KnobWidget_LPFenvAmt>   knob_LPFenvAmt;
    //std::unique_ptr<KnobWidget_VelAmount>   knob_LPFvelAmt;
    //std::unique_ptr<KnobWidget_LPFfmAmt>    knob_LPFfmAmt;
    //std::unique_ptr<KnobWidget_EnvDelay>    knob_LPFenvDelay;
    //std::unique_ptr<KnobWidget_EnvAttack>   knob_LPFenvAttack;
    //std::unique_ptr<KnobWidget_EnvDecay>    knob_LPFenvDecay;
    //std::unique_ptr<KnobWidget_EnvSustain>  knob_LPFenvSustain;
    //std::unique_ptr<KnobWidget_EnvRelease>  knob_LPFenvRelease;

    //std::unique_ptr<KnobWidget_VCAlevel>    knob_VCAlevel;
    //std::unique_ptr<KnobWidget_VCAenvAmt>   knob_VCAenvAmt;
    //std::unique_ptr<KnobWidget_VelAmount>   knob_VCAvelAmt;
    //std::unique_ptr<KnobWidget_PgmVolume>   knob_PgmVolume;
    //std::unique_ptr<KnobWidget_EnvDelay>    knob_VCAenvDelay;
    //std::unique_ptr<KnobWidget_EnvAttack>   knob_VCAenvAttack;
    //std::unique_ptr<KnobWidget_EnvDecay>    knob_VCAenvDecay;
    //std::unique_ptr<KnobWidget_EnvSustain>  knob_VCAenvSustain;
    //std::unique_ptr<KnobWidget_EnvRelease>  knob_VCAenvRelease;

    //std::unique_ptr<KnobWidget_Env3Amt>     knob_Env3Amt;
    //std::unique_ptr<KnobWidget_VelAmount>   knob_Env3VelAmt;
    //std::unique_ptr<KnobWidget_EnvDelay>    knob_Env3Delay;
    //std::unique_ptr<KnobWidget_EnvAttack>   knob_Env3Attack;
    //std::unique_ptr<KnobWidget_EnvDecay>    knob_Env3Decay;
    //std::unique_ptr<KnobWidget_EnvSustain>  knob_Env3Sustain;
    //std::unique_ptr<KnobWidget_EnvRelease>  knob_Env3Release;

    //std::unique_ptr<KnobWidget_ModAmt>      knob_Mod1Amt;
    //std::unique_ptr<KnobWidget_ModAmt>      knob_Mod2Amt;
    //std::unique_ptr<KnobWidget_ModAmt>      knob_Mod3Amt;
    //std::unique_ptr<KnobWidget_ModAmt>      knob_Mod4Amt;

    //std::unique_ptr<KnobWidget_MidiModAmt>  knob_ModWheelAmt;
    //std::unique_ptr<KnobWidget_MidiModAmt>  knob_AftertouchAmt;
    //std::unique_ptr<KnobWidget_MidiModAmt>  knob_BreathAmt;
    //std::unique_ptr<KnobWidget_MidiModAmt>  knob_VelocityAmt;
    //std::unique_ptr<KnobWidget_MidiModAmt>  knob_PedalAmt;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    TooltipWindow tooltipWindow;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
