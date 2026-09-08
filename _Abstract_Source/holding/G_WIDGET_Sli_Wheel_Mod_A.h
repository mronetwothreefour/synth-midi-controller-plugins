#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;

namespace WIDGET
{

	class Slider_Wheel_Mod_A :
		public Slider
	{
	private: UndoManager* u_m;
	public: bool for_pitch;
	public: const StringArray choices;
	public: const StringArray choices_curt;

	//==============================================================================
	public: explicit Slider_Wheel_Mod_A(const String& param_id, UndoManager* u_m);

	public: void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override;
	protected: virtual void mod_value(double increment, double& current_value);
	protected: virtual void alt_mod_value(double /*increment*/, double& /*current_value*/) {}
	protected: virtual void ctrl_mod_value(double /*increment*/, double& /*current_value*/) {}
	protected: virtual void shift_mod_value(double increment, double& current_value);

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod_A)
	};

}
