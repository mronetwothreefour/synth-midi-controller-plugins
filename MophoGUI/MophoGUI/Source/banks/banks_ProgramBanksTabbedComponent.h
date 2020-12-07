#pragma once

#include <JuceHeader.h>

#include "banks_TabForFactoryProgramBank.h"



class UnexposedParameters;

class ProgramBanksTabbedComponent :
    public TabbedComponent,
    public Label::Listener
{
    TabForFactoryProgramBank bank1;
    TabForFactoryProgramBank bank2;
    TabForFactoryProgramBank bank3;
    UnexposedParameters* unexposedParams;
    String programCopyBuffer;
    Label label_txTime;

public:
    ProgramBanksTabbedComponent() = delete;

    ProgramBanksTabbedComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    TabForFactoryProgramBank* getCurrentProgramBankTab();
    void updateTextForAllProgramSlotsInAllBanks();
    ~ProgramBanksTabbedComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTabbedComponent)
};
