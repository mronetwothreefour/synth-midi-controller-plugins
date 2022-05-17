#pragma once

#include <JuceHeader.h>



class ButtonForShowingGlobalParametersComponent;
class ButtonsLayer;
class EnvelopeRenderersLayer;
class ExposedParamsControlsLayer;
class GUILookAndFeel;
class UnexposedParameters;

class PluginEditor :
    public AudioProcessorEditor,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<EnvelopeRenderersLayer> envelopeRenderersLayer;
    std::unique_ptr<ExposedParamsControlsLayer> exposedParamsControlsLayer;
    std::unique_ptr<ButtonsLayer> buttonsLayer;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

public:
    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;

public:
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
