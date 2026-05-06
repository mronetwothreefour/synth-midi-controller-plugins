#pragma once

#include <JuceHeader.h>

#include "C_ENUM.h"

using namespace ENUM;

class Exposed_Parameter_Info
{
private: ValueTree tree;

//==============================================================================
public: Exposed_Parameter_Info();

private: const ValueTree param(const uint8 param_index) const;
public: const Identifier id_for(const uint8 param_index) const;
public: const uint8 param_num_for(const uint8 param_index) const;
public: const String name_for(const uint8 param_index) const;
public: const Ctrl_Type ctrl_type_for(const uint8 param_index) const;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Parameter_Info)
};