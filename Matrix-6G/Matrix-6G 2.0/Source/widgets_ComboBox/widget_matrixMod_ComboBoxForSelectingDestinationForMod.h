#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingDestinationForMatrixMod :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingDestinationForMatrixMod() = delete;

	ComboBoxForSelectingDestinationForMatrixMod(UnexposedParameters* unexposedParams, int modNumber);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingDestinationForMatrixMod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingDestinationForMatrixMod)
};

