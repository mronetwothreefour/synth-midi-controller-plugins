#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Ctrl_Slider_P.h"

using namespace WIDGET;

namespace LAYER
{

	class Ctrls_Exposed :
		public Component,
		public Data_User
	{
	private: Component trig_area_env;
	private: Component trig_area_vca_env;
	private: OwnedArray<Ctrl_Slider, CriticalSection> sliders;

	//==============================================================================
	public: explicit Ctrls_Exposed(Data_Hub* hub);

	public: void resized() override;
	public: void mouseEnter(const MouseEvent& e) override;
	public: void mouseExit(const MouseEvent& e) override;
	public: void mouseUp(const MouseEvent& e) override;
	public: ~Ctrls_Exposed();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ctrls_Exposed)
	};

}
