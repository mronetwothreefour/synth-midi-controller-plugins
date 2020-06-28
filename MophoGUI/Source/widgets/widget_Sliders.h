#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"

//==============================================================================
// A class derived from Slider that simply overrides mouseWheelMove() so that
// each wheel move event increments the slider's value by a single interval
class SliderWithWheelMod : public Slider
{
public:
	SliderWithWheelMod() :
		Slider{ Slider::RotaryHorizontalVerticalDrag, Slider::NoTextBox }
	{
		setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
	}

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

struct TooltipSetter
{};

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class Knob : public Component
{
	SliderWithWheelMod knob;
	std::unique_ptr<SliderAttachment> attachment;

	TooltipSetter tooltipSetter;

public:
	Knob()
	{
		addAndMakeVisible(knob);

		auto knob_diam{ 40 };
		setSize(knob_diam, knob_diam);
		knob.setBounds(getLocalBounds());
	}

	~Knob() 
	{
		attachment = nullptr;
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);
		g.fillEllipse(getLocalBounds().reduced(5, 5).toFloat());
	}

	void attachToPublicParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		attachment.reset(new SliderAttachment(*exposedParams, paramID.toString(), knob));
	}

	void attachToPrivateParameter() {}
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

	void attachToPublicParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		knob.attachToPublicParameter(exposedParams, paramID);
	}
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

	void attachToPublicParameter(AudioProcessorValueTreeState* exposedParams, Identifier paramID)
	{
		switch (controlType)
		{
		case ControlType::knobWithValueStringDisplay:
			if (knobWithValueStringDisplay != nullptr)
				knobWithValueStringDisplay->attachToPublicParameter(exposedParams, paramID);
			break;
		default: break;
		}
	}

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
