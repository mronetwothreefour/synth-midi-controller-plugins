#pragma once

#include <JuceHeader.h>

#include "gui_Constants.h"

using namespace constants;



struct VerticalBarLED {
	static Path createPath() {
		Path path;
		path.loadPathFromData(GUI::verticalBarPathData.data(), GUI::verticalBarPathData.size());
		return path;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VerticalBarLED)
};