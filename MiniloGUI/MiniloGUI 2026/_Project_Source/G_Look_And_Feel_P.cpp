#include "G_Look_And_Feel_P.h"

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Widget = DRAW::Paths_Widgets;

Look_And_Feel::Look_And_Feel(float& scale_factor) :
	Look_And_Feel_A{ scale_factor }
{}

void Look_And_Feel::positionComboBoxText(ComboBox& cbox, Label& lbl) {
	auto icon_w = 11;
	lbl.setBounds(0, 0, cbox.getWidth() - icon_w, cbox.getHeight());
}

PopupMenu::Options Look_And_Feel::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& /*lbl*/) {
	auto param_id = cbox.getComponentID().toStdString();
	auto cbox_area = cbox.getBoundsInParent();
	auto target_area = cbox.getScreenBounds();
	auto selected_item = cbox.getSelectedItemIndex();
	auto item_h = roundToInt(XYWH::cbox_item_h * scale_f);
	auto menu_above = GET::menu_above_for(param_id);
	auto col_count = GET::menu_col_count_for(param_id);
	auto row_count = GET::menu_row_count_for(param_id);
	auto offset_y = (selected_item % row_count + 1) * item_h;
	target_area.translate(0, offset_y - roundToInt(scale_f));
	return PopupMenu::Options().withTargetScreenArea(target_area)
		.withItemThatMustBeVisible(cbox.getSelectedId())
		.withMinimumWidth(cbox.getWidth())
		.withMinimumNumColumns(col_count)
		.withMaximumNumColumns(col_count)
		.withStandardItemHeight(item_h);
}

void Look_And_Feel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool /*separator*/, 
									  const bool active, const bool hilited, const bool ticked, 
									  const bool /*has_submenu*/, const String& txt, 
									  const String& /*shortcut_txt*/, const Drawable* /*icon*/, 
									  const Colour* const /*txt_clr*/)
{
	if (hilited && active) {
		g.setColour(Colour{ COLOR::popup_ground }.brighter(0.05f));
		g.fillRect(area);
	}
	if (ticked) {
		g.setColour(Colour{ COLOR::white });
		auto tick_diam = 4.0f * scale_f;
		g.fillEllipse(4.0f * scale_f, 4.0f * scale_f, tick_diam, tick_diam);
	}
	auto txt_area = area.withTrimmedLeft(roundToInt(12 * scale_f));
	g.setFont(FONT::cbox(scale_f));
	g.setColour(Colour{ COLOR::text });
	g.drawFittedText(txt, txt_area, Justification::centredLeft, 1);
}

void Look_And_Feel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									 float pos, const float min_angle, const float max_angle,
									 Slider& s)
{
	auto rotation = min_angle + pos * (max_angle - min_angle);
	if (s.getComponentID() == ID::exp_lpf_freq)
		Draw_Widget::knob_lpf_freq(g, rotation, scale_f);
	else
		Draw_Widget::knob(g, rotation, scale_f);
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
	if (n == NAME::ctr_sli_sw_key_octv)
		Draw_Widget::switch_keyboard_octave(g, scale_f, roundToInt(s.getValue()));
	if (n == NAME::ctr_sli_sw_lpf)
		Draw_Widget::switch_lpf_type(g, scale_f, roundToInt(s.getValue()));
	if (n == NAME::ctr_sli_sw_osc_octv)
		Draw_Widget::switch_osc_octave(g, scale_f, roundToInt(s.getValue()));
}
