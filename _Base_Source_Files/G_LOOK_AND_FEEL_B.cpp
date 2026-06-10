#include "G_LOOK_AND_FEEL_B.h"

Look_And_Feel_B::Look_And_Feel_B(float& scale_factor) :
	scale_factor{ scale_factor }
{
	setColour(PopupMenu::backgroundColourId, COLOR::popup_bkgrnd);
	setColour(TextEditor::backgroundColourId, COLOR::txt_edit_fill);
	setColour(TextEditor::textColourId, COLOR::text);
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
	if (id == ID::label_knob.toString() || id == ID::label_cbox.toString()) {
		g.setColour(COLOR::text);
		g.setFont(lbl.getFont());
		g.drawFittedText(lbl.getText(), lbl.getLocalBounds(), Justification::centred, 1, 1.0f);
		return;
	}
	draw_label_p(g, lbl, id);
}

void Look_And_Feel_B::fillTextEditorBackground(Graphics& g, int w, int /*h*/, TextEditor& editor) {
	auto fill_color = editor.findColour(TextEditor::backgroundColourId);
	if (editor.getComponentID() == ID::txt_edit_circ_fill.toString()) {
		g.setColour(fill_color);
		auto fill_diameter = 1.0f * w;
		auto inset = XYWH::txt_edit_circ_fill_inset * scale_factor;
		fill_diameter -= 2.0f * inset;
		g.fillEllipse(inset, inset, fill_diameter, fill_diameter);
	}
	else
		g.fillAll(fill_color);
}

