#pragma once

#include "G_DRAW_Envelope_P.h"

class Layer_Envelopes_P :
	public Component,
	public Data_User_P
{
private: Component trigger_area_env;
private: Component trigger_area_vca_env;
private: Draw_Envelope_P env;
private: Draw_Envelope_P vca_env;

//==============================================================================
public: explicit Layer_Envelopes_P(Data_Hub_P* hub);

public: void resized() override;
public: void mouseEnter(const MouseEvent& e) override;
public: void mouseExit(const MouseEvent& e) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Layer_Envelopes_P)
};