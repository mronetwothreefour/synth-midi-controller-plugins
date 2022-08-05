#pragma once

#include <JuceHeader.h>

#include "splits_SplitsBank.h"



class UnexposedParameters;

class SplitSlotsComponent :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton splitSlotButtons[50];
    UnexposedParameters* unexposedParams;

public:
    uint8 selectedSlot;

    SplitSlotsComponent() = delete;

    explicit SplitSlotsComponent(UnexposedParameters* unexposedParams);
    void setUpSplitSlotToggleButton(uint8 slot);
    void setTooltipForSplitSlotToggleButton(uint8 slot);
    void setTextForSplitSlotToggleButton(uint8 slot);
    void storeCurrentSplitSettingsInSelectedSlot();
    void loadSplitFromSelectedSlot();
    void pullSelectedSplitFromHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~SplitSlotsComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitSlotsComponent)
};