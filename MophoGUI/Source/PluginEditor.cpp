#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginEditor::PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters) :
    AudioProcessorEditor{ &p },
    processor{ p },
    privateParams{ privateParameters }
{
    mophoLaF.reset(new MophoLookAndFeel());

    sectionOsc.reset(new OscillatorsSection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionOsc.get());

    sectionLPF.reset(new LPFSection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionLPF.get());

    sectionVCA.reset(new VCASection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionVCA.get());

    sectionEnv3.reset(new Env3Section(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionEnv3.get());

    sectionMod.reset(new ModulatorsSection(publicParams, privateParameters, mophoLaF.get()));
    addAndMakeVisible(sectionMod.get());

    tooltipWindow.setMillisecondsBeforeTipAppears(privateParams->getTooltipDelay());
    tooltipWindow.setLookAndFeel(mophoLaF.get());
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
}

PluginEditor::~PluginEditor()
{
    tooltipWindow.setLookAndFeel(nullptr);

    sectionMod = nullptr;
    sectionEnv3 = nullptr;
    sectionVCA = nullptr;
    sectionLPF = nullptr;
    sectionOsc = nullptr;

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
    sectionOsc->setBounds(15, 15, sectionOsc->getWidth(), sectionOsc->getHeight());
    sectionLPF->setBounds(15, 154, sectionLPF->getWidth(), sectionLPF->getHeight());
    sectionVCA->setBounds(15, 312, sectionLPF->getWidth(), sectionLPF->getHeight());
    sectionEnv3->setBounds(15, 470, sectionLPF->getWidth(), sectionLPF->getHeight());
    sectionMod->setBounds(404, 154, sectionMod->getWidth(), sectionMod->getHeight());
}
