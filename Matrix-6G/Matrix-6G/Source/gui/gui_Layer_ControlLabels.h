#pragma once

#include <JuceHeader.h>

#include "gui_InfoForControlLabels_Singleton.h"



class ControlLabelsLayer :
	public Component
{
	HyperlinkButton button_ForGoingToWebSite;

public:
	ControlLabelsLayer();

	void paint(Graphics& g) override;
	Font getFontForLabelType(ControlLabelType labelType) const;
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlLabelsLayer)
};

