#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ButtonForHidingLayer :
	public TextButton,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

public:
	ButtonForHidingLayer() = delete;

	explicit ButtonForHidingLayer(UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ButtonForHidingLayer();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForHidingLayer)
};