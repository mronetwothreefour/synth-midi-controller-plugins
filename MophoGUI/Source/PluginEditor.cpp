#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams) :
    AudioProcessorEditor(&p), 
    processor(p)
{
    lookAndFeel_Knob.reset(new LaF_Knob);

    knob_Osc1Pitch.reset(new KnobWidget_OscPitch("Pitch", publicParams, ID::osc1Pitch, lookAndFeel_Knob.get()));
    addAndMakeVisible(knob_Osc1Pitch.get());

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    knob_Osc1Pitch = nullptr;

    lookAndFeel_Knob = nullptr;
}

//==============================================================================
void PluginEditor::paint(Graphics& g)
{
    g.fillAll(Color::device);

    g.setColour(Color::black);

    // Draw section labels
    //==============================================================================
    Font sectionLabel{ "Arial", "Black", JUCE_LIVE_CONSTANT(18.0f) };
    g.setFont(sectionLabel);

    Rectangle<int> oscSectionLabelArea{ 15, 15, 105, 15 };
    g.drawText("OSCILLATORS", oscSectionLabelArea, Justification::centredLeft);

    Rectangle<int> lpfSectionLabelArea{ 15, 150, 30, 15 };
    g.drawText("LPF", lpfSectionLabelArea, Justification::centredLeft);
}

void PluginEditor::resized()
{
    knob_Osc1Pitch->setBounds(28, 30, knob_Osc1Pitch->getWidth(), knob_Osc1Pitch->getHeight());
}
