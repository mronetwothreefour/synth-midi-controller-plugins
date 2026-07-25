#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Tip_Updater_G.h"

class Exposed_Control_G:
	public Data_User_P,
	public Value::Listener
{
protected: const Exp_Param param_id;
protected: RangedAudioParameter* exp_param;
protected: Value val_exp_param;
protected: Exp_Param mod_param_id;
protected: RangedAudioParameter* mod_param;
protected: Value val_mod_param;
public: const Ctrl_Type ctrl_type;
private: Rectangle<int> init_bounds;
protected: Tip_Updater_G tip_update;

//==============================================================================
public: Exposed_Control_G(const Exp_Param param_id, Data_Hub_P* hub);

public: virtual void attach_to_param()=0;
public: virtual void remove_attachment()=0;
public: Rectangle<int> get_scaled_bounds();
public: virtual void update_value_tip();
public: virtual void update_according_to_mod() {};
public: void valueChanged(Value& value) override;
public: ~Exposed_Control_G();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Control_G)
};