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

class TabForCustomVoicesBank :
    public Component,
    private Timer,
    public ApplicationCommandTarget
{
    VoicesBank bank;
    VoiceSlotsComponent voiceSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedVoice button_ForLoadingSelectedVoice;
    ButtonForSavingVoiceIntoSelectedSlot button_ForSavingVoiceIntoSelectedSlot;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForPullingSelectedVoiceFromHardware button_ForPullingSelectedVoiceFromHardware;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ApplicationCommandManager commandManager;
    String& voiceCopyBuffer;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    TabForCustomVoicesBank() = delete;

    TabForCustomVoicesBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
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
    ~TabForCustomVoicesBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomVoicesBank)
};
