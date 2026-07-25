#pragma once

#include "G_WIDG_Exp_Ctrl_G.h"

using Btn_Attachment = ButtonParameterAttachment;

class Toggle_Exposed_P :
	public Exposed_Control_G,
	public Component
{
protected: ToggleButton toggle;
protected: std::unique_ptr<Btn_Attachment> attachment;

//==============================================================================
public: Toggle_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub);

public: void resized() override;
public: void attach_to_param() override;
public: void remove_attachment() override;
public: void mouseDown(const MouseEvent& e) override;
public: void modifierKeysChanged(const Mods& mods) override;
public: void update_according_to_mod() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Toggle_Exposed_P)
};