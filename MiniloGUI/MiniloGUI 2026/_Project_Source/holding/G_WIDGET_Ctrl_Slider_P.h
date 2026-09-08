#pragma once

#include "G_WIDGET_Ctrl_Slider_A.h"

namespace WIDGET
{

	class Ctrl_Slider :
		public Ctrl_Slider_A
	{
	//==============================================================================
	public: Ctrl_Slider(const String& param_id, Value param_val, Data_Hub* hub);

	public: void update_tip_current_choice() override;
	public: void linked_param_changed() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ctrl_Slider)
	};

}
