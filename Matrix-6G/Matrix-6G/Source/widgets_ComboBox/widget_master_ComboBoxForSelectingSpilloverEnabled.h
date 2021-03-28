#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingSpilloverEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingSpilloverEnabled() = delete;

	ComboBoxForSelectingSpilloverEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingSpilloverEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingSpilloverEnabled)
};

