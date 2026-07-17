#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Constants.h"
#include "gui/gui_Layer_Buttons.h"
#include "gui/gui_Layer_ExposedParamsControls.h"
#include "gui/gui_Layer_VoiceNumber.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"

using namespace constants;



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    buttonsLayer{ new ButtonsLayer(exposedParams, unexposedParams) },
    exposedParamsControlsLayer{ new ExposedParamsControlsLayer(exposedParams, unexposedParams) },
    voiceNumberLayer{ new VoiceNumberLayer(unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(exposedParamsControlsLayer.get());
    addAndMakeVisible(voiceNumberLayer.get());
    addAndMakeVisible(buttonsLayer.get());

    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::P600GMainWindowBackground_png, BinaryData::P600GMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
    buttonsLayer->setBounds(getLocalBounds());
    exposedParamsControlsLayer->setBounds(getLocalBounds());
    voiceNumberLayer->setBounds(getLocalBounds());
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
    voiceNumberLayer = nullptr;
    exposedParamsControlsLayer = nullptr;
    buttonsLayer = nullptr;
}
