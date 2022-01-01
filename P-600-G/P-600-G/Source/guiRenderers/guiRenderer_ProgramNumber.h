#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_PathsForLCDnumbers_Singleton.h"

using namespace constants;



struct ProgramNumberRenderer {
	static void paintProgramNumberInComponent(Graphics& g, const uint8& pgmNum, Component* component, int inset_x, int inset_y) {
		jassert(pgmNum < 100);
		g.setColour(Color::lcdRed);
		auto& digitPaths{ PathsForLCDdigits::get() };
		Path positionPath;
		auto firstDigit{ uint8(pgmNum / 10) };
		auto secondDigit{ uint8(pgmNum % 10) };
		positionPath.addPath(digitPaths.getPathForDigit(firstDigit), AffineTransform::translation(inset_x, inset_y));
		positionPath.addPath(digitPaths.getPathForDigit(secondDigit), AffineTransform::translation(inset_x + GUI::lcdDigit_w, inset_y));
		g.fillPath(positionPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNumberRenderer)
};