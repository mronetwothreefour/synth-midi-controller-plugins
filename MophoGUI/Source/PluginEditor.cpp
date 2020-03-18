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

    Rectangle<int> vcaSectionLabelArea{ 15, 292, 30, 15 };
    g.drawText("VCA", vcaSectionLabelArea, Justification::centredLeft);

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
    auto ctrl_w{ 40 };
    auto ctrlGap{ 5 };
    auto ctrl_col1_x{ 28 };
    auto ctrl_col2_x{ ctrl_col1_x + ctrl_w + ctrlGap };
    auto ctrl_col3_x{ ctrl_col2_x + ctrl_w + ctrlGap };
    auto ctrl_col4_x{ ctrl_col3_x + ctrl_w + ctrlGap };
    auto ctrl_col5_x{ ctrl_col4_x + ctrl_w + ctrlGap };
    auto ctrl_col6_x{ ctrl_col5_x + ctrl_w + ctrlGap };
    auto ctrl_col7_x{ ctrl_col6_x + ctrl_w + ctrlGap };
    auto ctrl_col8_x{ ctrl_col7_x + ctrl_w + ctrlGap };
    auto ctrl_col9_x{ ctrl_col8_x + ctrl_w + ctrlGap };

    auto ctrl_row1_y{ 30  };
    auto ctrl_row2_y{ 90  };
    auto ctrl_row3_y{ 170 };
    auto ctrl_row4_y{ 227 };
    auto ctrl_row5_y{ 308 };
    auto ctrl_row6_y{ 365 };

    auto knobWidget_w{ knob_Osc1Pitch->getWidth() };
    auto knobWidget_h{ knob_Osc1Pitch->getHeight() };

    knob_Osc1Pitch->setBounds       (ctrl_col1_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1FineTune->setBounds    (ctrl_col2_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Shape->setBounds       (ctrl_col3_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Glide->setBounds       (ctrl_col4_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_SubOsc1Lvl->setBounds      (ctrl_col5_x, ctrl_row1_y, knobWidget_w, knobWidget_h);

    knob_Osc2Pitch->setBounds       (ctrl_col1_x, ctrl_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2FineTune->setBounds    (ctrl_col2_x, ctrl_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2Shape->setBounds       (ctrl_col3_x, ctrl_row2_y, knobWidget_w, knobWidget_h);
    knob_Osc2Glide->setBounds       (ctrl_col4_x, ctrl_row2_y, knobWidget_w, knobWidget_h);
    knob_SubOsc2Lvl->setBounds      (ctrl_col5_x, ctrl_row2_y, knobWidget_w, knobWidget_h);

    knob_OscSlop->setBounds         (ctrl_col7_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_OscMix->setBounds          (ctrl_col8_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_BendRange->setBounds       (ctrl_col9_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_NoiseLevel->setBounds      (ctrl_col7_x, ctrl_row2_y, knobWidget_w, knobWidget_h);
    knob_ExtInLevel->setBounds      (ctrl_col8_x, ctrl_row2_y, knobWidget_w, knobWidget_h);

    knob_LPFfreq->setBounds         (ctrl_col1_x, ctrl_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFreso->setBounds         (ctrl_col2_x, ctrl_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFkeyAmt->setBounds       (ctrl_col3_x, ctrl_row3_y, knobWidget_w, knobWidget_h);
    knob_LPFenvAmt->setBounds       (ctrl_col1_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFvelAmt->setBounds       (ctrl_col2_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFfmAmt->setBounds        (ctrl_col3_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvDelay->setBounds     (ctrl_col4_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvAttack->setBounds    (ctrl_col5_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvDecay->setBounds     (ctrl_col6_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvSustain->setBounds   (ctrl_col7_x, ctrl_row4_y, knobWidget_w, knobWidget_h);
    knob_LPFenvRelease->setBounds   (ctrl_col8_x, ctrl_row4_y, knobWidget_w, knobWidget_h);

    knob_VCAlevel->setBounds        (ctrl_col1_x, ctrl_row5_y, knobWidget_w, knobWidget_h);
    knob_VCAenvAmt->setBounds       (ctrl_col2_x, ctrl_row5_y, knobWidget_w, knobWidget_h);
    knob_VCAvelAmt->setBounds       (ctrl_col3_x, ctrl_row5_y, knobWidget_w, knobWidget_h);
    knob_PgmVolume->setBounds       (ctrl_col2_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvDelay->setBounds     (ctrl_col4_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvAttack->setBounds    (ctrl_col5_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvDecay->setBounds     (ctrl_col6_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvSustain->setBounds   (ctrl_col7_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
    knob_VCAenvRelease->setBounds   (ctrl_col8_x, ctrl_row6_y, knobWidget_w, knobWidget_h);
}
