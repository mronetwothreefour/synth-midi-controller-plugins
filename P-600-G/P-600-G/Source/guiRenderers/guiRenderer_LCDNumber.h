#pragma once

#include <JuceHeader.h>

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_PathsForLCDnumbers_Singleton.h"

using namespace constants;



struct LCDnumberRenderer {
	static void paintSliderValueWithLCDdigits(Graphics& g, Slider* slider, const int& totalNumberOfDigits, int inset_x, int inset_y) {
		auto currentValue{ slider->getValue() };
		jassert(currentValue < std::pow(10.0, totalNumberOfDigits));
		String currentValueString{ (int)currentValue };
		currentValueString = currentValueString.paddedLeft('0', totalNumberOfDigits);
		g.setColour(Color::lcdRed);
		auto& digitPaths{ PathsForLCDdigits::get() };
		Path positionPath;
		for (int i = 0; i < totalNumberOfDigits; ++i) {
			String digitString{ currentValueString[i] };
			auto digit{ (uint8)digitString.getIntValue() };
			auto pathForDigit{ digitPaths.getPathForDigit(digit) };
			positionPath.addPath(pathForDigit, AffineTransform::translation(inset_x + i * GUI::lcdDigit_w, inset_y));
		}
		g.fillPath(positionPath);
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LCDnumberRenderer)
};