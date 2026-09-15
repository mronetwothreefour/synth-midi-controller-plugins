#pragma once

#include "D_X_G_Data_User_P.h"
#include "G_WIDGET_Sli_Wheel_Mod_P.h"
#include "G_WIDGET_Tip_Updater_A.h"

namespace WIDGET
{

	class Slider_Label_A :
		public Label,
		public Slider::Listener,
		public Data_User
	{
	protected: Slider_Wheel_Mod* parent_sli;
	protected: Tip_Updater_A tip_update;
	public: bool editable;
	protected: std::string editor_allowed_chars;
	protected: int editor_char_limit;
	protected: std::string editor_tip;
	protected: const StringArray& choices;
	protected: const StringArray& choices_curt;

	//==============================================================================
	public: Slider_Label_A(const std::string & param_id, Data_Hub* hub,
						   Slider_Wheel_Mod* parent_slider);

	public: void resized() override;
	protected: void on_editor_show();
	protected: virtual void editor_mods_p(TextEditor* /*editor*/) {};
	public: virtual void set_text_to_stored_choice();
	private: virtual void on_text_change()=0;
	public: void sliderValueChanged(Slider* slider) override;
	public: ~Slider_Label_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Label_A)
	};

}