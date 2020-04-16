#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

#include "helpers/CustomColors.h"
#include "helpers/MophoLookAndFeel.h"
#include "parameters/PrivateParameters.h"
#include "editorSections/Env3Section.h"
#include "editorSections/KnobAssignSection.h"
#include "editorSections/LFOSection.h"
#include "editorSections/LPFSection.h"
#include "editorSections/MidiControllersSection.h"
#include "editorSections/ModulatorsSection.h"
#include "editorSections/OscillatorsSection.h"
#include "editorSections/PushItSection.h"
#include "editorSections/SequencerSection.h"
#include "editorSections/VCASection.h"
#include "widgets/KnobWidgets.h"

class PluginEditor : public AudioProcessorEditor, public Button::Listener
{
public:
    PluginEditor(PluginProcessor& p, AudioProcessorValueTreeState* publicParams, PrivateParameters* privateParameters);
    ~PluginEditor();

    //==============================================================================
    void paint(Graphics& g) override;
    void resized() override;

    //==============================================================================
    void buttonClicked(Button* buttonThatWasClicked) override;

private:
    PluginProcessor& processor;

    PrivateParameters* privateParams;

    std::unique_ptr<OscillatorsSection> sectionOsc;
    std::unique_ptr<LPFSection> sectionLPF;
    std::unique_ptr<VCASection> sectionVCA;
    std::unique_ptr<Env3Section> sectionEnv3;
    std::unique_ptr<ModulatorsSection> sectionMod;
    std::unique_ptr<MidiControllersSection> sectionMidi;
    std::unique_ptr<LFOSection> sectionLFO;
    std::unique_ptr<SequencerSection> sectionSeq;
    std::unique_ptr<KnobAssignSection> sectionKnobAssign;
    std::unique_ptr<PushItSection> sectionPushIt;

    std::unique_ptr<TextButton> button_Read;
    std::unique_ptr<TextButton> button_Write;

    std::unique_ptr<MophoLookAndFeel> mophoLaF;

    TooltipWindow tooltipWindow;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
