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
    ProgramSlotsWidget
    (
        int pgmBank,
        PrivateParameters* privateParameters,
        MophoLookAndFeel* mophoLaF
    );

    ~ProgramSlotsWidget();

    //==============================================================================
    void resized() override;

private:
    PrivateParameters* privateParams;

    ToggleButton programSlotButtons[128];

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
class ProgramBanksTab : public Component
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

private:
    int bank;

    PrivateParameters* privateParams;

    ProgramSlotsWidget programSlots;

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
    ProgramBanksTab bankA;
    ProgramBanksTab bankB;
    ProgramBanksTab bankC;

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
