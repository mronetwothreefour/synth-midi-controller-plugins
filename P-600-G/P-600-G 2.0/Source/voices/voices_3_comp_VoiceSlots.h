#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBank.h"
#include "voices_2_comp_VoiceSlotRadioButton.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_Voices.h"

class ExposedParameters;
class Outgoing_MIDI_Buffers;
class UnexposedParameters;

class VoiceSlots :
    public Component,
    private Timer
{
    ExposedParameters* exposedParams;
    UnexposedParameters* unexposedParams;
    Outgoing_MIDI_Buffers* outgoingMIDI;
    VoicesBank* voicesBank;
    std::vector<std::unique_ptr<VoiceSlotRadioButton>> voiceSlotButtons;
    const int voiceSlots_w{ 10 * GUI::voiceSlotRadioButtton_w };
    const int voiceSlots_h{ 10 * GUI::voiceSlotRadioButtton_h };

public:
    uint8 selectedSlot;

    VoiceSlots() = delete;

    VoiceSlots(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void saveCurrentVoiceSettingsIntoSelectedSlot();
    void loadVoiceFromSelectedSlot();
    void pullSelectedVoiceFromHardware();
    void pushSelectedVoiceToHardware();

private:
    void timerCallback() override;

public:
    ~VoiceSlots();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlots)
};

