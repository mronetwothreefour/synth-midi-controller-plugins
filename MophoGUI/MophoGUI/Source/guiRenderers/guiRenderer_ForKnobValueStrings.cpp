#include "guiRenderer_ForKnobValueStrings.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_IntToContextualStringConverters.h"




RendererForKnobValueStrings::RendererForKnobValueStrings(Slider* knob, IntToContextualStringConverter* converter) :
	knob{ knob },
	converter{ converter }
{
	knob->addListener(this);
	sliderValueChanged(knob);
}

void RendererForKnobValueStrings::paint(Graphics& g) {
	Font font(FontsMenu::family_Global, FontsMenu::style_ForKnobValueDisplay, FontsMenu::size_ForKnobValueDisplay);
	g.setFont(font);
	g.setColour(Color::controlText);
	g.drawText(valueString, getLocalBounds(), Justification::centred);
}

void RendererForKnobValueStrings::sliderValueChanged(Slider* slider) {
	if (slider == knob) {
		auto newValue{ (uint8)roundToInt(slider->getValue()) };
		valueString = converter->convert(newValue);
		repaint();
	}
}

RendererForKnobValueStrings::~RendererForKnobValueStrings() {
	knob->removeListener(this);
}
