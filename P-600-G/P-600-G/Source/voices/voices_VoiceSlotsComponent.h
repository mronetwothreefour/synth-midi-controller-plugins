#pragma once

#include <JuceHeader.h>

#include "voices_Constants.h"
#include "voices_VoicesBank.h"

using namespace constants;



class UnexposedParameters;

class VoiceSlotsComponent :
    public Component,
    public ValueTree::Listener,
    private Timer
{
    ToggleButton voiceSlotButtons[voices::numberOfSlotsInVoicesBank];
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;

public:
    uint8 selectedSlot;

    VoiceSlotsComponent() = delete;

    VoiceSlotsComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
    void setUpVoiceSlotToggleButton(uint8 slot);
    void setTooltipForVoiceSlotToggleButton(uint8 slot);

public:
    void setTextForVoiceSlotToggleButton(uint8 slot);
    void storeCurrentVoiceDataSettingsInSelectedSlot();
    void loadVoiceFromSelectedSlot();
    void pullSelectedVoiceFromHardware();
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~VoiceSlotsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceSlotsComponent)
};