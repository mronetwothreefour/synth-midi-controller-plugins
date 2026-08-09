#pragma once

#include "D_X_G_Editor_A.h"

class Editor :
    public Editor_A
{
//==============================================================================
public: Editor(Audio_Processor& processor/*, Data_Hub_P* hub*/);

public: void resized() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
