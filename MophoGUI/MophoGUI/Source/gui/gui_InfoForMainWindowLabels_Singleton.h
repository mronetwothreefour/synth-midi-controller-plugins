#pragma once

#include <JuceHeader.h>



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
	const int labelOutOfRange() const noexcept;
	const String textFor(uint16 labelIndex) const;
	const Point<int> centerPointFor(uint16 labelIndex) const;
	const int widthFor(uint16 labelIndex) const;
	const int heightFor(uint16 labelIndex) const;
	const int justificationFlagFor(uint16 labelIndex) const;
	const float fontSizeFor(uint16 labelIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForMainWindowLabels)
};