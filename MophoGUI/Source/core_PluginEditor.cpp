#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    widget_Logo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(widget_Logo.get());

    auto& controls{ ControlsForExposedParameters::get() };
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(InfoForExposedParameters::get().ctrlCenterPointFor(param));
    }

    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.addListener(this);
    auto tooltipsDelay{ (int)tooltipOptions.getProperty(ID::tooltips_DelayInMilliseconds) };
    tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor() {
    auto& tooltipOptions{ TooltipOptions_Singleton::get() };
    tooltipOptions.removeListener(this);

    auto& controls{ ControlsForExposedParameters::get() };
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        control->deleteAttachment();
    }

    widget_Logo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
}

void PluginEditor::paint(Graphics& g) {
    g.fillAll(Color::device);
}

void PluginEditor::resized() {
    widget_Logo->setBounds(836, 0, widget_Logo->getWidth(), widget_Logo->getHeight());
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property)
{
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto& tooltipOptions{ TooltipOptions_Singleton::get() };
        auto tooltipsDelay{ (int)tooltipOptions.getProperty(property) };
        tooltipWindow.setMillisecondsBeforeTipAppears(tooltipsDelay);
    }
}
