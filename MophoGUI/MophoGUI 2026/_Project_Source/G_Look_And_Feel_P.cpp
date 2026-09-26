#include "G_Look_And_Feel_P.h"

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"
#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Widget = DRAW::Paths_Widgets;

Look_And_Feel::Look_And_Feel(float& scale_factor) :
	Look_And_Feel_A{ scale_factor }
{}

void Look_And_Feel::positionComboBoxText(ComboBox& cbox, Label& lbl) {
	lbl.setBounds(0, 0, cbox.getWidth() - 11, cbox.getHeight());
}

PopupMenu::Options Look_And_Feel::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& /*lbl*/) {
	auto param_id = cbox.getComponentID().toStdString();
	auto selected_item = cbox.getSelectedItemIndex();
	auto selected_item_pos = cbox.getScreenBounds();
	auto item_h = roundToInt((XYWH::cbox_item_h) * scale_f);
	auto min_w = cbox.getWidth();
	auto menu_above = GET::menu_above_for(param_id);
	auto menu_to_left = GET::menu_to_left_for(param_id);
	auto offset_x = 0;
	auto offset_y = 0;
	auto col_count = GET::menu_col_count_for(param_id);
	auto row_count = GET::menu_row_count_for(param_id);
	if (col_count == 1) {
		if (menu_above)
			offset_y = (selected_item - row_count) * item_h;
		else
			offset_y = (selected_item + 1) * item_h;
	}
	else {
		if (menu_to_left)
			offset_x -= min_w * (col_count - 1);
		if (menu_above)
			offset_y = ((selected_item % row_count) - row_count) * item_h;
		else
			offset_y = (selected_item % row_count + 1) * item_h;
	}
	if (menu_above)
		selected_item_pos.translate(offset_x, offset_y - roundToInt(scale_f));
	else
		selected_item_pos.translate(offset_x, offset_y + roundToInt(4 * scale_f));
	return PopupMenu::Options().withTargetScreenArea(selected_item_pos)
							   .withItemThatMustBeVisible(cbox.getSelectedId())
							   .withMinimumWidth(min_w)
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
		g.setColour(Colour{ COLOR::yellow });
		auto tick_diam = 4.0f * scale_f;
		g.fillEllipse(tick_diam, tick_diam, tick_diam, tick_diam);
	}
	auto txt_area = area.withTrimmedLeft(roundToInt(12 * scale_f));
	g.setFont(FONT::cbox(scale_f));
	g.setColour(Colour{ COLOR::text });
	g.drawFittedText(txt, txt_area, Justification::centredLeft, 1);
}

void Look_And_Feel::draw_label_p(Graphics& g, Label& lbl, String& n) {
	auto txt = lbl.getText();
	g.setColour(Colour{ COLOR::text }.withAlpha(lbl.isBeingEdited() ? 0.0f : 1.0f));
	if (n == NAME::lbl_cbx) {
		g.setFont(FONT::cbox(scale_f));
		g.drawFittedText(txt, lbl.getLocalBounds(), Justification::centred, 1, 1.0f);
		return;
	}
	if (n == NAME::lbl_name_char) {
		Draw_Widget::lcd_char(g, (uint8)txt[0], scale_f);
		return;
	}
	if (n == NAME::lbl_osc_shape) {
		if (txt == "SAW") {
			Draw_Widget::wave_saw(g, scale_f);
			return;
		}
		if (txt == "TRI") {
			Draw_Widget::wave_tri(g, scale_f);
			return;
		}
		if (txt == "S/T") {
			Draw_Widget::wave_saw_tri(g, scale_f);
			return;
		}
		if (txt == "SQR" || txt.startsWith("PW ")) {
			auto w = 50;
			if (txt.startsWith("PW "))
				w = txt.fromFirstOccurrenceOf("PW ", false, false).getIntValue();
			Draw_Widget::wave_pulse(g, w, scale_f);
			g.setFont(FONT::pulse_w_txt(scale_f));
			auto txt_area = Rectangle<int>{ 10, 23, 18, 11 }
							.transformedBy(AffineTransform::scale(scale_f));
			g.drawText((String)(w), txt_area, Justification::centred);
			return;
		}
		g.setFont(FONT::knob(scale_f));
		g.drawFittedText(txt == "OFF" ? txt : "ERR", lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
		return;
	}
	if (n == NAME::lbl_seq_step) {
		auto sf = scale_f;
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
		g.setFont(FONT::seq_step(sf));
		g.drawFittedText(txt, lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
		return;
	}
	g.setFont(FONT::knob(scale_f));
	g.drawFittedText(txt, lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
}

void Look_And_Feel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	if (s.getComponentID().contains("_step_"))
		return;
	auto rotation = min_angle + pos * (max_angle - min_angle);
	Draw_Widget::knob(g, rotation, scale_f);
}

void Look_And_Feel::drawTickBox(Graphics& g, Component& c, float x, float y, 
								  float w, float h, const bool ticked, const bool /*enabled*/,
								  const bool /*hilited*/, const bool /*down*/)
{
	if (c.getName().startsWith("ctrl_tgl")) {
		g.setColour(ticked ? Colour{ COLOR::red_tgl_on } : Colour{ COLOR::red_tgl_off });
		g.fillEllipse(x, y, w, h);
	}
}
