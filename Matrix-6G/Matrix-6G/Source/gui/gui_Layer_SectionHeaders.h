#pragma once

#include <JuceHeader.h>

#include "gui_Fonts.h"



class SectionHeadersLayer :
	public Component
{
	const float textGapHorizontalOffset{ 10.0f };
	const float textGapVerticalOffset{ -1.0f };
	const float textGap_h{ 18.0f };
	const float textGapWidthBuffer{ 10.0f };

public:
	SectionHeadersLayer() = default;
	void paint(Graphics& g) override;

private:
	void paintBlueBarForHeader(Graphics& g, int header);
	void createHeaderTextLayout(Graphics& g, String headerText, Rectangle<int> blueBar);
	void paintTextLayoutInBlueBar(Graphics& g, TextLayout layout, Rectangle<int> blueBar);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SectionHeadersLayer)
};

