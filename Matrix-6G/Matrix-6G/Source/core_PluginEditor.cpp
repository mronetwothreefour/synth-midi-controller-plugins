#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "gui/gui_Logo.h"
#include "midi/midi_QuickPatchEditing.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    logo{ new Logo() }
{
    addAndMakeVisible(logo.get());

    setSize(1252, 596);
    QuickPatchEditing::sendActivateMessageToUnexposedParamsForHandling(unexposedParams);
}

void PluginEditor::paint(juce::Graphics& g) {
    g.fillAll(Color::device);
}

void PluginEditor::resized() {
    logo->setBounds(605, 320, logo->getWidth(), logo->getHeight());
}

PluginEditor::~PluginEditor() {
    logo = nullptr;
}
