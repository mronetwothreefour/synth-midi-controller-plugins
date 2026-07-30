#pragma once

#include "D_X_G_Data_User_P.h"

class Draw_Tracking_Env_P :
	public Component,
	public Data_User_P,
	public Value::Listener
{
private: Array<RangedAudioParameter*> params;
private: Value val_pt_0;
private: Value val_pt_1;
private: Value val_pt_2;
private: Value val_pt_3;
private: Value val_pt_4;
private: Array<float> y_coords;

//==============================================================================
public: explicit Draw_Tracking_Env_P(Data_Hub_P* hub);

public: void paint(Graphics& g) override;
public: void valueChanged(Value& value) override;
public: ~Draw_Tracking_Env_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Draw_Tracking_Env_P)
};