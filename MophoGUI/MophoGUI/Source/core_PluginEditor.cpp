#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "banks/banks_ProgramBanksComponent.h"
#include "global/global_GlobalParametersComponent.h"
#include "global/global_NRPNisOffWarningComponent.h"
#include "global/global_SysExIsOffWarningComponent.h"
#include "gui/gui_Colors.h"
#include "gui/gui_Fonts.h"
#include "gui/gui_InfoForMainWindowLabels_Singleton.h"
#include "gui/gui_Layer_ExposedParamControls.h"
#include "gui/gui_Logo.h"
#include "gui/gui_LookAndFeel.h"
#include "guiRenderers/guiRenderer_ForEnvelopes.h"
#include "midi/midi_GlobalParametersDump.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"
#include "widgets_Button/widget_ButtonAndLabelForEditingPgmName.h"
#include "widgets_Button/widget_ButtonForClearingSequencerTrack.h"
#include "widgets_Button/widget_ButtonForPerformingRedo.h"
#include "widgets_Button/widget_ButtonForPerformingUndo.h"
#include "widgets_Button/widget_ButtonForSendingProgramEditBufferDump.h"
#include "widgets_Button/widget_ButtonForSendingProgramEditBufferDumpRequest.h"
#include "widgets_Button/widget_ButtonForShowingGlobalParametersComponent.h"
#include "widgets_Button/widget_ButtonForShowingProgramBanksComponent.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    logo{ new Logo() },
    exposedParamsControlsLayer{ new ExposedParamsControlsLayer(exposedParams, unexposedParams) },
    rendererForEnvelope_LPF{ new RendererForEnvelopes("lpf", exposedParams) },
    rendererForEnvelope_VCA{ new RendererForEnvelopes("vca", exposedParams) },
    rendererForEnvelope_Env3{ new RendererForEnvelopes("env3", exposedParams) },
    button_ForEditingPgmName{ new ButtonAndLabelForEditingPgmName(exposedParams, unexposedParams) },
    button_ForSendingProgramEditBufferDump{ new ButtonForSendingProgramEditBufferDump(exposedParams, unexposedParams) },
    button_ForSendingProgramEditBufferDumpRequest{ new ButtonForSendingProgramEditBufferDumpRequest(unexposedParams) },
    button_ForShowingProgramBanksComponent{ new ButtonForShowingProgramBanksComponent(unexposedParams) },
    button_ForShowingGlobalParametersComponent{ new ButtonForShowingGlobalParametersComponent(unexposedParams) },
    button_ForPerformingUndo{ new ButtonForPerformingUndo(unexposedParams) },
    button_ForPerformingRedo{ new ButtonForPerformingRedo(unexposedParams) },
    button_ForClearingSequencerTrack1{ new ButtonForClearingSequencerTrack(1, exposedParams, unexposedParams) },
    button_ForClearingSequencerTrack2{ new ButtonForClearingSequencerTrack(2, exposedParams, unexposedParams) },
    button_ForClearingSequencerTrack3{ new ButtonForClearingSequencerTrack(3, exposedParams, unexposedParams) },
    button_ForClearingSequencerTrack4{ new ButtonForClearingSequencerTrack(4, exposedParams, unexposedParams) },
    tooltipWindow{ new TooltipWindow() }
{
    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    addAndMakeVisible(logo.get());
    addAndMakeVisible(exposedParamsControlsLayer.get());
    addAndMakeVisible(rendererForEnvelope_LPF.get());
    addAndMakeVisible(rendererForEnvelope_VCA.get());
    addAndMakeVisible(rendererForEnvelope_Env3.get());
    addAndMakeVisible(button_ForEditingPgmName.get());
    addAndMakeVisible(button_ForSendingProgramEditBufferDump.get());
    addAndMakeVisible(button_ForSendingProgramEditBufferDumpRequest.get());
    addAndMakeVisible(button_ForShowingProgramBanksComponent.get());
    addAndMakeVisible(button_ForShowingGlobalParametersComponent.get());
    addAndMakeVisible(button_ForPerformingUndo.get());
    addAndMakeVisible(button_ForPerformingRedo.get());
    addAndMakeVisible(button_ForClearingSequencerTrack1.get());
    addAndMakeVisible(button_ForClearingSequencerTrack2.get());
    addAndMakeVisible(button_ForClearingSequencerTrack3.get());
    addAndMakeVisible(button_ForClearingSequencerTrack4.get());

    button_ForShowingProgramBanksComponent->onClick = [this] { showProgramBanksComponent(); };
    button_ForShowingGlobalParametersComponent->onClick = [this] { prepareToShowGlobalParametersComponent(); };

    URL url{ "https://programming.mr1234.com/" };
    button_ForGoingToWebSite.reset(new HyperlinkButton("", url));
    button_ForGoingToWebSite->setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite->setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite.get());


    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->addListener(this);
    addChildComponent(tooltipWindow.get());
    tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    tooltipWindow->setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

