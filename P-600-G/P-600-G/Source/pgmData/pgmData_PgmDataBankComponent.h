#pragma once

#include <JuceHeader.h>

#include "pgmData_ProgramDataBank.h"
#include "pgmData_PgmDataSlotsComponent.h"



class UnexposedParameters;

class ProgramDataBankComponent :
    public Component,
    public Button::Listener
{
    UnexposedParameters* unexposedParams;
    ProgramDataSlotsComponent slotsComponent;
    TextButton button_ForClosingPgmDataBank;

public:
    ProgramDataBankComponent() = delete;

    ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;

private:
    void hideThisComponent();

public:
    ~ProgramDataBankComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataBankComponent)
};