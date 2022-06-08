#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class EditorForTooltipDelay :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	EditorForTooltipDelay() = delete;

	explicit EditorForTooltipDelay(UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~EditorForTooltipDelay();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorForTooltipDelay)
};
