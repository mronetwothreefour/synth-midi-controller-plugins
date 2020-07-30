#pragma once

#include <JuceHeader.h>

#include "banks_ProgramBankTab.h"
#include "banks_ProgramBanksButtons.h"
#include "../helpers/helper_CustomColors.h"



class ProgramBanksTabbedComponent : 
    public TabbedComponent,
    public Label::Listener
{
    ProgramBankTab bank1;
    ProgramBankTab bank2;
    ProgramBankTab bank3;

public:
    explicit ProgramBanksTabbedComponent(PluginProcessor& processor);
    void labelTextChanged(Label* label) override;
    void editorShown(Label* label, TextEditor& editor) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTabbedComponent)
};



class ProgramBanksWindow : public DialogWindow
{
public:
    ProgramBanksTabbedComponent contentComponent;

    explicit ProgramBanksWindow(PluginProcessor& processor);
    ~ProgramBanksWindow();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksWindow)
};