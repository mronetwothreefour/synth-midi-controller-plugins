#pragma once

#include <JuceHeader.h>

#include "voices_VoicesBank.h"
#include "voices_VoiceSlotsComponent.h"
#include "voices_BankTransmissionComponent.h"
#include "../widgets_LCDdisplayEditor/widget_LCDdisplayEditor.h"
#include "../widgets_Button/widget_voices_ButtonForEditingSelectedVoiceName.h"
#include "../widgets_Button/widget_voices_ButtonForExportingVoicesBankToFile.h"
#include "../widgets_Button/widget_voices_ButtonForExportingSelectedVoiceToFile.h"
#include "../widgets_Button/widget_voices_ButtonForImportingVoicesBankFromFile.h"
#include "../widgets_Button/widget_voices_ButtonForImportingVoiceFromFile.h"
#include "../widgets_Button/widget_voices_ButtonForLoadingSelectedVoice.h"
#include "../widgets_Button/widget_voices_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_voices_ButtonForPullingSelectedVoiceFromHardware.h"
#include "../widgets_Button/widget_voices_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_voices_ButtonForRestoringFactoryVoices.h"
#include "../widgets_Button/widget_voices_ButtonForSavingVoiceIntoSelectedSlot.h"



class ExportVoicesBankComponent;
class ExportVoiceDataComponent;
class ImportVoicesBankComponent;
class ImportVoiceDataComponent;
class RestoreFactoryVoicesConfirmDialogBox;
class UnexposedParameters;

class VoicesBankComponent :
    public Component,
    public Label::Listener,
    public Button::Listener,
    public ApplicationCommandTarget
{
    UnexposedParameters* unexposedParams;
    VoiceSlotsComponent slotsComponent;
    ButtonForLoadingSelectedVoice button_ForLoadingSelectedVoice;
    ButtonForSavingVoiceIntoSelectedSlot button_ForSavingVoiceIntoSelectedSlot;
    ButtonForPullingSelectedVoiceFromHardware button_ForPullingSelectedVoiceFromHardware;
    ButtonForImportingVoiceFromFile button_ForImportingVoiceFromFile;
    ButtonForExportingSelectedVoiceToFile button_ForExportingSelectedVoiceToFile;
    ButtonForEditingSelectedVoiceName button_ForEditingSelectedVoiceName;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForImportingVoicesBankFromFile button_ForImportingVoicesBankFromFile;
    ButtonForExportingVoicesBankToFile button_ForExportingVoicesBankToFile;
    ButtonForRestoringFactoryVoices button_ForRestoringFactoryVoices;
    TextButton button_ForClosingVoicesBank;
    Label label_VoiceNameEditor;
    LCDdisplayEditor editor_txTime;
    ApplicationCommandManager commandManager;
    String voiceCopyBuffer;
    std::unique_ptr<ExportVoiceDataComponent> exportSelectedVoiceComponent;
    std::unique_ptr<ImportVoiceDataComponent> importVoiceComponent;
    std::unique_ptr<BankTransmissionComponent> bankTransmissionComponent;
    std::unique_ptr<ImportVoicesBankComponent> importVoicesBankComponent;
    std::unique_ptr<ExportVoicesBankComponent> exportVoicesBankComponent;
    std::unique_ptr<RestoreFactoryVoicesConfirmDialogBox> restoreFactoryVoicesConfirmDialogBox;

public:
    enum commandChoices {
        copyVoice = 1,
        pasteVoice
    };

    VoicesBankComponent() = delete;

    VoicesBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    void showImportVoiceComponent();
    void showExportSelectedVoiceComponent();
    void showBankTransmissionComponent(BankTransmissionComponent::TransmissionType transmitType);
    void showImportVoicesBankComponent();
    void showExportVoicesBankComponent();
    void showRestoreFactoryVoicesConfirmDialogBox();
    void hideThisComponent();

public:
    ~VoicesBankComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesBankComponent)
};