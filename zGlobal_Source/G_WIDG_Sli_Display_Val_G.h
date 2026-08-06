#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Sli_Wheel_Mod_P.h"
#include "G_WIDG_Tip_Updater_G.h"

class Slider_Display_Value_G :
	public Label,
	public Slider::Listener,
	public Data_User_P
{
protected: const Slider_Display_Type display_type;
protected: Slider_Wheel_Mod_P* parent_slider;
protected: Tip_Updater_G tip_update;
protected: const StringArray& choices_list;
protected: const StringArray& choices_list_curt;

//==============================================================================
public: Slider_Display_Value_G(Data_Hub_P* hub, const Slider_Display_Type display_type,
							   Slider_Wheel_Mod_P* parent_slider);

public: void resized() override;
private: virtual void on_editor_show()=0;
public: virtual void set_text_to_stored_choice();
private: virtual void on_text_change()=0;
public: void sliderValueChanged(Slider* slider) override;
public: ~Slider_Display_Value_G();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Display_Value_G)
};