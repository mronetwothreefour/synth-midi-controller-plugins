#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class UnexposedParameters;

class ButtonForShowingMasterOptionsComponent : public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForShowingMasterOptionsComponent() = delete;

	explicit ButtonForShowingMasterOptionsComponent(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForShowingMasterOptionsComponent)
};

