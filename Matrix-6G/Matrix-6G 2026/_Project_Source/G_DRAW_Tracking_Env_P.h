#pragma once

#include "D_X_G_Data_User_P.h"

namespace DRAW
{

	class Tracking_Env :
		public Component,
		public Data_User,
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
	public: explicit Tracking_Env(Data_Hub* hub);

	public: void paint(Graphics& g) override;
	public: void valueChanged(Value& value) override;
	public: ~Tracking_Env();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Tracking_Env)
	};

}
