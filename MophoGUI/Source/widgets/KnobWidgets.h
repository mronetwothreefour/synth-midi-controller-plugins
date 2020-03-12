#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"

using Attachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
// A class derived from Slider that simply
// modifies mouseWheelMove() so that the
// slider's value is changed by a single
// interval with each wheel move
class CustomSlider :
	public Slider
{
public:
	CustomSlider() {}

	void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override
	{
		ignoreUnused(e);
		float delta{ wheel.deltaY };
		double currentValue{ getValue() };
		double interval{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
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
// Creates graphical representations of various wave shapes.
// Oscillator and LFO shape KnobWidgets use this to display their current values
class WaveShapeRenderer : public Component
{
public:
	WaveShapeRenderer() 
	{
		auto knob_diameter{ 30 };
		setSize(knob_diameter, knob_diameter);
	};

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
			Line<float> line1{ 5.0f, 15.0f, 15.0f, 7.0f };
			Line<float> line2{ 15.0f, 7.0f, 15.0f, 15.0f };
			Line<float> line3{ 15.0f, 15.0f, 20.0f, 22.0f };
			Line<float> line4{ 20.0f, 22.0f, 25.0f, 15.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			path.addLineSegment(line3, 0.5f);
			path.addLineSegment(line4, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
	}

	void clear() { selectedShape = "none"; repaint(); }
	void drawSawtooth() { selectedShape = "sawtooth"; repaint(); }
	void drawTriangle() { selectedShape = "triangle"; repaint(); }
	void drawSawTri() { selectedShape = "sawTri"; repaint(); }

private:
	String selectedShape;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveShapeRenderer)
};

//==============================================================================
// Base class for knob widgets. Derived classes must
// override drawValue() and createTooltipString()
class KnobWidget : public Component, public Slider::Listener
{
public:
	KnobWidget
	(
		String knobName,
		AudioProcessorValueTreeState* apvts,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		sliderAttachment{ *apvts, paramID.toString(), slider },
		mophoLaF{ mophoLaF },
		name{ knobName }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setLookAndFeel(mophoLaF);
		slider.addListener(this);
		addAndMakeVisible(slider);
		slider.setColour(TooltipWindow::backgroundColourId, Colours::lightblue);

		valueDisplayLabel.setInterceptsMouseClicks(false, false);
		valueDisplayLabel.setLookAndFeel(mophoLaF);
		addAndMakeVisible(valueDisplayLabel);

		tooltipWindow.setMillisecondsBeforeTipAppears(1000);
		tooltipWindow.setLookAndFeel(mophoLaF);
		tooltipWindow.setComponentEffect(nullptr);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget()
	{
		tooltipWindow.setLookAndFeel(nullptr);
		valueDisplayLabel.setLookAndFeel(nullptr);
		slider.removeListener(this);
		slider.setLookAndFeel(nullptr);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::black);
		g.fillEllipse(5, 5, 30, 30);

		Font controlLabel{ "Arial", "Black", 13.0f };
		g.setFont(controlLabel);
		Rectangle<int> controlLabelArea{ 0, 35, 40, 15 };
		g.drawText(name, controlLabelArea, Justification::centred);
	}

	void resized() override
	{
		slider.setBounds(0, 0, 40, 40);
		valueDisplayLabel.setBounds(5, 5, 30, 30);
	}

	void sliderValueChanged(Slider* sliderThatChanged)
	{
		if (sliderThatChanged == &slider)
		{
			auto currentValue{ slider.getValue() };
			drawValue(currentValue);
			auto tooltip{ createTooltipString(currentValue) };
			setSliderTooltip(tooltip);
		}
	}

	auto getSliderValue() { return slider.getValue(); }

	void setValueDisplayLabelText(String text) { valueDisplayLabel.setText(text, dontSendNotification); }
	
	void setSliderTooltip(String text) { slider.setTooltip(text); }
	
private:
	CustomSlider slider;
	Attachment sliderAttachment;
	MophoLookAndFeel* mophoLaF;
	Label valueDisplayLabel;

	String name;

	TooltipWindow tooltipWindow;

	//==============================================================================
	// Override this function to define how the current
	// parameter value is drawn on the knob
	virtual void drawValue(const double& currentValue) = 0;

	// Override this function to create a String with 
	// a verbose version of the current parameter value
	// along with a parameter description, which will
	// be used as the slider's tooltip
	virtual String createTooltipString(const double& currentValue) const = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget)
};

//==============================================================================
// A knob widget appropriate for controlling oscillator pitch parameters.
// Displays its value as a pitch name + octave number combination
class KnobWidget_OscPitch : public KnobWidget
{
public:
	KnobWidget_OscPitch
	(
		AudioProcessorValueTreeState* apvts, 
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "PITCH", apvts, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(getSliderValue());
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscPitch()
	{}

private:
	ValueConverters valueConverters;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscPitch)
};

//==============================================================================
// A knob widget appropriate for controlling oscillator fine tune parameters.
// Displays its value in a range from -50 to +50 (cents)
class KnobWidget_FineTune : public KnobWidget
{
public:
	KnobWidget_FineTune
	(
		AudioProcessorValueTreeState* apvts, 
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "FINE", apvts, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(getSliderValue());
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_FineTune()
	{}

private:
	ValueConverters valueConverters;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_FineTune)
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
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "SHAPE", apvts, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };

		shapeRenderer.setInterceptsMouseClicks(false, false);
		shapeRenderer.setBounds(5, 5, shapeRenderer.getWidth(), shapeRenderer.getHeight());
		addAndMakeVisible(shapeRenderer);

		drawValue(getSliderValue());
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscShape()
	{}

private:
	ValueConverters valueConverters;

	WaveShapeRenderer shapeRenderer;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscShape)
};