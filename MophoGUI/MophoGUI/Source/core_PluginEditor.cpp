#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "global/global_GlobalParametersComponent.h"
#include "global/global_NRPNisOffWarningComponent.h"
#include "global/global_SysExIsOffWarningComponent.h"
#include "gui/gui_Layer_Buttons.h"
#include "gui/gui_Layer_EnvelopeRenderers.h"
#include "gui/gui_Layer_ExposedParamControls.h"
#include "gui/gui_LookAndFeel.h"
#include "midi/midi_GlobalParametersDump.h"
#include "params/params_Identifiers.h"
#include "params/params_UnexposedParameters_Facade.h"
#include "widgets_Button/widget_ButtonForClearingSequencerTrack.h"
#include "widgets_Button/widget_ButtonForPerformingRedo.h"
#include "widgets_Button/widget_ButtonForPerformingUndo.h"
#include "widgets_Button/widget_ButtonForSendingProgramEditBufferDump.h"
#include "widgets_Button/widget_ButtonForSendingProgramEditBufferDumpRequest.h"
#include "widgets_Button/widget_ButtonForShowingGlobalParametersComponent.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    lookAndFeel{ new GUILookAndFeel() },
    envelopeRenderersLayer{ new EnvelopeRenderersLayer(exposedParams) },
    exposedParamsControlsLayer{ new ExposedParamsControlsLayer(exposedParams, unexposedParams) },
    buttonsLayer{ new ButtonsLayer(exposedParams, unexposedParams) },
    button_ForSendingProgramEditBufferDump{ new ButtonForSendingProgramEditBufferDump(exposedParams, unexposedParams) },
    button_ForSendingProgramEditBufferDumpRequest{ new ButtonForSendingProgramEditBufferDumpRequest(unexposedParams) },
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

    addAndMakeVisible(envelopeRenderersLayer.get());
    addAndMakeVisible(exposedParamsControlsLayer.get());
    addAndMakeVisible(button_ForSendingProgramEditBufferDump.get());
    addAndMakeVisible(button_ForSendingProgramEditBufferDumpRequest.get());
    addAndMakeVisible(button_ForShowingGlobalParametersComponent.get());
    addAndMakeVisible(button_ForPerformingUndo.get());
    addAndMakeVisible(button_ForPerformingRedo.get());
    addAndMakeVisible(button_ForClearingSequencerTrack1.get());
    addAndMakeVisible(button_ForClearingSequencerTrack2.get());
    addAndMakeVisible(button_ForClearingSequencerTrack3.get());
    addAndMakeVisible(button_ForClearingSequencerTrack4.get());
    addAndMakeVisible(buttonsLayer.get());

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
    MemoryInputStream memInputStream{ BinaryData::MophoGUIMainWindowBackground_png, BinaryData::MophoGUIMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void PluginEditor::resized() {
    envelopeRenderersLayer->setBounds(getLocalBounds());
    exposedParamsControlsLayer->setBounds(getLocalBounds());
    buttonsLayer->setBounds(getLocalBounds());
    auto utilityButtons_y{ 83 };
    auto utilityButtons_w{ 53 };
    auto utilityButtons_h{ 22 };
    button_ForSendingProgramEditBufferDump->setBounds(580, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForSendingProgramEditBufferDumpRequest->setBounds(643, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForShowingGlobalParametersComponent->setBounds(769, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    auto undoRedoButtons_x{ 837 };
    auto undoRedoButtons_w{ 44 };
    button_ForPerformingUndo->setBounds(undoRedoButtons_x, 26, undoRedoButtons_w, utilityButtons_h);
    button_ForPerformingRedo->setBounds(undoRedoButtons_x, 55, undoRedoButtons_w, utilityButtons_h);
    auto clearSeqTrackButtons_x{ 1166 };
    auto clearSeqTrackButtons_w{ 46 };
    auto clearSeqTrackButtons_h{ 18 };
    button_ForClearingSequencerTrack1->setBounds(clearSeqTrackButtons_x, 160, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack2->setBounds(clearSeqTrackButtons_x, 243, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack3->setBounds(clearSeqTrackButtons_x, 326, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack4->setBounds(clearSeqTrackButtons_x, 409, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForGoingToWebSite->setBounds(644, 122, 157, 9);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto tooltips{ unexposedParams->tooltipOptions_get() };
        tooltipWindow->setMillisecondsBeforeTipAppears(tooltips->delayInMilliseconds());
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
    nrpnIsOffWarningComponent = nullptr;
    sysExIsOffWarningComponent = nullptr;
    buttonsLayer = nullptr;
    button_ForGoingToWebSite = nullptr;
    button_ForClearingSequencerTrack4 = nullptr;
    button_ForClearingSequencerTrack3 = nullptr;
    button_ForClearingSequencerTrack2 = nullptr;
    button_ForClearingSequencerTrack1 = nullptr;
    button_ForPerformingRedo = nullptr;
    button_ForPerformingUndo = nullptr;
    button_ForShowingGlobalParametersComponent = nullptr;
    button_ForSendingProgramEditBufferDumpRequest = nullptr;
    button_ForSendingProgramEditBufferDump = nullptr;
    exposedParamsControlsLayer = nullptr;
    envelopeRenderersLayer = nullptr;
}
