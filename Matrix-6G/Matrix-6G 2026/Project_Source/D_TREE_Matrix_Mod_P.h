#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"

using namespace ENUM;

class Tree_Matrix_Mod_P
{
private: ValueTree tree;
private: UndoManager* u_m;

//==============================================================================
public: explicit Tree_Matrix_Mod_P(UndoManager* u_m);

public: const int mod_amt(const int mod_num);
public: void set_mod_amt(const int mod_num, const int new_setting);

public: const int mod_dest(const int mod_num);
public: void set_mod_dest(const int mod_num, const int new_setting);

public: const int mod_src(const int mod_num);
public: void set_mod_src(const int mod_num, const int new_setting);

public: Value get_param_as_value(const int mod_num, const Matrix_Mod_Param param);

public: std::unique_ptr<XmlElement> get_state();
public: void replace_state(const ValueTree& new_state);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_Matrix_Mod_P)
};