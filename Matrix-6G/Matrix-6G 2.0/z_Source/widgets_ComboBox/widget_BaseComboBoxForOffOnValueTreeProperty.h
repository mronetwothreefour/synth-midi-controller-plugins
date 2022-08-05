#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class BaseComboBoxForOffOnValueTreeProperty :
	public ComboBox,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	const Identifier& propertyID;

public:
	BaseComboBoxForOffOnValueTreeProperty() = delete;

	BaseComboBoxForOffOnValueTreeProperty(UnexposedParameters* unexposedParams, const Identifier& propertyID);
	virtual String generateTooltipString() = 0;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	void paint(Graphics& g) override;
	~BaseComboBoxForOffOnValueTreeProperty() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseComboBoxForOffOnValueTreeProperty)
};

