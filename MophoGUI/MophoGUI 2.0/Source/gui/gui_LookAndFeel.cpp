#include "gui_LookAndFeel.h"
#pragma once

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



void MophoLookAndFeel::drawRotarySlider(
	Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& /*slider*/)
{
	auto diameter{ (float)w };
	Point<float> sliderCenter{ diameter / 2.0f, diameter / 2.0f };
	auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
	Line<float> line;
	line.setStart(sliderCenter.x, float(y + 7));
	line.setEnd(sliderCenter.x, float(y + 1));
	Path pointerPath;
	pointerPath.addArrow(line, 1.0f, 8.0f, 6.0f);
	pointerPath.applyTransform(AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	g.setColour(GUI::color_Black);
	g.fillPath(pointerPath);
}



void MophoLookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(), 
		button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void MophoLookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, 
	const bool isTicked, const bool /*isEnabled*/, const bool /*isHighlighted*/, const bool /*isDown*/)
{
	auto componentID{ component.getComponentID() };
	if (componentID.startsWith(ID::component_ParamToggle.toString())) {
		g.setColour(isTicked ? GUI::color_ToggleOn : GUI::color_ToggleOff);
		g.fillEllipse(x, y, w, h);
	}
}
