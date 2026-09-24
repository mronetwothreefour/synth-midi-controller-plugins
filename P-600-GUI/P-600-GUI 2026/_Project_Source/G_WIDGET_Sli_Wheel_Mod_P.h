#pragma once

#include "G_WIDGET_Sli_Wheel_Mod_A.h"

namespace WIDGET
{

	class Slider_Wheel_Mod :
		public Slider_Wheel_Mod_A
	{
	//==============================================================================
	public: Slider_Wheel_Mod(const std::string& param_id, Value param_value, Data_Hub* hub);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod)
	};

}
