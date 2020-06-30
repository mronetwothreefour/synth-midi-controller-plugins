#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../widgets/widget_Knobs.h"

class ControlWithExposedParameterAttachment : public Component
{
	ControlType controlType;

	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;

	ControlWithExposedParameterAttachment() : controlType{ ControlType::nullControl } {}

public:
	explicit ControlWithExposedParameterAttachment(SynthParameter param) :
		controlType{ param.controlType }
	{
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(param));
			addAndMakeVisible(*knobWithValueStringDisplay);
			setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
			break;
		case ControlType::knobWithWaveShapeDisplay:
			knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(param));
			addAndMakeVisible(*knobWithWaveShapeDisplay);
			setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
			break;
		default: break;
		}
	}

	~ControlWithExposedParameterAttachment()
	{
		knobWithValueStringDisplay = nullptr;
		knobWithWaveShapeDisplay = nullptr;
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID) const
	{
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			if (knobWithValueStringDisplay != nullptr)
				knobWithValueStringDisplay->attachToExposedParameter(exposedParams, paramID);
			break;
		case ControlType::knobWithWaveShapeDisplay:
			if (knobWithWaveShapeDisplay != nullptr)
				knobWithWaveShapeDisplay->attachToExposedParameter(exposedParams, paramID);
			break;
		default: break;
		}
	}

	void deleteAttachment() const
	{
		if (knobWithValueStringDisplay != nullptr)
			knobWithValueStringDisplay->deleteAttachment();
		if (knobWithWaveShapeDisplay != nullptr)
			knobWithWaveShapeDisplay->deleteAttachment();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlWithExposedParameterAttachment)
};

