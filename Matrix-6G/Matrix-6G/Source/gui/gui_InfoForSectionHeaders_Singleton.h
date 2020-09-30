#pragma once

#include <JuceHeader.h>



class InfoForSectionHeaders
{
	Array<String> headerStrings;
	Array<Point<int>> startPoints;
	Array<Point<int>> endPoints;

	InfoForSectionHeaders();
	void fillAllInfoContainers();

public:
	InfoForSectionHeaders(InfoForSectionHeaders&&) = delete;
	InfoForSectionHeaders& operator=(InfoForSectionHeaders&&) = delete;

	static InfoForSectionHeaders& get() noexcept;
	int headerOutOfRange() const noexcept;
	String textFor(int headerNumber);
	Point<int> startPointFor(int headerNumber);
	Point<int> endPointFor(int headerNumber);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForSectionHeaders)
};
