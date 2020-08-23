#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ProgramSlotsWidget;
class UnexposedParameters;

class ButtonForResettingAllBanksToFactoryDefaults :
	public BaseButtonWithOnClickAndTooltipMethods
{
	UnexposedParameters* unexposedParams;

public:

	ButtonForResettingAllBanksToFactoryDefaults() = delete;

	ButtonForResettingAllBanksToFactoryDefaults(UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	~ButtonForResettingAllBanksToFactoryDefaults();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForResettingAllBanksToFactoryDefaults)
};
