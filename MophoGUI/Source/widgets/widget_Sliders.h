#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
// Overrides Slider's mouseWheelMove() operation so that each wheel move event
// increments/decrements the slider's value by a single interval (step)
class SliderWithMouseWheelMod : public Slider
{
public:
	void mouseWheelMove(const MouseEvent& /*e*/, const MouseWheelDetails& wheel) override
	{
		auto delta{ wheel.deltaY };
		auto currentValue{ getValue() };
		auto interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f)
		{
			setValue(currentValue + interval);
		}
	}
};

//==============================================================================
class RotarySliderWithMouseWheelMod : public SliderWithMouseWheelMod
{
public:
	RotarySliderWithMouseWheelMod()
	{
		setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
	}
	~RotarySliderWithMouseWheelMod() {}
};

//==============================================================================
struct TooltipSetter
{};

//==============================================================================
class Knob : public Component
{
	RotarySliderWithMouseWheelMod knob;
	std::unique_ptr<SliderAttachment> attachment;

	TooltipSetter tooltipSetter;

public:
	Knob()
	{
		addAndMakeVisible(knob);
		knob.setComponentID(ID::component_Knob.toString());

		auto knob_diam{ 40 };
		setSize(knob_diam, knob_diam);
		knob.setBounds(getLocalBounds());
	}

	~Knob() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		attachment.reset(new SliderAttachment(*exposedParams, paramID.toString(), knob));
	}

	void attachToPrivateParameter() {}

	void deleteAttachment()
	{
		attachment = nullptr;
	}
};

class KnobWithValueStringDisplay : public Component
{
	Knob knob;

public:
	KnobWithValueStringDisplay()
	{
		addAndMakeVisible(knob);
		setSize(knob.getWidth(), knob.getHeight());
	}

	~KnobWithValueStringDisplay() {}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		knob.attachToExposedParameter(exposedParams, paramID);
	}

	void deleteAttachment() { knob.deleteAttachment(); }
};


class ControlWithPublicParameterAttacher : public Component
{
	ControlType controlType;

	std::unique_ptr<KnobWithValueStringDisplay> knobWithValueStringDisplay;

	ControlWithPublicParameterAttacher() : controlType{ ControlType::nullControl } {}

public:
	explicit ControlWithPublicParameterAttacher(ControlType controlType) :
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

	~ControlWithPublicParameterAttacher()
	{
		knobWithValueStringDisplay = nullptr;
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
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

	void deleteAttachment()
	{
		knobWithValueStringDisplay->deleteAttachment();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlWithPublicParameterAttacher)
};

struct ControlWithPublicParameterAttacherArrayFactory
{
	static void fillVector(std::vector<std::unique_ptr<ControlWithPublicParameterAttacher>>& controlVector)
	{
		controlVector.push_back(std::make_unique<ControlWithPublicParameterAttacher>(ControlType::knobWithValueStringDisplay));
		controlVector.push_back(std::make_unique<ControlWithPublicParameterAttacher>(ControlType::knobWithValueStringDisplay));
	}
};

class ControlWithPublicParameterAttacherDatabase
{
	std::vector<std::unique_ptr<ControlWithPublicParameterAttacher>> controlVector_{};

	ControlWithPublicParameterAttacherDatabase()
	{
		ControlWithPublicParameterAttacherArrayFactory::fillVector(controlVector_);
	}

	~ControlWithPublicParameterAttacherDatabase() 
	{
		controlVector_.clear();
	}

public:
	ControlWithPublicParameterAttacherDatabase(ControlWithPublicParameterAttacherDatabase const&) = delete;
	ControlWithPublicParameterAttacherDatabase(ControlWithPublicParameterAttacherDatabase&&) = delete;
	ControlWithPublicParameterAttacherDatabase& operator=(ControlWithPublicParameterAttacherDatabase const&) = delete;
	ControlWithPublicParameterAttacherDatabase& operator=(ControlWithPublicParameterAttacherDatabase&&) = delete;

	static ControlWithPublicParameterAttacherDatabase& get()
	{
		static ControlWithPublicParameterAttacherDatabase controlDatabase;
		return controlDatabase;
	}

	ControlWithPublicParameterAttacher* getControl(uint16 index) const { return controlVector_[index].get(); }
};
