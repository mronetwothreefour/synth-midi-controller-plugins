#pragma once

#include <JuceHeader.h>

#include "pgmData_Constants.h"
#include "pgmData_ProgramDataBank.h"

using namespace constants;



class UnexposedParameters;

class ProgramDataSlotsComponent :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton pgmDataSlotButtons[pgmData::numberOfSlotsInPgmDataBank];
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;

public:
    uint8 selectedSlot;

    ProgramDataSlotsComponent() = delete;

    ProgramDataSlotsComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void setUpPgmDataSlotToggleButton(uint8 slot);
    void setTooltipForPgmDataSlotToggleButton(uint8 slot);
    void setTextForPgmDataSlotToggleButton(uint8 slot);
    void storeCurrentPgmDataSettingsInSelectedSlot();
    void loadPgmDataFromSelectedSlot();
    void pullSelectedPgmDataFromHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~ProgramDataSlotsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramDataSlotsComponent)
};