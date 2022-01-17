#pragma once

#include <JuceHeader.h>

#include "pgmData_ProgramDataBank.h"
#include "pgmData_PgmDataSlotsComponent.h"
#include "../widgets_Button/widget_PgmBank_ButtonForEditingSelectedProgramName.h"
#include "../widgets_Button/widget_PgmBank_ButtonForLoadingSelectedPgm.h"
#include "../widgets_Button/widget_PgmBank_ButtonForSavingPgmInSelectedSlot.h"



class UnexposedParameters;

class ProgramDataBankComponent :
    public Component,
    public Button::Listener,
    public Label::Listener,
    public ApplicationCommandTarget
{
    UnexposedParameters* unexposedParams;
    ProgramDataSlotsComponent slotsComponent;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    ButtonForSavingProgramInSelectedSlot button_ForSavingPgmInSelectedSlot;
    ButtonForEditingSelectedProgramName button_ForEditingSelectedPgmName;
    TextButton button_ForClosingPgmDataBank;
    Label label_PgmNameEditor;
    ApplicationCommandManager commandManager;
    String pgmCopyBuffer;

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
    void hideThisComponent();

public:
    ~ProgramDataBankComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBankComponent)
};