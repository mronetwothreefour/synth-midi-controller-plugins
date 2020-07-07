#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../widgets/widget_Knobs.h"



class ControlForExposedParameter : public Component
{
	ControlType controlType;
	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;
	std::unique_ptr<KnobWithWaveShapeDisplay> knobWithWaveShapeDisplay;

	ControlForExposedParameter() : 
		controlType{ ControlType::nullControl } 
	{
	}

public:
	explicit ControlForExposedParameter(uint16 paramIndex) :
		controlType{ InfoForExposedParameters_Singleton::get()[paramIndex].controlType }
	{
		switch (controlType) {
		case ControlType::knobWithValueStringDisplay:
			knobWithValueStringDisplay.reset(new KnobWithValueStringDisplay(paramIndex));
			addAndMakeVisible(*knobWithValueStringDisplay);
			setSize(knobWithValueStringDisplay->getWidth(), knobWithValueStringDisplay->getHeight());
			break;
		case ControlType::knobWithWaveShapeDisplay:
			knobWithWaveShapeDisplay.reset(new KnobWithWaveShapeDisplay(paramIndex));
			addAndMakeVisible(*knobWithWaveShapeDisplay);
			setSize(knobWithWaveShapeDisplay->getWidth(), knobWithWaveShapeDisplay->getHeight());
			break;
		default: break;
		}
	}

	~ControlForExposedParameter() {
		knobWithValueStringDisplay = nullptr;
		knobWithWaveShapeDisplay = nullptr;
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) const {
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			if (knobWithValueStringDisplay != nullptr)
				knobWithValueStringDisplay->attachToExposedParameter(exposedParams);
			break;
		case ControlType::knobWithWaveShapeDisplay:
			if (knobWithWaveShapeDisplay != nullptr)
				knobWithWaveShapeDisplay->attachToExposedParameter(exposedParams);
			break;
		default: break;
		}
	}

	void deleteAttachment() const {
		if (knobWithValueStringDisplay != nullptr)
			knobWithValueStringDisplay->deleteAttachment();
		if (knobWithWaveShapeDisplay != nullptr)
			knobWithWaveShapeDisplay->deleteAttachment();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlForExposedParameter)
};

