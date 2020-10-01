#pragma once

#include <JuceHeader.h>

#include "gui_InfoForControlLabels_Singleton.h"



class ControlLabelsLayer :
	public Component
{
public:
	ControlLabelsLayer() = default;

	void paint(Graphics& g) override;
	Font getFontForLabelType(ControlLabelType labelType) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlLabelsLayer)
};

