#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_Hub_P.h"
#include "C_FONT_P.h"

class Data_User_G
{
protected: Data_Hub_P* hub;
//protected: const Tree_Exposed_Info_P& exp_info;
protected: UndoManager* u_m;
//protected: AudioProcessorValueTreeState* exp_state;
protected: float& scale_factor;

//==============================================================================
public: explicit Data_User_G(Data_Hub_P* hub) :
	hub{ hub },
	//exp_info{ hub->get_exposed_info() },
	u_m{ hub->get_undo_mngr() },
	//exp_state{ hub->get_exposed_state() },
	scale_factor{ hub->get_scale_factor() }
{}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Data_User_G)
};