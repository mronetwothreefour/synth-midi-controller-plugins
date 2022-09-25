#include "core_1_PluginEditor.h"

#include "core_0_PluginProcessor.h"
#include "constants/constants_GUI_Dimensions.h"
#include "exposedParameters/ep_3_facade_ExposedParameters.h"
#include "gui/gui_layer_CurrentVoiceNameAndNumber.h"
#include "gui/gui_layer_EnvelopePainters.h"
#include "gui/gui_layer_ExposedParamControls.h"
#include "gui/gui_layer_MainWindowButtons.h"
#include "gui/gui_layer_TrackingGraphPainter.h"
#include "gui/gui_MatrixLookAndFeel.h"
#include "matrixMod/mMod_3_gui_layer_MatrixMod.h"
#include "unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

PluginEditor::PluginEditor (PluginProcessor& processor, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    layer_EnvelopePainters{ new GUI_Layer_EnvelopePainters{ exposedParams } },
    layer_TrackingGraphPainter{ new GUI_Layer_TrackingGraphPainter{ exposedParams } },
    layer_ExposedParamControls{ new GUI_Layer_ExposedParamControls{ exposedParams, unexposedParams } },
    layer_MatrixMod{ new GUI_Layer_MatrixMod{ exposedParams, unexposedParams->getTooltipsOptions() } },
    layer_CurrentVoiceNameAndNumber{ new GUI_Layer_CurrentVoiceNameAndNumber{ exposedParams, unexposedParams->getTooltipsOptions()}},
    layer_MainWindowButtons{ new GUI_Layer_MainWindowButtons{ exposedParams, unexposedParams } },
    lookAndFeel{ new MatrixLookAndFeel{} },
    tooltipsDelayInMillisecondsAsValue{ unexposedParams->getTooltipsOptions()->getTooltipsPropertyAsValue(ID::tooltips_DelayInMilliseconds) },
    tooltipWindow{ new TooltipWindow{} }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    layer_EnvelopePainters->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_EnvelopePainters.get());

    layer_TrackingGraphPainter->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_TrackingGraphPainter.get());

    layer_ExposedParamControls->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_ExposedParamControls.get());

    layer_MatrixMod->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_MatrixMod.get());

    layer_CurrentVoiceNameAndNumber->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_CurrentVoiceNameAndNumber.get());

    layer_MainWindowButtons->setBounds(0, 0, GUI::editor_w, GUI::editor_h);
    addAndMakeVisible(layer_MainWindowButtons.get());

    tooltipsDelayInMillisecondsAsValue.addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsAsValue.getValue());
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
    tooltipWindow->setMillisecondsBeforeTipAppears((int)tooltipsDelayInMillisecondsAsValue.getValue());
}

PluginEditor::~PluginEditor() {
    layer_EnvelopePainters = nullptr;
    layer_TrackingGraphPainter = nullptr;
    layer_ExposedParamControls = nullptr;
    layer_MatrixMod = nullptr;
    layer_MainWindowButtons = nullptr;
    layer_CurrentVoiceNameAndNumber = nullptr;
    tooltipsDelayInMillisecondsAsValue.removeListener(this);
    tooltipWindow = nullptr;
}
