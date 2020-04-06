#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../helpers/ValueConverters.h"
#include "../parameters/PrivateParameters.h"

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
// A special slider used for setting the values of steps in sequencer tracks 2, 3, and 4.
// Derives from CustomSlider and overrides mouseDown() so that the slider's value
// changes to 126 (sequencer track reset) if it is clicked while the CTRL key is down
class CustomSliderForTracks2to4Steps : public CustomSlider
{
public:
	CustomSliderForTracks2to4Steps() {}

	void mouseDown(const MouseEvent& e) override
	{
		if (e.mods.isCtrlDown())
			setValue(126, sendNotification);
		else Slider::mouseDown(e);
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomSliderForTracks2to4Steps)
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
// Creates graphical representations of various wave shapes.
// Oscillator and LFO shape KnobWidgets use this to display their current values
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
class KnobWidget : public Component, public Slider::Listener
{
public:
	PrivateParameters* privateParams;

	KnobWidget
	(
		String knobName,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		sliderAttachment{ *apvts, paramID.toString(), slider },
		privateParams{ privateParameters },
		mophoLaF{ mophoLaF },
		name{ knobName }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setLookAndFeel(mophoLaF);
		slider.addListener(this);
		addAndMakeVisible(slider);

		auto knobWidget_w{ 40 };
		auto knobWidget_h{ 50 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget()
	{
		slider.removeListener(this);
		slider.setLookAndFeel(nullptr);
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
			auto tooltip{ createTooltipString(currentValue) };
			setSliderTooltip(tooltip);
		}
	}

	void setCurrentValueText(String text) { currentValueText = text; repaint(); }
	
	void setSliderTooltip(String text) { slider.setTooltip(text); }
	
private:
	CustomSlider slider;
	SliderAttachment sliderAttachment;
	MophoLookAndFeel* mophoLaF;

	String name;
	String currentValueText;

	//==============================================================================
	// Override this function to define how the current
	// parameter value is drawn on the knob
	virtual void drawValue(const int& currentValue) noexcept = 0;

	// Derived classes must override this function to create a tooltip String with a
	// parameter description and/or a verbose version of the parameter's current value
	virtual String createTooltipString(const int& currentValue) const noexcept = 0;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget)
};

//==============================================================================
// A knob widget appropriate for controlling any parameter
// with a simple 7-bit MIDI value range (0..127)
class KnobWidget_0to127 : public KnobWidget
{
public:
	KnobWidget_0to127
	(
		String label,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ label, apvts, privateParameters, paramID, mophoLaF }
	{
		drawValue(getSliderValue());
	}

	~KnobWidget_0to127() {}

private:
	WaveShapeRenderer shapeRenderer;

	void drawValue(const int& currentValue) noexcept override;

	// Derived classes must override this function to create a tooltip String with a
	// parameter description and/or a verbose version of the parameter's current value
	String createTooltipString(const int& /*currentValue*/) const noexcept override { return ""; };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_0to127)
};

//==============================================================================
// A knob widget appropriate for controlling any
// parameter with a value range of -127 to +127
class KnobWidget_PlusMinus127 : public KnobWidget
{
public:
	KnobWidget_PlusMinus127
	(
		String label,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ label, apvts, privateParameters, paramID, mophoLaF }
	{
		drawValue(getSliderValue());
	}

	~KnobWidget_PlusMinus127() {}

	ValueConverters valueConverters;

private:
	void drawValue(const int& currentValue) noexcept override;

	// Derived classes must override this function to create a tooltip String with a
	// parameter description and/or a verbose version of the parameter's current value
	String createTooltipString(const int& /*currentValue*/) const noexcept override { return ""; };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_PlusMinus127)
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
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "PITCH", apvts, privateParameters, paramID, mophoLaF }
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

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

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
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "FINE", apvts, privateParameters, paramID, mophoLaF }
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

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

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
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "SHAPE", apvts, privateParameters, paramID, mophoLaF }
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

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscShape)
};

//==============================================================================
// A knob widget appropriate for controlling an oscillator's glide rate.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_OscGlide : public KnobWidget_0to127
{
public:
	KnobWidget_OscGlide
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("GLIDE"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscGlide() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscGlide)
};

