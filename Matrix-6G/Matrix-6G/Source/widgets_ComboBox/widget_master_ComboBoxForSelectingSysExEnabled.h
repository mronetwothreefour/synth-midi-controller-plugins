#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingSysExEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingSysExEnabled() = delete;

	ComboBoxForSelectingSysExEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingSysExEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingSysExEnabled)
};

