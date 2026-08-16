#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Tip_Updater_A.h"

namespace WIDGET
{

	class Param_Ctrl_A :
		public Data_User,
		public Value::Listener
	{
	protected: RangedAudioParameter* param_ptr;
	protected: Value param_val;
	protected: String linked_param_id;
	protected: RangedAudioParameter* linked_param_ptr;
	protected: Value linked_param_val;
	protected: Tip_Updater_A tip_update;
	public: const StringArray choices;
	public: const StringArray choices_curt;
	private: Rectangle<int> init_bounds;

	//==============================================================================
	public: Param_Ctrl_A(const String& param_id, Data_Hub* hub);

	public: virtual void attach_to_param()=0;
	public: virtual void remove_attachment()=0;
	public: Rectangle<int> scaled_bounds();
	public: virtual void update_tip_current_choice();
	public: virtual void linked_param_changed() {};
	public: void valueChanged(Value& value) override;
	public: ~Param_Ctrl_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Param_Ctrl_A)
	};

}