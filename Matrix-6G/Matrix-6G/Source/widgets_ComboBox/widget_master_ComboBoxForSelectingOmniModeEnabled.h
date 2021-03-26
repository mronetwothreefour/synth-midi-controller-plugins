#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingOmniModeEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingOmniModeEnabled() = delete;

	ComboBoxForSelectingOmniModeEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingOmniModeEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingOmniModeEnabled)
};

