#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/MophoLookAndFeel.h"
#include "../parameters/PrivateParameters.h"
#include "../widgets/KnobWidgets.h"

// Creates a graphical representation of an envelope,
// derived from the current settings for its delay,
// attack, decay, sustain, and release parameters.
// For the envelopeID String, use "lpf", "vca", or "env3"
class EnvelopeRenderer : 
	public Component,
	public AudioProcessorParameter::Listener
{
public:
	EnvelopeRenderer
	(
		AudioProcessorValueTreeState* publicParams,
		String envelopeID
	) :
		delayParam{publicParams->getParameter(envelopeID + "Delay")},
		attackParam {publicParams->getParameter(envelopeID + "Attack")},
		decayParam{ publicParams->getParameter(envelopeID + "Decay") },
		sustainParam{ publicParams->getParameter(envelopeID + "Sustain") },
		releaseParam{ publicParams->getParameter(envelopeID + "Release") }
	{
		if(delayParam != nullptr) delayParam->addListener(this);
		if(attackParam != nullptr) attackParam->addListener(this);
		if(decayParam != nullptr) decayParam->addListener(this);
		if(sustainParam != nullptr) sustainParam->addListener(this);
		if(releaseParam != nullptr) releaseParam->addListener(this);

		auto envelopeRenderer_w{ 210 };
		auto envelopeRenderer_h{ 90 };
		setSize(envelopeRenderer_w, envelopeRenderer_h);
	}

	~EnvelopeRenderer() 
	{
		releaseParam->removeListener(this);
		sustainParam->removeListener(this);
		decayParam->removeListener(this);
		attackParam->removeListener(this);
		delayParam->removeListener(this);
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
		auto attackStart_x{ envelopeStart_x + (delayParam->getValue() * maxSegment_w) };
		auto decayStart_x{ attackStart_x + (attackParam->getValue() * maxSegment_w) };
		auto sustainStart_x{ decayStart_x + (decayParam->getValue() * maxSegment_w) };
		auto releaseStart_x{ sustainStart_x + sustainSegment_w };
		auto releaseEnd_x{ releaseStart_x + (releaseParam->getValue() * maxSegment_w) };
		auto envelopeEnd_x{ 205.0f };
		auto minimum_y{ 75.0f };
		auto maximum_y{ 15.0f };
		auto sustain_y{ minimum_y - (sustainParam->getValue() * 60.0f) };
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

	void parameterValueChanged(int /*parameterIndex*/, float /*newValue*/) override
	{
		repaint();
	}

	void parameterGestureChanged(int /*parameterIndex*/, bool /*gestureIsStarting*/) override {}

private:
	AudioProcessorParameter* delayParam;
	AudioProcessorParameter* attackParam;
	AudioProcessorParameter* decayParam;
	AudioProcessorParameter* sustainParam;
	AudioProcessorParameter* releaseParam;

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
		String envelopeID,
		MophoLookAndFeel* mophoLaF
	) :
		envelopeRenderer{publicParams, envelopeID},
		knob_Delay{ publicParams, privateParameters, envelopeID + "Delay", mophoLaF },
		knob_Attack{ publicParams, privateParameters, envelopeID + "Attack", mophoLaF },
		knob_Decay{ publicParams, privateParameters, envelopeID + "Decay", mophoLaF },
		knob_Sustain{ publicParams, privateParameters, envelopeID + "Sustain", mophoLaF },
		knob_Release{ publicParams, privateParameters, envelopeID + "Release", mophoLaF }
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