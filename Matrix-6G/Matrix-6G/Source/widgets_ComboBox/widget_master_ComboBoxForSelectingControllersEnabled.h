#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingControllersEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingControllersEnabled() = delete;

	ComboBoxForSelectingControllersEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingControllersEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingControllersEnabled)
};

