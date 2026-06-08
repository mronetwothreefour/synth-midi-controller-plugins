#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_LED_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{
}

void Look_And_Feel_P::drawLabel(Graphics& g, Label& lbl) {
	auto parent_id{ lbl.getParentComponent()->getComponentID() };
	auto grandparent_id{ lbl.getParentComponent()->getParentComponent()->getComponentID() };
	auto in_file_browser{ parent_id == ID::cmp_file_browser.toString() ||
						  grandparent_id == ID::cmp_file_browser.toString()
	};
	if (in_file_browser) {
		auto textArea{ lbl.getLocalBounds() };
		textArea.removeFromLeft(5);
		g.setColour(COLOR::text);
		g.setFont(FONT::file_browser);
		g.drawFittedText(lbl.getText(), textArea, Justification::centredLeft, 1, 1.0f);
		return;
	}
	if (lbl.getComponentID() != ID::cmp_display_editor.toString()) {
		auto right_justified{ lbl.getComponentID() != ID::cmp_voice_name_editor.toString() };
		g.setColour(COLOR::light_blue);
		auto txt{ lbl.getText() };
		Draw_Paths_LED_P::display_text(g, txt, lbl.getWidth(), scale_factor, right_justified);
	}
}
