#pragma once

#include <JuceHeader.h>

#include "dXg_Audio_Processor_p.h"

class Editor :
    public AudioProcessorEditor
{
private: Audio_Processor& processor;

//==============================================================================
public: Editor(Audio_Processor& processor);

public: void paint(Graphics& g) override;
public: void resized() override;
public: void modifierKeysChanged(const ModifierKeys& mods) override;
public: ~Editor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
