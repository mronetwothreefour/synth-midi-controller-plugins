#pragma once

#include "G_DRAW_Envelope_P.h"

namespace LAYER
{

class Envelopes :
	public Component,
	public Data_User,
	public Value::Listener
{
private: DRAW::Envelope env;
private: DRAW::Envelope vca_env;
private: Value val_show_env;
private: Value val_show_vca_env;

//==============================================================================
public: explicit Envelopes(Data_Hub * hub);

public: void resized() override;
public: void valueChanged(Value& value) override;
public: ~Envelopes();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelopes)
};

}
