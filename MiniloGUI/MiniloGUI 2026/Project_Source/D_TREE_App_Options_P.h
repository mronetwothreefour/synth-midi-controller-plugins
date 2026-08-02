#pragma once

#include "D_TREE_App_Options_G.h"

class Tree_App_Options_P :
	public Tree_App_Options_G
{
//==============================================================================
public: Tree_App_Options_P();

public: const bool show_envelope();
public: void set_show_envelope(const bool should_show);

public: const bool show_vca_envelope();
public: void set_show_vca_envelope(const bool should_show);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_App_Options_P)
};