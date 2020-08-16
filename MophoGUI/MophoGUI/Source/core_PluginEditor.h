#pragma once

#include <JuceHeader.h>

#include "widgets_ControlsForExposedParameters/widget_ControlsForExposedParameters.h"



class ButtonAndLabelForEditingPgmName;
class GUILookAndFeel;
class Logo;
class RendererForEnvelopes;
class UnexposedParameters;

class PluginEditor : 
    public AudioProcessorEditor,
    private ControlsForExposedParameters,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<Logo> logo;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_LPF;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_VCA;
    std::unique_ptr<RendererForEnvelopes> rendererForEnvelope_Env3;
    std::unique_ptr<ButtonAndLabelForEditingPgmName> button_ForEditingPgmName;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics&) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
