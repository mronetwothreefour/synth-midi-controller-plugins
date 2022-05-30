#pragma once

#include <JuceHeader.h>

#include "1_global_comp_KnobForGlobalParam.h"



class UnexposedParameters;

class GUI_Layer_GlobalParameters :
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    private Timer
{
    UnexposedParameters* unexposedParams;
    TextButton button_Close;
    KnobForGlobalParameter knob_GlobalTranspose;
    KnobForGlobalParameter knob_GlobalFineTune;
    KnobForGlobalParameter knob_HardwareReceiveChannel;
    ComboBox comboBox_MIDI_Clock;
    ComboBox comboBox_PedalMode;
    ComboBox comboBox_VoiceChange;
    ComboBox comboBox_ParamChangeSendType;
    Label label_ParamChangeReceiveType;
    Label label_MIDI_ControllersStatus;
    Label label_SysExStatus;
    Label label_AudioOutput;
    Label label_BalanceTweak;
    ToggleButton toggle_CurrentSettingTooltip;
    ToggleButton toggle_DescriptionTooltip;
    Label label_TooltipDelayEditor;

public:
    GUI_Layer_GlobalParameters() = delete;

    explicit GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void sliderValueChanged(Slider* slider) override;

private:
    void sendNewValueForNRPN_TypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType);
    void timerCallback() override;
    void hideThisLayer();

public:
    ~GUI_Layer_GlobalParameters() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_GlobalParameters)
};