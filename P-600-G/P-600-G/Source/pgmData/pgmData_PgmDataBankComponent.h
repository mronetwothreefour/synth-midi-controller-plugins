#pragma once

#include <JuceHeader.h>

#include "pgmData_ProgramDataBank.h"
#include "pgmData_PgmDataSlotsComponent.h"
#include "pgmData_BankTransmissionComponent.h"
#include "../widgets_Button/widget_PgmBank_ButtonForEditingSelectedProgramName.h"
#include "../widgets_Button/widget_PgmBank_ButtonForExportingPgmBankToFile.h"
#include "../widgets_Button/widget_PgmBank_ButtonForExportingSelectedPgmToFile.h"
#include "../widgets_Button/widget_PgmBank_ButtonForImportingPgmBankFromFile.h"
#include "../widgets_Button/widget_PgmBank_ButtonForImportingPgmFromFile.h"
#include "../widgets_Button/widget_PgmBank_ButtonForLoadingSelectedPgm.h"
#include "../widgets_Button/widget_PgmBank_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_PgmBank_ButtonForPullingSelectedPgmFromHardware.h"
#include "../widgets_Button/widget_PgmBank_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_PgmBank_ButtonForRestoringFactoryPrograms.h"
#include "../widgets_Button/widget_PgmBank_ButtonForSavingPgmInSelectedSlot.h"



class ExportProgramDataBankComponent;
class ExportProgramDataComponent;
class ImportProgramDataBankComponent;
class ImportProgramDataComponent;
class RestoreFactoryProgramsConfirmDialogBox;
class UnexposedParameters;

class ProgramDataBankComponent :
    public Component,
    public Label::Listener,
    public Button::Listener,
    public ApplicationCommandTarget
{
    UnexposedParameters* unexposedParams;
    ProgramDataSlotsComponent slotsComponent;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingPgmInSelectedSlot;
    ButtonForPullingSelectedProgramFromHardware button_ForPullingSelectedPgmFromHardware;
    ButtonForImportingProgramFromFile button_ForImportingPgmFromFile;
    ButtonForExportingSelectedProgramToFile button_ForExportingSelectedPgmToFile;
    ButtonForEditingSelectedProgramName button_ForEditingSelectedPgmName;
    ButtonForPullingEntireBankFromHardware button_ForPullingEntireBankFromHardware;
    ButtonForPushingEntireBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForImportingProgramBankFromFile button_ForImportingProgramBankFromFile;
    ButtonForExportingProgramBankToFile button_ForExportingProgramBankToFile;
    ButtonForRestoringFactoryPrograms button_ForRestoringFactoryPrograms;
    TextButton button_ForClosingPgmDataBank;
    Label label_PgmNameEditor;
    ApplicationCommandManager commandManager;
    String pgmCopyBuffer;
    std::unique_ptr<ExportProgramDataComponent> exportSelectedPgmComponent;
    std::unique_ptr<ImportProgramDataComponent> importPgmComponent;
    std::unique_ptr<ProgramBankTransmissionComponent> pgmBankTransmissionComponent;
    std::unique_ptr<ImportProgramDataBankComponent> importPgmDataBankComponent;
    std::unique_ptr<ExportProgramDataBankComponent> exportPgmDataBankComponent;
    std::unique_ptr<RestoreFactoryProgramsConfirmDialogBox> restoreFactoryPgmsConfirmDialogBox;

public:
    enum commandChoices {
        copyPgm = 1,
        pastePgm
    };

    ProgramDataBankComponent() = delete;

    ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
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
    void showImportPgmComponent();
    void showExportSelectedPgmComponent();
    void showProgramBankTransmissionComponent(ProgramBankTransmissionComponent::TransmissionType transmitType);
    void showImportPgmDataBankComponent();
    void showExportPgmDataBankComponent();
    void showRestoreFactoryPgmsConfirmDialogBox();
    void hideThisComponent();

public:
    ~ProgramDataBankComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBankComponent)
};