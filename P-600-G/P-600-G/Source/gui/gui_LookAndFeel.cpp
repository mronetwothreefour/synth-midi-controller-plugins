#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "../params/params_Identifiers.h"

using namespace constants;



void GUILookAndFeel::drawRotarySlider(Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& /*slider*/) {
	Point<float> sliderCenter{ float(w) / 2.0f, float(w) / 2.0f };
	auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
	Line<float> line;
	line.setStart(sliderCenter.x, float(y + 34));
	line.setEnd(sliderCenter.x, float(y + 30));
	Path pointerPath;
	pointerPath.addLineSegment(line, 2.0f);
	g.setColour(Color::offWhite);
	PathStrokeType stroke{ 2.0f, PathStrokeType::mitered };
	g.strokePath(pointerPath, stroke, AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
}
