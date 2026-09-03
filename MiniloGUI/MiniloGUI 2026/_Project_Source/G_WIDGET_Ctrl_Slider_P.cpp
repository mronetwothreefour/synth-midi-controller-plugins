#include "G_WIDGET_Ctrl_Slider_P.h"

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"

using namespace WIDGET;

Ctrl_Slider::Ctrl_Slider(const String& param_id, Value param_val, Data_Hub* hub) :
	Ctrl_Slider_A{ param_id, param_val, hub }
{
	auto n = getName();
	if (n == NAME::knob_lfo_rate) {
		linked_param_val = avp.get_param_as_value(ID::avp_lfo_sync_bpm_on);
		linked_param_val.addListener(this);
	}
	if (n == NAME::knob_voice_mode_depth) {
		linked_param_val = avp.get_param_as_value(ID::avp_voice_mode);
		linked_param_val.addListener(this);
	}
	if (n.startsWith("switch_"))
		removeChildComponent(&label);
	linked_param_changed();
}

void Ctrl_Slider::update_tip_current_choice() {
	auto n = getName();
	if (n == NAME::knob_lfo_rate || n == NAME::knob_voice_mode_depth) {
		auto& choice = Ctrl_A::choices[roundToInt(getValue())];
		String tip{};
		if (n == NAME::knob_lfo_rate) {
			if (avp.lfo_sync_bpm_on())
				tip = choice.fromFirstOccurrenceOf("|", false, false);
			else
				tip = choice.upToFirstOccurrenceOf("|", false, false);
		}
		else {
			auto mode = avp.voice_mode();
			if (mode == 1 || mode == 2)
				tip = choice.fromFirstOccurrenceOf("2&3:", false, false);
			else
				tip = choice.fromFirstOccurrenceOf(String{ mode + 1 } + ":", false, false);
			tip = tip.upToFirstOccurrenceOf("|", false, false);
		}
		tip_update.tip_current_choice = tip;
	}
	else
		Ctrl_Slider_A::update_tip_current_choice();
}

void Ctrl_Slider::linked_param_changed() {
	label.set_text_to_stored_choice();
	if (getName() == NAME::knob_voice_mode_depth)
		update_for_voice_mode(avp.voice_mode());
	Timer::callAfterDelay(10, [this] { update_tip_current_choice(); });
}