void PluginEditor::showSysExIsOffWarningComponent() {
    sysExIsOffWarningComponent.reset(new SysExIsOffWarningComponent(unexposedParams));
    if (sysExIsOffWarningComponent != nullptr) {
        addAndMakeVisible(sysExIsOffWarningComponent.get());
        sysExIsOffWarningComponent->setBounds(getLocalBounds());
    }
}

void PluginEditor::showNRPNisOffWarningComponent() {
    nrpnIsOffWarningComponent.reset(new NRPNisOffWarningComponent(unexposedParams));
    if (nrpnIsOffWarningComponent != nullptr) {
        addAndMakeVisible(nrpnIsOffWarningComponent.get());
        nrpnIsOffWarningComponent->setBounds(getLocalBounds());
    }
}

void PluginEditor::paint(Graphics& g) {
    g.fillAll(Color::device);
    g.setColour(Color::controlLabelText);
    auto& info{ InfoForMainWindowLabels::get() };
    for (uint16 label = 0; label != info.labelOutOfRange(); ++label) {
        Font font{ FontsDB::family_Global, FontsDB::style_ForControlLabels, info.fontSizeFor(label) };
        g.setFont(font);
        Rectangle<int> labelArea{ info.widthFor(label), info.heightFor(label) };
        labelArea.setCentre(info.centerPointFor(label));
        g.drawFittedText(info.textFor(label), labelArea, info.justificationFlagFor(label), 1, 1.0f);
    }
    g.drawHorizontalLine(85, 15.0f, 295.0f);
    Rectangle<int> pgmNameBackground{ 580, 33, 242, 37 };
    g.fillRect(pgmNameBackground);
    Font infoLineFont{ FontsDB::family_Global, FontsDB::style_ForPluginInfoLine, FontsDB::size_ForPluginInfoLine };
    g.setFont(infoLineFont);
    Rectangle<int> infoLineArea{ 580, 118, 227, 16 };
    g.drawText("Build " + (String)ProjectInfo::versionString + "  |  Mister 1-2-3-4 Programming", infoLineArea, Justification::centred);
}

