#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p) :
    AudioProcessorEditor{ &p }, 
    processor{ p }
{
    setSize(400, 300);
}

PluginEditor::~PluginEditor()
{
}

//==============================================================================
void PluginEditor::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setColour(Colours::white);
    g.setFont(15.0f);
    g.drawFittedText(ID::pitchOsc1.toString(), getLocalBounds(), Justification::centred, 1);
}

void PluginEditor::resized()
{
}
