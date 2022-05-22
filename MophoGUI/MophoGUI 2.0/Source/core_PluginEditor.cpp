#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "constants/constants_GUI_Dimensions.h"
#include "gui/gui_LookAndFeel.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;




PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new MophoLookAndFeel() },
    layerForExposedParamControls{ new GUI_Layer_ExposedParamControls(exposedParams, unexposedParams) }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(layerForExposedParamControls.get());

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
    layerForExposedParamControls->setBounds(getLocalBounds());
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& /*property*/) {
}

PluginEditor::~PluginEditor() {
    layerForExposedParamControls = nullptr;
}
