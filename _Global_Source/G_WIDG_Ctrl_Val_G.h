#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Tip_Updater_G.h"

class Control_Value_G :
	public Data_User_P,
	public Value::Listener
{
protected: Value val_param;
public: const Ctrl_Type ctrl_type;
public: const StringArray choices_list;
public: const StringArray choices_list_curt;
private: const Rectangle<int> init_bounds;
protected: Tip_Updater_G tip_update;

//==============================================================================
public: Control_Value_G(Value val_param, const Ctrl_Type ctrl_type, Data_Hub_P* hub,
						StringArray choices_list, StringArray choices_list_curt,
						const Rectangle<int> init_bounds, const String& info_tip);

public: Rectangle<int> get_scaled_bounds();
public: virtual void update_value_tip();
public: void valueChanged(Value& value) override;
public: ~Control_Value_G();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Control_Value_G)
};