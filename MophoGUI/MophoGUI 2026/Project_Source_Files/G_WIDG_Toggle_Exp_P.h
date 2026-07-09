#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Exp_Ctrl_B.h"

class Toggle_Exposed_P :
	public Exposed_Control_B,
	public Component
{
protected: ToggleButton toggle;
protected: std::unique_ptr<ButtonParameterAttachment> attachment;

//==============================================================================
public: Toggle_Exposed_P(const int param_index, Data_Hub_P* hub);

public: void resized() override;
public: void attach_to_param() override;
public: void remove_attachment() override;
public: void mouseDown(const MouseEvent& e) override;
public: void update_according_to_mod() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Toggle_Exposed_P)
};