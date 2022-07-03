#pragma once

#include <JuceHeader.h>

#include "voices_1_tree_VoicesBanks.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_Voices.h"



class ExposedParameters;
class OutgoingMidiBuffers;
class UnexposedParameters;
class VoicesBanks;
class VoiceTransmissionOptions;

class VoiceSlots :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton voiceSlotButtons[VCS::numberOfSlotsInVoicesBank];
    const VoicesBank bank;
    ExposedParameters* exposedParams;
    UnexposedParameters* unexposedParams;
    OutgoingMidiBuffers* outgoingMIDI;
    VoicesBanks* voicesBanks;
    VoiceTransmissionOptions* voiceTransmit;
    const int voiceSlotRadioButtton_w{ 125 };
    const int voiceSlotRadioButtton_h{ 19 };
    const int voiceSlotRadioButtons_HorizGap{ 7 };
    const int voiceSlots_w{ (8 * voiceSlotRadioButtton_w) + (7 * voiceSlotRadioButtons_HorizGap) };
    const int voiceSlots_h{ 16 * voiceSlotRadioButtton_h };

public:
    uint8 selectedSlot;

    VoiceSlots() = delete;

    VoiceSlots(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void setTextForVoiceSlotToggleButton(uint8 slot);
    void saveCurrentVoiceSettingsIntoSelectedSlot();
    void loadVoiceFromSelectedSlot();
    void pullSelectedVoiceFromHardware();
    void pushSelectedVoiceToHardware();
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~VoiceSlots();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlots)
};
