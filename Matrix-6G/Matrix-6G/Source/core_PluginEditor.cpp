#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Layer_Controls.h"
#include "gui/gui_LookAndFeel.h"
#include "midi/midi_QuickPatchEditing.h"
#include "params/params_Identifiers.h"
#include "widgets_Button/widget_ButtonForActivatingQuickPatchEdit.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    controlsLayer{ new ControlsLayer(exposedParams, unexposedParams) },
    button_ForActivatingQuickPatchEdit{ new ButtonForActivatingQuickPatchEdit(unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(controlsLayer.get());

    addAndMakeVisible(button_ForActivatingQuickPatchEdit.get());

    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    auto device_w{ 1252 };
    auto device_h{ 596 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::Matrix6GMainWindowBackground_png, BinaryData::Matrix6GMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
    controlsLayer->setBounds(getLocalBounds());
    auto smallButtons_y{ 367 };
    auto smallButtons_h{ 20 };
    button_ForActivatingQuickPatchEdit->setBounds(597, smallButtons_y, 78, smallButtons_h);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto tooltips{ unexposedParams->tooltipOptions_get() };
        tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    }
}

PluginEditor::~PluginEditor() {
    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->removeListener(this);
    tooltipWindow = nullptr;
    button_ForActivatingQuickPatchEdit = nullptr;
    controlsLayer = nullptr;
}
