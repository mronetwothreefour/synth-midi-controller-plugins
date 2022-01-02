#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "../params/params_Identifiers.h"

using namespace constants;



void GUILookAndFeel::drawRotarySlider(Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& slider) {
	if (slider.getComponentID() == ID::component_Knob.toString()) {
		Point<float> sliderCenter{ float(w) / 2.0f, float(w) / 2.0f };
		auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
		Line<float> line;
		line.setStart(sliderCenter.x, float(y + 34));
		line.setEnd(sliderCenter.x, float(y + 30));
		Path pointerPath;
		pointerPath.addLineSegment(line, 1.5f);
		g.setColour(Color::offWhite);
		PathStrokeType stroke{ 1.5f, PathStrokeType::mitered };
		g.strokePath(pointerPath, stroke, AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	}
}

void GUILookAndFeel::drawLinearSlider(Graphics& g, int x, int /*y*/, int /*w*/, int h, float /*sliderPos*/, float /*minSliderPos*/, float /*maxSliderPos*/, const Slider::SliderStyle /*sliderStyle*/, Slider& slider) {
	MemoryInputStream memInputStream{ BinaryData::Switch_png, BinaryData::Switch_pngSize, false };
	PNGImageFormat imageFormat;
	auto switchTab{ imageFormat.decodeImage(memInputStream) };
	auto currentValue{ (int)slider.getValue() };
	g.drawImageAt(switchTab, x, h - (currentValue * GUI::switchTabs_h) + GUI::theWeirdOffsetThatJucePutsOnLinearSliders);
}

