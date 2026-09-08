#pragma once

#include "G_WIDGET_Ctrl_A.h"

using Btn_Attachment = ButtonParameterAttachment;

namespace WIDGET
{

	class Ctrl_Toggle :
		public Ctrl_A,
		public Component
	{
	protected: ToggleButton toggle;
	protected: std::unique_ptr<Btn_Attachment> attachment;

	//==============================================================================
	public: Ctrl_Toggle(const String& param_id, Value param_val, Data_Hub* hub);

	public: void resized() override;
	public: void attach_to_param() override;
	public: void remove_attachment() override;
	protected: void update_ctrl_setting() override;
	public: void mouseDown(const MouseEvent& e) override;
	public: void modifierKeysChanged(const Mods& mods) override;
	public: void linked_param_changed() override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ctrl_Toggle)
	};

}
