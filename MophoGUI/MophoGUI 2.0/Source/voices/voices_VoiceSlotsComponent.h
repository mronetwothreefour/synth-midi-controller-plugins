#pragma once

#include <JuceHeader.h>

#include "voices_VoicesBanks.h"



class UnexposedParameters;

class VoiceSlotsComponent :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton voiceSlotButtons[128];
    const VoicesBank bank;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;

public:
    uint8 selectedSlot;

    VoiceSlotsComponent() = delete;

    VoiceSlotsComponent(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void setUpVoiceSlotToggleButton(uint8 slot);
    void setTooltipForVoiceSlotToggleButton(uint8 slot);
    void setTextForVoiceSlotToggleButton(uint8 slot);
    void saveCurrentVoiceSettingsIntoSelectedSlot();
    void loadVoiceFromSelectedSlot();
    void pullSelectedVoiceFromHardware();
    void pushSelectedVoiceToHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~VoiceSlotsComponent();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlotsComponent)
};

