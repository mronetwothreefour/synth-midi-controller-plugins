#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"

using Attachment = AudioProcessorValueTreeState::SliderAttachment;



// For the envelopeID String, use "lpf", "vca", or "env3"
class EnvelopeRenderer :
	public Component,
	public Slider::Listener
{
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

public:
	EnvelopeRenderer(String envelopeID, AudioProcessorValueTreeState* exposedParams) :
		delayAttachment{ *exposedParams, envelopeID + "Delay", delay },
		attackAttachment{ *exposedParams, envelopeID + "Attack", attack },
		decayAttachment{ *exposedParams, envelopeID + "Decay", decay },
		sustainAttachment{ *exposedParams, envelopeID + "Sustain", sustain },
		releaseAttachment{ *exposedParams, envelopeID + "Release", release }
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

	~EnvelopeRenderer() {
		release.removeListener(this);
		sustain.removeListener(this);
		decay.removeListener(this);
		attack.removeListener(this);
		delay.removeListener(this);
	}

	void paint(Graphics& g) override {
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

	void sliderValueChanged(Slider* /*sliderThatChanged*/) override {
		repaint();
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderer)
};