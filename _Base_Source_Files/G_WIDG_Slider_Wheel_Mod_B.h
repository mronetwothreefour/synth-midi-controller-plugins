#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"

class Slider_Wheel_Mod_B :
	public Slider,
	public Data_User_P
{
protected: bool modifying_pitch;

//==============================================================================
public: explicit Slider_Wheel_Mod_B(Data_Hub_P* hub);	

public: void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override;
protected: virtual void alt_increment_value(double increment, double& value);
protected: virtual void ctrl_increment_value(double increment, double& value);
protected: virtual void increment_value(double increment, double& value);
protected: virtual void shift_increment_value(double increment, double& value);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Wheel_Mod_B)
};