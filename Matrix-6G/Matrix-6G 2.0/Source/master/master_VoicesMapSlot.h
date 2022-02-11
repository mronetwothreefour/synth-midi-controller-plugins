#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_voicesMap_SliderForSettingInVoiceForProgramNumber.h"
#include "../widgets_Slider/widget_voicesMap_SliderForSettingOutProgramNumber.h"



class UnexposedParameters;

class VoicesMapSlot :
    public Component,
    public Slider::Listener
{
    UnexposedParameters* unexposedParams;
    uint8 programNumber;
    SliderForSettingInVoiceForProgramNumber slider_ForSettingInVoice;
    SliderForSettingOutProgramNumber slider_ForSettingOutProgramNumber;

public:
    VoicesMapSlot() = delete;

    VoicesMapSlot(UnexposedParameters* unexposedParams, uint8 programNumber);
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    ~VoicesMapSlot();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoicesMapSlot)
};