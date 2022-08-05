#pragma once

#include <JuceHeader.h>

#include "splits_SplitSlotsComponent.h"
#include "../widgets_ComboBox/widget_splits_ComboBoxForSelectingZoneMIDIout.h"
#include "../widgets_ComboBox/widget_splits_ComboBoxForSelectingZoneVoiceAssignments.h"
#include "../widgets_Button/widget_splits_ButtonForLoadingSelectedSplit.h"
#include "../widgets_Button/widget_splits_ButtonForPullingEntireBankFromHardware.h"
#include "../widgets_Button/widget_splits_ButtonForPullingSelectedSplitFromHardware.h"
#include "../widgets_Button/widget_splits_ButtonForPushingEntireBankToHardware.h"
#include "../widgets_Button/widget_splits_ButtonForSavingCurrentSplitSettingsInSelectedSlot.h"
#include "../widgets_Label/widget_EditableLabel.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneLimit.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneVoiceNumber.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneTranspose.h"
#include "../widgets_Slider/widget_splits_SliderForSettingZoneVolumeBalance.h"



class SplitsBankTransmissionComponent;
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
    SliderForSettingZoneVoiceNumber slider_ForSettingLowerZoneVoiceNumber;
    SliderForSettingZoneTranspose slider_ForSettingLowerZoneTranspose;
    ComboBoxForSelectingZoneMIDIout comboBox_ForSelectingLowerZoneMIDIout;
    SliderForSettingZoneLimit slider_ForSettingUpperZoneLimit;
    SliderForSettingZoneVoiceNumber slider_ForSettingUpperZoneVoiceNumber;
    SliderForSettingZoneTranspose slider_ForSettingUpperZoneTranspose;
    ComboBoxForSelectingZoneMIDIout comboBox_ForSelectingUpperZoneMIDIout;
    SplitSlotsComponent splitSlots;
    ButtonForLoadingSelectedSplit button_ForLoadingSelectedSplit;
    ButtonForSavingCurrentSplitSettingsInSelectedSlot button_ForSavingCurrentSplitSettingsInSelectedSlot;
    ButtonForPullingSelectedSplitFromHardware button_ForPullingSelectedSplitFromHardware;
    ButtonForPushingEntireSplitBankToHardware button_ForPushingEntireBankToHardware;
    ButtonForPullingEntireSplitsBankFromHardware button_ForPullingEntireBankFromHardware;
    std::unique_ptr<SplitsBankTransmissionComponent> pushEntireBankComponent;
    std::unique_ptr<SplitsBankTransmissionComponent> pullEntireBankComponent;

public:
    SplitsComponent() = delete;

    explicit SplitsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void padNameLessThan6CharactersLongWithSpaces(String& name);
    String generateSplitNameTooltipString();
    void sliderValueChanged(Slider* slider) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    void buttonClicked(Button* button) override;

private:
    void showPushEntireBankComponent();
    void showPullEntireBankComponent();
    void hideThisComponent();

public:
    ~SplitsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitsComponent)
};