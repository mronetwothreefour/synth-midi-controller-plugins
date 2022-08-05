#pragma once

#include <JuceHeader.h>

#include "global_VoicesMapComponent.h"
#include "../widgets_Button/widget_global_ButtonForPushingGlobalOptionsToHardware.h"
#include "../widgets_Button/widget_global_ButtonForShowingVoicesMapComponent.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingActiveSensingEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingControllersEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingDescriptionTipsEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingLocalControlEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingMIDIechoEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingMIDImonoEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingOmniModeEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingSpilloverEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingSplitStereoEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingSQUICKenabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingSysExEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingValueTipsEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingVibratoModSource.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingVibratoWaveType.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingVoiceChangesEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingVoicesMapEchoEnabled.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForSelectingVoicesMapEnabled.h"
#include "../widgets_Label/widget_EditableLabel.h"
#include "../widgets_Slider/widget_global_SliderForSettingBasicChannel.h"
#include "../widgets_Slider/widget_global_SliderForSettingDisplayBrightness.h"
#include "../widgets_Slider/widget_global_SliderForSettingLever2Controller.h"
#include "../widgets_Slider/widget_global_SliderForSettingLever3Controller.h"
#include "../widgets_Slider/widget_global_SliderForSettingGlobalTune.h"
#include "../widgets_Slider/widget_global_SliderForSettingPedalController.h"
#include "../widgets_Slider/widget_global_SliderForSettingVibratoAmplitude.h"
#include "../widgets_Slider/widget_global_SliderForSettingVibratoModAmount.h"
#include "../widgets_Slider/widget_global_SliderForSettingVibratoSpeed.h"



class UnexposedParameters;

class GlobalOptionsComponent :
    public Component,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingGlobalOptionsComponent;
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
    SliderForSettingGlobalTune slider_ForSettingGlobalTune;
    ComboBoxForSelectingSplitStereoEnabled comboBox_ForSelectingSplitStereoEnabled;
    ComboBoxForSelectingVoiceMapEnabled comboBox_ForSelectingVoicesMapEnabled;
    ComboBoxForSelectingVoicesMapEchoEnabled comboBox_ForSelectingVoiceMapEchoEnabled;
    SliderForSettingDisplayBrightness slider_ForSettingDisplayBrightness;
    ComboBoxForSelectingSQUICKenabled comboBox_ForSelectingSQUICKenabled;
    ComboBoxForSelectingDescriptionTipsEnabled comboBox_ForSelectingDescriptionTipsEnabled;
    ComboBoxForSelectingValueTipsEnabled comboBox_ForSelectingValueTipsEnabled;
    EditableLabel tipsDelayEditor;
    ButtonForShowingVoicesMapComponent button_ForShowingVoiceMapComponent;
    ButtonForPushingGlobalOptionsToHardware button_ForPushingGlobalOptionsToHardware;
    std::unique_ptr<VoicesMapComponent> voicesMapComponent;

public:
    GlobalOptionsComponent() = delete;

    explicit GlobalOptionsComponent(UnexposedParameters* unexposedParams);
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
    ~GlobalOptionsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptionsComponent)
};