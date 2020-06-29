#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../widgets/widget_Sliders.h"

class ControlWithExposedParameterAttachment : public Component
{
	ControlType controlType;

	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;

	ControlWithExposedParameterAttachment() : controlType{ ControlType::nullControl } {}

public:
	explicit ControlWithExposedParameterAttachment(ControlType controlType) :
		controlType{ controlType }
	{
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay());
			addAndMakeVisible(*knobWithValueStringDisplay);
			setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
		default: break;
		}
	}

	~ControlWithExposedParameterAttachment()
	{
		knobWithValueStringDisplay = nullptr;
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID) const
	{
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			if (knobWithValueStringDisplay != nullptr)
				knobWithValueStringDisplay->attachToExposedParameter(exposedParams, paramID);
			break;
		default: break;
		}
	}

	void deleteAttachment() const
	{
		knobWithValueStringDisplay->deleteAttachment();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlWithExposedParameterAttachment)
};

