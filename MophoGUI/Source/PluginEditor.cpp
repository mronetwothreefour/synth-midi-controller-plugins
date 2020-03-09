#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p) :
    AudioProcessorEditor(&p), 
    processor(p)
{
    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
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
}
