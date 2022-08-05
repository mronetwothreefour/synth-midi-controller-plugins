#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingSourceForMatrixMod :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingSourceForMatrixMod() = delete;

	ComboBoxForSelectingSourceForMatrixMod(UnexposedParameters* unexposedParams, int modNumber);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingSourceForMatrixMod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingSourceForMatrixMod)
};

