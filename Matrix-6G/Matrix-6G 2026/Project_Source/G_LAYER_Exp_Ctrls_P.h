#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Cbox_Exp_G.h"
#include "G_WIDG_Slider_Exp_P.h"

class Layer_Exposed_Controls_P :
	public Component,
	public Data_User_P
{
private: std::vector<std::unique_ptr<Combo_Box_Exposed_G>> cboxes;
private: std::vector<std::unique_ptr<Slider_Exposed_P>> sliders;

//==============================================================================
public: Layer_Exposed_Controls_P(Data_Hub_P* hub);

public: void resized() override;
public: ~Layer_Exposed_Controls_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Layer_Exposed_Controls_P)
};