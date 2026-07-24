#include "G_LOOK_AND_FEEL_P.h"

#include "C_COLOR_P.h"
#include "C_ENUM_P.h"
#include "C_EXP_P.h"
#include "C_FONT_P.h"
#include "C_ID_P.h"
#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using namespace ENUM;

using Draw_Widget = Draw_Paths_Widgets_P;

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_G{ scale_factor }
{}

void Look_And_Feel_P::positionComboBoxText(ComboBox& cbox, Label& lbl) {
	auto icon_w = 11;
	lbl.setBounds(0, 0, cbox.getWidth() - icon_w, cbox.getHeight());
}

PopupMenu::Options Look_And_Feel_P::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& /*lbl*/) {
	auto cbox_area = cbox.getBoundsInParent();
	auto cbox_area_x = cbox_area.getCentreX();
	auto cbox_area_y = cbox_area.getCentreY();
	auto target_area = cbox.getScreenBounds();
	auto selected_item = cbox.getSelectedItemIndex();
	auto item_h = roundToInt((XYWH::cbox_h - 2) * scale_factor);
	auto col_count = 1;
	auto item_count = cbox.getNumItems();
	if (item_count == EXP::choice_count_mod_src)
		col_count = 2;
	if (item_count >= EXP::choice_count_mod_dest)
		col_count = 5;
	auto min_w = cbox.getWidth();
	auto menu_above = cbox_area_y > XYWH::lfo_row_1_y * scale_factor;
	auto offset_y = 0;
	auto offset_x = 0;
	if (col_count == 1) {
		if (menu_above)
			offset_y = (selected_item - item_count) * item_h;
		else
			offset_y = (selected_item + 1) * item_h;
	}
	else {
		if (col_count == 2)
			offset_y = (selected_item % 12 + 1) * item_h;
		if (col_count == 5) {
			if (item_count == EXP::choice_count_mod_dest ||
				item_count == EXP::choice_count_seq_track_2_4_dest)
			{
				if (menu_above)
					offset_y = (selected_item % 10 - 10) * item_h;
				else
					offset_y = (selected_item % 10 + 1) * item_h;
				if (cbox_area_x >= XYWH::cc_col_1_x * scale_factor &&
					cbox_area_x < XYWH::seq_step_col_1 * scale_factor)
				{
					offset_x -= min_w;
				}
				if (cbox_area_x > XYWH::seq_step_col_1 * scale_factor)
					offset_x -= min_w * (menu_above ? 2 : 3);
			}
			else {
				offset_x -= min_w * 4;
				offset_y = (selected_item % 34 - 34) * item_h;
			}
		}
	}
	if (menu_above)
		target_area.translate(offset_x, offset_y - roundToInt(scale_factor));
	else
		target_area.translate(offset_x, offset_y + roundToInt(3 * scale_factor));
	return PopupMenu::Options().withTargetScreenArea(target_area)
							   .withItemThatMustBeVisible(cbox.getSelectedId())
							   .withMinimumWidth(min_w)
							   .withMinimumNumColumns(col_count)
							   .withMaximumNumColumns(col_count)
							   .withStandardItemHeight(roundToInt(item_h));
}

void Look_And_Feel_P::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool /*separator*/, 
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
		g.setColour(COLOR::yellow);
		auto tick_diam = 4.0f * scale_factor;
		g.fillEllipse(4.0f * scale_factor, 4.0f * scale_factor, tick_diam, tick_diam);
	}
	auto txt_area = area.withTrimmedLeft(roundToInt(12 * scale_factor));
	g.setFont(FONT::cbox(scale_factor));
	g.setColour(COLOR::text);
	g.drawFittedText(txt, txt_area, Justification::centredLeft, 1);
}

void Look_And_Feel_P::draw_label_p(Graphics& g, Label& lbl, String& id) {
	auto txt = lbl.getText();
	g.setColour(COLOR::text.withAlpha(lbl.isBeingEdited() ? 0.0f : 1.0f));
	if (id == ID::label_osc_shape) {
		if (txt == "SAW") {
			Draw_Widget::wave_saw(g, scale_factor);
			return;
		}
		if (txt == "TRI") {
			Draw_Widget::wave_tri(g, scale_factor);
			return;
		}
		if (txt == "S/T") {
			Draw_Widget::wave_saw_tri(g, scale_factor);
			return;
		}
		if (txt == "SQR" || txt.startsWith("PW ")) {
			auto w = 50;
			if (txt.startsWith("PW "))
				w = txt.fromFirstOccurrenceOf("PW ", false, false).getIntValue();
			Draw_Widget::wave_pulse(g, w, scale_factor);
			g.setFont(FONT::pulse_w_txt(scale_factor));
			auto txt_area = Rectangle<int>{ 10, 23, 18, 11 }.transformedBy(AffineTransform::scale(scale_factor));
			g.drawText((String)(w), txt_area, Justification::centred);
			return;
		}
		g.setFont(FONT::knob(scale_factor));
		g.drawFittedText(txt == "OFF" ? txt : "ERR", lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
		return;
	}
	if (id == ID::label_seq_step) {
		auto sf = scale_factor;
		if (txt == "<") {
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			l.applyTransform(AffineTransform::scale(sf));
			g.drawArrow(l, 5.0f * sf, 10.0f * sf, 8.0f * sf);
			return;
		}
		if (txt == ".") {
			g.fillEllipse(10.0f * sf, 10.0f * sf, 6.0f * sf, 6.0f * sf);
			return;
		}
		g.setFont(FONT::seq_step(scale_factor));
		g.drawFittedText(txt, lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
		return;
	}
	if (id == ID::label_voice_name_char) {
		Draw_Widget::lcd_char(g, (uint8)txt[0], scale_factor);
		return;
	}
	g.setFont(FONT::cbox(scale_factor));
	g.drawFittedText(txt, lbl.getLocalBounds(), Justification::centred, 1, 1.0f);
}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	auto id = s.getComponentID();
	if (id == ID::knob_seq_step || id == ID::knob_seq_step_trk_1)
		return;
	auto rotation = min_angle + pos * (max_angle - min_angle);
	Draw_Widget::knob(g, rotation, scale_factor);
}

void Look_And_Feel_P::drawTickBox(Graphics& g, Component& c, float x, float y, 
								  float w, float h, const bool ticked, const bool /*enabled*/,
								  const bool /*hilited*/, const bool /*down*/)
{
	auto componentID{ c.getComponentID() };
	if (componentID == ID::toggle_red) {
		g.setColour(ticked ? COLOR::red_toggle_on : COLOR::red_toggle_off);
		g.fillEllipse(x, y, w, h);
	}
}
