#pragma once

#include "G_WIDG_Exp_Ctrl_G.h"
#include "G_WIDG_Sli_Display_Exp_P.h"
#include "G_WIDG_Sli_Wheel_Mod_P.h"

using Slider_Attachment = SliderParameterAttachment;

class Slider_Exposed_G :
	public Exposed_Control_G,
	public Slider_Wheel_Mod_P
{
protected: Slider_Display_Exposed_P display;
protected: std::unique_ptr<Slider_Attachment> attachment;

//==============================================================================
public: Slider_Exposed_G(const Exp_Param param_id, Data_Hub_P* hub);

public: void resized() override;
public: void attach_to_param() override;
public: void remove_attachment() override;
protected: void mouseDoubleClick(const MouseEvent& e) override;
public: void modifierKeysChanged(const Mods& mods) override;
};