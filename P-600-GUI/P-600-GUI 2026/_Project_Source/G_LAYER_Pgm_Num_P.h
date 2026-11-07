#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Ctrl_Slider_P.h"

using namespace WIDGET;

namespace LAYER
{

	class Pgm_Num :
		public Component,
		public Data_User
	{
	private: Value val_pgm_num;
	private: Ctrl_Slider sli_pgm_num;
	private: const Rectangle<int> init_bounds_pgm_num;

	//==============================================================================
	public: explicit Pgm_Num(Data_Hub* hub);

	public: void resized() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Pgm_Num)
	};

}
