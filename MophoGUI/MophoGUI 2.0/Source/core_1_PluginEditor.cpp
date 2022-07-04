#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "constants/constants_Identifiers.h"
#include "gui/gui_LookAndFeel.h"

using namespace MophoConstants;



PluginEditor::PluginEditor (PluginProcessor& processor) :
    AudioProcessorEditor (&processor), 
    processor (processor),
    lookAndFeel{ new MophoLookAndFeel() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint (Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::bkgrnd_MainWindow_png, BinaryData::bkgrnd_MainWindow_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& /*propertyID*/) {
}

PluginEditor::~PluginEditor()
{
}
