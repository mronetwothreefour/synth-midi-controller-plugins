#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBanks.h"
#include "voices_2_comp_VoiceSlotRadioButton.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_Voices.h"

class ExposedParameters;
class OutgoingMidiBuffers;
class UnexposedParameters;
class VoicesBanks;

class VoiceSlots :
    public Component,
    private Timer
{
    const VoicesBank bank;
    ExposedParameters* exposedParams;
    UnexposedParameters* unexposedParams;
    OutgoingMidiBuffers* outgoingMIDI;
    VoicesBanks* voicesBanks;
    std::vector<std::unique_ptr<VoiceSlotRadioButton>> voiceSlotButtons;
    const int voiceSlotRadioButtons_HorizGap{ 5 };
    const int voiceSlots_w{ (8 * GUI::voiceSlotRadioButtton_w) + (7 * voiceSlotRadioButtons_HorizGap) };
    const int voiceSlots_h{ 16 * GUI::voiceSlotRadioButtton_h };

public:
    uint8 selectedSlot;

    VoiceSlots() = delete;

    VoiceSlots(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
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

