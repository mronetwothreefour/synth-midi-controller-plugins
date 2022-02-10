#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingVoicesBank :
	public ComboBox
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingVoicesBank() = delete;

	explicit ComboBoxForSelectingVoicesBank(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingVoicesBank)
};

