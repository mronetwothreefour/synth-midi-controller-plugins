#pragma once

#include <JuceHeader.h>

#include "master_VoicesMapComponent.h"
#include "../widgets_Button/widget_master_ButtonForShowingVoicesMapComponent.h"
#include "../widgets_Button/widget_master_ButtonForPushingMasterOptionsToHardware.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingActiveSensingEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingControllersEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingDescriptionTipsEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingLocalControlEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingMIDIechoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingMIDImonoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingOmniModeEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSpilloverEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSplitStereoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSQUICKenabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSysExEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingValueTipsEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingVibratoModSource.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingVibratoWaveType.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingVoiceChangesEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingVoicesMapEchoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingVoicesMapEnabled.h"
#include "../widgets_Label/widget_EditableLabel.h"
#include "../widgets_Slider/widget_master_SliderForSettingBasicChannel.h"
#include "../widgets_Slider/widget_master_SliderForSettingDisplayBrightness.h"
#include "../widgets_Slider/widget_master_SliderForSettingLever2Controller.h"
#include "../widgets_Slider/widget_master_SliderForSettingLever3Controller.h"
#include "../widgets_Slider/widget_master_SliderForSettingMasterTune.h"
#include "../widgets_Slider/widget_master_SliderForSettingPedalController.h"
#include "../widgets_Slider/widget_master_SliderForSettingVibratoAmplitude.h"
#include "../widgets_Slider/widget_master_SliderForSettingVibratoModAmount.h"
#include "../widgets_Slider/widget_master_SliderForSettingVibratoSpeed.h"



class UnexposedParameters;

class MasterOptionsComponent :
    public Component,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingMasterOptionsComponent;
    SliderForSettingBasicChannel slider_ForSettingBasicChannel;
    ComboBoxForSelectingOmniModeEnabled comboBox_ForSelectingOmniModeEnabled;
    ComboBoxForSelectingControllersEnabled comboBox_ForSelectingControllersEnabled;
    ComboBoxForSelectingVoiceChangesEnabled comboBox_ForSelectingVoiceChangesEnabled;
    ComboBoxForSelectingSysExEnabled comboBox_ForSelectingSysExEnabled;
    ComboBoxForSelectingSpilloverEnabled comboBox_ForSelectingSpilloverEnabled;
    ComboBoxForSelectingMIDIechoEnabled comboBox_ForSelectingMIDIechoEnabled;
    ComboBoxForSelectingMIDImonoEnabled comboBox_ForSelectingMIDImonoEnabled;
    ComboBoxForSelectingActiveSensingEnabled comboBox_ForSelectingActiveSensingEnabled;
    ComboBoxForSelectingLocalControlEnabled comboBox_ForSelectingLocalControlEnabled;
    SliderForSettingPedalController slider_ForSettingPedal1Controller;
    SliderForSettingPedalController slider_ForSettingPedal2Controller;
    SliderForSettingLever2Controller slider_ForSettingLever2Controller;
    SliderForSettingLever3Controller slider_ForSettingLever3Controller;
    SliderForSettingVibratoSpeed slider_ForSettingVibratoSpeed;
    SliderForSettingVibratoAmplitude slider_ForSettingVibratoAmplitude;
    ComboBoxForSelectingVibratoWaveType comboBox_ForSelectingVibratoWaveType;
    ComboBoxForSelectingVibratoModSource comboBox_ForSelectingVibratoSpeedModSource;
    SliderForSettingVibratoModAmount sliderForSettingVibratoSpeedModAmount;
    ComboBoxForSelectingVibratoModSource comboBox_ForSelectingVibratoAmplitudeModSource;
    SliderForSettingVibratoModAmount sliderForSettingVibratoAmplitudeModAmount;
    SliderForSettingMasterTune slider_ForSettingMasterTune;
    ComboBoxForSelectingSplitStereoEnabled comboBox_ForSelectingSplitStereoEnabled;
    ComboBoxForSelectingVoiceMapEnabled comboBox_ForSelectingVoicesMapEnabled;
    ComboBoxForSelectingVoicesMapEchoEnabled comboBox_ForSelectingVoiceMapEchoEnabled;
    SliderForSettingDisplayBrightness slider_ForSettingDisplayBrightness;
    ComboBoxForSelectingSQUICKenabled comboBox_ForSelectingSQUICKenabled;
    ComboBoxForSelectingDescriptionTipsEnabled comboBox_ForSelectingDescriptionTipsEnabled;
    ComboBoxForSelectingValueTipsEnabled comboBox_ForSelectingValueTipsEnabled;
    EditableLabel tipsDelayEditor;
    ButtonForShowingVoicesMapComponent button_ForShowingVoiceMapComponent;
    ButtonForPushingMasterOptionsToHardware button_ForPushingMasterOptionsToHardware;
    std::unique_ptr<VoicesMapComponent> voicesMapComponent;

public:
    MasterOptionsComponent() = delete;

    explicit MasterOptionsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    String generateTipsDelayTooltipString();
    void sliderValueChanged(Slider* slider) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    void showVoicesMapComponent();

private:
    void hideThisComponent();

public:
    ~MasterOptionsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterOptionsComponent)
};