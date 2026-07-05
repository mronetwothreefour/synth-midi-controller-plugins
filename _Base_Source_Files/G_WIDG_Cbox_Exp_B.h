#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Exp_Ctrl_B.h"

class Combo_Box_Exposed_B :
	public Exposed_Control_B,
	public ComboBox
{
protected: std::unique_ptr<ComboBoxParameterAttachment> attachment;

//==============================================================================
public: Combo_Box_Exposed_B(const int param_index, Data_Hub_P* hub) :
			Exposed_Control_B{ param_index, hub }
		{
			auto choices_list = exp_info.choices_list_for(param_index, true);
			addItemList(choices_list, 1);
		}

public: void attach_to_param() override {
				 attachment.reset(new ComboBoxParameterAttachment{ *exp_param, *this, Exposed_Control_B::u_m });
			 }

public: void remove_attachment() override {
			 	 attachment = nullptr;
			 }

public: void modifierKeysChanged(const Mods& mods) override {
				 tip_update.on_mod_keys_changed(mods, this);
			 }
};