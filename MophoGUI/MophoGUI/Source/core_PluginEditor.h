#pragma once

#include <JuceHeader.h>

#include "widgets_ControlsForParameters/widget_ControlsForExposedParameters.h"



class ButtonAndLabelForEditingPgmName;
class ButtonForClearingSequencerTrack;
class ButtonForPerformingRedo;
class ButtonForPerformingUndo;
class ButtonForSendingProgramEditBufferDump;
class ButtonForSendingProgramEditBufferDumpRequest;
class ButtonForShowingProgramBanksComponent;
class ButtonForShowingGlobalParametersComponent;
class GlobalParametersComponent;
class GUILookAndFeel;
class Logo;
class NRPNisOffWarningComponent;
class ProgramBanksComponent;
class RendererForEnvelopes;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class PluginEditor : 
    public AudioProcessorEditor,
    private ControlsForExposedParameters,
    public ValueTree::Listener,
    private Timer
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<Logo> logo;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_LPF;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_VCA;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_Env3;
    std::unique_ptr<ButtonAndLabelForEditingPgmName> button_ForEditingPgmName;
    std::unique_ptr<ButtonForPerformingRedo> button_ForPerformingRedo;
    std::unique_ptr<ButtonForPerformingUndo> button_ForPerformingUndo;
    std::unique_ptr<ButtonForSendingProgramEditBufferDump> button_ForSendingProgramEditBufferDump;
    std::unique_ptr<ButtonForSendingProgramEditBufferDumpRequest> button_ForSendingProgramEditBufferDumpRequest;
    std::unique_ptr<ButtonForShowingProgramBanksComponent> button_ForShowingProgramBanksComponent;
    std::unique_ptr<ButtonForShowingGlobalParametersComponent> button_ForShowingGlobalParametersComponent;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack1;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack2;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack3;
    std::unique_ptr<ButtonForClearingSequencerTrack> button_ForClearingSequencerTrack4;
    std::unique_ptr<ProgramBanksComponent> programBanksComponent;
    std::unique_ptr<GlobalParametersComponent> globalParamsComponent;
    std::unique_ptr<SysExIsOffWarningComponent> sysExIsOffWarningComponent;
    std::unique_ptr<NRPNisOffWarningComponent> nrpnIsOffWarningComponent;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void showSysExIsOffWarningComponent();
    void showNRPNisOffWarningComponent();

public:
    void paint(Graphics&) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void showProgramBanksComponent();
    void prepareToShowGlobalParametersComponent();
    void showGlobalParametersComponent();
    void timerCallback() override;

public:
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
