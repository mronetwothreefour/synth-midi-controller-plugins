#pragma once

#include <JuceHeader.h>

#include "D_X_G_Audio_Processor_P.h"

class Editor_P :
    public AudioProcessorEditor
{
private: Audio_Processor_P& processor;
private: Image background_texture;

//==============================================================================
public: Editor_P(Audio_Processor_P& processor);

public: void paint(Graphics& g) override;
public: void resized() override;
public: void modifierKeysChanged(const ModifierKeys& mods) override;
public: ~Editor_P() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
