#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"
#include "../widgets_ComboBox/widget_global_ComboBoxForMidiClock.h"
#include "../widgets_Slider/widget_global_KnobForGlobalFineTune.h"
#include "../widgets_Slider/widget_global_KnobForGlobalMidiChannel.h"
#include "../widgets_Slider/widget_global_KnobForGlobalTranspose.h"
#include "../widgets_ToggleButton/widget_global_ToggleButtonForSysEx.h"



class UnexposedParameters;

class GlobalParametersComponent : 
    public Component,
    public Button::Listener,
    public ComboBox::Listener,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener,
    private Timer
{
    UnexposedParameters* unexposedParams;
    const uint16 nrpnType_SysExOn;
    const uint16 nrpnType_GlobalTranspose;
    const uint16 nrpnType_GlobalFineTune;
    const uint16 nrpnType_GlobalMidiChannel;
    const uint16 nrpnType_MidiClock;
    TextButton button_ForClosingGlobalParameters;
    KnobForGlobalTranspose knob_ForGlobalTranspose;
    RendererForKnobValueStrings valueDisplay_ForGlobalTranspose;
    KnobForGlobalFineTune knob_ForGlobalFineTune;
    RendererForKnobValueStrings valueDisplay_ForGlobalFineTune;
    KnobForGlobalMidiChannel knob_ForGlobalMidiChannel;
    RendererForKnobValueStrings valueDisplay_ForGlobalMidiChannel;
    ComboBoxForMidiClock comboBox_ForMidiClock;
    ToggleButtonForSysEx toggle_ForSysEx;

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
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void sendNewValueForNRPNtypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType);
    void timerCallback() override;

public:
    ~GlobalParametersComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParametersComponent)
};