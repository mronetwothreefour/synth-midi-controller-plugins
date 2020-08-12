#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

class ProgramSlotsWidget :
    public Component,
    private Timer
{
    ToggleButton programSlotButtons[128];
    uint8 bank;
    AudioProcessorValueTreeState* exposedParams;
    OutgoingMidiBuffers* outgoingBuffers;
    int buttton_w;
    int buttton_h;
    int buttonHorizontalGap;

    void timerCallback() override;

public:
    uint8 selectedSlot;

    ProgramSlotsWidget(uint8 bank, AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);
    ~ProgramSlotsWidget();

    void resized() override;
    void setTextForProgramSlotToggleButton(uint8 slot);
    void loadProgramFromSelectedSlot();
    void storeCurrentProgramSettingsInSelectedSlot();
    void pushSelectedProgramToHardware();
    void pullSelectedProgramFromHardware();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramSlotsWidget)
};

