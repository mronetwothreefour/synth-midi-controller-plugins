#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"

using Attachment = AudioProcessorValueTreeState::SliderAttachment;

// Creates a graphical representation of an envelope,
// derived from the current settings for its delay,
// attack, decay, sustain, and release parameters.
// For the envelopeID String, use "lpf", "vca", or "env3"
class EnvelopeRenderer : 
	public Component,
	public Slider::Listener
{
public:
	EnvelopeRenderer
	(
		AudioProcessorValueTreeState* publicParams,
		String envelopeID
	) :
		delayAttachment{ *publicParams, envelopeID + "Delay", delay },
		attackAttachment{ *publicParams, envelopeID + "Attack", attack },
		decayAttachment{ *publicParams, envelopeID + "Decay", decay },
		sustainAttachment{ *publicParams, envelopeID + "Sustain", sustain },
		releaseAttachment{ *publicParams, envelopeID + "Release", release }
	{
		delay.addListener(this);
		attack.addListener(this);
		decay.addListener(this);
		sustain.addListener(this);
		release.addListener(this);

		auto envelopeRenderer_w{ 210 };
		auto envelopeRenderer_h{ 90 };
		setSize(envelopeRenderer_w, envelopeRenderer_h);
	}

	~EnvelopeRenderer() 
	{
		release.removeListener(this);
		sustain.removeListener(this);
		decay.removeListener(this);
		attack.removeListener(this);
		delay.removeListener(this);
	}

	void paint(Graphics& g) override
	{
		g.fillAll(Color::black);

		g.setColour(Color::controlText);
		Line<float> baseline{ 5.0f, 75.0f, 205.0f, 75.0f };
		float dashes[2];
		dashes[0] = 5.0f;
		dashes[1] = 5.0f;
		g.drawDashedLine(baseline, dashes, 2);

		auto maxSegment_w{ 43.0f };
		auto sustainSegment_w{ 28.0f };
		Path path;
		auto envelopeStart_x{ 5.0f };
		auto attackStart_x{ envelopeStart_x + (((float)delay.getValue() / 127.0f) * maxSegment_w) };
		auto decayStart_x{ attackStart_x + (((float)attack.getValue() / 127.0f) * maxSegment_w) };
		auto sustainStart_x{ decayStart_x + (((float)decay.getValue() / 127.0f) * maxSegment_w) };
		auto releaseStart_x{ sustainStart_x + sustainSegment_w };
		auto releaseEnd_x{ releaseStart_x + (((float)release.getValue() / 127.0f) * maxSegment_w) };
		auto envelopeEnd_x{ 205.0f };
		auto minimum_y{ 75.0f };
		auto maximum_y{ 15.0f };
		auto sustain_y{ minimum_y - (((float)sustain.getValue() / 127.0f) * 60.0f) };
		path.startNewSubPath(envelopeStart_x, minimum_y);
		path.lineTo(attackStart_x, minimum_y);
		path.lineTo(decayStart_x, maximum_y);
		path.lineTo(sustainStart_x, sustain_y);
		path.lineTo(releaseStart_x, sustain_y);
		path.lineTo(releaseEnd_x, minimum_y);
		path.lineTo(envelopeEnd_x, minimum_y);
		PathStrokeType strokeType{ 2.0f, PathStrokeType::mitered, PathStrokeType::rounded };
		g.strokePath(path, strokeType);
	}

	void sliderValueChanged(Slider* /*sliderThatChanged*/) override
	{
		repaint();
	}

private:
	Slider delay;
	Slider attack;
	Slider decay;
	Slider sustain;
	Slider release;

	Attachment delayAttachment;
	Attachment attackAttachment;
	Attachment decayAttachment;
	Attachment sustainAttachment;
	Attachment releaseAttachment;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderer)
};

// A set of knobs for controlling the specified envelope's
// delay, attack, decay, sustain, and release parameters,
// as well as an envelope renderer widget.
// For the envelopeID String, use "lpf", "vca", or "env3"
class EnvelopeWidget : public Component
{
public:
	EnvelopeWidget
	(
		AudioProcessorValueTreeState* publicParams,
		PrivateParameters* privateParameters,
		String envelopeID
	) :
		envelopeRenderer{publicParams, envelopeID},
		knob_Delay{ publicParams, privateParameters, envelopeID + "Delay" },
		knob_Attack{ publicParams, privateParameters, envelopeID + "Attack" },
		knob_Decay{ publicParams, privateParameters, envelopeID + "Decay" },
		knob_Sustain{ publicParams, privateParameters, envelopeID + "Sustain" },
		knob_Release{ publicParams, privateParameters, envelopeID + "Release" }
	{
		addAndMakeVisible(envelopeRenderer);
		addAndMakeVisible(knob_Delay);
		addAndMakeVisible(knob_Attack);
		addAndMakeVisible(knob_Decay);
		addAndMakeVisible(knob_Sustain);
		addAndMakeVisible(knob_Release);

		auto envelopeWidget_w{ 220 };
		auto envelopeWidget_h{ 150 };
		setSize(envelopeWidget_w, envelopeWidget_h);
	}
	~EnvelopeWidget() {}

	void resized() override
	{
		envelopeRenderer.setBounds(5, 0, envelopeRenderer.getWidth(), envelopeRenderer.getHeight());

		auto knobs_w{ knob_Attack.getWidth() };
		auto knobs_h{ knob_Attack.getHeight() };
		auto knobGap{ 5 };
		auto knob1_x{ 0 };
		auto knob2_x{ knob1_x + knobs_w + knobGap };
		auto knob3_x{ knob2_x + knobs_w + knobGap };
		auto knob4_x{ knob3_x + knobs_w + knobGap };
		auto knob5_x{ knob4_x + knobs_w + knobGap };
		auto knobs_y{ 93 };
		knob_Delay.setBounds	(knob1_x, knobs_y, knobs_w, knobs_h);
		knob_Attack.setBounds	(knob2_x, knobs_y, knobs_w, knobs_h);
		knob_Decay.setBounds	(knob3_x, knobs_y, knobs_w, knobs_h);
		knob_Sustain.setBounds	(knob4_x, knobs_y, knobs_w, knobs_h);
		knob_Release.setBounds	(knob5_x, knobs_y, knobs_w, knobs_h);
	}

private:
	EnvelopeRenderer envelopeRenderer;

	KnobWidget_EnvDelay    knob_Delay;
	KnobWidget_EnvAttack   knob_Attack;
	KnobWidget_EnvDecay    knob_Decay;
	KnobWidget_EnvSustain  knob_Sustain;
	KnobWidget_EnvRelease  knob_Release;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeWidget)
};