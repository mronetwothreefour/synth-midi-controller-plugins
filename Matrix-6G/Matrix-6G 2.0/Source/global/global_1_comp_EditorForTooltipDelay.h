#pragma once

#include <JuceHeader.h>

class UnexposedParameters;

class EditorForTooltipDelay :
	public Component,
	Value::Listener
{
	Label tooltipDelayEditor;
	Value shouldShowDescriptionAsValue;

public:
	EditorForTooltipDelay() = delete;

	explicit EditorForTooltipDelay(UnexposedParameters* unexposedParams);
	void updateTooltip();
	void valueChanged(Value& value) override;
	~EditorForTooltipDelay();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorForTooltipDelay)
};
