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

    addAndMakeVisible(pitchOsc1);
    pitchOsc1.setCentrePosition(33, 35);
    pitchOsc1.attachToPublicParameter(processor.exposedParams.get(), ID::pitchOsc1);
    //auto& exposedParamsDB{ ExposedSynthParametersDatabase::get() };
    //for (uint8 index = 0; index != exposedParamsDB.size(); ++index)
    //{
    //    auto param{ exposedParamsDB.getSynthParameter(index) };
        //auto controlType{ ControlType(param.controlType) };
        //if (controlType == ControlType::knobWithValueStringDisplay)
        //{
        //    KnobWithValueStringDisplay knobWithValueStringDisplay;
        //    addAndMakeVisible(knobWithValueStringDisplay);
        //    knobWithValueStringDisplay.attachToPublicParameter(processor.exposedParams.get(), Identifier(param.ID));
        //    knobWithValueStringDisplay.setCentrePosition(Point<int>(33, 35));
        //}
    //}

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
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
