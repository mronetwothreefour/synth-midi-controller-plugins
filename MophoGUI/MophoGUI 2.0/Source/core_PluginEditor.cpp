#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"




PluginEditor::PluginEditor(PluginProcessor& processor/*, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams*/) :
    AudioProcessorEditor{ &processor },
    processor{ processor }/*,
    exposedParams{ exposedParams }*/
{
    setSize(400, 200);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& /*g*/) {
}

void PluginEditor::resized() {
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& /*property*/) {
}

PluginEditor::~PluginEditor() {
}
