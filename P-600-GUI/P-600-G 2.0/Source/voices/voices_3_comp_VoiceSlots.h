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
class VoiceTransmissionOptions;

class VoiceSlots :
    public Component,
    private Timer
{
    ExposedParameters* exposedParams;
    Outgoing_MIDI_Buffers* outgoingBuffers;
    VoicesBank* voicesBank;
    VoiceTransmissionOptions* transmitOptions;
    std::vector<std::unique_ptr<VoiceSlotRadioButton>> voiceSlotButtons;
    Label voiceNameEditor;
    const int voiceSlots_w{ 10 * GUI::voiceSlotRadioButtton_w };
    const int voiceSlots_h{ 10 * GUI::voiceSlotAndAllowChoiceRadioButtton_h };
    const int voiceNameInset{ 17 };

public:
    uint8 selectedSlot;

    VoiceSlots() = delete;

    VoiceSlots(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
    void saveCurrentVoiceSettingsIntoSelectedSlot();
    void loadVoiceFromSelectedSlot();
    void pullSelectedVoiceFromHardware();
    void pushSelectedVoiceToHardware();
    void showVoiceNameEditorForSelectedSlot();

private:
    void timerCallback() override;

public:
    ~VoiceSlots();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlots)
};

