#pragma once

#include <JuceHeader.h>



class GUILookAndFeel;

class PluginEditor : 
    public AudioProcessorEditor
{
    PluginProcessor& processor;
    std::unique_ptr<GUILookAndFeel> lookAndFeel;

public:
    PluginEditor(PluginProcessor& processor, UndoManager* undoManager);
    void paint(Graphics&) override;
    void resized() override;
    ~PluginEditor() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
