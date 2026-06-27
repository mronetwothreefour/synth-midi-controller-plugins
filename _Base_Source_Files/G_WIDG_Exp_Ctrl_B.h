#pragma once

#include <JuceHeader.h>

#include "D_X_G_Data_User_P.h"
#include "G_WIDG_Tip_Updater_B.h"

using namespace ENUM;

class Exposed_Control_B:
	public Data_User_P,
	public AudioProcessorParameter::Listener,
	public AsyncUpdater
{
protected: const int param_index;
protected: RangedAudioParameter* param;
public: const Ctrl_Type ctrl_type;
protected: Tip_Updater_B tip_update;

//==============================================================================
private: Exposed_Control_B();
public: Exposed_Control_B(const int param_index, Data_Hub_P* hub);

public: virtual void attach_to_param()=0;
public: virtual void remove_attachment()=0;
public: virtual void update_value_tip();
public: void handleAsyncUpdate() override;
public: void parameterValueChanged(int param_index, float new_value) override;
public: void parameterGestureChanged(int /*param_index*/, bool /*starting*/) override {}
public: ~Exposed_Control_B();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Exposed_Control_B)
};