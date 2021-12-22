#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Constants.h"

using namespace constants;



PluginEditor::PluginEditor (PluginProcessor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint (juce::Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::P600GMainWindowBackground_png, BinaryData::P600GMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
}

PluginEditor::~PluginEditor() {
}
