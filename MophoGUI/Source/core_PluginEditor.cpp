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

    div_Osc.reset(new MainWindowDivision_Oscillators(processor));
    addAndMakeVisible(div_Osc.get());

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    div_Osc = nullptr;
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
    div_Osc->setBounds(0, 0, div_Osc->getWidth(), div_Osc->getHeight());
}
