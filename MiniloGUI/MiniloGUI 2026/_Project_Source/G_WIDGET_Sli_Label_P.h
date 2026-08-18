#pragma once

#include "G_WIDGET_Sli_Label_A.h"

namespace WIDGET
{

	class Slider_Label :
		public Slider_Label_A
	{
	//==============================================================================
	public: Slider_Label(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider);

	private: void on_editor_show() override;
	public: void set_text_to_stored_choice() override;
	private: void on_text_change() override;
	private: void on_text_change_get_best_match();
	private: void on_text_change_lfo_rate();
	private: void on_text_change_unsigned_10_bit();
	private: void on_text_change_voice_mode_depth();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Label)
	};

}
