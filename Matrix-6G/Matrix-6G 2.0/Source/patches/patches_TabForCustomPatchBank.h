#pragma once

#include <JuceHeader.h>

#include "patches_PatchBanks.h"
#include "patches_PatchSlotsComponent.h"
#include "../widgets_Button/widget_patches_ButtonForLoadingSelectedPatch.h"
#include "../widgets_Button/widget_patches_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_patches_ButtonForPullingSelectedPatchFromHardware.h"
#include "../widgets_Button/widget_patches_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_patches_ButtonForSavingPatchInSelectedSlot.h"



class UnexposedParameters;

class TabForCustomPatchBank :
    public Component,
    private Timer,
    public ApplicationCommandTarget
{
    VoicesBank bank;
    VoiceSlotsComponent patchSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedPatch button_ForLoadingSelectedPatch;
    ButtonForSavingPatchInSelectedSlot button_ForSavingPatchInSelectedSlot;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForPullingSelectedPatchFromHardware button_ForPullingSelectedPatchFromHardware;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ApplicationCommandManager commandManager;
    String& patchCopyBuffer;

public:
    enum commandChoices {
        copyPatch = 1,
        pastePatch
    };

    TabForCustomPatchBank() = delete;

    TabForCustomPatchBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& patchCopyBuffer);
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToPullEntireBankButton(Button::Listener* listener);
    void addListenerToPushEntireBankButton(Button::Listener* listener);
    void removeListenerFromPullEntireBankButton(Button::Listener* listener);
    void removeListenerFromPushEntireBankButton(Button::Listener* listener);

private:
    void timerCallback() override;

public:
    ~TabForCustomPatchBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomPatchBank)
};
