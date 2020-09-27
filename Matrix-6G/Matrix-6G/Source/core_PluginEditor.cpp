#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "midi/midi_QuickPatchEditing.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams }
{
    setSize(1252, 596);
    QuickPatchEditing::sendActivateMessageToUnexposedParamsForHandling(unexposedParams);
}

void PluginEditor::paint(juce::Graphics& g) {
    g.fillAll(Color::device);
    g.setColour(Color::offWhite);
    Font testFont(FontsDB::family_HeavyText, FontsDB::style_ForHeavyText, FontsDB::size_ForSectionHeaderText);
    g.setFont(testFont);
    g.drawFittedText("OSCILLATOR", getLocalBounds(), juce::Justification::centred, 1);
}

void PluginEditor::resized() {
}

PluginEditor::~PluginEditor() {
}
