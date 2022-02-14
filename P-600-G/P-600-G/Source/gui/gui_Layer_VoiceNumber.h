#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_SliderForVoiceNumber.h"



class UnexposedParameters;

class VoiceNumberLayer :
    public Component,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    SliderForVoiceNumber slider_ForVoiceNumber;

public:
    VoiceNumberLayer() = delete;

    explicit VoiceNumberLayer(UnexposedParameters* unexposedParams);
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    String generateVoiceNumberTooltipString();
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~VoiceNumberLayer() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceNumberLayer)
};