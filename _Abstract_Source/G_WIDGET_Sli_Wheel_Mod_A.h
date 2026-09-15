#pragma once

#include "G_WIDGET_Ctrl_A.h"

using Mods = ModifierKeys;

namespace WIDGET
{

	class Slider_Wheel_Mod_A :
		public Ctrl_A,
		public Slider
	{
	public: bool for_pitch;

	//==============================================================================
	public: Slider_Wheel_Mod_A(const std::string& param_id, Value param_value, Data_Hub* hub);

	protected: void update_ctrl_setting() override;
	public: void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override;
	protected: virtual void mod_value(double increment, double& current_value);
	protected: virtual void alt_mod_value(double /*increment*/, double& /*current_value*/) {}
	protected: virtual void ctrl_mod_value(double /*increment*/, double& /*current_value*/) {}
	protected: virtual void shift_mod_value(double increment, double& current_value);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod_A)
	};

}
