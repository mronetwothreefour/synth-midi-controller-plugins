#pragma once

#include <JuceHeader.h>



enum class DividerType {
	gray = 0,
	blue
};




class InfoForDividerLines
{
	Array<DividerType> dividerTypes;
	Array<Point<float>> startPoints;
	Array<Point<float>> endPoints;

	InfoForDividerLines();
	void fillAllInfoContainers();

public:
	InfoForDividerLines(InfoForDividerLines&&) = delete;
	InfoForDividerLines& operator=(InfoForDividerLines&&) = delete;

	static InfoForDividerLines& get() noexcept;
	int pathOutOfRange() const noexcept;
	DividerType typeFor(int pathNumber);
	Point<float> startPointFor(int pathNumber);
	Point<float> endPointFor(int pathNumber);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForDividerLines)
};

