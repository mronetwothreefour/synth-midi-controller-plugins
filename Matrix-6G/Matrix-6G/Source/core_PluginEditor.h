#pragma once

#include <JuceHeader.h>

#include "gui/gui_LookAndFeel.h"



class ButtonForActivatingQuickPatchEdit;
class ControlsLayer;
class GUILookAndFeel;

class PluginEditor :
    public juce::AudioProcessorEditor,
    public ValueTree::Listener
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<ControlsLayer> controlsLayer;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;
    std::unique_ptr<ButtonForActivatingQuickPatchEdit> button_ForActivatingQuickPatchEdit;
    std::unique_ptr<TooltipWindow> tooltipWindow;

public:
    explicit PluginEditor(PluginProcessor& processor, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics& g) override;
    void resized() override;
    void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
