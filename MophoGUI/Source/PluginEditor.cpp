#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters) :
    AudioProcessorEditor{ &p },
    processor{ p },
    privateParams{ privateParameters }
{
    mophoLaF.reset(new MophoLookAndFeel());

    //==============================================================================
    // Initialize oscillator 1 controls

    knob_Osc1Pitch.reset(new KnobWidget_OscPitch(publicParams, privateParams, ID::osc1Pitch, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1Pitch.get());

    knob_Osc1FineTune.reset(new KnobWidget_FineTune(publicParams, privateParams, ID::osc1Fine, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1FineTune.get());

    knob_Osc1Shape.reset(new KnobWidget_OscShape(publicParams, privateParams, ID::osc1Shape, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1Shape.get());

    knob_Osc1Glide.reset(new KnobWidget_OscGlide(publicParams, privateParams, ID::osc1Glide, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1Glide.get());

    knob_SubOsc1Lvl.reset(new KnobWidget_SubOscLvl(publicParams, privateParams, ID::subOsc1Level, mophoLaF.get()));
    addAndMakeVisible(knob_SubOsc1Lvl.get());

    //==============================================================================
    // Initialize oscillator 2 controls

    knob_Osc2Pitch.reset(new KnobWidget_OscPitch(publicParams, privateParams, ID::osc2Pitch, mophoLaF.get()));
    addAndMakeVisible(knob_Osc2Pitch.get());

    knob_Osc2FineTune.reset(new KnobWidget_FineTune(publicParams, privateParams, ID::osc2Fine, mophoLaF.get()));
    addAndMakeVisible(knob_Osc2FineTune.get());

    knob_Osc2Shape.reset(new KnobWidget_OscShape(publicParams, privateParams, ID::osc2Shape, mophoLaF.get()));
    addAndMakeVisible(knob_Osc2Shape.get());

    knob_Osc2Glide.reset(new KnobWidget_OscGlide(publicParams, privateParams, ID::osc2Glide, mophoLaF.get()));
    addAndMakeVisible(knob_Osc2Glide.get());

    knob_SubOsc2Lvl.reset(new KnobWidget_SubOscLvl(publicParams, privateParams, ID::subOsc2Level, mophoLaF.get()));
    addAndMakeVisible(knob_SubOsc2Lvl.get());

    //==============================================================================
    // Initialize miscellaneous oscillator controls

    knob_OscSlop.reset(new KnobWidget_OscSlop(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_OscSlop.get());

    knob_OscMix.reset(new KnobWidget_OscMix(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_OscMix.get());

    knob_BendRange.reset(new KnobWidget_BendRange(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_BendRange.get());

    knob_NoiseLevel.reset(new KnobWidget_NoiseLevel(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_NoiseLevel.get());

    knob_ExtInLevel.reset(new KnobWidget_ExtInLevel(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_ExtInLevel.get());

    //==============================================================================
    // Initialize low-pass filter controls

    knob_LPFfreq.reset(new KnobWidget_LPFfreq(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_LPFfreq.get());

    knob_LPFreso.reset(new KnobWidget_LPFreso(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_LPFreso.get());

    knob_LPFkeyAmt.reset(new KnobWidget_LPFkeyAmt(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_LPFkeyAmt.get());

    knob_LPFenvAmt.reset(new KnobWidget_LPFenvAmt(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvAmt.get());

    knob_LPFvelAmt.reset(new KnobWidget_VelAmount(publicParams, privateParams, ID::lpfVelAmount, mophoLaF.get()));
    addAndMakeVisible(knob_LPFvelAmt.get());

    knob_LPFfmAmt.reset(new KnobWidget_LPFfmAmt(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_LPFfmAmt.get());

    knob_LPFenvDelay.reset(new KnobWidget_EnvDelay(publicParams, privateParams, ID::lpfDelay, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvDelay.get());

    knob_LPFenvAttack.reset(new KnobWidget_EnvAttack(publicParams, privateParams, ID::lpfAttack, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvAttack.get());

    knob_LPFenvDecay.reset(new KnobWidget_EnvDecay(publicParams, privateParams, ID::lpfDecay, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvDecay.get());

    knob_LPFenvSustain.reset(new KnobWidget_EnvSustain(publicParams, privateParams, ID::lpfSustain, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvSustain.get());

    knob_LPFenvRelease.reset(new KnobWidget_EnvRelease(publicParams, privateParams, ID::lpfRelease, mophoLaF.get()));
    addAndMakeVisible(knob_LPFenvRelease.get());

    //==============================================================================
    // Initialize voltage-controlled amplifier controls

    knob_VCAlevel.reset(new KnobWidget_VCAlevel(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_VCAlevel.get());

    knob_VCAenvAmt.reset(new KnobWidget_VCAenvAmt(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvAmt.get());

    knob_VCAvelAmt.reset(new KnobWidget_VelAmount(publicParams, privateParams, ID::vcaVelAmount, mophoLaF.get()));
    addAndMakeVisible(knob_VCAvelAmt.get());

    knob_PgmVolume.reset(new KnobWidget_PgmVolume(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_PgmVolume.get());

    knob_VCAenvDelay.reset(new KnobWidget_EnvDelay(publicParams, privateParams, ID::vcaDelay, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvDelay.get());

    knob_VCAenvAttack.reset(new KnobWidget_EnvAttack(publicParams, privateParams, ID::vcaAttack, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvAttack.get());

    knob_VCAenvDecay.reset(new KnobWidget_EnvDecay(publicParams, privateParams, ID::vcaDecay, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvDecay.get());

    knob_VCAenvSustain.reset(new KnobWidget_EnvSustain(publicParams, privateParams, ID::vcaSustain, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvSustain.get());

    knob_VCAenvRelease.reset(new KnobWidget_EnvRelease(publicParams, privateParams, ID::vcaRelease, mophoLaF.get()));
    addAndMakeVisible(knob_VCAenvRelease.get());

    //==============================================================================
    // Initialize envelope 3 controls

    knob_Env3Amt.reset(new KnobWidget_Env3Amt(publicParams, privateParams, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Amt.get());

    knob_Env3VelAmt.reset(new KnobWidget_VelAmount(publicParams, privateParams, ID::env3VelAmount, mophoLaF.get()));
    addAndMakeVisible(knob_Env3VelAmt.get());

    knob_Env3Delay.reset(new KnobWidget_EnvDelay(publicParams, privateParams, ID::env3Delay, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Delay.get());

    knob_Env3Attack.reset(new KnobWidget_EnvAttack(publicParams, privateParams, ID::env3Attack, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Attack.get());

    knob_Env3Decay.reset(new KnobWidget_EnvDecay(publicParams, privateParams, ID::env3Decay, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Decay.get());

    knob_Env3Sustain.reset(new KnobWidget_EnvSustain(publicParams, privateParams, ID::env3Sustain, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Sustain.get());

    knob_Env3Release.reset(new KnobWidget_EnvRelease(publicParams, privateParams, ID::env3Release, mophoLaF.get()));
    addAndMakeVisible(knob_Env3Release.get());

    //==============================================================================
    // Initialize modulator controls

    knob_Mod1Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod1Amount, mophoLaF.get()));
    addAndMakeVisible(knob_Mod1Amt.get());

    knob_Mod2Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod2Amount, mophoLaF.get()));
    addAndMakeVisible(knob_Mod2Amt.get());

    knob_Mod3Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod3Amount, mophoLaF.get()));
    addAndMakeVisible(knob_Mod3Amt.get());

    knob_Mod4Amt.reset(new KnobWidget_ModAmt(publicParams, privateParams, ID::mod4Amount, mophoLaF.get()));
    addAndMakeVisible(knob_Mod4Amt.get());

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

    knob_Mod4Amt = nullptr;
    knob_Mod3Amt = nullptr;
    knob_Mod2Amt = nullptr;
    knob_Mod1Amt = nullptr;

    knob_Env3Release = nullptr;
    knob_Env3Sustain = nullptr;
    knob_Env3Decay = nullptr;
    knob_Env3Attack = nullptr;
    knob_VCAenvDelay = nullptr;
    knob_Env3VelAmt = nullptr;
    knob_Env3Amt = nullptr;

    knob_VCAenvRelease = nullptr;
    knob_VCAenvSustain = nullptr;
    knob_VCAenvDecay = nullptr;
    knob_VCAenvAttack = nullptr;
    knob_VCAenvDelay = nullptr;
    knob_PgmVolume = nullptr;
    knob_VCAvelAmt = nullptr;
    knob_VCAenvAmt = nullptr;
    knob_VCAlevel = nullptr;

    knob_LPFenvRelease = nullptr;
    knob_LPFenvSustain = nullptr;
    knob_LPFenvDecay = nullptr;
    knob_LPFenvAttack = nullptr;
    knob_LPFenvDelay = nullptr;
    knob_LPFfmAmt = nullptr;
    knob_LPFvelAmt = nullptr;
    knob_LPFenvAmt = nullptr;
    knob_LPFkeyAmt = nullptr;
    knob_LPFreso = nullptr;
    knob_LPFfreq = nullptr;

    knob_ExtInLevel = nullptr;
    knob_NoiseLevel = nullptr;
    knob_BendRange = nullptr;
    knob_OscMix = nullptr;
    knob_OscSlop = nullptr;
 
    knob_SubOsc2Lvl = nullptr;
    knob_Osc2Glide = nullptr;
    knob_Osc2Shape = nullptr;
    knob_Osc2FineTune = nullptr;
    knob_Osc2Pitch = nullptr;
 
    knob_SubOsc1Lvl = nullptr;
    knob_Osc1Glide = nullptr;
    knob_Osc1Shape = nullptr;
    knob_Osc1FineTune = nullptr;
    knob_Osc1Pitch = nullptr;

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

    Rectangle<int> oscSectionLabelArea{ 15, 15, 105, 15 };
    g.drawText("OSCILLATORS", oscSectionLabelArea, Justification::centredLeft);

    Rectangle<int> lpfSectionLabelArea{ 15, 154, 30, 15 };
    g.drawText("LPF", lpfSectionLabelArea, Justification::centredLeft);

    Rectangle<int> vcaSectionLabelArea{ 15, 312, 30, 15 };
    g.drawText("VCA", vcaSectionLabelArea, Justification::centredLeft);

    Rectangle<int> env3SectionLabelArea{ 15, 470, 105, 15 };
    g.drawText("ENVELOPE 3", env3SectionLabelArea, Justification::centredLeft);

    Rectangle<int> modSectionLabelArea{ 404, 154, 105, 15 };
    g.drawText("MODULATORS", modSectionLabelArea, Justification::centredLeft);

    // Draw oscillator number labels
    //==============================================================================
    Font oscNumLabel{ "Arial", "Black", 24.0f };
    g.setFont(oscNumLabel);

    Rectangle<int> osc1NumLabelArea{ 15, 35, 15, 30 };
    g.drawText("1", osc1NumLabelArea, Justification::centredLeft);
    Rectangle<int> osc2NumLabelArea{ 15, 95, 15, 30 };
    g.drawText("2", osc2NumLabelArea, Justification::centredLeft);

    // Draw oscillator dividing line
    //==============================================================================
    g.drawHorizontalLine(85, 15, 295);

    // Draw oscillator number labels for mix knob
    //==============================================================================
    Font mixNumLabel{ "Arial", "Bold", 11.0f };
    g.setFont(mixNumLabel);

    Rectangle<int> mixNum1LabelArea{ 343, 59, 6, 13 };
    g.drawText("1", mixNum1LabelArea, Justification::centred);
    Rectangle<int> mixNum2LabelArea{ 378, 59, 6, 13 };
    g.drawText("2", mixNum2LabelArea, Justification::centred);
}

void PluginEditor::resized()
{
    auto knobWidget_w{ knob_Osc1Pitch->getWidth() };
    auto knobWidget_h{ knob_Osc1Pitch->getHeight() };

    auto knob_w{ 40 };
    auto knobGap{ 5 };
    auto knob_col1_x{ 28 };
    auto knob_col2_x{ knob_col1_x + knob_w + knobGap };
    auto knob_col3_x{ knob_col2_x + knob_w + knobGap };
    auto knob_col4_x{ knob_col3_x + knob_w + knobGap };
    auto knob_col5_x{ knob_col4_x + knob_w + knobGap };
    auto knob_col6_x{ knob_col5_x + knob_w + knobGap };
    auto knob_col7_x{ knob_col6_x + knob_w + knobGap };
    auto knob_col8_x{ knob_col7_x + knob_w + knobGap };
    auto knob_col9_x{ knob_col8_x + knob_w + knobGap };

    auto knob_row1_y{ 30  };
    auto knob_row2_y{ 90  };
    auto knob_row3_y{ 195 };
    auto knob_row4_y{ 247 };
    auto knob_row5_y{ 353 };
    auto knob_row6_y{ 405 };
    auto knob_row7_y{ 511 };
    auto knob_row8_y{ 563 };

    knob_Osc1Pitch->setBounds       (knob_col1_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1FineTune->setBounds    (knob_col2_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Shape->setBounds       (knob_col3_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Glide->setBounds       (knob_col4_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_SubOsc1Lvl->setBounds      (knob_col5_x, knob_row1_y, knobWidget_w, knobWidget_h);

    knob_Osc2Pitch->setBounds       (knob_col1_x, knob_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2FineTune->setBounds    (knob_col2_x, knob_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2Shape->setBounds       (knob_col3_x, knob_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2Glide->setBounds       (knob_col4_x, knob_row2_y, knobWidget_w, knobWidget_h);
    knob_SubOsc2Lvl->setBounds      (knob_col5_x, knob_row2_y, knobWidget_w, knobWidget_h);

    knob_OscSlop->setBounds         (knob_col7_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_OscMix->setBounds          (knob_col8_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_BendRange->setBounds       (knob_col9_x, knob_row1_y, knobWidget_w, knobWidget_h);
    knob_NoiseLevel->setBounds      (knob_col7_x, knob_row2_y, knobWidget_w, knobWidget_h);
    knob_ExtInLevel->setBounds      (knob_col8_x, knob_row2_y, knobWidget_w, knobWidget_h);

    knob_LPFfreq->setBounds         (knob_col1_x, knob_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFreso->setBounds         (knob_col2_x, knob_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFkeyAmt->setBounds       (knob_col3_x, knob_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFenvAmt->setBounds       (knob_col1_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFvelAmt->setBounds       (knob_col2_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFfmAmt->setBounds        (knob_col3_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvDelay->setBounds     (knob_col4_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvAttack->setBounds    (knob_col5_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvDecay->setBounds     (knob_col6_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvSustain->setBounds   (knob_col7_x, knob_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvRelease->setBounds   (knob_col8_x, knob_row4_y, knobWidget_w, knobWidget_h);

    knob_VCAlevel->setBounds        (knob_col1_x, knob_row5_y, knobWidget_w, knobWidget_h);
    knob_VCAenvAmt->setBounds       (knob_col2_x, knob_row5_y, knobWidget_w, knobWidget_h);
    knob_VCAvelAmt->setBounds       (knob_col3_x, knob_row5_y, knobWidget_w, knobWidget_h);
    knob_PgmVolume->setBounds       (knob_col2_x, knob_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvDelay->setBounds     (knob_col4_x, knob_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvAttack->setBounds    (knob_col5_x, knob_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvDecay->setBounds     (knob_col6_x, knob_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvSustain->setBounds   (knob_col7_x, knob_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvRelease->setBounds   (knob_col8_x, knob_row6_y, knobWidget_w, knobWidget_h);

    knob_Env3Amt->setBounds         (knob_col2_x, knob_row7_y, knobWidget_w, knobWidget_h);
    knob_Env3VelAmt->setBounds      (knob_col3_x, knob_row7_y, knobWidget_w, knobWidget_h);
    knob_Env3Delay->setBounds       (knob_col4_x, knob_row8_y, knobWidget_w, knobWidget_h);
    knob_Env3Attack->setBounds      (knob_col5_x, knob_row8_y, knobWidget_w, knobWidget_h);
    knob_Env3Decay->setBounds       (knob_col6_x, knob_row8_y, knobWidget_w, knobWidget_h);
    knob_Env3Sustain->setBounds     (knob_col7_x, knob_row8_y, knobWidget_w, knobWidget_h);
    knob_Env3Release->setBounds     (knob_col8_x, knob_row8_y, knobWidget_w, knobWidget_h);

    auto modKnobs_x{ 560 };
    auto modKnob1_y{ 186 };
    auto modKnob2_y{ modKnob1_y + 78 };
    auto modKnob3_y{ modKnob2_y + 78 };
    auto modKnob4_y{ modKnob3_y + 78 };

    knob_Mod1Amt->setBounds(modKnobs_x, modKnob1_y, knobWidget_w, knobWidget_h);
    knob_Mod2Amt->setBounds(modKnobs_x, modKnob2_y, knobWidget_w, knobWidget_h);
    knob_Mod3Amt->setBounds(modKnobs_x, modKnob3_y, knobWidget_w, knobWidget_h);
    knob_Mod4Amt->setBounds(modKnobs_x, modKnob4_y, knobWidget_w, knobWidget_h);
}
