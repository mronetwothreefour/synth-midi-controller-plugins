#include "gui_Layer_Buttons.h"

#include "../banks/banks_ProgramBanksComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ButtonsLayer::ButtonsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
    exposedParams{ exposedParams },
    unexposedParams{ unexposedParams },
    button_ForEditingPgmName{ exposedParams, unexposedParams },
    button_ForSendingProgramEditBufferDump{ exposedParams, unexposedParams },
    button_ForSendingProgramEditBufferDumpRequest{ unexposedParams },
    button_ForShowingProgramBanksComponent{ unexposedParams },
    button_ForPerformingUndo{ unexposedParams },
    button_ForPerformingRedo{ unexposedParams },
    button_ForClearingSequencerTrack1{ 1, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack2{ 2, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack3{ 3, exposedParams, unexposedParams },
    button_ForClearingSequencerTrack4{ 4, exposedParams, unexposedParams },
    button_ForGoingToWebSite{ "", URL("https://programming.mr1234.com/") }
{
    setInterceptsMouseClicks(false, true);
    addAndMakeVisible(button_ForEditingPgmName);
    addAndMakeVisible(button_ForSendingProgramEditBufferDump);
    addAndMakeVisible(button_ForSendingProgramEditBufferDumpRequest);
    addAndMakeVisible(button_ForShowingProgramBanksComponent);
    button_ForShowingProgramBanksComponent.onClick = [this] { showProgramBanksComponent(); };
    addAndMakeVisible(button_ForPerformingUndo);
    addAndMakeVisible(button_ForPerformingRedo);
    addAndMakeVisible(button_ForClearingSequencerTrack1);
    addAndMakeVisible(button_ForClearingSequencerTrack2);
    addAndMakeVisible(button_ForClearingSequencerTrack3);
    addAndMakeVisible(button_ForClearingSequencerTrack4);
    button_ForGoingToWebSite.setComponentID(ID::component_HyperlinkButton.toString());
    button_ForGoingToWebSite.setTooltip("Click to go to programming.mr1234.com");
    addAndMakeVisible(button_ForGoingToWebSite);
}

void ButtonsLayer::showProgramBanksComponent() {
    programBanksComponent.reset(new ProgramBanksComponent(exposedParams, unexposedParams));
    if (programBanksComponent != nullptr) {
        addAndMakeVisible(programBanksComponent.get());
        programBanksComponent->setBounds(getLocalBounds());
    }
}

void ButtonsLayer::resized() {
    button_ForEditingPgmName.setBounds(590, 11, button_ForEditingPgmName.getWidth(), button_ForEditingPgmName.getHeight());
    auto utilityButtons_y{ 83 };
    auto utilityButtons_w{ 53 };
    auto utilityButtons_h{ 22 };
    button_ForSendingProgramEditBufferDump.setBounds(580, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForSendingProgramEditBufferDumpRequest.setBounds(643, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    button_ForShowingProgramBanksComponent.setBounds(706, utilityButtons_y, utilityButtons_w, utilityButtons_h);
    auto undoRedoButtons_x{ 837 };
    auto undoRedoButtons_w{ 44 };
    button_ForPerformingUndo.setBounds(undoRedoButtons_x, 26, undoRedoButtons_w, utilityButtons_h);
    button_ForPerformingRedo.setBounds(undoRedoButtons_x, 55, undoRedoButtons_w, utilityButtons_h);
    auto clearSeqTrackButtons_x{ 1166 };
    auto clearSeqTrackButtons_w{ 46 };
    auto clearSeqTrackButtons_h{ 18 };
    button_ForClearingSequencerTrack1.setBounds(clearSeqTrackButtons_x, 160, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack2.setBounds(clearSeqTrackButtons_x, 243, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack3.setBounds(clearSeqTrackButtons_x, 326, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForClearingSequencerTrack4.setBounds(clearSeqTrackButtons_x, 409, clearSeqTrackButtons_w, clearSeqTrackButtons_h);
    button_ForGoingToWebSite.setBounds(644, 122, 157, 9);
}

ButtonsLayer::~ButtonsLayer() {
    programBanksComponent = nullptr;
}
