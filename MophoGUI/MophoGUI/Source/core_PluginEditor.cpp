#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "gui/gui_InfoForMainWindowLabels_Singleton.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& g) {
    g.fillAll(Color::device);
    g.setColour(Color::controlLabelText);
    auto& info{ InfoForMainWindowLabels::get() };
    for (uint16 label = 0; label != info.labelOutOfRange(); ++label) {
        Font font{ FontsDB::family_Global, FontsDB::style_ForControlLabels, info.fontSizeFor(label) };
        g.setFont(font);
        Rectangle<int> labelArea{ info.widthFor(label), info.heightFor(label) };
        labelArea.setCentre(info.centerPointFor(label));
        g.drawFittedText(info.textFor(label), labelArea, info.justificationFlagFor(label), 1, 1.0f);
    }
    g.drawHorizontalLine(85, 15.0f, 295.0f);
    Rectangle<int> pgmNameBackground{ 580, 33, 242, 37 };
    g.fillRect(pgmNameBackground);
}

void PluginEditor::resized() {
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
    LookAndFeel::setDefaultLookAndFeel(nullptr);
    lookAndFeel = nullptr;
}
