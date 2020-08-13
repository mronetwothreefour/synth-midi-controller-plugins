#pragma once

#include <JuceHeader.h>



class GUILookAndFeel;
class UnexposedParameters;

class PluginEditor : 
    public AudioProcessorEditor
{
    PluginProcessor& processor;
    AudioProcessorValueTreeState* exposedParams;
    UnexposedParameters* unexposedParams;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;

public:
    PluginEditor(PluginProcessor& processor, UndoManager* undoManager, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
    void paint(Graphics&) override;
    void resized() override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
