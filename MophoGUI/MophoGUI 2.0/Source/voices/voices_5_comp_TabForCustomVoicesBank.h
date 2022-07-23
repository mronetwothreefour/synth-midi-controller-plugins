#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBanks.h"
#include "voices_3_comp_VoiceSlots.h"
#include "voices_4_comp_ButtonsForVoicesBankTab.h"



class ExposedParameters;
class UnexposedParameters;
class VoicesBanks;

class TabForCustomVoicesBank :
    public Component,
    public ApplicationCommandTarget
{
    VoicesBank bank;
    VoiceSlots voiceSlots;
    VoicesBanks* voicesBanks;
    ButtonForLoadingSelectedVoice button_LoadSelected;
    ButtonForSavingVoiceIntoSelectedSlot button_SaveIntoSelected;
    ButtonForPushingSelectedVoiceToHardware button_PushSelected;
    ButtonForPullingSelectedVoiceFromHardware button_PullSelected;;
    ButtonForExportingSelectedVoiceToFile button_ExportSelected;
    ButtonForImportingVoiceFromFile button_ImportSelected;
    ButtonForPushingEntireBankToHardware button_PushBank;
    ButtonForPullingEntireBankFromHardware button_PullBank;
    ButtonForExportingEntireBankToFile button_ExportBank;
    ButtonForImportingEntireBankFromFile button_ImportBank;
    ApplicationCommandManager commandManager;
    String& voiceCopyBuffer;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    TabForCustomVoicesBank() = delete;

    TabForCustomVoicesBank(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void paint(Graphics& g) override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToButtons(Button::Listener* listener);
    void removeListenerFromButtons(Button::Listener* listener);
    VoiceSlots* getVoiceSlots();
    ~TabForCustomVoicesBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomVoicesBank)
};
