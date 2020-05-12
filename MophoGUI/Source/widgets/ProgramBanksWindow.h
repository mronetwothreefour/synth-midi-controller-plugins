#pragma once

#include <JuceHeader.h>

#include "../PluginProcessor.h"

#include "../helpers/CustomColors.h"
#include "../parameters/PrivateParameters.h"

// An array of 128 toggle buttons in a radio group, used in
// ProgramSlotsWidget to select which program storage slot
// in the Mopho hardware to read from or write to.
class ProgramSlotsWidget : public Component
{
public:
    int selectedSlot{ -1 };

    ProgramSlotsWidget
    (
        int pgmBank,
        PrivateParameters* privateParameters
    );

    ~ProgramSlotsWidget();

    //==============================================================================
    void resized() override;

    void setNameForProgramSlotButton(int slot);

private:
    PrivateParameters* privateParams;

    ToggleButton programSlotButtons[128];

    int bankNum;
    int buttton_w{ 120 };
    int buttton_h{ 17 };
    int buttonGap{ 5 };

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

//==============================================================================
// When a command is sent to transmit all the programs stored in one of the
// plugin's storage banks to the corresponding bank in the Mopho hardware,
// this opens a progress window showing which program is being transmitted
// and also allows the user to stop the transmission.
class PushBankThread : public ThreadWithProgressWindow
{
public:
    PushBankThread
    (
        int bankNum,
        PluginProcessor& p,
        PrivateParameters* privateParameters
    );

    //==============================================================================
    void run() override;

    void threadComplete(bool userPressedCancel) override;

private:
    int bank;

    PluginProcessor& processor;

    PrivateParameters* privateParams;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PushBankThread)
};

//==============================================================================
// When a command is sent to pull all the programs stored in one of the
// Mopho hardware's storage banks into the corresponding bank in the plugin,
// this opens a progress window showing which program is being transmitted
// and also allows the user to stop the transmission.
class PullBankThread : public ThreadWithProgressWindow
{
public:
    PullBankThread
    (
        int bankNum,
        PluginProcessor& p,
        PrivateParameters* privateParameters,
        ProgramSlotsWidget& slots
    );

    //==============================================================================
    void run() override;

    void threadComplete(bool userPressedCancel) override;

private:
    int bank;

    PluginProcessor& processor;

    PrivateParameters* privateParams;

    ProgramSlotsWidget& programSlots;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PullBankThread)
};

//==============================================================================
// A component holding a program storage bank widget plus buttons for
// reading/writing individual programs or entire banks and a slider for
// adjusting the transfer time between the GUI and the hardware
class ProgramBanksTab :
    public Component,
    public Timer,
    public ApplicationCommandTarget
{
public:
    enum commandChoices
    {
        copyProgram = 1,
        pasteProgram
    };

    ProgramBanksTab
    (
        int pgmBank,
        PluginProcessor& p,
        PrivateParameters* privateParameters
    );

    ~ProgramBanksTab();

    //==============================================================================
    void resized() override;

    void timerCallback() override {}

    ApplicationCommandTarget* getNextCommandTarget() override { return nullptr; }

    void getAllCommands(Array<CommandID>& commands) override;

    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;

    bool perform(const InvocationInfo& info) override;

private:
    int bank;

    PluginProcessor& processor;

    PrivateParameters* privateParams;

    ProgramSlotsWidget programSlots;

    TextButton button_Load;
    TextButton button_Save;
    TextButton button_Push;
    TextButton button_Pull;
    TextButton button_PushBank;
    TextButton button_PullBank;

    ApplicationCommandManager commandManager;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTab)
};

//==============================================================================
// The content component for the program banks dialog window.
// This is a tabbed component with three tabs for program banks
class ProgramBanksTabbedComponent : public TabbedComponent
{
public:
    ProgramBanksTabbedComponent
    (
        PluginProcessor& p,
        PrivateParameters* privateParameters
    );

private:
    ProgramBanksTab bank1;
    ProgramBanksTab bank2;
    ProgramBanksTab bank3;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksTabbedComponent)
};

// Opens the program bank tabs in a floating window
class ProgramBanksWindow : public DialogWindow
{
public:
    ProgramBanksWindow
    (
        PluginProcessor& p,
        PrivateParameters* privateParameters
    ) :
        DialogWindow{ "Program Banks", Color::device, true, false }
    {
        contentComponent.reset(new ProgramBanksTabbedComponent(p, privateParameters));
        contentComponent->setVisible(true);
    }

    ~ProgramBanksWindow()
    {
        contentComponent = nullptr;
    }

    std::unique_ptr<ProgramBanksTabbedComponent> contentComponent;

private:

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanksWindow)
};
