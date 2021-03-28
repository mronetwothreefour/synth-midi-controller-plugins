#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingPatchChangesEnabled :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingPatchChangesEnabled() = delete;

	ComboBoxForSelectingPatchChangesEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingPatchChangesEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingPatchChangesEnabled)
};

