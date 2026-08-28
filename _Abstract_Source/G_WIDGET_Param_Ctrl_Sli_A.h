#pragma once

#include "G_WIDGET_Param_Ctrl_A.h"
#include "G_WIDGET_Sli_Label_P.h"
#include "G_WIDGET_Sli_Wheel_Mod_P.h"

using Slider_Attachment = SliderParameterAttachment;

namespace WIDGET
{

	class Param_Ctrl_Slider_A :
		public Param_Ctrl_A,
		public Slider_Wheel_Mod
	{
	protected: Slider_Label label;
	protected: std::unique_ptr<Slider_Attachment> attachment;

	//==============================================================================
	public: Param_Ctrl_Slider_A(const String& param_id, Data_Hub* hub);

	public: void resized() override;
	public: void attach_to_param() override;
	public: void remove_attachment() override;
	protected: virtual void set_drag_sensitivity();
	protected: void mouseDoubleClick(const MouseEvent& e) override;
	public: void modifierKeysChanged(const Mods& mods) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Param_Ctrl_Slider_A)
	};

}
