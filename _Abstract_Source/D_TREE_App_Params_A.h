#pragma once

#include <JuceHeader.h>

namespace TREE
{

	class App_Params_A
	{
	protected: ValueTree tree;
	private: UndoManager* u_m;

	//==============================================================================
	public: App_Params_A(UndoManager* u_m);

	public: const int scale_i();
	public: void set_scale_i(const int new_setting);
	public: void set_scale_i_excluding(const int new_setting,
									   ValueTree::Listener* listener_to_exclude);

	public: void add_listener(ValueTree::Listener* listener);
	public: void remove_listener(ValueTree::Listener* listener);
	public: Value get_param_as_value(const String& param_id);

	public: std::unique_ptr<XmlElement> get_current_state();
	public: void replace_state(const ValueTree& new_state);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(App_Params_A)
	};

}
