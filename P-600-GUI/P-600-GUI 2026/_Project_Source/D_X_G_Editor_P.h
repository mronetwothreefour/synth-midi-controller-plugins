#pragma once

#include "D_X_G_Editor_A.h"
#include "G_LAYER_Pgm_Num_P.h"

using namespace LAYER;

class Editor :
    public Editor_A
{
private: Pgm_Num pgm_num;

//==============================================================================
public: Editor(Audio_Processor& processor, Data_Hub* hub);

public: void resized() override;
public: void paint(Graphics& g) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
