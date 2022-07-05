#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "constants/constants_Identifiers.h"
#include "gui/gui_layer_EnvelopePainters.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "gui/gui_LookAndFeel.h"
#include "unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



PluginEditor::PluginEditor (PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor (&processor), 
    processor (processor),
    tooltips{ unexposedParams->getTooltipsOptions() },
    lookAndFeel{ new MophoLookAndFeel() },
    layer_EnvelopePainters{ new GUI_Layer_EnvelopePainters(exposedParams) },
    layer_ExposedParamControls{ new GUI_Layer_ExposedParamControls(exposedParams, unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    layer_EnvelopePainters->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_EnvelopePainters.get());

    layer_ExposedParamControls->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_ExposedParamControls.get());

    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint (Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::bkgrnd_MainWindow_png, BinaryData::bkgrnd_MainWindow_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
    if (propertyID == ID::tooltips_DelayInMilliseconds) {
        tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    }
}

PluginEditor::~PluginEditor() {
    layer_EnvelopePainters = nullptr;
    layer_ExposedParamControls = nullptr;
    tooltips->removeListener(this);
    tooltipWindow = nullptr;
}
