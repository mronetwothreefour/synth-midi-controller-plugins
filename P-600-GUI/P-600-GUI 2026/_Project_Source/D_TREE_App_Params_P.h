#pragma once

#include "D_TREE_App_Params_A.h"

namespace TREE
{

	class App_Params :
		public App_Params_A
	{
	//==============================================================================
	public: App_Params(UndoManager* u_m);

	public: const bool auto_push_enabled();
	public: void set_auto_push_enabled(const bool is_true);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(App_Params)
	};

}
