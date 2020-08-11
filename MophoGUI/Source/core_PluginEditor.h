#pragma once

#include <JuceHeader.h>

#include "guiControls/ControlsForExposedParameters.h"



class ButtonAndLabelForEditingPgmName;
class ButtonForClearingSequencerTrack;
class ButtonForOpeningProgramBanksWindow;
class ButtonForSendingProgramEditBufferDump;
class ButtonForSendingProgramEditBufferDumpRequest;
class EnvelopeRenderer;
class MophoLogo;
class MophoLookAndFeel;
class ProgramBanksComponent;

class PluginEditor : 
    public AudioProcessorEditor,
    private ControlsForExposedParameters,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    std::unique_ptr<MophoLookAndFeel> mophoLaF;
    std::unique_ptr<MophoLogo> mophoguiLogo;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_LPF;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_VCA;
    std::unique_ptr<EnvelopeRenderer> envelopeRenderer_Env3;
    std::unique_ptr<ButtonAndLabelForEditingPgmName> button_ForEditingPgmName;
    std::unique_ptr<ButtonForSendingProgramEditBufferDump> button_ForSendingPgmEditBufDump;
    std::unique_ptr<ButtonForSendingProgramEditBufferDumpRequest> button_ForSendingPgmEditBufDumpRequest;
    std::unique_ptr<ButtonForOpeningProgramBanksWindow> button_ForOpeningProgramBanksWindow;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack1;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack2;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack3;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack4;
    std::unique_ptr<ProgramBanksComponent> programBanksComponent;
    TooltipWindow tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams);
    ~PluginEditor();

    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    void showProgramBanksComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
