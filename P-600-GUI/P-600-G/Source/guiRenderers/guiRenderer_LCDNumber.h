#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_PathsForLCDnumbers_Singleton.h"

using namespace constants;



struct LCDnumberRenderer {
	static void paintValueStringInComponent(Graphics& g, const String& valueString) {
		auto& digitPaths{ PathsForLCDdigits::get() };
		Path unlitSegmentsPath;
		Path litSegmentsPath;
		for (int i = 0; i < valueString.length(); ++i) {
			auto pathForAllSegments{ digitPaths.getPathForDigit(8) };
			unlitSegmentsPath.addPath(pathForAllSegments, AffineTransform::translation(GUI::lcdDigitInset_x + i * GUI::lcdDigit_w, GUI::lcdDigitInset_y));
			String digitString{ valueString[i] };
			auto digit{ (uint8)(digitString.getIntValue() - (int)'0') };
			auto pathForDigit{ digitPaths.getPathForDigit(digit) };
			litSegmentsPath.addPath(pathForDigit, AffineTransform::translation(GUI::lcdDigitInset_x + i * GUI::lcdDigit_w, GUI::lcdDigitInset_y));
		}
		g.setColour(Color::lcdRedUnlit);
		g.fillPath(unlitSegmentsPath);
		g.setColour(Color::lcdRed);
		g.fillPath(litSegmentsPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDnumberRenderer)
};