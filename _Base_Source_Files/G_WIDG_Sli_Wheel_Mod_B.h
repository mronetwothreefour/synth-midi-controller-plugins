#pragma once

#include <JuceHeader.h>

using Mods = ModifierKeys;

class Slider_Wheel_Mod_B :
	public Slider
{
private: UndoManager* u_m;
public: bool modifying_pitch;

//==============================================================================
public: explicit Slider_Wheel_Mod_B(UndoManager* u_m);	

public: void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override;
protected: virtual void increment_value(double increment, double& value);
protected: virtual void alt_increment_value(double /*increment*/, double& /*value*/) {}
protected: virtual void ctrl_increment_value(double /*increment*/, double& /*value*/) {}
protected: virtual void shift_increment_value(double increment, double& value);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod_B)
};