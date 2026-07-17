#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Tip_Updater_B.h"

using namespace ENUM;

class Exposed_Control_B:
	public Data_User_P,
	public Value::Listener
{
protected: const int exp_param_index;
protected: RangedAudioParameter* exp_param;
protected: Value val_exp_param;
protected: int mod_param_index;
protected: RangedAudioParameter* mod_param;
protected: Value val_mod_param;
public: const Ctrl_Type ctrl_type;
private: Rectangle<int> init_bounds;
protected: Tip_Updater_B tip_update;

//==============================================================================
public: Exposed_Control_B(const int exp_param_index, Data_Hub_P* hub);

public: virtual void attach_to_param()=0;
public: virtual void remove_attachment()=0;
public: Rectangle<int> get_scaled_bounds();
public: virtual void update_value_tip();
public: virtual void update_according_to_mod() {};
public: void valueChanged(Value& value) override;
public: ~Exposed_Control_B();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Control_B)
};