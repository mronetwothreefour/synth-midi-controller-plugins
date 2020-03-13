#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams) :
    AudioProcessorEditor(&p), 
    processor(p)
{
    mophoLaF.reset(new MophoLookAndFeel());

    knob_Osc1Pitch.reset(new KnobWidget_OscPitch(publicParams, ID::osc1Pitch, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1Pitch.get());

    knob_Osc1FineTune.reset(new KnobWidget_FineTune(publicParams, ID::osc1Fine, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1FineTune.get());

    knob_Osc1Shape.reset(new KnobWidget_OscShape(publicParams, ID::osc1Shape, mophoLaF.get()));
    addAndMakeVisible(knob_Osc1Shape.get());

    tooltipWindow.setMillisecondsBeforeTipAppears(1000);
    tooltipWindow.setLookAndFeel(mophoLaF.get());
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    tooltipWindow.setLookAndFeel(nullptr);

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
}

void PluginEditor::resized()
{
    auto ctrl_col1_x{ 28 };
    auto ctrl_col2_x{ ctrl_col1_x + 45 };
    auto ctrl_col3_x{ ctrl_col2_x + 45 };

    auto ctrl_row1_y{ 30 };

    knob_Osc1Pitch->setBounds(ctrl_col1_x, ctrl_row1_y, knob_Osc1Pitch->getWidth(), knob_Osc1Pitch->getHeight());
    knob_Osc1FineTune->setBounds(ctrl_col2_x, ctrl_row1_y, knob_Osc1FineTune->getWidth(), knob_Osc1FineTune->getHeight());
    knob_Osc1Shape->setBounds(ctrl_col3_x, ctrl_row1_y, knob_Osc1FineTune->getWidth(), knob_Osc1FineTune->getHeight());
}
