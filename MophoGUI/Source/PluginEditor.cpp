#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters) :
    AudioProcessorEditor{ &p },
    processor{ p },
    privateParams{ privateParameters }
{
    mophoLaF.reset(new MophoLookAndFeel());

    sectionOsc.reset(new OscillatorsSection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionOsc.get());

    sectionLPF.reset(new LPFSection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionLPF.get());

    sectionVCA.reset(new VCASection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionVCA.get());

    ////==============================================================================
    //// Initialize envelope 3 controls

    //knob_Env3Amt.reset(new KnobWidget_Env3Amt(publicParams, privateParams, mophoLaF.get()));
    //addAndMakeVisible(knob_Env3Amt.get());

    //knob_Env3VelAmt.reset(new KnobWidget_VelAmount(publicParams, privateParams, ID::env3VelAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_Env3VelAmt.get());

    ////==============================================================================
    //// Initialize modulator controls

    //knob_Mod1Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod1Amount, mophoLaF.get()));
    //addAndMakeVisible(knob_Mod1Amt.get());

    //knob_Mod2Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod2Amount, mophoLaF.get()));
    //addAndMakeVisible(knob_Mod2Amt.get());

    //knob_Mod3Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod3Amount, mophoLaF.get()));
    //addAndMakeVisible(knob_Mod3Amt.get());

    //knob_Mod4Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod4Amount, mophoLaF.get()));
    //addAndMakeVisible(knob_Mod4Amt.get());

    ////==============================================================================
    //// Initialize MIDI modulator controls

    //knob_ModWheelAmt.reset(new KnobWidget_MidiModAmt(publicParams, privateParams, ID::modWheelAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_ModWheelAmt.get());

    //knob_AftertouchAmt.reset(new KnobWidget_MidiModAmt(publicParams, privateParams, ID::aftertouchAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_AftertouchAmt.get());

    //knob_BreathAmt.reset(new KnobWidget_MidiModAmt(publicParams, privateParams, ID::breathAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_BreathAmt.get());

    //knob_VelocityAmt.reset(new KnobWidget_MidiModAmt(publicParams, privateParams, ID::velocityAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_VelocityAmt.get());

    //knob_PedalAmt.reset(new KnobWidget_MidiModAmt(publicParams, privateParams, ID::footPedalAmount, mophoLaF.get()));
    //addAndMakeVisible(knob_PedalAmt.get());

    //==============================================================================

    tooltipWindow.setMillisecondsBeforeTipAppears(privateParams->getTooltipDelay());
    tooltipWindow.setLookAndFeel(mophoLaF.get());
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    tooltipWindow.setLookAndFeel(nullptr);

    sectionVCA = nullptr;
    sectionLPF = nullptr;
    sectionOsc = nullptr;

    //knob_PedalAmt = nullptr;
    //knob_VelocityAmt = nullptr;
    //knob_BreathAmt = nullptr;
    //knob_AftertouchAmt = nullptr;
    //knob_ModWheelAmt = nullptr;

    //knob_Mod4Amt = nullptr;
    //knob_Mod3Amt = nullptr;
    //knob_Mod2Amt = nullptr;
    //knob_Mod1Amt = nullptr;

    //knob_Env3VelAmt = nullptr;
    //knob_Env3Amt = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
}

//==============================================================================
void PluginEditor::paint(Graphics& g)
{
    g.fillAll(Color::device);

    g.setColour(Color::black);

    // Draw section labels
    //==============================================================================
    Font sectionLabel{ "Arial", "Black", 18.0f };
    g.setFont(sectionLabel);

    Rectangle<int> env3SectionLabelArea{ 15, 470, 105, 15 };
    g.drawText("ENVELOPE 3", env3SectionLabelArea, Justification::centredLeft);

    Rectangle<int> modSectionLabelArea{ 404, 154, 105, 15 };
    g.drawText("MODULATORS", modSectionLabelArea, Justification::centredLeft);

    Rectangle<int> midiModSectionLabelArea{ 617, 154, 150, 15 };
    g.drawText("MIDI CONTROLLERS", midiModSectionLabelArea, Justification::centredLeft);
}

void PluginEditor::resized()
{
    sectionOsc->setBounds(15, 15, sectionOsc->getWidth(), sectionOsc->getHeight());
    sectionLPF->setBounds(15, 154, sectionLPF->getWidth(), sectionLPF->getHeight());
    sectionVCA->setBounds(15, 312, sectionLPF->getWidth(), sectionLPF->getHeight());

    //knob_Env3Amt->setBounds         (knob_col2_x, knob_row7_y, knobWidget_w, knobWidget_h);
    //knob_Env3VelAmt->setBounds      (knob_col3_x, knob_row7_y, knobWidget_w, knobWidget_h);

    //auto modKnobs_x{ 560 };
    //auto modKnob1_y{ 186 };
    //auto modKnob2_y{ modKnob1_y + 78 };
    //auto modKnob3_y{ modKnob2_y + 78 };
    //auto modKnob4_y{ modKnob3_y + 78 };

    //knob_Mod1Amt->setBounds(modKnobs_x, modKnob1_y, knobWidget_w, knobWidget_h);
    //knob_Mod2Amt->setBounds(modKnobs_x, modKnob2_y, knobWidget_w, knobWidget_h);
    //knob_Mod3Amt->setBounds(modKnobs_x, modKnob3_y, knobWidget_w, knobWidget_h);
    //knob_Mod4Amt->setBounds(modKnobs_x, modKnob4_y, knobWidget_w, knobWidget_h);

    //auto midiModKnobs_x{ 756 };
    //auto midiModKnob1_y{ 176 };
    //auto midiModKnob2_y{ midiModKnob1_y + 62 };
    //auto midiModKnob3_y{ midiModKnob2_y + 62 };
    //auto midiModKnob4_y{ midiModKnob3_y + 62 };
    //auto midiModKnob5_y{ midiModKnob4_y + 62 };

    //knob_ModWheelAmt->  setBounds(midiModKnobs_x, midiModKnob1_y, knobWidget_w, knobWidget_h);
    //knob_AftertouchAmt->setBounds(midiModKnobs_x, midiModKnob2_y, knobWidget_w, knobWidget_h);
    //knob_BreathAmt->    setBounds(midiModKnobs_x, midiModKnob3_y, knobWidget_w, knobWidget_h);
    //knob_VelocityAmt->  setBounds(midiModKnobs_x, midiModKnob4_y, knobWidget_w, knobWidget_h);
    //knob_PedalAmt->     setBounds(midiModKnobs_x, midiModKnob5_y, knobWidget_w, knobWidget_h);
}
