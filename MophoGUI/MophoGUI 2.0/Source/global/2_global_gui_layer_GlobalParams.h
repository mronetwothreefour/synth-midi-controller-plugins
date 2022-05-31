#pragma once

#include <JuceHeader.h>

#include "1_global_comp_KnobForGlobalParam.h"
#include "1_global_comp_ComboBoxForGlobalParam.h"
#include "1_global_comp_DisplayLabelForGlobalParam.h"
#include "1_global_comp_EditorForTooltipDelay.h"
#include "1_global_comp_ToggleForTooltipParam.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_GlobalParameters :
    public Component,
    private Timer
{
    UnexposedParameters* unexposedParams;
    ButtonForHidingLayer button_Close;
    KnobForGlobalParameter knob_GlobalTranspose;
    KnobForGlobalParameter knob_GlobalFineTune;
    KnobForGlobalParameter knob_HardwareReceiveChannel;
    ComboBoxForGlobalParameter comboBox_MIDI_ClockSource;
    ComboBoxForGlobalParameter comboBox_PedalMode;
    ComboBoxForGlobalParameter comboBox_VoiceChange;
    ComboBoxForGlobalParameter comboBox_ParamChangeSendType;
    DisplayLabelForGlobalParameter label_ParamChangeReceiveType;
    DisplayLabelForGlobalParameter label_MIDI_ControllersStatus;
    DisplayLabelForGlobalParameter label_SysExStatus;
    DisplayLabelForGlobalParameter label_AudioOutput;
    DisplayLabelForGlobalParameter label_HardwareOutputBalance;
    ToggleForTooltipParameter toggle_CurrentValueTooltip;
    ToggleForTooltipParameter toggle_DescriptionTooltip;
    EditorForTooltipDelay editorForTooltipDelay;

public:
    GUI_Layer_GlobalParameters() = delete;

    explicit GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;

private:
    void timerCallback() override;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_GlobalParameters)
};