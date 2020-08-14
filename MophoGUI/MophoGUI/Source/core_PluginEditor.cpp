#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "gui/gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "gui/gui_InfoForMainWindowLabels_Singleton.h"
#include "gui/gui_Logo.h"
#include "gui/gui_LookAndFeel.h"
#include "guiRenderers/guiRenderer_ForEnvelopes.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    ControlsForExposedParameters{ unexposedParams },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    logo{ new Logo() },
    rendererForEnvelope_LPF{ new RendererForEnvelopes("lpf", exposedParams) },
    rendererForEnvelope_VCA{ new RendererForEnvelopes("vca", exposedParams) },
    rendererForEnvelope_Env3{ new RendererForEnvelopes("env3", exposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(logo.get());

    rebuildControls(unexposedParams);
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(InfoForExposedParameters::get().ctrlCenterPointFor(param));
    }

    addAndMakeVisible(rendererForEnvelope_LPF.get());
    addAndMakeVisible(rendererForEnvelope_VCA.get());
    addAndMakeVisible(rendererForEnvelope_Env3.get());

    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
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
    logo->setBounds(880, 0, logo->getWidth(), logo->getHeight());
    auto envRenderers_x{ 168 };
    rendererForEnvelope_LPF->setBounds(envRenderers_x, 154, rendererForEnvelope_LPF->getWidth(), rendererForEnvelope_LPF->getHeight());
    rendererForEnvelope_VCA->setBounds(envRenderers_x, 312, rendererForEnvelope_VCA->getWidth(), rendererForEnvelope_VCA->getHeight());
    rendererForEnvelope_Env3->setBounds(envRenderers_x, 470, rendererForEnvelope_Env3->getWidth(), rendererForEnvelope_Env3->getHeight());
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
    rendererForEnvelope_Env3 = nullptr;
    rendererForEnvelope_VCA = nullptr;
    rendererForEnvelope_LPF = nullptr;
    for (uint8 param = 0; param != paramOutOfRange(); ++param) {
        auto control{ controlFor(param) };
        control->deleteAttachment();
    }
    clearControls();
    logo = nullptr;
}
