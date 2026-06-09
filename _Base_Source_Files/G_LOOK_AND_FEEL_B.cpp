#include "G_LOOK_AND_FEEL_B.h"

Look_And_Feel_B::Look_And_Feel_B(float& scale_factor) :
	scale_factor{ scale_factor }
{
	setColour(PopupMenu::backgroundColourId, COLOR::popup_bkgrnd);
	setColour(TextEditor::backgroundColourId, COLOR::txt_edit_bkgrnd);
	setColour(TextEditor::textColourId, COLOR::text);
	setColour(TextEditor::highlightColourId, COLOR::txt_highlight);
}

void Look_And_Feel_B::fillTextEditorBackground(Graphics& g, int w, int /*h*/, TextEditor& editor) {
	if (editor.getComponentID() == ID::cmp_display_editor.toString()) {
		g.setColour(COLOR::txt_edit_bkgrnd);
		auto knob_diameter = 1.0f * w;
		auto inset = XYWH::knob_disp_inset * scale_factor;
		auto diameter = knob_diameter - (2.0f * inset);
		g.fillEllipse(inset, inset, diameter, diameter);
	}
	else
		g.fillAll(COLOR::txt_edit_bkgrnd);
}

