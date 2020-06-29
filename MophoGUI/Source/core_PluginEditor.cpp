#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    div_Logo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(div_Logo.get());

    auto& exposedParamsDB{ ExposedSynthParametersDatabase::get() };
    auto& controlDB{ ControlWithPublicParameterAttacherDatabase::get() };
    for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
    {
        auto param{ exposedParamsDB.getSynthParameter(index) };
        auto control{ controlDB.getControl(index) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(processor.exposedParams.get(), param.ID);
        control->setCentrePosition(param.centerPoint);
    }

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    auto& exposedParamsDB{ ExposedSynthParametersDatabase::get() };
    auto& controlDB{ ControlWithPublicParameterAttacherDatabase::get() };
    for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
    {
        auto control{ controlDB.getControl(index) };
        control->deleteAttachment();
    }

    div_Logo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
}

//==============================================================================
void PluginEditor::paint(Graphics& g)
{
    g.fillAll(Color::device);
}

void PluginEditor::resized()
{
    div_Logo->setBounds(836, 0, div_Logo->getWidth(), div_Logo->getHeight());
}
