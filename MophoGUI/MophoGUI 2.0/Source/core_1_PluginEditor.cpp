#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "gui/gui_layer_EnvelopePainters.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "gui/gui_layer_MainWindowButtons.h"
#include "gui/gui_MophoLookAndFeel.h"
#include "unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

PluginEditor::PluginEditor(PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    layer_EnvelopePainters{ new GUI_Layer_EnvelopePainters{ exposedParams } },
    layer_ExposedParamControls{ new GUI_Layer_ExposedParamControls{ exposedParams, unexposedParams->getTooltipsOptions() } },
    layer_Buttons{ new GUI_Layer_MainWindowButtons(exposedParams, unexposedParams) },
    lookAndFeel{ new MophoLookAndFeel{} },
    tooltipsDelayInMillisecondsAsValue{ unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_DelayInMilliseconds) },
    tooltipWindow{ new TooltipWindow{} }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    layer_EnvelopePainters->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_EnvelopePainters.get());

    layer_ExposedParamControls->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_ExposedParamControls.get());

    layer_Buttons->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_Buttons.get());

    tooltipsDelayInMillisecondsAsValue.addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsAsValue.getValue());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);

    callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::bkgrnd_MainWindow_png, BinaryData::bkgrnd_MainWindow_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::timerCallback() {
}

void PluginEditor::valueChanged(Value& /*value*/) {
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsAsValue.getValue());
}

PluginEditor::~PluginEditor() {
    layer_EnvelopePainters = nullptr;
    layer_ExposedParamControls = nullptr;
    layer_Buttons = nullptr;
    tooltipsDelayInMillisecondsAsValue.removeListener(this);
    tooltipWindow = nullptr;
}
