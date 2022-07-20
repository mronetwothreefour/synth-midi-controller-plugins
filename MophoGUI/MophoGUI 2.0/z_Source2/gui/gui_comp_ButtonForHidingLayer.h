#pragma once

#include <JuceHeader.h>



class TooltipsOptions;
class UnexposedParameters;

class ButtonForHidingLayer :
	public TextButton,
	public ValueTree::Listener
{
	TooltipsOptions* tooltips;

public:
	ButtonForHidingLayer() = delete;

	explicit ButtonForHidingLayer(UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~ButtonForHidingLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForHidingLayer)
};