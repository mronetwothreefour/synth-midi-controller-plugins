#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_SliderForPatchNumber.h"



class UnexposedParameters;

class PatchNumberAndNameLayer :
    public Component,
    public Label::Listener,
    public Slider::Listener,
    public ValueTree::Listener
{
    UnexposedParameters* unexposedParams;
    SliderForPatchNumber slider_ForPatchNumber;
    Label patchNameEditor;

public:
    PatchNumberAndNameLayer() = delete;

    explicit PatchNumberAndNameLayer(UnexposedParameters* unexposedParams);
    void resized() override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void padNameLessThan8CharactersLongWithSpaces(String& name);
    void sliderValueChanged(Slider* slider) override;
    void paint(Graphics& g) override;
    String generatePatchNumberTooltipString();
    String generatePatchNameTooltipString();
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~PatchNumberAndNameLayer() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchNumberAndNameLayer)
};