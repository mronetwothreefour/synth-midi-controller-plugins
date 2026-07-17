#pragma once

#include <JuceHeader.h>



class PathsForLCDdigits
{
	Array<Path> digitPaths;

	PathsForLCDdigits();
	void fillDigitPaths();
	Path createPathFor0();
	Path createPathFor1();
	Path createPathFor2();
	Path createPathFor3();
	Path createPathFor4();
	Path createPathFor5();
	Path createPathFor6();
	Path createPathFor7();
	Path createPathFor8();
	Path createPathFor9();

public:
	PathsForLCDdigits(PathsForLCDdigits&&) = delete;
	PathsForLCDdigits& operator=(PathsForLCDdigits&&) = delete;

	static PathsForLCDdigits& get() noexcept;
	Path getPathForDigit(uint8 digit);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PathsForLCDdigits)
};