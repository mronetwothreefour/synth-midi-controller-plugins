#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Logo.h"
#include "gui/gui_Layer_DividerLines.h"
#include "gui/gui_Layer_SectionHeaders.h"
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
    dividerLinesLayer{ new DividerLinesLayer() },
    sectionHeadersLayer{ new SectionHeadersLayer() },
    logo{ new Logo() },
    button_ForActivatingQuickPatchEdit{ new ButtonForActivatingQuickPatchEdit(unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(dividerLinesLayer.get());
    addAndMakeVisible(sectionHeadersLayer.get());
    addAndMakeVisible(logo.get());

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
    g.fillAll(Color::device);
}

void PluginEditor::resized() {
    dividerLinesLayer->setBounds(getLocalBounds());
    sectionHeadersLayer->setBounds(getLocalBounds());
    logo->setBounds(605, 320, logo->getWidth(), logo->getHeight());
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
    logo = nullptr;
    sectionHeadersLayer = nullptr;
    dividerLinesLayer = nullptr;
}
