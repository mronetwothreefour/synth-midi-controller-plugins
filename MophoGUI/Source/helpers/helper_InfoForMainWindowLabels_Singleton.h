#pragma once

#include <JuceHeader.h>

#include "helper_Fonts.h"



class InfoForMainWindowLabels
{
	Array<String> labelTexts;
	Array<Point<int>> centerPoints;
	Array<int> widths;
	Array<int> heights;
	Array<int> justificationFlags;
	Array<float> fontSizes;

	InfoForMainWindowLabels();
	void fillAllInfoContainers();
	~InfoForMainWindowLabels();

public:
	InfoForMainWindowLabels(InfoForMainWindowLabels&&) = delete;
	InfoForMainWindowLabels& operator=(InfoForMainWindowLabels&&) = delete;

	static InfoForMainWindowLabels& get() noexcept;
	int labelOutOfRange() const noexcept;
	String textFor(uint16 labelIndex) const;
	Point<int> centerPointFor(uint16 labelIndex) const;
	int widthFor(uint16 labelIndex) const;
	int heightFor(uint16 labelIndex) const;
	int justificationFlagFor(uint16 labelIndex) const;
	float fontSizeFor(uint16 labelIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForMainWindowLabels)
};