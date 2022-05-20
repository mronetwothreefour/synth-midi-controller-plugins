#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "constants/constants_GUI_Bounds.h"
#include "unexposedParameters/up_facade_UnexposedParameters.h"

using namespace mophoConstants;




PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams }

{
    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::background_MainWindow_png, BinaryData::background_MainWindow_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& /*property*/) {
}

PluginEditor::~PluginEditor() {
}
