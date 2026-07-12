#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"
#include "D_TIP_Widget_P.h"
#include "G_WIDG_Sli_Wheel_Mod_P.h"
#include "G_WIDG_Tip_Updater_B.h"

using Tip_W = Tip_Widget_P;

class Slider_Display_Exposed_B :
	public Label,
	public Slider::Listener,
	public Data_User_P
{
protected: const int param_index;
protected: const Slider_Display_Type display_type;
protected: Slider_Wheel_Mod_P* parent_slider;
protected: Tip_Updater_B tip_update;
public: bool editable;

//==============================================================================
public: Slider_Display_Exposed_B(const int param_index, Data_Hub_P* hub,
								 Slider_Wheel_Mod_P* parent_slider);

public: void resized() override;
private: virtual void on_editor_show()=0;
public: virtual void set_text_to_stored_choice()=0;
private: virtual void on_text_change()=0;
public: void sliderValueChanged(Slider* slider) override;
public: ~Slider_Display_Exposed_B();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Display_Exposed_B)
};