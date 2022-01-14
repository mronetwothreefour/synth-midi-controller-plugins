#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_PathsForLCDnumbers_Singleton.h"

using namespace constants;



struct LCDnumberRenderer {
	static void paintSliderValueWithLCDdigits(Graphics& g, Slider* slider, const int& totalNumberOfDigits, float inset_x, float inset_y) {
		auto currentValue{ slider->getValue() };
		jassert(currentValue < std::pow(10.0, totalNumberOfDigits));
		String currentValueString{ roundToInt(currentValue) };
		currentValueString = currentValueString.paddedLeft('0', totalNumberOfDigits);
		auto& digitPaths{ PathsForLCDdigits::get() };
		Path unlitSegmentsPath;
		Path litSegmentsPath;
		for (int i = 0; i < totalNumberOfDigits; ++i) {
			auto pathForAllSegments{ digitPaths.getPathForDigit(8) };
			unlitSegmentsPath.addPath(pathForAllSegments, AffineTransform::translation(inset_x + i * GUI::lcdDigit_w, inset_y));
			String digitString{ currentValueString[i] };
			auto digit{ (uint8)(digitString.getIntValue() - (int)'0')};
			auto pathForDigit{ digitPaths.getPathForDigit(digit) };
			litSegmentsPath.addPath(pathForDigit, AffineTransform::translation(inset_x + i * GUI::lcdDigit_w, inset_y));
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