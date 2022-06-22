#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "constants/constants_GUI_Dimensions.h"
#include "constants/constants_Identifiers.h"
#include "gui/gui_LookAndFeel.h"
#include "gui/gui_layer_EnvelopePainters.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "gui/gui_layer_MainWindowButtons.h"
#include "unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;




PluginEditor::PluginEditor(PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    tooltips{ unexposedParams->getTooltipsOptions() },
    lookAndFeel{ new MophoLookAndFeel() },
    layerForEnvelopePainters{ new GUI_Layer_EnvelopePainters(exposedParams) },
    layerForExposedParamControls{ new GUI_Layer_ExposedParamControls(exposedParams, unexposedParams) },
    layerForButtons{ new GUI_Layer_MainWindowButtons(exposedParams, unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(layerForEnvelopePainters.get());
    addAndMakeVisible(layerForExposedParamControls.get());
    addAndMakeVisible(layerForButtons.get());

    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
    layerForEnvelopePainters->setBounds(getLocalBounds());
    layerForExposedParamControls->setBounds(getLocalBounds());
    layerForButtons->setBounds(getLocalBounds());
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::bkgrnd_MainWindow_png, BinaryData::bkgrnd_MainWindow_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_DelayInMilliseconds) {
        tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    }
}

PluginEditor::~PluginEditor() {
    tooltips->removeListener(this);
    tooltipWindow = nullptr;
    layerForButtons = nullptr;
    layerForExposedParamControls = nullptr;
    layerForEnvelopePainters = nullptr;
}
