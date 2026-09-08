#pragma once

#include "G_WIDGET_Sli_Wheel_Mod_A.h"

namespace WIDGET
{

	class Slider_Wheel_Mod :
		public Slider_Wheel_Mod_A
	{
	public: bool for_osc_shape;
	public: bool for_seq_step;
	public: bool for_seq_trk_1;

	//==============================================================================
	public: Slider_Wheel_Mod(const String& param_id, UndoManager* u_m);

	private: void shift_mod_value(double increment, double& current_value) override;

	public: void mouseDown(const MouseEvent& e) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod)
	};

}
