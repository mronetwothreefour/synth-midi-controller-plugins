#pragma once

#include <JuceHeader.h>

#include "D_X_G_Editor_G.h"

class Editor_P :
    public Editor_G
{
//==============================================================================
public: Editor_P(Audio_Processor_P& processor/*, Data_Hub_P* hub*/);

public: void resized() override;
public: ~Editor_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
