#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "constants/constants_Identifiers.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "gui/gui_P_600_LookAndFeel.h"
#include "unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

PluginEditor::PluginEditor(PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    layer_ExposedParamControls{ new GUI_Layer_ExposedParamControls{ exposedParams, unexposedParams } },
    lookAndFeel{ new P_600_LookAndFeel{} },
    tooltipsDelayInMillisecondsValue{ unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_DelayInMilliseconds) },
    tooltipWindow{ new TooltipWindow{} }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    layer_ExposedParamControls->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_ExposedParamControls.get());

    tooltipsDelayInMillisecondsValue.addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsValue.getValue());
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
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsValue.getValue());
}

PluginEditor::~PluginEditor() {
    layer_ExposedParamControls = nullptr;
    tooltipsDelayInMillisecondsValue.removeListener(this);
    tooltipWindow = nullptr;
}
