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
	protected: Slider_Wheel_Mod* parent_slider;
	protected: Tip_Updater_A tip_update;
	public: bool editable;
	private: const StringArray& choices;
	private: const StringArray& choices_curt;

	//==============================================================================
	public: Slider_Label_A(const String& param_id, Data_Hub* hub, Slider_Wheel_Mod* parent_slider);

	public: void resized() override;
	private: virtual void on_editor_show()=0;
	public: virtual void set_text_to_stored_choice();
	private: virtual void on_text_change()=0;
	public: void sliderValueChanged(Slider* slider) override;
	public: ~Slider_Label_A();

	//==============================================================================
	private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Label_A)
	};

}