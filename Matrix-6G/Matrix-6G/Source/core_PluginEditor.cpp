#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Constants.h"
#include "gui/gui_Layer_Buttons.h"
#include "gui/gui_Layer_EnvelopeRenderers.h"
#include "gui/gui_Layer_ExposedParamsControls.h"
#include "gui/gui_Layer_MatrixMod.h"
#include "gui/gui_Layer_PatchNumberAndName.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"

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
    matrixModLayer{ new MatrixModLayer(unexposedParams) },
    patchNumberAndNameLayer{ new PatchNumberAndNameLayer(unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(envelopeRenderersLayer.get());
    addAndMakeVisible(exposedParamsControlsLayer.get());
    addAndMakeVisible(buttonsLayer.get());
    addAndMakeVisible(matrixModLayer.get());
    addAndMakeVisible(patchNumberAndNameLayer.get());

    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    setSize(GUI::editor_w, GUI::editor_h);
    setResizable(false, false);
}

void PluginEditor::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::Matrix6GMainWindowBackground_png, BinaryData::Matrix6GMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
    envelopeRenderersLayer->setBounds(getLocalBounds());
    exposedParamsControlsLayer->setBounds(getLocalBounds());
    buttonsLayer->setBounds(getLocalBounds());
    matrixModLayer->setBounds(getLocalBounds());
    patchNumberAndNameLayer->setBounds(getLocalBounds());
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
    patchNumberAndNameLayer = nullptr;
    matrixModLayer = nullptr;
    buttonsLayer = nullptr;
    exposedParamsControlsLayer = nullptr;
    envelopeRenderersLayer = nullptr;
}
