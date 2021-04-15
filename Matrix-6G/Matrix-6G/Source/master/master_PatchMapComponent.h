#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class PatchMapComponent :
    public Component,
    public Slider::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingPatchMapComponent;

public:
    PatchMapComponent() = delete;

    explicit PatchMapComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;

private:
    void hideThisComponent();

public:
    ~PatchMapComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchMapComponent)
};