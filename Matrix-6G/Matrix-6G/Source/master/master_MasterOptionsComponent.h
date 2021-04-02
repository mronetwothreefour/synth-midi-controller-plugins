#pragma once

#include <JuceHeader.h>

#include "../widgets_Button/widget_master_ButtonForPullingMasterOptionsFromHardware.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingActiveSensingEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingControllersEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingLocalControlEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingMIDIechoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingMIDImonoEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingOmniModeEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingPatchChangesEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSpilloverEnabled.h"
#include "../widgets_ComboBox/widget_master_ComboBoxForSelectingSysExEnabled.h"
#include "../widgets_Slider/widget_master_SliderForSettingBasicChannel.h"
#include "../widgets_Slider/widget_master_SliderForSettingLever2Controller.h"
#include "../widgets_Slider/widget_master_SliderForSettingLever3Controller.h"
#include "../widgets_Slider/widget_master_SliderForSettingPedalController.h"



class UnexposedParameters;

class MasterOptionsComponent :
    public Component,
    public ComboBox::Listener,
    public Slider::Listener
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingMasterOptionsComponent;
    SliderForSettingBasicChannel slider_ForSettingBasicChannel;
    ComboBoxForSelectingOmniModeEnabled comboBox_ForSelectingOmniModeEnabled;
    ComboBoxForSelectingControllersEnabled comboBox_ForSelectingControllersEnabled;
    ComboBoxForSelectingPatchChangesEnabled comboBox_ForSelectingPatchChangesEnabled;
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
    ButtonForPullingMasterOptionsFromHardware button_ForPullingMasterOptionsFromHardware;

public:
    MasterOptionsComponent() = delete;

    explicit MasterOptionsComponent(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void sliderValueChanged(Slider* slider) override;

private:
    void hideThisComponent();

public:
    ~MasterOptionsComponent();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MasterOptionsComponent)
};