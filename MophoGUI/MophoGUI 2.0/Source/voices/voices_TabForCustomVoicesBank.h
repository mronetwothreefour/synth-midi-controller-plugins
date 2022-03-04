#pragma once

#include <JuceHeader.h>

#include "voices_VoicesBanks.h"
#include "voices_VoiceSlotsComponent.h"
#include "../widgets_Button/widget_voices_ButtonForExportingSelectedVoiceToFile.h"
#include "../widgets_Button/widget_voices_ButtonForExportingVoicesBankToFile.h"
#include "../widgets_Button/widget_voices_ButtonForImportingVoiceFromFile.h"
#include "../widgets_Button/widget_voices_ButtonForImportingVoicesBankFromFile.h"
#include "../widgets_Button/widget_voices_ButtonForLoadingSelectedVoice.h"
#include "../widgets_Button/widget_voices_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_voices_ButtonForPullingSelectedVoiceFromHardware.h"
#include "../widgets_Button/widget_voices_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_voices_ButtonForPushingSelectedVoiceToHardware.h"
#include "../widgets_Button/widget_voices_ButtonForSavingVoiceIntoSelectedSlot.h"



class UnexposedParameters;

class TabForCustomVoiceBank :
    public Component,
    private Timer,
    public ApplicationCommandTarget
{
    VoicesBank bank;
    VoiceSlotsComponent voiceSlots;
    UnexposedParameters* unexposedParams;
    ButtonForLoadingSelectedVoice button_ForLoadingSelectedVoice;
    ButtonForSavingVoiceIntoSelectedSlot button_ForSavingVoiceIntoSelectedSlot;
    ButtonForPushingSelectedVoiceToHardware button_ForPushingSelectedVoiceToHardware;
    ButtonForPullingSelectedVoiceFromHardware button_ForPullingSelectedVoiceFromHardware;
    ButtonForExportingSelectedVoiceToFile button_ForExportingSelectedVoiceToFile;
    ButtonForImportingVoiceFromFile button_ForImportingVoiceFromFile;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForExportingVoicesBankToFile button_ForExportingVoicesBankToFile;
    ButtonForImportingVoicesBankFromFile button_ForImportingVoicesBankFromFile;
    ApplicationCommandManager commandManager;
    String& voiceCopyBuffer;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    TabForCustomVoiceBank() = delete;

    TabForCustomVoiceBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer);
    void paint(Graphics& g) override;
    void resized() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void addListenerToButtons(Button::Listener* listener);
    void removeListenerFromButtons(Button::Listener* listener);
    VoiceSlotsComponent* getVoiceSlotsComponent();

private:
    void timerCallback() override;

public:
    ~TabForCustomVoiceBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabForCustomVoiceBank)
};
