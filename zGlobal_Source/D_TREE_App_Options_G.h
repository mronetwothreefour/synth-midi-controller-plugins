#pragma once

#include <JuceHeader.h>

#include "C_ENUM_P.h"

using namespace ENUM;

class Tree_App_Options_G
{
protected: ValueTree tree;

//==============================================================================
public: Tree_App_Options_G();

public: const int scale_percentage();
public: void set_scale_percentage(const int new_setting);
public: void set_scale_percentage_excluding(const int new_setting, 
											ValueTree::Listener* listener_to_exclude);

public: void add_listener(ValueTree::Listener* listener);
public: void remove_listener(ValueTree::Listener* listener);
public: Value get_option_as_value(App_Option option);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tree_App_Options_G)
};