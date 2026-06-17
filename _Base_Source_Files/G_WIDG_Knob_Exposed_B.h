#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Exposed_Control_B.h"
#include "G_WIDG_Knob_Display_Exposed_P.h"
#include "G_WIDG_Slider_Wheel_Mod_P.h"

class Knob_Exposed_B :
	public Exposed_Control_B,
	public Slider_Wheel_Mod_P
{
protected: const int param_index;
protected: Knob_Display_Exposed_P display;
protected: std::unique_ptr<SliderParameterAttachment> attachment;

//==============================================================================
public: Knob_Exposed_B(const int param_index, Data_Hub_P* hub);

public: void resized() override;
public: void set_modifying_pitch(bool is_true);
public: void attach_to_param() override;
public: void remove_attachment() override;
protected: void mouseDoubleClick(const MouseEvent& e) override;
};