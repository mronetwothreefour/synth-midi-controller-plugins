#pragma once

#include <JuceHeader.h>

#include "D_X_G_Audio_Processor_P.h"
#include "D_X_G_Data_User_P.h"

class Editor_P :
    public AudioProcessorEditor,
    public Data_User_P
{
private: Audio_Processor_P& processor;

//==============================================================================
public: Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub);

public: void paint(Graphics& g) override;
public: void resized() override;
public: void modifierKeysChanged(const ModifierKeys& mods) override;
public: ~Editor_P() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
