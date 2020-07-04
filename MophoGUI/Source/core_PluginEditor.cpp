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


    auto& controls{ ControlsForExposedParameters_Singleton::get() };
    for (uint8 index = 0; index != controls.size(); ++index)
    {
        auto& paramInfoArray{ ExposedParamInfoArray_Singleton::get() };
        auto param{ paramInfoArray[index] };
        auto control{ controls[index].get() };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(param.centerPoint);
    }

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor() {
    auto& paramInfoArray{ ExposedParamInfoArray_Singleton::get() };
    auto& controls{ ControlsForExposedParameters_Singleton::get() };
    for (uint8 index = 0; index != paramInfoArray.size(); ++index)
    {
        auto control{ controls[index].get() };
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