void PluginEditor::resized() {
    logo->setBounds(901, 13, logo->getWidth(), logo->getHeight());
    exposedParamsControlsLayer->setBounds(getLocalBounds());
    auto envRenderers_x{ 168 };
    rendererForEnvelope_LPF->setBounds(envRenderers_x, 154, rendererForEnvelope_LPF->getWidth(), rendererForEnvelope_LPF->getHeight());
    rendererForEnvelope_VCA->setBounds(envRenderers_x, 312, rendererForEnvelope_VCA->getWidth(), rendererForEnvelope_VCA->getHeight());
    rendererForEnvelope_Env3->setBounds(envRenderers_x, 470, rendererForEnvelope_Env3->getWidth(), rendererForEnvelope_Env3->getHeight());
    button_ForEditingPgmName->setBounds(590, 11, button_ForEditingPgmName->getWidth(), button_ForEditingPgmName->getHeight());
    auto utilityButtons_y{ 83 };
    auto utilityButtons_w{ 53 };
    auto utilityButtons_h{ 21 };
    button_ForSendingProgramEditBufferDump->setBounds(580, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForSendingProgramEditBufferDumpRequest->setBounds(643, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForShowingProgramBanksComponent->setBounds(706, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForShowingGlobalParametersComponent->setBounds(769, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    auto undoRedoButtons_x{ 837 };
    auto undoRedoButtons_w{ 40 };
    button_ForPerformingUndo->setBounds(undoRedoButtons_x, 27, undoRedoButtons_w, utilityButtons_h);
    button_ForPerformingRedo->setBounds(undoRedoButtons_x, 56, undoRedoButtons_w, utilityButtons_h);
    auto clearSeqTrackButtons_x{ 1166 };
    auto clearSeqTrackButtons_w{ 42 };
    auto clearSeqTrackButtons_h{ 16 };
    button_ForClearingSequencerTrack1->setBounds(clearSeqTrackButtons_x, 161, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack2->setBounds(clearSeqTrackButtons_x, 244, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack3->setBounds(clearSeqTrackButtons_x, 327, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack4->setBounds(clearSeqTrackButtons_x, 410, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForGoingToWebSite->setBounds(656, 117, 140, 16);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto tooltips{ unexposedParams->tooltipOptions_get() };
        tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
    }
}

void PluginEditor::showProgramBanksComponent() {
    programBanksComponent.reset(new ProgramBanksComponent(exposedParams, unexposedParams));
    if (programBanksComponent != nullptr) {
        addAndMakeVisible(programBanksComponent.get());
        programBanksComponent->setBounds(getLocalBounds());
    }
}

void PluginEditor::prepareToShowGlobalParametersComponent() {
    auto midiOptions{ unexposedParams->midiOptions_get() };
    midiOptions->resetMidiOptionsToDefaults();
    auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
    globalAudioOptions->resetGlobalAudioOptionsToDefaults();
    auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
    GlobalParametersDump::addRequestForDumpToOutgoingMidiBuffers(outgoingMidiBuffers);
    callAfterDelay(300, [this, midiOptions] { 
        if (midiOptions->sysExIsOn()) {
            if (midiOptions->hardwareIsNotSetToReceiveNRPNcontrollers())
                showNRPNisOffWarningComponent();
            else
                showGlobalParametersComponent();
        }
        else showSysExIsOffWarningComponent(); 
    });
}

void PluginEditor::showGlobalParametersComponent() {
    globalParamsComponent.reset(new GlobalParametersComponent(unexposedParams));
    if (globalParamsComponent != nullptr) {
        addAndMakeVisible(globalParamsComponent.get());
        globalParamsComponent->setBounds(getLocalBounds());
    }
}

void PluginEditor::timerCallback() {
}

PluginEditor::~PluginEditor() {
    auto tooltips{ unexposedParams->tooltipOptions_get() };
    tooltips->removeListener(this);
    tooltipWindow = nullptr;
    globalParamsComponent = nullptr;
    programBanksComponent = nullptr;
    nrpnIsOffWarningComponent = nullptr;
    sysExIsOffWarningComponent = nullptr;
    button_ForGoingToWebSite = nullptr;
    button_ForClearingSequencerTrack4 = nullptr;
    button_ForClearingSequencerTrack3 = nullptr;
    button_ForClearingSequencerTrack2 = nullptr;
    button_ForClearingSequencerTrack1 = nullptr;
    button_ForPerformingRedo = nullptr;
    button_ForPerformingUndo = nullptr;
    button_ForShowingGlobalParametersComponent = nullptr;
    button_ForShowingProgramBanksComponent = nullptr;
    button_ForSendingProgramEditBufferDumpRequest = nullptr;
    button_ForSendingProgramEditBufferDump = nullptr;
    button_ForEditingPgmName = nullptr;
    rendererForEnvelope_Env3 = nullptr;
    rendererForEnvelope_VCA = nullptr;
    rendererForEnvelope_LPF = nullptr;
    exposedParamsControlsLayer = nullptr;
    logo = nullptr;
}
