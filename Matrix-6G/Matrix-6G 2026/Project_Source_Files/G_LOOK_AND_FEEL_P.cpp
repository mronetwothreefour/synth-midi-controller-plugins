#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_LED_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{
}

void Look_And_Feel_P::draw_label_p(Graphics& g, Label& lbl, String& id) {
	if (id == ID::label_led.toString()) {
		g.setColour(COLOR::light_blue);
		auto txt{ lbl.getText() };
		Draw_Paths_LED_P::display_text(g, txt, lbl.getWidth(), scale_factor, lbl.getJustificationType());
	}
}
