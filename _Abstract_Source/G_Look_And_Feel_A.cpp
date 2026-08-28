#include "G_Look_And_Feel_A.h"

#include "C_COLOR_P.h"
#include "C_FONT_P.h"
#include "C_NAME_P.h"

Look_And_Feel_A::Look_And_Feel_A(float& scale_factor) :
	scale_factor{ scale_factor }
{
	setColour(PopupMenu::backgroundColourId, COLOR::popup_ground);
	setColour(TextEditor::textColourId, COLOR::text);
	setColour(CaretComponent::caretColourId, COLOR::txt_caret);
	setColour(TextEditor::highlightColourId, COLOR::txt_highlight);
}

void Look_And_Feel_A::getIdealPopupMenuItemSizeWithOptions(const String& /*txt*/,
														   bool /*separator*/, int standard_h,
														   int& ideal_w, int& ideal_h,
														   const PopupMenu::Options& o)
{
	ideal_w = o.getMinimumWidth() - 4;
	ideal_h = standard_h;
}

void Look_And_Feel_A::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(COLOR::popup_ground);
}

void Look_And_Feel_A::drawLabel(Graphics& g, Label& lbl) {
	g.setColour(lbl.isBeingEdited() ? COLOR::text.withAlpha(0.0f) : COLOR::text);
	auto name = lbl.getName();
	if (name == NAME::lbl_browser) {
		auto txt_area{ lbl.getLocalBounds().removeFromLeft(5) };
		g.setFont(FONT::file_browser(scale_factor));
		g.drawFittedText(lbl.getText(), txt_area, Justification::centredLeft, 1, 1.0f);
		return;
	}
	if (name == NAME::lbl_slider || name == NAME::lbl_cbox) {
		g.setFont(lbl.getFont());
		g.drawFittedText(lbl.getText(), lbl.getLocalBounds().translated(0, 1),
			Justification::centred, 1, 1.0f);
		return;
	}
	draw_label_p(g, lbl, name);
}

void Look_And_Feel_A::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/,
											   TextEditor& editor)
{
	if (editor.getName() == NAME::txt_editor_filled)
		g.fillAll(findColour(TextEditor::backgroundColourId));
}

void Look_And_Feel_A::drawToggleButton(Graphics& g, ToggleButton& btn, bool hilited, bool down) {
	drawTickBox(g, btn, 0.0f, 0.0f, (float)btn.getWidth(), (float)btn.getHeight(),
				btn.getToggleState(), btn.isEnabled(), hilited, down);
}

void Look_And_Feel_A::drawTooltip(Graphics& g, const String& txt, int w, int h) {
	Rectangle<int> tip_box(w, h);
	g.setColour(COLOR::popup_ground);
	g.fillRect(tip_box);
	g.setColour(COLOR::tip_border);
	g.drawRect(tip_box, 1);
	layout_tip_text(txt).draw(g, { (float)w, (float)h });
}

Rectangle<int> Look_And_Feel_A::getTooltipBounds(const String& txt, Point<int> pos,
												 Rectangle<int> parent_area)
{
	auto layout(layout_tip_text(txt));
	auto w = roundToInt(layout.getWidth() + 16.0f);
	auto h = roundToInt(layout.getHeight() + 14.0f);
	return Rectangle<int>(
		pos.x > parent_area.getCentreX() ? pos.x - (w + 12) : pos.x + 24,
		pos.y > parent_area.getCentreY() ? pos.y - (h + 6) :
				pos.y + 6, w, h).constrainedWithin(parent_area);
}

TextLayout Look_And_Feel_A::layout_tip_text(const String& txt) noexcept {
	AttributedString attrib_txt;
	attrib_txt.setJustification(Justification::centred);
	attrib_txt.append(txt, FONT::tip(), COLOR::text);
	TextLayout layout;
	auto max_w = 500.0f;
	layout.createLayout(attrib_txt, max_w);
	return layout;
}

