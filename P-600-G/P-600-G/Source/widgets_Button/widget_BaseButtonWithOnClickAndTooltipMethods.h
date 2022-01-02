#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class BaseButtonWithOnClickAndTooltipMethods :
	public TextButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	BaseButtonWithOnClickAndTooltipMethods() = delete;

	explicit BaseButtonWithOnClickAndTooltipMethods(UnexposedParameters* unexposedParams);

protected:
	virtual const String createButtonTooltipString() = 0;
	virtual void onClickMethod() = 0;

public:
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~BaseButtonWithOnClickAndTooltipMethods();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseButtonWithOnClickAndTooltipMethods)
};