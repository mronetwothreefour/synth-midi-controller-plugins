#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBanks.h"
#include "voices_2_comp_VoiceSlots.h"
#include "voices_3_comp_ButtonsForVoicesBankTab.h"



class ExposedParameters;
class UnexposedParameters;
class VoicesBanks;

class TabForFactoryVoicesBank :
    public Component,
    public ApplicationCommandTarget
{
    VoicesBank bank;
    VoiceSlots voiceSlots;
    VoicesBanks* voicesBanks;
    ButtonForLoadingSelectedVoice button_LoadSelected;
    ButtonForPushingSelectedVoiceToHardware button_PushSelected;
    ButtonForExportingSelectedVoiceToFile button_ExportSelected;
    ButtonForPushingEntireBankToHardware button_PushBank;
    ButtonForExportingEntireBankToFile button_ExportBank;
    ApplicationCommandManager commandManager;
    String& voiceCopyBuffer;

public:
    enum commandChoices {
        copyVoice = 1
    };

    TabForFactoryVoicesBank() = delete;

    TabForFactoryVoicesBank(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void paint(Graphics& g) override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToButtons(Button::Listener* listener);
    void removeListenerFromButtons(Button::Listener* listener);
    VoiceSlots* getVoiceSlots();
    ~TabForFactoryVoicesBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForFactoryVoicesBank)
};
