#include "G_Look_And_Feel_P.h"

#include "C_ID_A.h"
#include "C_NAME_P.h"
#include "G_DRAW_Paths_LED_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Widget = DRAW::Paths_Widgets;

Look_And_Feel::Look_And_Feel(float& scale_factor) :
	Look_And_Feel_A{ scale_factor }
{}

void Look_And_Feel::draw_label_p(Graphics& g, Label& lbl, String& lbl_id) {
	if (lbl_id == NAME::lbl_led_num) {
		if (!lbl.isBeingEdited()) {
			auto txt{ lbl.getText() };
			auto transform = AffineTransform::scale(scale_f);
			if (lbl.getComponentID() == ID::app_curr_pgm_num) {
				transform = transform.translated(5.0f * scale_f, 8.0f * scale_f);
				DRAW::Paths_LED::digit(g, txt.substring(0, 1).getIntValue(), transform);
				transform = transform.translated(26.0f * scale_f, 0.0f);
				DRAW::Paths_LED::digit(g, txt.substring(1, 2).getIntValue(), transform);
			}
		}
	}
}

void Look_And_Feel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									 const float min_angle, const float max_angle, Slider& s)
{
	if (s.getName() != NAME::ctr_sli_led_num) {
		auto rotation = min_angle + pos * (max_angle - min_angle);
		Draw_Widget::knob(g, rotation, scale_f);
	}
}

void Look_And_Feel::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float /*pos*/, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	auto n = s.getName();
	if (n == NAME::ctr_sli_sw_2)
		Draw_Widget::switch_2_pole(g, scale_f, roundToInt(s.getValue()));
	if (n == NAME::ctr_sli_sw_3)
		Draw_Widget::switch_3_pole(g, scale_f, roundToInt(s.getValue()));
}

