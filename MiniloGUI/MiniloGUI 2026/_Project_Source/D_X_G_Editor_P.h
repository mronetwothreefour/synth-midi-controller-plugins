#pragma once

#include "D_X_G_Editor_A.h"
//#include "G_LAYER_Envelopes_P.h"

class Editor :
    public Editor_A
{
//private: Layer_Envelopes_P layer_envelopes;

//==============================================================================
public: Editor(Audio_Processor& processor, Data_Hub* hub);

public: void resized() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
