#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_SliderForProgramNumber.h"



class UnexposedParameters;

class ProgramNumberLayer :
    public Component,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    SliderForProgramNumber slider_ForProgramNumber;

public:
    ProgramNumberLayer() = delete;

    explicit ProgramNumberLayer(UnexposedParameters* unexposedParams);
    void resized() override;
    void sliderValueChanged(Slider* slider) override;
    String generateProgramNumberTooltipString();
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~ProgramNumberLayer() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNumberLayer)
};