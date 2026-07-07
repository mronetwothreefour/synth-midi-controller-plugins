#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_LED_P.h"

using Draw_LED = Draw_Paths_LED_P;

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{
	setColour(TextEditor::backgroundColourId, COLOR::black);
}

void Look_And_Feel_P::positionComboBoxText(ComboBox& cbox, Label& lbl) {
	lbl.setComponentID(ID::label_led.toString());
	lbl.setJustificationType(Justification::right);
	lbl.setBounds(0, 0, cbox.getWidth(), cbox.getHeight());
}

PopupMenu::Options Look_And_Feel_P::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& /*lbl*/) {
	auto target_area = cbox.getScreenBounds();
	auto menu_above = target_area.getY() > (XYWH::env_ctrl_row_1_y * scale_factor);
	auto selected_index = cbox.getSelectedItemIndex();
	auto item_h = roundToInt(XYWH::ctrl_h * scale_factor);
	if (menu_above) {
		auto item_count = cbox.getNumItems();
		auto offset_y = (selected_index - item_count) * item_h;
		target_area.translate(0, offset_y - roundToInt(2 * scale_factor));
	}
	else {
		auto offset_y = (selected_index + 1) * item_h;
		target_area.translate(0, offset_y + roundToInt(3 * scale_factor));
	}
	return PopupMenu::Options().withTargetScreenArea(target_area)
							   .withItemThatMustBeVisible(cbox.getSelectedId())
							   .withMinimumWidth(cbox.getWidth())
							   .withMaximumNumColumns(1)
							   .withStandardItemHeight(item_h);
}

void Look_And_Feel_P::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(COLOR::popup_bkgrnd);
}

void Look_And_Feel_P::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool /*separator*/, 
										const bool active, const bool hilited, const bool ticked, 
										const bool /*has_submenu*/, const String& txt, 
										const String& /*shortcut_txt*/, const Drawable* /*icon*/, 
										const Colour* const /*txt_clr*/)
{
	if (hilited && active) {
		g.setColour(COLOR::popup_bkgrnd.brighter(0.05f));
		g.fillRect(area);
	}
	if (ticked) {
		g.setColour(COLOR::light_blue);
		auto vert_bar = Draw_LED::build_vert_bar(scale_factor);
		g.fillPath(vert_bar, AffineTransform::translation(2.5f * scale_factor, 0.0f));
	}
	Draw_LED::display_text(g, txt, area.getWidth(), scale_factor, Justification::right, 1.0f);
}

void Look_And_Feel_P::getIdealPopupMenuItemSizeWithOptions(const String& /*txt*/, bool /*separator*/,
														   int standard_h, int& ideal_w, 
														   int& ideal_h, const PopupMenu::Options& o)
{
	ideal_w = roundToInt(o.getTargetScreenArea().getWidth() - 3 * scale_factor);
	ideal_h = standard_h;
}

void Look_And_Feel_P::draw_label_p(Graphics& g, Label& lbl, String& id) {
	if (id == ID::label_led.toString()) {
		auto txt{ lbl.getText() };
		auto alpha = lbl.isBeingEdited() ? 0.0f : 1.0f;
		Draw_LED::display_text(g, txt, lbl.getWidth(), scale_factor, lbl.getJustificationType(), alpha);
	}
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float pos, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& /*s*/)
{
	Draw_Paths_LED_P::slider_tab(g, pos, scale_factor);
}
