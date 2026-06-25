#include "G_LOOK_AND_FEEL_B.h"

Look_And_Feel_B::Look_And_Feel_B(float& scale_factor) :
	scale_factor{ scale_factor }
{
	setColour(PopupMenu::backgroundColourId, COLOR::popup_bkgrnd);
	setColour(TextEditor::textColourId, COLOR::text);
	setColour(CaretComponent::caretColourId, COLOR::txt_caret);
	setColour(TextEditor::highlightColourId, COLOR::txt_highlight);
}

void Look_And_Feel_B::drawLabel(Graphics& g, Label& lbl) {
	auto id = lbl.getComponentID();
	if (id == ID::label_file_browser.toString()) {
		auto txt_area{ lbl.getLocalBounds().removeFromLeft(5) };
		g.setColour(COLOR::text);
		g.setFont(FONT::file_browser(scale_factor));
		g.drawFittedText(lbl.getText(), txt_area, Justification::centredLeft, 1, 1.0f);
		return;
	}
	if (id == ID::label_slider.toString() || id == ID::label_cbox.toString()) {
		g.setColour(lbl.isBeingEdited() ? COLOR::text.withAlpha(0.0f) : COLOR::text);
		g.setFont(lbl.getFont());
		g.drawFittedText(lbl.getText(), lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
		return;
	}
	draw_label_p(g, lbl, id);
}

void Look_And_Feel_B::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& editor) {
	if (editor.getComponentID() == ID::txt_editor_filled.toString())
		g.fillAll(findColour(TextEditor::backgroundColourId));
}

void Look_And_Feel_B::drawTooltip(Graphics& g, const String& txt, int w, int h) {
	Rectangle<int> tip_box(w, h);
	g.setColour(COLOR::popup_bkgrnd);
	g.fillRect(tip_box);
	g.setColour(COLOR::tip_border);
	g.drawRect(tip_box, 1);
	layout_tip_text(txt).draw(g, { (float)w, (float)h });
}

Rectangle<int> Look_And_Feel_B::getTooltipBounds(const String& txt, Point<int> pos, Rectangle<int> parent_area) {
	auto layout(layout_tip_text(txt));
	auto w = roundToInt(layout.getWidth() + 16.0f);
	auto h = roundToInt(layout.getHeight() + 14.0f);
	return Rectangle<int>(
		pos.x > parent_area.getCentreX() ? pos.x - (w + 12) : pos.x + 24,
		pos.y > parent_area.getCentreY() ? pos.y - (h + 6) : pos.y + 6, w, h).constrainedWithin(parent_area);
}

TextLayout Look_And_Feel_B::layout_tip_text(const String& txt) noexcept {
	AttributedString attrib_txt;
	attrib_txt.setJustification(Justification::centred);
	attrib_txt.append(txt, FONT::tip(), COLOR::text);
	TextLayout layout;
	auto tooltipMaxWidth = 500.0f;
	layout.createLayout(attrib_txt, tooltipMaxWidth);
	return layout;
}

