#pragma once

#include "D_X_G_Editor_A.h"
#include "G_LAYER_Buttons_Main_P.h"
#include "G_LAYER_Envelopes_P.h"
#include "G_LAYER_Ctrls_MMod_P.h"
#include "G_LAYER_Pgm_Num_And_Name_P.h"

using namespace LAYER;

class Editor :
    public Editor_A
{
private: Envelopes envelopes;
private: Buttons_Main buttons;
private: Ctrls_Matrix_Mod ctrls_mmod;
private: Pgm_Num_And_Name pgm_num_and_name;

//==============================================================================
public: Editor(Audio_Processor& processor, Data_Hub* hub);

public: void resized() override;
public: ~Editor();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)
};
