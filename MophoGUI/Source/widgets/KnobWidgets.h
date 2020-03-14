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

		valueDisplayLabel.setInterceptsMouseClicks(false, false);
		valueDisplayLabel.setLookAndFeel(mophoLaF);
		addAndMakeVisible(valueDisplayLabel);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget()
	{
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

	//==============================================================================
	// Override this function to define how the current
	// parameter value is drawn on the knob
	virtual void drawValue(const double& currentValue) noexcept = 0;

	// Override this function to create a String with 
	// a verbose version of the current parameter value
	// along with a parameter description, which will
	// be used as the slider's tooltip
	virtual String createTooltipString(const double& currentValue) const noexcept = 0;

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
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscPitch()
	{}

private:
	ValueConverters valueConverters;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) noexcept override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const noexcept override;

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
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_FineTune()
	{}

private:
	ValueConverters valueConverters;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) noexcept override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const noexcept override;

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
	ValueConverters valueConverters;

	WaveShapeRenderer shapeRenderer;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) noexcept override;

	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscShape)
};

//==============================================================================
// A knob widget appropriate for controlling any parameter
// with a simple 7-bit MIDI value range (0 to 127)
class KnobWidget_0to127 : public KnobWidget
{
public:
	KnobWidget_0to127
	(
		String label,
		AudioProcessorValueTreeState* apvts,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ label, apvts, paramID, mophoLaF }
	{
		drawValue(getSliderValue());
	}

	~KnobWidget_0to127() {}

private:
	ValueConverters valueConverters;

	WaveShapeRenderer shapeRenderer;

	//==============================================================================
	// Draws the current parameter value on the knob
	void drawValue(const double& currentValue) noexcept override;

	// KnobWidgets that derive from this class must 
	// override this function to create a tooltip String 
	// appropriate to the type of parameter they control
	String createTooltipString(const double& /*currentValue*/) const noexcept override { return ""; };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_0to127)
};

//==============================================================================
// A knob widget appropriate for controlling any parameter
// with a simple 7-bit MIDI value range (0 to 127)
class KnobWidget_OscGlide : public KnobWidget_0to127
{
public:
	KnobWidget_OscGlide
	(
		AudioProcessorValueTreeState* apvts, 
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("GLIDE"), apvts, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscGlide() {}

private:

	//==============================================================================
	// Draws a pop-up window with a parameter description and 
	// a verbose version of the current parameter value when 
	// the mouse hovers over the slider
	String createTooltipString(const double& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscGlide)
};
