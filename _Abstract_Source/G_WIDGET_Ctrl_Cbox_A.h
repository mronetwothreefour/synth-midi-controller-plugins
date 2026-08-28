#pragma once

#include "G_WIDGET_Ctrl_A.h"

using Cbox_Attachment = ComboBoxParameterAttachment;

namespace WIDGET
{

	class Ctrl_Cbox_A :
		public Ctrl_A,
		public ComboBox
	{
	protected: std::unique_ptr<Cbox_Attachment> attachment;

	//==============================================================================
	public: Ctrl_Cbox_A(const String& param_id, Value param_val, Data_Hub* hub);

	public: void attach_to_param() override;
	public: void remove_attachment() override;
	public: void mouseDown(const MouseEvent& e) override;
	public: void modifierKeysChanged(const Mods& mods) override;

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ctrl_Cbox_A)
	};

}