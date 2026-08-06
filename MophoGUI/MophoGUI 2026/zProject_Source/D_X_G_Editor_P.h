#pragma once

#include "D_X_G_Editor_G.h"
#include "G_LAYER_Envelopes_P.h"

class Editor_P :
    public Editor_G
{
private: Layer_Envelopes_P layer_envelopes;

//==============================================================================
public: Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub);

public: void resized() override;
public: ~Editor_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor_P)
};
