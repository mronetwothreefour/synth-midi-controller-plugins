#pragma once

#include <JuceHeader.h>

#include "../PluginProcessor.h"
#include "../helpers/CustomColors.h"
#include "../helpers/InfoStrings.h"
#include "../helpers/ParameterTools.h"
#include "../parameters/PrivateParameters.h"
#include "LCDcharacterRenderer.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
// A class derived from Slider that simply modifies mouseWheelMove() so that
// the slider's value is changed by a single interval with each wheel move
class CustomSlider : public Slider
{
public:
	CustomSlider() {}

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

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomSlider)
};

//==============================================================================
// A special slider used for setting the values of steps in sequence 1.
// Derives from CustomSlider and overrides mouseDown() so that the slider's value
// changes to 126 (sequencer track reset) if it is clicked while the CTRL key is down,
// and to 127 (rest) if it is clicked while the ALT key is down
class CustomSliderForTrack1Steps : public CustomSlider
{
public:
	CustomSliderForTrack1Steps() {}

	void mouseDown(const MouseEvent& e) override
	{
		if (e.mods.isCtrlDown())
			setValue(126.0, sendNotification);
		if (e.mods.isAltDown())
			setValue(127.0, sendNotification);
		else Slider::mouseDown(e);
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomSliderForTrack1Steps)
};

//==============================================================================
// A special slider used for setting the values of steps in sequencer tracks 2, 3, and 4.
// Derives from CustomSlider and overrides mouseDown() so that the slider's value
// changes to 126 (sequencer track reset) if it is clicked while the CTRL key is down
class CustomSliderForTracks2_3_4Steps : public CustomSlider
{
public:
	CustomSliderForTracks2_3_4Steps() {}

	void mouseDown(const MouseEvent& e) override
	{
		if (e.mods.isCtrlDown())
			setValue(126, sendNotification);
		else Slider::mouseDown(e);
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomSliderForTracks2_3_4Steps)
};

