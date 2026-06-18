#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"
#include "D_TIP_Widget_P.h"
#include "G_WIDG_Tooltip_Updater_B.h"

using Tip_W = Tip_Widget_P;

class Knob_Display_Exposed_B :
	public Label,
	public AudioProcessorParameter::Listener,
	public AsyncUpdater,
	public Data_User_P
{
protected: const int param_index;
protected: RangedAudioParameter* param;
protected: const Knob_Display_Type display_type;
protected: Tooltip_Updater_B tip_update;

//==============================================================================
public: Knob_Display_Exposed_B(const int param_index, Data_Hub_P* hub);

public: void resized() override;
private: virtual void on_editor_show()=0;
private: virtual void set_text_to_stored_choice()=0;
private: virtual void on_text_change()=0;
public: void handleAsyncUpdate() override;
public: void parameterValueChanged(int param_index, float new_value) override;
public: void parameterGestureChanged(int /*param_index*/, bool /*starting*/) override {}
public: ~Knob_Display_Exposed_B();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Knob_Display_Exposed_B)
};