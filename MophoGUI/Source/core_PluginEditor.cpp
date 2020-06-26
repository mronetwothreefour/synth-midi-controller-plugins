#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p) :
    AudioProcessorEditor{ &p }, 
    processor{ p }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    div_Logo.reset(new MainWindowDivision_Logo());
    addAndMakeVisible(div_Logo.get());

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
