#include "G_Look_And_Feel_P.h"

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
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
	auto cbox_area = cbox.getBoundsInParent();
	auto target_area = cbox.getScreenBounds();
	auto selected_item = cbox.getSelectedItemIndex();
	auto item_h = roundToInt((XYWH::cbox_h - 2) * scale_factor);
	auto item_count = cbox.getNumItems();
	auto items_per_col = item_count / 2 + item_count % 2;
	auto offset_y = (selected_item % items_per_col + 1) * item_h;
	target_area.translate(0, offset_y - roundToInt(scale_factor));
	return PopupMenu::Options().withTargetScreenArea(target_area)
		.withItemThatMustBeVisible(cbox.getSelectedId())
		.withMinimumWidth(cbox.getWidth())
		.withMinimumNumColumns(2)
		.withMaximumNumColumns(2)
		.withStandardItemHeight(item_h);
}

void Look_And_Feel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool /*separator*/, 
									  const bool active, const bool hilited, const bool ticked, 
									  const bool /*has_submenu*/, const String& txt, 
									  const String& /*shortcut_txt*/, const Drawable* /*icon*/, 
									  const Colour* const /*txt_clr*/)
{
	if (hilited && active) {
		g.setColour(COLOR::popup_ground.brighter(0.05f));
		g.fillRect(area);
	}
	if (ticked) {
		g.setColour(COLOR::white);
		auto tick_diam = 4.0f * scale_factor;
		g.fillEllipse(4.0f * scale_factor, 4.0f * scale_factor, tick_diam, tick_diam);
	}
	auto txt_area = area.withTrimmedLeft(roundToInt(12 * scale_factor));
	g.setFont(FONT::cbox(scale_factor));
	g.setColour(COLOR::text);
	g.drawFittedText(txt, txt_area, Justification::centredLeft, 1);
}

void Look_And_Feel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									 float pos, const float min_angle, const float max_angle,
									 Slider& s)
{
	auto rotation = min_angle + pos * (max_angle - min_angle);
	if (s.getName() == NAME::knob_lpf_freq)
		Draw_Widget::knob_lpf_freq(g, rotation, scale_factor);
	else
		Draw_Widget::knob(g, rotation, scale_factor);
}

void Look_And_Feel::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									 float /*pos*/, float /*min_pos*/, float /*max_pos*/,
									 const Slider::SliderStyle /*style*/, Slider& s)
{
	auto n = s.getName();
	if (n == NAME::switch_2_pole)
		Draw_Widget::switch_2_pole(g, scale_factor, roundToInt(s.getValue()));
	if (n == NAME::switch_3_pole)
		Draw_Widget::switch_3_pole(g, scale_factor, roundToInt(s.getValue()));
	if (n == NAME::switch_lpf_type)
		Draw_Widget::switch_lpf_type(g, scale_factor, roundToInt(s.getValue()));
	if (n == NAME::switch_keyboard_octave)
		Draw_Widget::switch_keyboard_octave(g, scale_factor, roundToInt(s.getValue()));
	if (n == NAME::switch_osc_octave)
		Draw_Widget::switch_osc_octave(g, scale_factor, roundToInt(s.getValue()));
}
