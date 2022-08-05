#pragma once

#include <JuceHeader.h>

#include "../widgets_Label/widget_EditableLabel.h"
#include "../widgets_Slider/widget_SliderForVoiceNumber.h"



class UnexposedParameters;

class VoiceNumberAndNameLayer :
    public Component,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    SliderForVoiceNumber slider_ForVoiceNumber;
    EditableLabel voiceNameEditor;

public:
    VoiceNumberAndNameLayer() = delete;

    explicit VoiceNumberAndNameLayer(UnexposedParameters* unexposedParams);
    void resized() override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void padNameLessThan8CharactersLongWithSpaces(String& name);
    void sliderValueChanged(Slider* slider) override;
    String generateVoiceNumberTooltipString();
    String generateVoiceNameTooltipString();
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~VoiceNumberAndNameLayer() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoiceNumberAndNameLayer)
};