//==============================================================================
// Creates graphical representations of various wave shapes.
// Oscillator KnobWidgets use this to display their current values
class WaveShapeRenderer : public Component
{
public:
	WaveShapeRenderer() 
	{
		auto knob_diameter{ 30 };
		setSize(knob_diameter, knob_diameter);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::controlText);
		Path path;
		if (selectedShape == "sawtooth")
		{
			Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
			Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
		if (selectedShape == "triangle")
		{
			Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
			Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
		if (selectedShape == "sawTri")
		{
			Line<float> line1{ 5.0f, 15.0f, 10.0f, 8.0f };
			Line<float> line2{ 10.0f, 8.0f, 15.0f, 15.0f };
			Line<float> line3{ 15.0f, 15.0f, 15.0f, 23.0f };
			Line<float> line4{ 15.0f, 23.0f, 25.0f, 15.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			path.addLineSegment(line3, 0.5f);
			path.addLineSegment(line4, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
		if (selectedShape == "pulse")
		{
			auto polaritySwitch_x{ 6.0f + (18.0f * (pulseWidth * .01f)) };
			Line<float> line1{ 6.0f, 17.0f, 6.0f, 8.0f };
			Line<float> line2{ 6.0f, 8.0f, polaritySwitch_x, 8.0f };
			Line<float> line3{ polaritySwitch_x, 8.0f, polaritySwitch_x, 17.0f };
			Line<float> line4{ polaritySwitch_x, 17.0f, 24.0f, 17.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			path.addLineSegment(line3, 0.5f);
			path.addLineSegment(line4, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);

			Font pwText{ "Arial", "Narrow", 11.0f };
			g.setFont(pwText);

			Rectangle<int> pwTextArea{ 6, 18, 18, 11 };
			g.drawText((String)(pulseWidth - 1), pwTextArea, Justification::centred);
		}
	}

	void clear() noexcept { selectedShape = "none"; repaint(); }
	void drawSawtooth() noexcept { selectedShape = "sawtooth"; repaint(); }
	void drawTriangle() noexcept { selectedShape = "triangle"; repaint(); }
	void drawSawTri() noexcept { selectedShape = "sawTri"; repaint(); }
	void drawPulse(int width) noexcept { selectedShape = "pulse"; pulseWidth = width;  repaint(); }

private:
	String selectedShape{ "" };
	int pulseWidth{ 50 };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveShapeRenderer)
};

//==============================================================================
// Base class for knob widgets. Derived classes must
// override drawValue() and createTooltipString()
class KnobWidget : 
	public Component, 
	public Slider::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	String currentValueText{ "" };

	KnobWidget
	(
		String labelText,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		int index,
		int type,
		int knobSensitivity
	) :
		sliderAttachment{ *apvts, paramID.toString(), slider },
		privateParams{ privateParameters },
		name{ labelText },
		paramIndex{ index },
		paramType{ type }
	{
		privateParams->addListenerToGlobalOptions(this);

		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setMouseDragSensitivity(knobSensitivity);
		slider.addListener(this);
		addAndMakeVisible(slider);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget()
	{
		slider.removeListener(this);
		privateParams->removeListenerFromGlobalOptions(this);
	}

	void paint(Graphics& g) override
	{
		// draw knob circle
		g.setColour(Color::black);
		g.fillEllipse(5, 5, 30, 30);

		// draw knob name 
		Font knobName{ "Arial", "Black", 12.0f };
		g.setFont(knobName);
		Rectangle<int> knobNameArea{ 0, 35, 40, 15 };
		g.drawText(name, knobNameArea, Justification::centred);

		// draw knob value
		g.setColour(Color::controlText);
		Font knobValue{ "Arial", "Narrow Bold", 13.0f };
		g.setFont(knobValue);
		Rectangle<int> knobValueArea{ 5, 5, 30, 30 };
		g.drawText(currentValueText, knobValueArea, Justification::centred);
	}

	void resized() override
	{
		slider.setBounds(0, 0, 40, 40);
	}

	auto getSliderValue() { return roundToInt(slider.getValue()); }

	void sliderValueChanged(Slider* sliderThatChanged) override
	{
		if (sliderThatChanged == &slider)
		{
			auto currentValue{ getSliderValue() };
			drawValue(currentValue);
			auto tooltip{ createTooltipString(paramIndex, paramType, currentValue, privateParams->shouldShowValueTip, privateParams->shouldShowInfoTip) };
			setSliderTooltip(tooltip);
		}
	}

	void setSliderTooltip(String text) { slider.setTooltip(text); }

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
		{
			setSliderTooltip(createTooltipString(paramIndex, paramType, getSliderValue(), privateParams->shouldShowValueTip, privateParams->shouldShowInfoTip));
		}
	}

private:
	CustomSlider slider;
	SliderAttachment sliderAttachment;

	String name;

	int paramIndex;
	int paramType;

	void drawValue(const int& currentValue) noexcept
	{
		currentValueText = convertIntToValueString(paramType, currentValue, false);
		repaint();
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget)
};

//==============================================================================
// A knob widget appropriate for controlling oscillator wave shape parameters.
// Displays its value graphically using a WaveShapeRenderer
class KnobWidget_OscShape : public KnobWidget
{
public:
	KnobWidget_OscShape
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		int paramIndex
	) :
		KnobWidget{ "SHAPE", apvts, privateParameters, paramID, paramIndex, MophoParameterType::oscShape, 160 }
	{
		shapeRenderer.setInterceptsMouseClicks(false, false);
		shapeRenderer.setBounds(5, 5, shapeRenderer.getWidth(), shapeRenderer.getHeight());
		addAndMakeVisible(shapeRenderer);

		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscShape()
	{}

private:
	WaveShapeRenderer shapeRenderer;

	void drawValue(const int& currentValue) noexcept
	{
		if (currentValue > -1 && currentValue < 104)
		{
			if (currentValue == 0) // Off
			{
				shapeRenderer.clear();
				setCurrentValueText("OFF");
			}
			if (currentValue == 1) // Sawtooth
			{
				setCurrentValueText("");
				shapeRenderer.drawSawtooth();
			}
			if (currentValue == 2) // Triangle
			{
				setCurrentValueText("");
				shapeRenderer.drawTriangle();
			}
			if (currentValue == 3) // Sawtooth-Triangle Mix
			{
				setCurrentValueText("");
				shapeRenderer.drawSawTri();
			}
			if (currentValue > 3 && currentValue < 104) // Pulse
			{
				setCurrentValueText("");
				shapeRenderer.drawPulse(currentValue - 3);
			}
		}
		else
		{
			shapeRenderer.clear();
			setCurrentValueText("ERR");
		}
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscShape)
};

