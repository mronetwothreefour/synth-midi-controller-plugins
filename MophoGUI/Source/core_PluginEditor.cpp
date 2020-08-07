#include "core_PluginProcessor.h"
#include "core_PluginEditor.h"

#include "banksWindow/banks_ProgramBanksComponent.h"
#include "guiControls/ControlsForExposedParameters_Singleton.h"
#include "helpers/helper_InfoForMainWindowLabels_Singleton.h"
#include "helpers/helper_MophoLookAndFeel.h"
#include "widgets/widget_ButtonAndLabelForEditingPgmName.h"
#include "widgets/widget_ButtonForClearingSequencerTrack.h"
#include "widgets/widget_ButtonForOpeningProgramBanksWindow.h"
#include "widgets/widget_ButtonForSendingProgramEditBufferDump.h"
#include "widgets/widget_ButtonForSendingProgramEditBufferDumpRequest.h"
#include "widgets/widget_EnvelopeRenderer.h"
#include "widgets/widget_Logo.h"



PluginEditor::PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    exposedParams{ exposedParams }
{
    mophoLaF.reset(new MophoLookAndFeel());
    LookAndFeel::setDefaultLookAndFeel(mophoLaF.get());

    mophoguiLogo.reset(new MophoLogo());
    addAndMakeVisible(mophoguiLogo.get());

    auto& controls{ ControlsForExposedParameters::get() };
    controls.rebuildControls();
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        addAndMakeVisible(control);
        control->attachToExposedParameter(exposedParams);
        control->setCentrePosition(InfoForExposedParameters::get().ctrlCenterPointFor(param));
    }

    envelopeRenderer_LPF.reset(new EnvelopeRenderer("lpf", exposedParams));
    envelopeRenderer_VCA.reset(new EnvelopeRenderer("vca", exposedParams));
    envelopeRenderer_Env3.reset(new EnvelopeRenderer("env3", exposedParams));
    addAndMakeVisible(envelopeRenderer_LPF.get());
    addAndMakeVisible(envelopeRenderer_VCA.get());
    addAndMakeVisible(envelopeRenderer_Env3.get());

    button_ForEditingPgmName.reset(new ButtonAndLabelForEditingPgmName(exposedParams));
    addAndMakeVisible(button_ForEditingPgmName.get());

    button_ForSendingPgmEditBufDump.reset(new ButtonForSendingProgramEditBufferDump(exposedParams));
    addAndMakeVisible(button_ForSendingPgmEditBufDump.get());

    button_ForSendingPgmEditBufDumpRequest.reset(new ButtonForSendingProgramEditBufferDumpRequest());
    addAndMakeVisible(button_ForSendingPgmEditBufDumpRequest.get());

    button_ForOpeningProgramBanksWindow.reset(new ButtonForOpeningProgramBanksWindow());
    button_ForOpeningProgramBanksWindow->onClick = [this] {showProgramBanksComponent(); };
    addAndMakeVisible(button_ForOpeningProgramBanksWindow.get());

    button_ForClearingSequencerTrack1.reset(new ButtonForClearingSequencerTrack(1, exposedParams));
    button_ForClearingSequencerTrack2.reset(new ButtonForClearingSequencerTrack(2, exposedParams));
    button_ForClearingSequencerTrack3.reset(new ButtonForClearingSequencerTrack(3, exposedParams));
    button_ForClearingSequencerTrack4.reset(new ButtonForClearingSequencerTrack(4, exposedParams));
    addAndMakeVisible(button_ForClearingSequencerTrack1.get());
    addAndMakeVisible(button_ForClearingSequencerTrack2.get());
    addAndMakeVisible(button_ForClearingSequencerTrack3.get());
    addAndMakeVisible(button_ForClearingSequencerTrack4.get());

    auto& tooltips{ TooltipOptions::get() };
    tooltips.addListener(this);
    tooltipWindow.setMillisecondsBeforeTipAppears(tooltips.delayInMilliseconds());
    tooltipWindow.setComponentEffect(nullptr);

    auto device_w{ 1273 };
    auto device_h{ 626 };
    setSize(device_w, device_h);
    setResizable(false, false);
}

PluginEditor::~PluginEditor() {
    auto& tooltipOptions{ TooltipOptions::get() };
    tooltipOptions.removeListener(this);

    programBanksComponent = nullptr;
    button_ForClearingSequencerTrack4 = nullptr;
    button_ForClearingSequencerTrack3 = nullptr;
    button_ForClearingSequencerTrack2 = nullptr;
    button_ForClearingSequencerTrack1 = nullptr;
    button_ForOpeningProgramBanksWindow = nullptr;
    button_ForSendingPgmEditBufDumpRequest = nullptr;
    button_ForSendingPgmEditBufDump = nullptr;
    button_ForEditingPgmName = nullptr;
    envelopeRenderer_Env3 = nullptr;
    envelopeRenderer_VCA = nullptr;
    envelopeRenderer_LPF = nullptr;

    auto& controls{ ControlsForExposedParameters::get() };
    for (uint8 param = 0; param != controls.paramOutOfRange(); ++param) {
        auto control{ controls.controlFor(param) };
        control->deleteAttachment();
    }

    controls.clear();

    mophoguiLogo = nullptr;

    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mophoLaF = nullptr;
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
}

void PluginEditor::resized() {
    mophoguiLogo->setBounds(880, 0, mophoguiLogo->getWidth(), mophoguiLogo->getHeight());
    auto envelopeRenderers_x{ 168 };
    envelopeRenderer_LPF->setBounds(envelopeRenderers_x, 154, envelopeRenderer_LPF->getWidth(), envelopeRenderer_LPF->getHeight());
    envelopeRenderer_VCA->setBounds(envelopeRenderers_x, 312, envelopeRenderer_VCA->getWidth(), envelopeRenderer_VCA->getHeight());
    envelopeRenderer_Env3->setBounds(envelopeRenderers_x, 470, envelopeRenderer_Env3->getWidth(), envelopeRenderer_Env3->getHeight());
    button_ForEditingPgmName->setBounds(590, 11, button_ForEditingPgmName->getWidth(), button_ForEditingPgmName->getHeight());
    auto utilityButtons_y{ 83 };
    auto utilityButtons_w{ 53 };
    auto utilityButtons_h{ 21 };
    button_ForSendingPgmEditBufDump->setBounds(580, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForSendingPgmEditBufDumpRequest->setBounds(643, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForOpeningProgramBanksWindow->setBounds(706, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    auto clearSeqTrackButtons_x{ 1166 };
    auto clearSeqTrackButtons_w{ 42 };
    auto clearSeqTrackButtons_h{ 16 };
    button_ForClearingSequencerTrack1->setBounds(clearSeqTrackButtons_x, 161, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack2->setBounds(clearSeqTrackButtons_x, 244, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack3->setBounds(clearSeqTrackButtons_x, 327, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack4->setBounds(clearSeqTrackButtons_x, 410, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
}

void PluginEditor::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property)
{
    if (property == ID::tooltips_DelayInMilliseconds) {
        auto& tooltips{ TooltipOptions::get() };
        tooltipWindow.setMillisecondsBeforeTipAppears(tooltips.delayInMilliseconds());
    }
}

void PluginEditor::showProgramBanksComponent() {
    programBanksComponent.reset(new ProgramBanksComponent(exposedParams));
    if (programBanksComponent != nullptr) {
        addAndMakeVisible(programBanksComponent.get());
        programBanksComponent->setBounds(getLocalBounds());
    }
}

