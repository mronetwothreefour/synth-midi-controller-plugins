#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ComboBoxForSelectingVibratoModSource :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	const Identifier& propertyID;

public:
	ComboBoxForSelectingVibratoModSource() = delete;

	explicit ComboBoxForSelectingVibratoModSource(UnexposedParameters* unexposedParams, const Identifier& propertyID);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~ComboBoxForSelectingVibratoModSource() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingVibratoModSource)
};

