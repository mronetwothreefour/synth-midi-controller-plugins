#pragma once

#include "G_DRAW_Envelope_P.h"

class Layer_Envelopes_P :
	public Component,
	public Data_User_P,
	public Value::Listener
{
private: Draw_Envelope_P env;
private: Draw_Envelope_P vca_env;
private: Value val_show_env;
private: Value val_show_vca_env;

//==============================================================================
public: explicit Layer_Envelopes_P(Data_Hub_P* hub);

public: void resized() override;
public: void valueChanged(Value& value) override;
public: ~Layer_Envelopes_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Layer_Envelopes_P)
};