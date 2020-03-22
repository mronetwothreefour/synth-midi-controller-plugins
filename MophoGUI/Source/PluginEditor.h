#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"
#include "helpers/MophoLookAndFeel.h"
#include "parameters/PrivateParameters.h"
#include "editorSections/Env3Section.h"
#include "editorSections/LPFSection.h"
#include "editorSections/OscillatorsSection.h"
#include "editorSections/VCASection.h"
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
    std::unique_ptr<LPFSection> sectionLPF;
    std::unique_ptr<VCASection> sectionVCA;
    std::unique_ptr<Env3Section> sectionEnv3;

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
