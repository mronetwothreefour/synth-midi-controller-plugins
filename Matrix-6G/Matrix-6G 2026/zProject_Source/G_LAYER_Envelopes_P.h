#pragma once

#include "G_DRAW_Envelope_P.h"
#include "G_DRAW_Tracking_Env_P.h"

class Layer_Envelopes_P :
	public Component,
	public Data_User_P
{
private: Draw_Tracking_Env_P tracking_env;
private: Draw_Envelope_P env_1;
private: Draw_Envelope_P env_2;
private: Draw_Envelope_P env_3;

//==============================================================================
public: explicit Layer_Envelopes_P(Data_Hub_P* hub);

public: void resized() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Layer_Envelopes_P)
};