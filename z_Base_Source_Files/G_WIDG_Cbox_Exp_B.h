#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Exp_Ctrl_B.h"

class Combo_Box_Exposed_B :
	public Exposed_Control_B,
	public ComboBox
{
protected: std::unique_ptr<ComboBoxParameterAttachment> attachment;

//==============================================================================
public: Combo_Box_Exposed_B(const int param_index, Data_Hub_P* hub);

public: void attach_to_param() override;
public: void remove_attachment() override;
public: void mouseDown(const MouseEvent& e) override;
public: void modifierKeysChanged(const Mods& mods) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Combo_Box_Exposed_B)
};