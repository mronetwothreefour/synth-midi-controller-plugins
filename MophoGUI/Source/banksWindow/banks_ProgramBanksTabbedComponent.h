#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBankTab.h"



class ProgramBanksTabbedComponent :
    public TabbedComponent,
    public Label::Listener
{
    ProgramBankTab bank1;
    ProgramBankTab bank2;
    ProgramBankTab bank3;

public:
    ProgramBanksTabbedComponent() = delete;

    explicit ProgramBanksTabbedComponent(AudioProcessorValueTreeState* exposedParams);

    void labelTextChanged(Label* label) override;
    void editorShown(Label* label, TextEditor& editor) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTabbedComponent)
};
