#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"



PluginEditor::PluginEditor(PluginProcessor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    setSize(1256, 612);
}

void PluginEditor::paint(juce::Graphics& g) {
    g.fillAll(Color::device);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void PluginEditor::resized() {
}

PluginEditor::~PluginEditor() {
}
