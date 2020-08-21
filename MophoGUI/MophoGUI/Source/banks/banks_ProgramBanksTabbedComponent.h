#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBankTab.h"



class UnexposedParameters;

class ProgramBanksTabbedComponent :
    public TabbedComponent,
    public Label::Listener
{
    ProgramBankTab bank1;
    ProgramBankTab bank2;
    ProgramBankTab bank3;
    UnexposedParameters* unexposedParams;
    String programCopyBuffer;
    Label label_txTime;

public:
    ProgramBanksTabbedComponent() = delete;

    ProgramBanksTabbedComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    ProgramBankTab* getCurrentProgramBankTab();
    ~ProgramBanksTabbedComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTabbedComponent)
};
