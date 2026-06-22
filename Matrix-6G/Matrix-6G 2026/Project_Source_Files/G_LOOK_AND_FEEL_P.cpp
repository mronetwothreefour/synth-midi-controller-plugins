#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_LED_P.h"

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{
	setColour(TextEditor::backgroundColourId, COLOR::black);
}

void Look_And_Feel_P::draw_label_p(Graphics& g, Label& lbl, String& id) {
	if (id == ID::label_led.toString()) {
		auto txt{ lbl.getText() };
		auto alpha = lbl.isBeingEdited() ? 0.0f : 1.0f;
		Draw_Paths_LED_P::display_text(g, txt, lbl.getWidth(), scale_factor, lbl.getJustificationType(), alpha);
	}
}

void Look_And_Feel_P::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
									   float pos, float /*min_pos*/, float /*max_pos*/,
									   const Slider::SliderStyle /*style*/, Slider& s)
{
	Draw_Paths_LED_P::slider_tab(g, pos);
}
