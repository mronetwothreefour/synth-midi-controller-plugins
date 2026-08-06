#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Ctrl_Exp_G.h"

using Cbox_Attachment = ComboBoxParameterAttachment;

class Combo_Box_Exposed_G :
	public Control_Exposed_G,
	public ComboBox
{
protected: std::unique_ptr<Cbox_Attachment> attachment;

//==============================================================================
public: Combo_Box_Exposed_G(const Exp_Param param_id, Data_Hub_P* hub);

public: void attach_to_param() override;
public: void remove_attachment() override;
public: void mouseDown(const MouseEvent& e) override;
public: void modifierKeysChanged(const Mods& mods) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Combo_Box_Exposed_G)
};