#pragma once

#include <JuceHeader.h>

#include "splits_0_tree_SplitsBank.h"
#include "splits_1_comp_SplitSlotRadioButton.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_Splits.h"

using namespace Matrix_6G_Constants;

class Outgoing_MIDI_Buffers;
class UnexposedParameters;
class SplitOptions;
class VoiceTransmissionOptions;

class SplitSlots :
    public Component,
    private Timer
{
    Outgoing_MIDI_Buffers* outgoingBuffers;
    SplitsBank* splitsBank;
    SplitOptions* splitOptions;
    VoiceTransmissionOptions* transmitOptions;
    std::vector<std::unique_ptr<SplitSlotRadioButton>> splitSlotButtons;
    const int splitSlotRadioButtons_HorizGap{ 7 };
    const int splitSlots_w{ (5 * GUI::splitSlotRadioButtton_w) + (4 * splitSlotRadioButtons_HorizGap) };
    const int splitSlots_h{ 10 * GUI::voiceAndSplitSlotRadioButtton_h };

public:
    uint8 selectedSlot;

    SplitSlots() = delete;

    explicit SplitSlots(UnexposedParameters* unexposedParams);
    void saveCurrentSplitSettingsIntoSelectedSlot();
    void loadSplitFromSelectedSlot();
    void pullSelectedSplitFromHardware();
    void pushSelectedSplitToHardware();

private:
    void timerCallback() override;

public:
    ~SplitSlots();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitSlots)
};

