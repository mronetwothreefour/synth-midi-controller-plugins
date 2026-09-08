#pragma once

#include "G_WIDGET_Sli_Label_A.h"

namespace WIDGET
{

	class Slider_Label :
		public Slider_Label_A
	{
	private: const bool for_osc_balance;

	//==============================================================================
	public: Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider);

	private: void on_editor_show() override;
	private: void on_text_change() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Label)
	};

}
