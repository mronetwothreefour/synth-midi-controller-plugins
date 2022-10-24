#pragma once

#include <JuceHeader.h>

#include "global_1_comp_SliderForGlobalParam.h"
#include "global_1_comp_ComboBoxForGlobalParam.h"
#include "global_1_comp_EditorForTooltipDelay.h"
#include "global_3_gui_layer_VoiceMap.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class TooltipsOptions;
class UnexposedParameters;

class GUI_Layer_GlobalParameters :
    public Component,
    public Value::Listener
{
    TooltipsOptions* tooltips;
    ButtonForHidingLayer btn_Close;
    SliderForGlobalParameter slider_BasicChannel;
    ComboBoxForGlobalParameter comboBox_OmniMode;
    ComboBoxForGlobalParameter comboBox_Controllers;
    ComboBoxForGlobalParameter comboBox_VoiceChanges;
    ComboBoxForGlobalParameter comboBox_SysEx;
    ComboBoxForGlobalParameter comboBox_Spillover;
    ComboBoxForGlobalParameter comboBox_MIDI_Echo;
    ComboBoxForGlobalParameter comboBox_MIDI_Mono;
    ComboBoxForGlobalParameter comboBox_ActiveSensing;
    ComboBoxForGlobalParameter comboBox_LocalControl;
    SliderForGlobalParameter slider_Pedal_1_ControllerNum;
    SliderForGlobalParameter slider_Pedal_2_ControllerNum;
    SliderForGlobalParameter slider_Lever_2_ControllerNum;
    SliderForGlobalParameter slider_Lever_3_ControllerNum;
    SliderForGlobalParameter slider_VibratoSpeed;
    ComboBoxForGlobalParameter comboBox_VibratoWaveType;
    SliderForGlobalParameter slider_VibratoAmplitude;
    ComboBoxForGlobalParameter comboBox_VibratoSpeedModSource;
    SliderForGlobalParameter slider_VibratoSpeedModAmount;
    ComboBoxForGlobalParameter comboBox_VibratoAmpModSource;
    SliderForGlobalParameter slider_VibratoAmpModAmount;
    SliderForGlobalParameter slider_GlobalTune;
    ComboBoxForGlobalParameter comboBox_SplitStereo;
    ComboBoxForGlobalParameter comboBox_VoiceMap;
    ComboBoxForGlobalParameter comboBox_VoiceMapEcho;
    SliderForGlobalParameter slider_DisplayBrightness;
    ComboBoxForGlobalParameter comboBox_SQUICK;
    ComboBoxForGlobalParameter comboBox_DescriptionTooltip;
    ComboBoxForGlobalParameter comboBox_CurrentChoiceTooltip;
    EditorForTooltipDelay editorForTooltipDelay;
    TextButton btn_ShowVoiceMap;
    TextButton btn_Push;
    std::unique_ptr<GUI_Layer_VoiceMap> voiceMapLayer;
    Value shouldShowDescriptionAsValue;
    const Rectangle<int> borderBounds{ 299, 129, 654, 338 };

public:
    GUI_Layer_GlobalParameters() = delete;

    explicit GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams);
    void updateTooltips();
    void paint(Graphics& g) override;
    void valueChanged(Value& value) override;
    void showVoiceMapLayer();
    ~GUI_Layer_GlobalParameters();

private:

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_GlobalParameters)
};