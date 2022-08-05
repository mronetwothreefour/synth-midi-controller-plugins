#pragma once

#include <JuceHeader.h>

#include "gui_Path_VerticalBarLED.h"



struct LEDsliderTab {
	static Path createPath() {
		Path tabPath;
		auto verticalBarPath{ VerticalBarLED::createPath() };
		for (auto i = 0; i != 6; ++i) {
			tabPath.addPath(verticalBarPath, AffineTransform::translation(i * 3.0f, 0.0f));
		}
		return tabPath;
	}
};