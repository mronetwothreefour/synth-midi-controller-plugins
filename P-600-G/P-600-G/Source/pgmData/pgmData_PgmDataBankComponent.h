#pragma once

#include <JuceHeader.h>

#include "pgmData_ProgramDataBank.h"
#include "pgmData_PgmDataSlotsComponent.h"
#include "../widgets_Button/widget_PgmBank_ButtonForLoadingSelectedPgm.h"



class UnexposedParameters;

class ProgramDataBankComponent :
    public Component,
    public Button::Listener,
    public Label::Listener
{
    UnexposedParameters* unexposedParams;
    ProgramDataSlotsComponent slotsComponent;
    ButtonForLoadingSelectedProgram button_ForLoadingSelectedProgram;
    TextButton button_ForNamingSelectedPgm;
    TextButton button_ForClosingPgmDataBank;
    Label label_PgmNameEditor;

public:
    ProgramDataBankComponent() = delete;

    ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void buttonClicked(Button* button) override;

private:
    void setComponentTooltips();
    void hideThisComponent();
    void positionAndShowNameEditorForSelectedPgm();

public:
    ~ProgramDataBankComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBankComponent)
};