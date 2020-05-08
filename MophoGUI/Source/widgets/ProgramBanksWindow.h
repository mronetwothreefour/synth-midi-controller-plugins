#pragma once

#include <JuceHeader.h>

#include "../PluginProcessor.h"

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
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
        PrivateParameters* privateParameters,
        MophoLookAndFeel* mophoLaF
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
// A component holding a program storage bank widget plus buttons for
// reading/writing individual programs or entire banks and a slider for
// adjusting the transfer time between the GUI and the hardware
class ProgramBanksTab : public Component, public Timer
{
public:
    ProgramBanksTab
    (
        int pgmBank,
        PluginProcessor& p,
        PrivateParameters* privateParameters,
        MophoLookAndFeel* mophoLaF
    );

    ~ProgramBanksTab();

    //==============================================================================
    void resized() override;

    void timerCallback() override {}

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
        PrivateParameters* privateParameters,
        MophoLookAndFeel* mophoLaF
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
        PrivateParameters* privateParameters,
        MophoLookAndFeel* mophoLaF
    ) :
        DialogWindow{ "Program Banks", Color::device, true, false }
    {
        contentComponent.reset(new ProgramBanksTabbedComponent(p, privateParameters, mophoLaF));
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