//==============================================================================
// A knob widget appropriate for controlling a sub-oscillator's level.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_OscSubLvl : public KnobWidget_0to127
{
public:
	KnobWidget_OscSubLvl
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("SUB"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscSubLvl() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscSubLvl)
};

//==============================================================================
// A knob widget appropriate for controlling the oscillator slop parameter.
// Displays its value in a range from 0 to 5
class KnobWidget_OscSlop : public KnobWidget
{
public:
	KnobWidget_OscSlop
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "SLOP", apvts, privateParameters, ID::oscSlop, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscSlop()
	{}

private:
	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscSlop)
};

//==============================================================================
// A knob widget appropriate for controlling the balance of oscillators 1 & 2.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_OscMix : public KnobWidget_0to127
{
public:
	KnobWidget_OscMix
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("MIX"), apvts, privateParameters, ID::oscMix, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_OscMix() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscMix)
};

//==============================================================================
// A knob widget appropriate for controlling the pitch bend range parameter.
// Displays its value in a range from 0 to +/-12
class KnobWidget_BendRange : public KnobWidget
{
public:
	KnobWidget_BendRange
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "BEND", apvts, privateParameters, ID::bendRange, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_BendRange()
	{}

private:
	ValueConverters valueConverters;

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_BendRange)
};

//==============================================================================
// A knob widget appropriate for controlling the noise level.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_NoiseLevel : public KnobWidget_0to127
{
public:
	KnobWidget_NoiseLevel
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("NOISE"), apvts, privateParameters, ID::noiseLevel, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_NoiseLevel() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_NoiseLevel)
};

//==============================================================================
// A knob widget appropriate for controlling the external audio input level.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_ExtInLevel : public KnobWidget_0to127
{
public:
	KnobWidget_ExtInLevel
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("EXT IN"), apvts, privateParameters, ID::extInLevel, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_ExtInLevel() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_ExtInLevel)
};

//==============================================================================
// A knob widget appropriate for controlling the LPF cuttoff frequency parameter.
// Displays its value in a range from 0 to 164
class KnobWidget_LPFfreq : public KnobWidget
{
public:
	KnobWidget_LPFfreq
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "CUTOFF", apvts, privateParameters, ID::lpfFreq, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LPFfreq()
	{}

private:
	ValueConverters valueConverters;

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LPFfreq)
};

//==============================================================================
// A knob widget appropriate for controlling the LPF resonance parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_LPFreso : public KnobWidget_0to127
{
public:
	KnobWidget_LPFreso
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("RESO"), apvts, privateParameters, ID::lpfReso, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LPFreso() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LPFreso)
};

//==============================================================================
// A knob widget appropriate for controlling the LPF envelope amount parameter.
// Derives from KnobWidget_PlusMinus127 and overrides createTooltipString()
class KnobWidget_LPFenvAmt : public KnobWidget_PlusMinus127
{
public:
	KnobWidget_LPFenvAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_PlusMinus127{ String("ENV"), apvts, privateParameters, ID::lpfEnvAmount, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LPFenvAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LPFenvAmt)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope velocity amount parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_VelAmount : public KnobWidget_0to127
{
public:
	KnobWidget_VelAmount
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("VELO"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_VelAmount() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_VelAmount)
};

//==============================================================================
// A knob widget appropriate for controlling the LPF keyboard amount parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_LPFkeyAmt : public KnobWidget_0to127
{
public:
	KnobWidget_LPFkeyAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("KEY"), apvts, privateParameters, ID::lpfKeyAmount, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LPFkeyAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LPFkeyAmt)
};

