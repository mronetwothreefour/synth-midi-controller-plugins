#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForMidiClock.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForParameterSend.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForPedalMode.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForProgramChange.h"
#include "../widgets_Labels/widget_global_DisplayLabelForAudioOutput.h"
#include "../widgets_Labels/widget_global_DisplayLabelForBalanceTweak.h"
#include "../widgets_Labels/widget_global_DisplayLabelForMidiControllers.h"
#include "../widgets_Labels/widget_global_DisplayLabelForParameterReceive.h"
#include "../widgets_Labels/widget_global_DisplayLabelForSysEx.h"
#include "../widgets_Labels/widget_global_LabelForSettingTooltipDelay.h"
#include "../widgets_Slider/widget_global_KnobForGlobalFineTune.h"
#include "../widgets_Slider/widget_global_KnobForGlobalMidiChannel.h"
#include "../widgets_Slider/widget_global_KnobForGlobalTranspose.h"
#include "../widgets_ToggleButton/widget_global_ToggleButtonForCurrentSettingTooltip.h"
#include "../widgets_ToggleButton/widget_global_ToggleButtonForDescriptionTooltip.h"



class UnexposedParameters;

class GlobalParametersComponent : 
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    private Timer
{
    UnexposedParameters* unexposedParams;
    TextButton button_ForClosingGlobalParameters;
    KnobForGlobalTranspose knob_ForGlobalTranspose;
    RendererForKnobValueStrings valueDisplay_ForGlobalTranspose;
    KnobForGlobalFineTune knob_ForGlobalFineTune;
    RendererForKnobValueStrings valueDisplay_ForGlobalFineTune;
    KnobForGlobalMidiChannel knob_ForGlobalMidiChannel;
    RendererForKnobValueStrings valueDisplay_ForGlobalMidiChannel;
    ComboBoxForMidiClock comboBox_ForMidiClock;
    ComboBoxForPedalMode comboBox_ForPedalMode;
    ComboBoxForProgramChange comboBox_ForProgramChange;
    ComboBoxForParameterSend comboBox_ForParameterSend;
    DisplayLabelForParameterReceive displayLabel_ForParameterReceive;
    DisplayLabelForMidiControllers displayLabel_ForMidiControllers;
    DisplayLabelForSysEx displayLabel_ForSysEx;
    DisplayLabelForAudioOutput displayLabel_ForAudioOutput;
    DisplayLabelForBalanceTweak displayLabel_ForBalanceTweak;
    ToggleButtonForCurrentSettingTooltip toggle_ForCurrentSettingTooltip;
    ToggleButtonForDescriptionTooltip toggle_ForDescriptionTooltip;
    LabelForSettingTooltipDelay label_ForSettingTooltipDelay;

public:
    GlobalParametersComponent() = delete;

    explicit GlobalParametersComponent(UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();

public:
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void sliderValueChanged(Slider* slider) override;

private:
    void sendNewValueForNRPNtypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType);
    void timerCallback() override;

public:
    ~GlobalParametersComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParametersComponent)
};