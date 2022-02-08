#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_patchMap_SliderForSettingInPatchForProgramNumber.h"
#include "../widgets_Slider/widget_patchMap_SliderForSettingOutPatchForProgramNumber.h"



class UnexposedParameters;

class PatchMapSlot :
    public Component,
    public Slider::Listener
{
    UnexposedParameters* unexposedParams;
    uint8 programNumber;
    SliderForSettingInPatchForProgramNumber slider_ForSettingInPatch;
    SliderForSettingOutPatchForProgramNumber slider_ForSettingOutPatch;

public:
    PatchMapSlot() = delete;

    PatchMapSlot(UnexposedParameters* unexposedParams, uint8 programNumber);
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    ~PatchMapSlot();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchMapSlot)
};