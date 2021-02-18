#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class SplitsComponent :
    public Component,
    public Button::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingSplitsComponent;

public:
    SplitsComponent() = delete;

    explicit SplitsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void buttonClicked(Button* button) override;

private:
    void hideThisComponent();

public:
    ~SplitsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsComponent)
};