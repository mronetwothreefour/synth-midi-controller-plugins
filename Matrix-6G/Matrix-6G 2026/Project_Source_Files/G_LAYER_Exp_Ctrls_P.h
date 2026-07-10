#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"

class Layer_Exposed_Controls_P :
	public Component,
	public Data_User_P
{
private: std::vector<std::unique_ptr<Component>> controls;

//==============================================================================
public: Layer_Exposed_Controls_P(Data_Hub_P* hub);

public: void resized() override;
public: ~Layer_Exposed_Controls_P();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Layer_Exposed_Controls_P)
};