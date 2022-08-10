#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "constants/constants_Identifiers.h"
#include "unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

PluginEditor::PluginEditor (PluginProcessor& processor, ExposedParameters* /*exposedParams*/, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    tooltipsDelayInMillisecondsValue{ unexposedParams->getTooltipsOptions()->getTooltipsPropertyValue(ID::tooltips_DelayInMilliseconds) },
    tooltipWindow{ new TooltipWindow{} }
{
    tooltipsDelayInMillisecondsValue.addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsValue.getValue());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);

    callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void PluginEditor::paint (Graphics& g) {
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
    tooltipsDelayInMillisecondsValue.removeListener(this);
    tooltipWindow = nullptr;
}
