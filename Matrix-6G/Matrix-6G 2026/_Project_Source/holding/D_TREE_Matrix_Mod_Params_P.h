#pragma once

#include <JuceHeader.h>

namespace TREE
{

	class Matrix_Mod_Params
	{
	private: ValueTree tree;
	private: UndoManager* u_m;

	//==============================================================================
	public: Matrix_Mod_Params(UndoManager* u_m);

	public: const int current_setting_for(const String& param_id);
	public: void set_param(const String& param_id, const int new_setting);

	public: Value get_param_as_value(const String& param_id);

	public: std::unique_ptr<XmlElement> get_current_state();
	public: void replace_state(const ValueTree& new_state);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Matrix_Mod_Params)
	};

}
