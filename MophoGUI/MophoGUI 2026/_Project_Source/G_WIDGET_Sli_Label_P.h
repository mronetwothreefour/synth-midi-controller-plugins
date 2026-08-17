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
	private: float text_to_float(const String& text);
	private: float text_to_float_lfo_freq(const String& text);
	private: float text_to_float_osc_pitch_and_lpf_freq(const String& text);
	private: float text_to_float_osc_shape(const String& text);
	private: float text_to_float_seq_step(const String& text);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Label)
	};

}
