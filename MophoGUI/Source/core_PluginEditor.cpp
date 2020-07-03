#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    div_Logo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(div_Logo.get());

    auto& exposedParamsDB{ ExposedSynthParameters_Database::get() };
    auto& controlDB{ ControlWithExposedParameterAttachment_Database::get() };
    for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
    {
        auto param{ exposedParamsDB.getSynthParameter(index) };
        auto control{ controlDB.getControl(index) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(param.centerPoint);
    }

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor() {
    auto& exposedParamsDB{ ExposedSynthParameters_Database::get() };
    auto& controlDB{ ControlWithExposedParameterAttachment_Database::get() };
    for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
    {
        auto control{ controlDB.getControl(index) };
        control->deleteAttachment();
    }

    div_Logo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
}

void PluginEditor::paint(Graphics& g) {
    g.fillAll(Color::device);
}

void PluginEditor::resized() {
    div_Logo->setBounds(836, 0, div_Logo->getWidth(), div_Logo->getHeight());
}
