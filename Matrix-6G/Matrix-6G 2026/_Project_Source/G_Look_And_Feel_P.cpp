#include "G_Look_And_Feel_P.h"

#include "C_COLOR_P.h"
#include "C_MISC_P.h"
#include "C_NAME_P.h"
#include "C_XYWH_P.h"
#include "G_DRAW_Paths_LED_P.h"

using Justify = Justification;

Look_And_Feel::Look_And_Feel(float& scale_factor) :
	Look_And_Feel_A{ scale_factor }
{
	setColour(TextEditor::backgroundColourId, COLOR::black);
}

void Look_And_Feel::positionComboBoxText(ComboBox& cbox, Label& lbl) {
	lbl.setJustificationType(Justify::right);
	lbl.setBounds(0, 0, cbox.getWidth(), cbox.getHeight());
}

PopupMenu::Options Look_And_Feel::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& /*lbl*/) {
	auto cbox_area = cbox.getBoundsInParent();
	auto cbox_cntr_y = cbox_area.getCentreY();
	auto target_area = cbox.getScreenBounds();
	auto selected_item = cbox.getSelectedItemIndex();
	auto item_h = roundToInt(XYWH::ctrl_h * scale_factor);
	auto col_count = 1;
	auto item_count = cbox.getNumItems();
	if (item_count == MISC::choice_count_mod_src || item_count == MISC::choice_count_mod_dst)
		col_count = 3;
	auto min_w = cbox.getWidth();
	auto menu_above = cbox_cntr_y > XYWH::env_ctrl_row_0_y * scale_factor;
	auto offset_y = 0;
	auto offset_x = 0;
	if (col_count == 1) {
		if (menu_above)
			offset_y = (selected_item - item_count) * item_h;
		else
			offset_y = (selected_item + 1) * item_h;
	}
	else {
		min_w += 8;
		offset_x -= min_w * 2;
		auto m = item_count == MISC::choice_count_mod_src ? 7 : 11;
		offset_y = (selected_item % m + 1) * item_h;
	}
	if (menu_above)
		target_area.translate(offset_x, offset_y - roundToInt(2 * scale_factor));
	else
		target_area.translate(offset_x, offset_y + roundToInt(3 * scale_factor));
	return PopupMenu::Options().withTargetScreenArea(target_area)
							   .withItemThatMustBeVisible(cbox.getSelectedId())
							   .withMinimumWidth(min_w)
							   .withMinimumNumColumns(col_count)
							   .withMaximumNumColumns(col_count)
							   .withStandardItemHeight(roundToInt(item_h));
}

void Look_And_Feel::drawPopupMenuItemWithOptions(Graphics& g, const Rectangle<int>& area,
												 bool hilited, const PopupMenu::Item& i,
												 const PopupMenu::Options& /*o*/)
{
	if (hilited) {
		g.setColour(COLOR::popup_ground.brighter(0.05f));
		g.fillRect(area);
	}
	if (i.isTicked) {
		g.setColour(COLOR::orange);
		auto vert_bar = DRAW::Paths_LED::build_vert_bar(scale_factor);
		g.fillPath(vert_bar, AffineTransform::translation(2.5f * scale_factor, 0.0f));
	}
	DRAW::Paths_LED::display_text(g, i.text, area.getWidth(), scale_factor, Justify::left, 1.0f);
}

void Look_And_Feel::draw_label_p(Graphics& g, Label& lbl, String& /*lbl_name*/) {
	auto txt{ lbl.getText() };
	auto alpha = lbl.isBeingEdited() ? 0.0f : 1.0f;
	DRAW::Paths_LED::display_text(g, txt, lbl.getWidth(), scale_factor,
		lbl.getJustificationType(), alpha);
}

void Look_And_Feel::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									 float pos, float /*min_pos*/, float /*max_pos*/,
									 const Slider::SliderStyle /*style*/, Slider& /*s*/)
{
	DRAW::Paths_LED::slider_tab(g, pos, scale_factor);
}
