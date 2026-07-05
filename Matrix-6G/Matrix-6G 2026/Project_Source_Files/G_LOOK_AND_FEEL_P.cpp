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

PopupMenu::Options Look_And_Feel_P::getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& lbl) {
	auto item_count = cbox.getNumItems();
	auto cbox_bounds = cbox.getScreenBounds();
	auto popup_x = cbox_bounds.getX() * scale_factor;
	auto draw_above = cbox_bounds.getY() > (XYWH::env_ctrl_row_1_y * scale_factor);
	float popup_y{ 0.0f };
	if (draw_above)
		popup_y = cbox_bounds.getY() - XYWH::ctrl_h * (item_count - cbox.getSelectedItemIndex()) - 3;
	else
		popup_y = cbox_bounds.getBottom() + XYWH::ctrl_h * cbox.getSelectedItemIndex() + 3;
	auto popup_w = cbox_bounds.getWidth() * 1.0f;
	auto popup_h = item_count * XYWH::ctrl_h * scale_factor;
	Rectangle<float> popup_bounds{ popup_x, popup_y, popup_w, popup_h };
	return PopupMenu::Options().withTargetScreenArea(popup_bounds.toNearestInt())
							   .withItemThatMustBeVisible(cbox.getSelectedId())
							   .withMinimumWidth(cbox.getWidth())
							   .withMaximumNumColumns(1)
							   .withStandardItemHeight(lbl.getHeight() + 2);
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
		g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
		g.fillRect(area.translated(0, 50));
		g.setColour(findColour(PopupMenu::highlightedTextColourId));
	}
	if (ticked) {
		g.setColour(COLOR::light_blue);
		auto vert_bar = Draw_LED::build_vert_bar(scale_factor);
		g.fillPath(vert_bar, AffineTransform::translation(1.0f * scale_factor, 0.0f));
	}
	Draw_LED::display_text(g, txt, area.getWidth(), scale_factor, Justification::right, 1.0f);
}

void Look_And_Feel_P::getIdealPopupMenuItemSizeWithOptions(const String& /*txt*/, bool /*separator*/, int /*standard_h*/, int& ideal_w, int& ideal_h, const PopupMenu::Options& o)
{
	ideal_w = o.getTargetScreenArea().getWidth() - 3;
	ideal_h = XYWH::ctrl_h;
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
