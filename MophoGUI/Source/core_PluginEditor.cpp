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
    auto& paramDB{ SynthParametersDatabase::get() };
    auto param{ paramDB.getSynthParameter(1) };
    g.drawFittedText(param.publicName, getLocalBounds(), Justification::centred, 1);
}

void PluginEditor::resized()
{
}
