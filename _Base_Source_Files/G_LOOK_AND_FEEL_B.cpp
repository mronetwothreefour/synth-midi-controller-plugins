#include "G_LOOK_AND_FEEL_B.h"

Look_And_Feel_B::Look_And_Feel_B(float& scale_factor) :
	scale_factor{ scale_factor }
{
	setColour(PopupMenu::backgroundColourId, COLOR::popup_bkgrnd);
	setColour(TextEditor::backgroundColourId, COLOR::txt_edit_bkgrnd);
	setColour(TextEditor::textColourId, COLOR::text);
	setColour(TextEditor::highlightColourId, COLOR::txt_highlight);
}

void Look_And_Feel_B::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& /*editor*/) {
	g.fillAll(COLOR::txt_edit_bkgrnd);
}

