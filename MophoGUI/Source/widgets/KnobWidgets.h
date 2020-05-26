#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/InfoStrings.h"
#include "../helpers/ParameterTools.h"
#include "../parameters/PrivateParameters.h"
#include "LCDcharacterRenderer.h"
#include "WaveShapeRenderer.h"

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
// Base class for knob widgets.
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
		sliderValueChanged(&slider);

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
			auto currentValue(getSliderValue());
			drawValue(currentValue);
			slider.setTooltip(createTooltipString(paramIndex, paramType, getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
		}
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
			slider.setTooltip(createTooltipString(paramIndex, paramType, getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
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
	}

	~KnobWidget_OscShape()
	{}

private:
	WaveShapeRenderer shapeRenderer;

	void drawValue(const int& currentValue) noexcept
	{
		if (currentValue >= MophoOscWaveShape::off && currentValue <= MophoOscWaveShape::pulseMaxWidth)
		{
			if (currentValue == MophoOscWaveShape::off)
			{
				shapeRenderer.clear();
				currentValueText = "OFF";
			}
			if (currentValue == MophoOscWaveShape::sawtooth)
			{
				currentValueText = "";
				shapeRenderer.drawSawtooth();
			}
			if (currentValue == MophoOscWaveShape::triangle)
			{
				currentValueText = "";
				shapeRenderer.drawTriangle();
			}
			if (currentValue == MophoOscWaveShape::sawTriMix)
			{
				currentValueText = "";
				shapeRenderer.drawSawTri();
			}
			if (currentValue >= MophoOscWaveShape::pulse)
			{
				currentValueText = "";
				shapeRenderer.drawPulse(currentValue - 3);
			}
		}
		else
		{
			shapeRenderer.clear();
			currentValueText = "ERR";
		}
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_OscShape)
};

//==============================================================================
// A knob widget appropriate for setting one of the program name characters.
class KnobWidget_PgmNameChar : 
	public Component, 
	public Slider::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	KnobWidget_PgmNameChar
	(
		int charNumber,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		int index
	) :
		sliderAttachment{ *apvts, "nameChar" + (String)charNumber, slider },
		privateParams{ privateParameters },
		paramIndex{ index }
	{
		addAndMakeVisible(charRenderer);

		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setAlpha(0.0f);
		slider.setMouseDragSensitivity(175);
		slider.setRange(32.0, 127.0, 1.0);
		slider.addListener(this);
		addAndMakeVisible(slider);

		sliderValueChanged(&slider);

		auto char_w{ 12 };
		auto char_h{ 17 };
		setSize(char_w, char_h);
	}

	~KnobWidget_PgmNameChar()
	{
		slider.removeListener(this);
	}

	void resized() override
	{
		slider.setBounds(0, 0, 26, 26);
	}

	auto getSliderValue() { return roundToInt(slider.getValue()); }

	void setCharValue(int newValue)
	{
		slider.setValue(32.0, sendNotification);
		slider.setValue((double)newValue, sendNotification);
	}

	void sliderValueChanged(Slider* sliderThatChanged) override
	{
		if (sliderThatChanged == &slider)
			slider.setTooltip(createTooltipString(paramIndex, MophoParameterType::pgmNameChar, getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
			slider.setTooltip(createTooltipString(paramIndex, MophoParameterType::pgmNameChar, getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

private:

private:
	CustomSlider slider;
	SliderAttachment sliderAttachment;

	LCDcharacterRenderer charRenderer;

	int paramIndex;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_PgmNameChar)
};

//==============================================================================
// A knob widget appropriate for controlling a step in sequencer track 1.
class KnobWidget_Track1Step : 
	public Component, 
	public Slider::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	KnobWidget_Track1Step
	(
		int stepNumber,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		int index
	) :
		sliderAttachment{ *apvts, "track1Step" + (String)stepNumber, slider },
		privateParams{ privateParameters },
		name{ (String)stepNumber },
		isPitch{ true },
		paramIndex{ index }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setAlpha(0.0f);
		slider.setMouseDragSensitivity(MophoKnobSensitivity::zeroTo127);
		slider.addListener(this);
		addAndMakeVisible(slider);
		sliderValueChanged(&slider);

		auto knobWidget_w{ 26 };
		auto knobWidget_h{ 40 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget_Track1Step()
	{
		slider.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		//draw step square
		g.setColour(Color::black);
		g.fillRect(0, 0, 26, 26);

		// draw step name 
		Font stepName{ "Arial", "Black", 12.0f };
		g.setFont(stepName);
		Rectangle<int> stepNameArea{ 0, 27, getWidth(), 10 };
		g.drawText(name, stepNameArea, Justification::centredTop);

		// draw step value
		g.setColour(Color::controlText);
		Font stepValue{ "Arial", "Narrow Bold", 13.0f };
		g.setFont(stepValue);
		Rectangle<int> stepValueArea{ 0, 0, 26, 26 };
		auto currentValue{ roundToInt(slider.getValue()) };
		if (currentValue < 126)
			g.drawText(convertIntToValueString(isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue, currentValue, true), 
					   stepValueArea, Justification::centred);
		if (currentValue == 126) // sequencer track reset
		{
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			g.drawArrow(l, 5.0f, 10.0f, 8.0f);
		}
		if (currentValue == 127) // rest
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
			slider.setTooltip(createTooltipString(paramIndex, isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue, 
							  getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
			slider.setTooltip(createTooltipString(paramIndex, isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue,
							  getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

	void drawValueAsPitch(bool shouldDrawAsPitch)
	{
		isPitch = shouldDrawAsPitch;
		repaint();
		sliderValueChanged(&slider);
	}

	void setToRest() { slider.setValue(127.0, sendNotification); }

private:
	CustomSliderForTrack1Steps slider;
	SliderAttachment sliderAttachment;

	String name;

	bool isPitch;

	int paramIndex;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_Track1Step)
};

//==============================================================================
// A knob widget appropriate for controlling a step in sequencer track 2, 3, or 4.
class KnobWidget_Tracks2_3_4Step : 
	public Component, 
	public Slider::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	KnobWidget_Tracks2_3_4Step
	(
		int trackNumber,
		int stepNumber,
		AudioProcessorValueTreeState* apvts,
		PrivateParameters* privateParameters,
		int index
	) :
		sliderAttachment{ *apvts, "track" + (String)trackNumber + "Step" + (String)stepNumber, slider },
		privateParams{ privateParameters },
		name{ (String)stepNumber },
		isPitch{ true },
		paramIndex{ index }
	{
		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setAlpha(0.0f);
		slider.setMouseDragSensitivity(MophoKnobSensitivity::zeroTo127);
		slider.addListener(this);
		addAndMakeVisible(slider);
		sliderValueChanged(&slider);

		auto knobWidget_w{ 26 };
		auto knobWidget_h{ 40 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget_Tracks2_3_4Step()
	{
		slider.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		//draw step square
		g.setColour(Color::black);
		g.fillRect(0, 0, 26, 26);

		// draw step name 
		Font stepName{ "Arial", "Black", 12.0f };
		g.setFont(stepName);
		Rectangle<int> stepNameArea{ 0, 27, getWidth(), 10 };
		g.drawText(name, stepNameArea, Justification::centredTop);

		// draw step value
		g.setColour(Color::controlText);
		Font stepValue{ "Arial", "Narrow Bold", 13.0f };
		g.setFont(stepValue);
		Rectangle<int> stepValueArea{ 0, 0, 26, 26 };
		auto currentValue{ roundToInt(slider.getValue()) };
		if (currentValue < 126)
			g.drawText(convertIntToValueString(isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue, currentValue, true), 
					   stepValueArea, Justification::centred);
		if (currentValue == 126) // sequencer track reset
		{
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			g.drawArrow(l, 5.0f, 10.0f, 8.0f);
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
			slider.setTooltip(createTooltipString(paramIndex, isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue, 
							  getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
		}
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
			slider.setTooltip(createTooltipString(paramIndex, isPitch ? MophoParameterType::stepValueAsPitch : MophoParameterType::stepValue,
							  getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
	}

	void drawValueAsPitch(bool shouldDrawAsPitch)
	{
		isPitch = shouldDrawAsPitch;
		repaint();
		sliderValueChanged(&slider);
	}

	void setToZero() { slider.setValue(0.0, sendNotification); }

private:
	CustomSliderForTracks2_3_4Steps slider;
	SliderAttachment sliderAttachment;

	String name;

	bool isPitch;

	int paramIndex;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_Tracks2_3_4Step)
};

//==============================================================================
// Base class for knob widgets in the global options window
class KnobWidget_GlobalOptions :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener,
	public MophoParameterTooltipGenerator
{
public:
	PrivateParameters* privateParams;

	String currentValueText{ "" };

	KnobWidget_GlobalOptions
	(
		String labelText1,
		String labelText2,
		PluginProcessor& p,
		PrivateParameters* privateParameters,
		Identifier parameterID,
		int index,
		int type,
		int nrpn,
		int maximum,
		int knobSensitivity
	) :
		processor{ p },
		paramID{ parameterID },
		privateParams{ privateParameters },
		nameLine1{ labelText1 },
		nameLine2{ labelText2 },
		paramIndex{ index },
		paramType{ type },
		nrpnIndex{ nrpn },
		maxValue{ maximum }
	{
		privateParams->addListenerToGlobalOptions(this);

		slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		slider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		slider.setRotaryParameters(degreesToRadians(225.0f), degreesToRadians(495.0f), true);
		slider.setMouseDragSensitivity(knobSensitivity);
		slider.addListener(this);
		addAndMakeVisible(slider);
		sliderValueChanged(&slider);

		auto knobWidget_w{ 70 };
		auto knobWidget_h{ 65 };
		setSize(knobWidget_w, knobWidget_h);
	}

	~KnobWidget_GlobalOptions()
	{
		slider.removeListener(this);
		privateParams->removeListenerFromGlobalOptions(this);
	}

	void paint(Graphics& g) override
	{
		// draw knob circle
		g.setColour(Color::black);
		g.fillEllipse(20, 5, 30, 30);

		// draw knob name 
		Font knobName{ "Arial", "Black", 12.0f };
		g.setFont(knobName);
		Rectangle<int> knobNameArea1{ 0, 35, 70, 15 };
		g.drawText(nameLine1, knobNameArea1, Justification::centred);
		Rectangle<int> knobNameArea2{ 0, 45, 70, 15 };
		g.drawText(nameLine2, knobNameArea2, Justification::centred);

		// draw knob value
		g.setColour(Color::controlText);
		Font knobValue{ "Arial", "Narrow Bold", 13.0f };
		g.setFont(knobValue);
		Rectangle<int> knobValueArea{ 20, 5, 30, 30 };
		g.drawText(currentValueText, knobValueArea, Justification::centred);
	}

	void resized() override
	{
		slider.setBounds(15, 0, 40, 40);
	}

	auto getSliderValue() { return roundToInt(slider.getValue()); }

	void sliderValueChanged(Slider* sliderThatChanged) override
	{
		if (sliderThatChanged == &slider)
		{
			auto currentValue{ getSliderValue() };
			privateParams->setGlobalOptionsProperty(paramID, currentValue);
			processor.addNRPNmessagesToBuffer(nrpnIndex, currentValue);
			drawValue(currentValue);
			slider.setTooltip(createTooltipString(paramIndex, paramType, currentValue, privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
		}
	}

	void valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) override
	{
		if (property == ID::showCurrentVal || property == ID::showParamInfo)
		{
			auto currentValue{ privateParams->getGlobalOptionsProperty(property) };
			slider.setValue((double)currentValue, dontSendNotification);
			drawValue(currentValue);
			slider.setTooltip(createTooltipString(paramIndex, paramType, getSliderValue(), privateParams->shouldShowValueTip(), privateParams->shouldShowInfoTip()));
		}
	}

private:
	PluginProcessor& processor;

	Identifier paramID;

	CustomSlider slider;

	String nameLine1;
	String nameLine2;

	int paramIndex;
	int paramType;
	int nrpnIndex;
	int maxValue;


	void drawValue(const int& currentValue) noexcept
	{
		currentValueText = convertIntToValueString(paramType, currentValue, false);
		repaint();
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWidget_GlobalOptions)
};

