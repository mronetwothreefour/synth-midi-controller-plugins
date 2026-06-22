#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Wheel_Mod_B.h"

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
private: const bool inverted_range;

//==============================================================================
public: Slider_Wheel_Mod_P(Data_Hub_P* hub, Ctrl_Type ctrl_type) :
			Slider_Wheel_Mod_B{ hub },
			inverted_range{ ctrl_type == Ctrl_Type::slider_osc_balance }
		{
			if (ctrl_type == Ctrl_Type::slider_osc_balance) {
				setSliderStyle(SliderStyle::LinearHorizontal);
				setSliderSnapsToMousePosition(false);
			}
		}

public: double proportionOfLengthToValue(double proportion) override {
			return Slider::proportionOfLengthToValue(inverted_range ? 1.0 - proportion : proportion);
		}

public: double valueToProportionOfLength(double value) override {
			auto proportion = Slider::valueToProportionOfLength(value);
			return inverted_range ? 1.0 - proportion : proportion;
		}
};