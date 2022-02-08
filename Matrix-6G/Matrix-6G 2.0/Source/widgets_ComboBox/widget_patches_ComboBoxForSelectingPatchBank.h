#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingPatchBank :
	public ComboBox
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingPatchBank() = delete;

	explicit ComboBoxForSelectingPatchBank(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingPatchBank)
};

