#pragma once

#include <JuceHeader.h>



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
    TextButton button_ForClosingGlobalParameters;

public:
    GlobalParametersComponent() = delete;

    explicit GlobalParametersComponent(UnexposedParameters* unexposedParams);

private:
    void hideThisComponent();

public:
    void paint(Graphics& g) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void buttonStateChanged(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;
    void editorShown(Label* label, TextEditor& editor) override;
    void labelTextChanged(Label* label) override;
    void sliderValueChanged(Slider* slider) override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

private:
    void timerCallback() override;

public:
    ~GlobalParametersComponent() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParametersComponent)
};