#pragma once

#include <JuceHeader.h>



class InfoForMainWindowLabels
{
	juce::Array<juce::String> labelTexts;
	juce::Array<juce::Point<int>> centerPoints;
	juce::Array<int> widths;
	juce::Array<int> heights;
	juce::Array<int> justificationFlags;
	juce::Array<float> fontSizes;

	InfoForMainWindowLabels();
	void fillAllInfoContainers();
	~InfoForMainWindowLabels();

public:
	InfoForMainWindowLabels(InfoForMainWindowLabels&&) = delete;
	InfoForMainWindowLabels& operator=(InfoForMainWindowLabels&&) = delete;

	static InfoForMainWindowLabels& get() noexcept;
	const int labelOutOfRange() const noexcept;
	const juce::String textFor(juce::uint16 labelIndex) const;
	const juce::Point<int> centerPointFor(juce::uint16 labelIndex) const;
	const int widthFor(juce::uint16 labelIndex) const;
	const int heightFor(juce::uint16 labelIndex) const;
	const int justificationFlagFor(juce::uint16 labelIndex) const;
	const float fontSizeFor(juce::uint16 labelIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForMainWindowLabels)
};