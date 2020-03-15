#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters) :
    AudioProcessorEditor{ &p },
    processor{ p },
    privateParams{ privateParameters }
{
    mophoLaF.reset(new MophoLookAndFeel());

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

    Rectangle<int> lpfSectionLabelArea{ 15, 150, 30, 15 };
    g.drawText("LPF", lpfSectionLabelArea, Justification::centredLeft);

    // Draw oscillator number labels
    //==============================================================================
    Font oscNumLabel{ "Arial", "Black", 24.0f };
    g.setFont(oscNumLabel);

    Rectangle<int> oscNumLabelArea{ 15, 35, 15, 30 };
    g.drawText("1", oscNumLabelArea, Justification::centredLeft);
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

    auto ctrl_row1_y{ 30 };

    auto knobWidget_w{ knob_Osc1Pitch->getWidth() };
    auto knobWidget_h{ knob_Osc1Pitch->getHeight() };

    knob_Osc1Pitch->setBounds       (ctrl_col1_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1FineTune->setBounds    (ctrl_col2_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Shape->setBounds       (ctrl_col3_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_Osc1Glide->setBounds       (ctrl_col4_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
    knob_SubOsc1Lvl->setBounds      (ctrl_col5_x, ctrl_row1_y, knobWidget_w, knobWidget_h);
}
