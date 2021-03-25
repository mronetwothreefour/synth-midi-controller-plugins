#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_master_ButtonForPullingMasterOptionsFromHardware.h"
#include "../widgets_Slider/widget_master_SliderForSettingBasicChannel.h"



class UnexposedParameters;

class MasterOptionsComponent :
    public Component,
    public Slider::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingMasterOptionsComponent;
    SliderForSettingBasicChannel slider_ForSettingBasicChannel;
    ButtonForPullingMasterOptionsFromHardware button_ForPullingMasterOptionsFromHardware;

public:
    MasterOptionsComponent() = delete;

    explicit MasterOptionsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;

private:
    void hideThisComponent();

public:
    ~MasterOptionsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterOptionsComponent)
};