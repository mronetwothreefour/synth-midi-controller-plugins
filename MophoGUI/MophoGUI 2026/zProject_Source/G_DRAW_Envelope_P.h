#pragma once

#include "G_DRAW_Envelope_G.h"

class Draw_Envelope_P :
	public Draw_Envelope_G
{
//==============================================================================
public: Draw_Envelope_P(Env_Type env_type, Data_Hub_P* hub);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Draw_Envelope_P)
};