#pragma once

#include <JuceHeader.h>

#include "../core_PluginProcessor.h"
#include "../helpers/helper_CustomColors.h"
#include "../parameters/params_PluginProgramBanks_Singleton.h"



class ProgramSlotsWidget : public Component
{
    ToggleButton programSlotButtons[128];
    uint8 bank;
    int buttton_w;
    int buttton_h;
    int buttonGap;

public:
    int selectedSlot;

    explicit ProgramSlotsWidget(uint8 bank);
    ~ProgramSlotsWidget();

    void resized() override;
    void setTextForProgramSlotToggleButton(uint8 slot);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};



class ProgramBanksTab :
    public Component,
    public Timer,
    public ApplicationCommandTarget,
    public Label::Listener
{
    uint8 bank;
    ProgramSlotsWidget programSlots;
    PluginProcessor& processor;
    ApplicationCommandManager commandManager;

public:
    enum commandChoices {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBanksTab(uint8 bank, PluginProcessor& processor);
    ~ProgramBanksTab();

    void paint(Graphics& g) override;
    void resized() override;
    void timerCallback() override;
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& commands) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    void labelTextChanged(Label* label) override;
    void editorShown(Label* label, TextEditor& editor) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTab)
};



class ProgramBanksTabbedComponent : public TabbedComponent
{
    ProgramBanksTab bank1;
    ProgramBanksTab bank2;
    ProgramBanksTab bank3;

public:
    explicit ProgramBanksTabbedComponent(PluginProcessor& processor);

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