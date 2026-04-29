#pragma once

#include <JuceHeader.h>

#include "A _0_Processor.h"

class Editor :
    public AudioProcessorEditor
{
private: Processor& processor;

//==============================================================================
public: Editor(Processor& processor);

public: void paint(Graphics& g) override;
public: void resized() override;
public: void modifierKeysChanged(const ModifierKeys& mods) override;
public: ~Editor() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
