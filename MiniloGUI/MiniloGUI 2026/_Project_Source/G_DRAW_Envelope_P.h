#pragma once

#include "G_DRAW_Envelope_A.h"

namespace DRAW
{

class Envelope :
	public Envelope_A
{
//==============================================================================
public: Envelope(bool vca_env, Data_Hub * hub);

public: void paint(Graphics& g) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope)
};

}