//==============================================================================
// A knob widget appropriate for controlling the LPF FM amount parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_LPFfmAmt : public KnobWidget_0to127
{
public:
	KnobWidget_LPFfmAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("FM"), apvts, privateParameters, ID::lpfFMamount, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LPFfmAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LPFfmAmt)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope delay length parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_EnvDelay : public KnobWidget_0to127
{
public:
	KnobWidget_EnvDelay
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("DELAY"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_EnvDelay() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_EnvDelay)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope attack length parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_EnvAttack : public KnobWidget_0to127
{
public:
	KnobWidget_EnvAttack
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("ATTACK"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_EnvAttack() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_EnvAttack)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope decay length parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_EnvDecay : public KnobWidget_0to127
{
public:
	KnobWidget_EnvDecay
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("DECAY"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_EnvDecay() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_EnvDecay)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope sustain level parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_EnvSustain : public KnobWidget_0to127
{
public:
	KnobWidget_EnvSustain
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("SUST"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_EnvSustain() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_EnvSustain)
};

//==============================================================================
// A knob widget appropriate for controlling any of the envelope release length parameters.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_EnvRelease : public KnobWidget_0to127
{
public:
	KnobWidget_EnvRelease
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("REL"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_EnvRelease() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_EnvRelease)
};

//==============================================================================
// A knob widget appropriate for controlling the VCA level parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_VCAlevel : public KnobWidget_0to127
{
public:
	KnobWidget_VCAlevel
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("LEVEL"), apvts, privateParameters, ID::vcaLevel, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_VCAlevel() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_VCAlevel)
};

//==============================================================================
// A knob widget appropriate for controlling the VCA envelope amount parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_VCAenvAmt : public KnobWidget_0to127
{
public:
	KnobWidget_VCAenvAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("ENV"), apvts, privateParameters, ID::vcaEnvAmount, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_VCAenvAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_VCAenvAmt)
};

//==============================================================================
// A knob widget appropriate for controlling the program volume parameter.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_PgmVolume : public KnobWidget_0to127
{
public:
	KnobWidget_PgmVolume
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_0to127{ String("VOLUME"), apvts, privateParameters, ID::pgmVolume, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_PgmVolume() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_PgmVolume)
};

//==============================================================================
// A knob widget appropriate for controlling the Envelope 3 amount parameter.
// Derives from KnobWidget_PlusMinus127 and overrides createTooltipString()
class KnobWidget_Env3Amt : public KnobWidget_PlusMinus127
{
public:
	KnobWidget_Env3Amt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_PlusMinus127{ String("AMT"), apvts, privateParameters, ID::env3Amount, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_Env3Amt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_Env3Amt)
};

//==============================================================================
// A knob widget appropriate for controlling the amount parameter for any of the modulators.
// Derives from KnobWidget_PlusMinus127 and overrides createTooltipString()
class KnobWidget_ModAmt : public KnobWidget_PlusMinus127
{
public:
	KnobWidget_ModAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_PlusMinus127{ String("AMT"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_ModAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_ModAmt)
};

//==============================================================================
// A knob widget appropriate for controlling the amount parameter for any of the MIDI controllers.
// Derives from KnobWidget_PlusMinus127 and overrides createTooltipString()
class KnobWidget_MidiModAmt : public KnobWidget_PlusMinus127
{
public:
	KnobWidget_MidiModAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget_PlusMinus127{ String("AMT"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_MidiModAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_MidiModAmt)
};

//==============================================================================
// A knob widget appropriate for controlling a low-frequency oscillator's amount.
// Derives from KnobWidget_0to127 and overrides createTooltipString()
class KnobWidget_LFOAmt : public KnobWidget_0to127
{
public:
	KnobWidget_LFOAmt
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		Identifier paramID,
		MophoLookAndFeel* mophoLaF
		) :
		KnobWidget_0to127{ String("AMT"), apvts, privateParameters, paramID, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LFOAmt() {}

private:
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LFOAmt)
};

//==============================================================================
// A knob widget appropriate for controlling a low-frequency oscillator's frequency.
// Derives from KnobWidget and overrides drawValue() and createTooltipString()
class KnobWidget_LFOfreq : public KnobWidget
{
public:
	KnobWidget_LFOfreq
	(
		int lfoNumber,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "FREQ", apvts, privateParameters, "lfo" + (String)lfoNumber + "Freq", mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_LFOfreq()
	{}

private:
	ValueConverters valueConverters;

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_LFOfreq)
};

//==============================================================================
// A knob widget appropriate for controlling the clock tempo parameter.
// Derives from KnobWidget and overrides drawValue() and createTooltipString()
class KnobWidget_ClockTempo : public KnobWidget
{
public:
	KnobWidget_ClockTempo
	(
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		KnobWidget{ "BPM", apvts, privateParameters, ID::clockTempo, mophoLaF }
	{
		auto currentValue{ getSliderValue() };
		drawValue(currentValue);
		auto tooltip{ createTooltipString(currentValue) };
		setSliderTooltip(tooltip);
	}

	~KnobWidget_ClockTempo()
	{}

private:
	ValueConverters valueConverters;

	void drawValue(const int& currentValue) noexcept override;
	String createTooltipString(const int& currentValue) const noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_ClockTempo)
};

//==============================================================================
// A knob widget appropriate for controlling a step in sequencer track 1.
class KnobWidget_Track1Step : public Component, public Slider::Listener
{
public:
	PrivateParameters* privateParams;

	KnobWidget_Track1Step
	(
		int stepNumber,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		MophoLookAndFeel* mophoLaF
	) :
		sliderAttachment{ *apvts, "track1Step" + (String)stepNumber, slider },
		privateParams{ privateParameters },
		mophoLaF{ mophoLaF },
		name{ (String)stepNumber },
		isPitch{ true }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setLookAndFeel(mophoLaF);
		slider.setAlpha(0.0f);
		slider.addListener(this);
		addAndMakeVisible(slider);

		auto tooltip{ createTooltipString(roundToInt(slider.getValue())) };
		setSliderTooltip(tooltip);

		auto knobWidget_w{ 26 };
		auto knobWidget_h{ 40 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget_Track1Step()
	{
		slider.removeListener(this);
		slider.setLookAndFeel(nullptr);
	}

	void paint(Graphics& g) override
	{
		//draw step square
		g.setColour(Color::black);
		g.fillRect(0, 0, 26, 26);

		// draw step name 
		Font knobName{ "Arial", "Black", 12.0f };
		g.setFont(knobName);
		Rectangle<int> knobNameArea{ 0, 27, getWidth(), 10 };
		g.drawText(name, knobNameArea, Justification::centredTop);

		// draw step value
		g.setColour(Color::controlText);
		Font knobValue{ "Arial", "Narrow Bold", 13.0f };
		g.setFont(knobValue);
		Rectangle<int> knobValueArea{ 0, 0, 26, 26 };
		auto currentValue{ roundToInt(slider.getValue()) };
		if (currentValue < 126)
			g.drawText(valueConverters.intToStepValue(currentValue, isPitch), knobValueArea, Justification::centred);
		if (currentValue == 126) // sequencer track reset
		{
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			g.drawArrow(l, 5.0f, 10.0f, 8.0f);
		}
		if (currentValue == 127) // est
		{
			g.fillEllipse(10.0f, 10.0f, 6.0f, 6.0f);
		}
	}

	void resized() override
	{
		slider.setBounds(0, 0, 26, 26);
	}

	auto getSliderValue() { return roundToInt(slider.getValue()); }

	void sliderValueChanged(Slider* sliderThatChanged) override
	{
		if (sliderThatChanged == &slider)
		{
			auto currentValue{ getSliderValue() };
			auto tooltip{ createTooltipString(currentValue) };
			setSliderTooltip(tooltip);
			repaint();
		}
	}

	void drawValueAsPitch(bool shouldDrawAsPitch)
	{
		isPitch = shouldDrawAsPitch;
		repaint();
		sliderValueChanged(&slider);
	}

	void setSliderTooltip(String text) { slider.setTooltip(text); }

	void setToRest() { slider.setValue(127.0, sendNotification); }

private:
	CustomSliderForTrack1Steps slider;
	SliderAttachment sliderAttachment;
	MophoLookAndFeel* mophoLaF;

	String name;

	bool isPitch;

	ValueConverters valueConverters;

	// Creates a tooltip String with a parameter description
	// a verbose version of the parameter's current value
	String createTooltipString(const int& currentValue) const noexcept;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_Track1Step)
};

