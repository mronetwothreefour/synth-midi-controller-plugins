#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    mophoguiLogo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(mophoguiLogo.get());

    auto& controls{ ControlsForExposedParameters::get() };
    controls.rebuildControls();
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(InfoForExposedParameters::get().ctrlCenterPointFor(param));
    }

    envelopeRenderer_LPF.reset(new EnvelopeRenderer("lpf", exposedParams));
    envelopeRenderer_VCA.reset(new EnvelopeRenderer("vca", exposedParams));
    envelopeRenderer_Env3.reset(new EnvelopeRenderer("env3", exposedParams));
    addAndMakeVisible(envelopeRenderer_LPF.get());
    addAndMakeVisible(envelopeRenderer_VCA.get());
    addAndMakeVisible(envelopeRenderer_Env3.get());

    button_ForEditingPgmName.reset(new ButtonAndLabelForEditingPgmName(processor));
    addAndMakeVisible(button_ForEditingPgmName.get());

    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.addListener(this);
    auto tooltipsDelay{ (int)tooltipOptions.getProperty(ID::tooltips_DelayInMilliseconds) };
    tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

PluginEditor::~PluginEditor() {
    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.removeListener(this);

    button_ForEditingPgmName = nullptr;
    envelopeRenderer_Env3 = nullptr;
    envelopeRenderer_VCA = nullptr;
    envelopeRenderer_LPF = nullptr;

    auto& controls{ ControlsForExposedParameters::get() };
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        control->deleteAttachment();
    }

    controls.clear();

    mophoguiLogo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
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
    mophoguiLogo->setBounds(836, 0, mophoguiLogo->getWidth(), mophoguiLogo->getHeight());
    auto envelopeRenderers_x{ 168 };
    envelopeRenderer_LPF->setBounds(envelopeRenderers_x, 154, envelopeRenderer_LPF->getWidth(), envelopeRenderer_LPF->getHeight());
    envelopeRenderer_VCA->setBounds(envelopeRenderers_x, 312, envelopeRenderer_VCA->getWidth(), envelopeRenderer_VCA->getHeight());
    envelopeRenderer_Env3->setBounds(envelopeRenderers_x, 470, envelopeRenderer_Env3->getWidth(), envelopeRenderer_Env3->getHeight());
    button_ForEditingPgmName->setBounds(590, 11, button_ForEditingPgmName->getWidth(), button_ForEditingPgmName->getHeight());
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property)
{
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto& tooltipOptions{ TooltipOptions_Singleton::get() };
        auto tooltipsDelay{ (int)tooltipOptions.getProperty(property) };
        tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    }
}

