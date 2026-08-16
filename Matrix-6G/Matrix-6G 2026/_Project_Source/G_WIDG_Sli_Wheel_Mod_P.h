#pragma once

#include "C_ENUM_P.h"
#include "G_WIDG_Sli_Wheel_Mod_G.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_G
{
private: const bool inverted_range;

//==============================================================================
public: Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type);

public: double proportionOfLengthToValue(double proportion) override;

public: double valueToProportionOfLength(double value) override;
};