#pragma once

#include <JuceHeader.h>



class ButtonForClearingSequencerTrack;
class ButtonForPerformingRedo;
class ButtonForPerformingUndo;
class ButtonForSendingProgramEditBufferDump;
class ButtonForSendingProgramEditBufferDumpRequest;
class ButtonForShowingProgramBanksComponent;
class ButtonForShowingGlobalParametersComponent;
class ButtonsLayer;
class EnvelopeRenderersLayer;
class ExposedParamsControlsLayer;
class GlobalParametersComponent;
class GUILookAndFeel;
class NRPNisOffWarningComponent;
class ProgramBanksComponent;
class SysExIsOffWarningComponent;
class UnexposedParameters;

class PluginEditor : 
    public AudioProcessorEditor,
    public ValueTree::Listener,
    private Timer
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<EnvelopeRenderersLayer> envelopeRenderersLayer;
    std::unique_ptr<ExposedParamsControlsLayer> exposedParamsControlsLayer;
    std::unique_ptr<ButtonsLayer> buttonsLayer;
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
    std::unique_ptr<HyperlinkButton> button_ForGoingToWebSite;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void showSysExIsOffWarningComponent();
    void showNRPNisOffWarningComponent();

public:
    void paint(Graphics& g) override;
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
