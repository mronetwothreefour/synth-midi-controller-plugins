#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBank.h"
#include "voices_3_comp_VoiceSlots.h"
#include "voices_4_comp_ButtonsForVoicesBank.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class GUI_Layer_VoicesBankTransmit;
class GUI_Layer_Export_Voice;
class GUI_Layer_Export_VoicesBank;
class GUI_Layer_Import_Voice;
class GUI_Layer_Import_VoicesBank;
class GUI_Layer_RestoreFactoryVoicesDialog;
class UnexposedParameters;

class GUI_Layer_VoicesBank :
    public Component,
    public ApplicationCommandTarget,
    public Button::Listener
{
    UnexposedParameters* unexposedParams;
    VoicesBank* voicesBank;
    ButtonForLoadingSelectedVoice btn_LoadSelected;
    ButtonForSavingVoiceIntoSelectedSlot btn_SaveIntoSelected;
    ButtonForPullingSelectedVoiceFromHardware btn_PullSelected;;
    ButtonForExportingSelectedVoiceToFile btn_ExportSelected;
    ButtonForImportingVoiceFromFile btn_ImportSelected;
    ButtonForEditingSelectedVoiceName btn_EditName;
    ButtonForPushingEntireBankToHardware btn_PushBank;
    ButtonForPullingEntireBankFromHardware btn_PullBank;
    ButtonForExportingEntireBankToFile btn_ExportBank;
    ButtonForImportingEntireBankFromFile btn_ImportBank;
    ButtonForRestoringFactoryVoices btn_RestoreFactoryVoices;
    Label lbl_txTimeEditor;
    ButtonForHidingLayer btn_Exit;
    std::unique_ptr<GUI_Layer_Export_Voice> exportVoiceLayer;
    std::unique_ptr<GUI_Layer_Import_Voice> importVoiceLayer;
    std::unique_ptr<GUI_Layer_VoicesBankTransmit> pushBankLayer;
    std::unique_ptr<GUI_Layer_VoicesBankTransmit> pullBankLayer;
    std::unique_ptr<GUI_Layer_Export_VoicesBank> exportBankLayer;
    std::unique_ptr<GUI_Layer_Import_VoicesBank> importBankLayer;
    std::unique_ptr<GUI_Layer_RestoreFactoryVoicesDialog> restoreFactoryVoicesDialogLayer;
    VoiceSlots voiceSlots;
    ApplicationCommandManager commandManager;
    String voiceCopyBuffer;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    GUI_Layer_VoicesBank() = delete;

    GUI_Layer_VoicesBank(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void buttonClicked(Button* button) override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    void showExportVoiceLayer();
    void showImportVoiceLayer();
    void showPushBankLayer();
    void showPullBankLayer();
    void showExportBankLayer();
    void showImportBankLayer();
    void showRestoreFactoryVoicesDialogLayer();

public:
    ~GUI_Layer_VoicesBank();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_VoicesBank)
};