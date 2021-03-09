#pragma once

#include <JuceHeader.h>
#include "splits_SplitSlotsComponent.h"
#include "../widgets_ComboBox/widget_splits_ComboBoxForSelectingZoneVoiceAssignments.h"
#include "../widgets_Button/widget_splits_ButtonForLoadingSelectedSplit.h"
#include "../widgets_Button/widget_splits_ButtonForPullingSelectedSplitFromHardware.h"
#include "../widgets_Label/widget_EditableLabel.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneLimit.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZonePatchNumber.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneVolumeBalance.h"



class UnexposedParameters;

class SplitsComponent :
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingSplitsComponent;
    EditableLabel splitNameEditor;
    ComboBoxForSelectingZoneVoiceAssignments comboBox_ForSelectingZoneVoiceAssignments;
    SliderForSettingZoneVolumeBalance slider_ForSettingZoneVolumeBalance;
    SliderForSettingZoneLimit slider_ForSettingLowerZoneLimit;
    SliderForSettingZonePatchNumber slider_ForSettingLowerZonePatchNumber;
    SliderForSettingZoneLimit slider_ForSettingUpperZoneLimit;
    SliderForSettingZonePatchNumber slider_ForSettingUpperZonePatchNumber;
    SplitSlotsComponent splitSlots;
    ButtonForLoadingSelectedSplit button_ForLoadingSelectedSplit;
    ButtonForPullingSelectedSplitFromHardware button_ForPullingSelectedSplitFromHardware;

public:
    SplitsComponent() = delete;

    explicit SplitsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void padNameLessThan6CharactersLongWithSpaces(String& name);
    String generateSplitNameTooltipString();
    void sliderValueChanged(Slider* slider) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void hideThisComponent();

public:
    ~SplitsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsComponent)
};