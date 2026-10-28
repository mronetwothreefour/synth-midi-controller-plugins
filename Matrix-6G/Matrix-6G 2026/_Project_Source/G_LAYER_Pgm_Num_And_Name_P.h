#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Ctrl_Slider_P.h"

using namespace WIDGET;

namespace LAYER
{

	class Pgm_Num_And_Name :
		public Component,
		public Data_User,
		public Value::Listener
	{
	private: Value val_pgm_num;
	private: Value val_pgm_name;
	private: Ctrl_Slider sli_pgm_num;
	private: Label lbl_pgm_name;
	private: bool name_edited_by_label;
	private: const Rectangle<int> init_bounds_pgm_num;
	private: const Rectangle<int> init_bounds_pgm_name;

	//==============================================================================
	public: explicit Pgm_Num_And_Name(Data_Hub* hub);

	public: void resized() override;
	public: void valueChanged(Value& value) override;
	public: void modifierKeysChanged(const Mods& mods) override;
	public: ~Pgm_Num_And_Name();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Pgm_Num_And_Name)
	};

}