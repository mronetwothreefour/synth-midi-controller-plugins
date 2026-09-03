#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Ctrl_Cbox_A.h"
#include "G_WIDGET_Ctrl_Slider_P.h"

using namespace WIDGET;

namespace LAYER
{

	class Ctrls_Aux_Voice :
		public Component,
		public Data_User
	{
	private: OwnedArray<Ctrl_Cbox_A, CriticalSection> cboxes;
	private: OwnedArray<Ctrl_Slider, CriticalSection> sliders;

	//==============================================================================
	public: explicit Ctrls_Aux_Voice(Data_Hub* hub);

	public: void resized() override;
	public: ~Ctrls_Aux_Voice();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ctrls_Aux_Voice)
	};

}
