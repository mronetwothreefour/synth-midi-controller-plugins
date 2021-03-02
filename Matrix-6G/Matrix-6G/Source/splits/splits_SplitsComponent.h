#pragma once

#include <JuceHeader.h>
#include "splits_SplitSlotsComponent.h"
#include "../widgets_ComboBox/widget_splits_ComboBoxForSelectingZoneVoiceAssignments.h"



class UnexposedParameters;

class SplitsComponent :
    public Component,
    public Button::Listener,
    public ComboBox::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingSplitsComponent;
    ComboBoxForSelectingZoneVoiceAssignments comboBox_ForSelectingZoneVoiceAssignments;
    SplitSlotsComponent splitSlots;

public:
    SplitsComponent() = delete;

    explicit SplitsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;

private:
    void hideThisComponent();

public:
    ~SplitsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsComponent)
};