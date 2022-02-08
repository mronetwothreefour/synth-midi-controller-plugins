#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Constants.h"
#include "gui/gui_Layer_Buttons.h"
#include "gui/gui_Layer_EnvelopeRenderers.h"
#include "gui/gui_Layer_ExposedParamControls.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"

using namespace constants;



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    envelopeRenderersLayer{ new EnvelopeRenderersLayer(exposedParams) },
    exposedParamsControlsLayer{ new ExposedParamsControlsLayer(exposedParams, unexposedParams) },
    buttonsLayer{ new ButtonsLayer(exposedParams, unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(envelopeRenderersLayer.get());
    addAndMakeVisible(exposedParamsControlsLayer.get());
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
    MemoryInputStream memInputStream{ BinaryData::MophoGUIMainWindowBackground_png, BinaryData::MophoGUIMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
    envelopeRenderersLayer->setBounds(getLocalBounds());
    exposedParamsControlsLayer->setBounds(getLocalBounds());
    buttonsLayer->setBounds(getLocalBounds());
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
    buttonsLayer = nullptr;
    exposedParamsControlsLayer = nullptr;
    envelopeRenderersLayer = nullptr;
}
