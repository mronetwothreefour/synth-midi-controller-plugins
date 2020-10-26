#pragma once

#include <JuceHeader.h>

using Attachment = AudioProcessorValueTreeState::SliderAttachment;



class RendererForEnvelopes :
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
	const float maxSegment_w{ 43.0f };
	const float sustainSegment_w{ 28.0f };
	const float envelopeStart_x{ 5.0f };
	const float envelopeEnd_x{ 205.0f };
	const float minimum_y{ 75.0f };
	const float maximum_y{ 15.0f };
	float attackStart_x;
	float decayStart_x;
	float sustainStart_x;
	float releaseStart_x;
	float releaseEnd_x;
	float sustain_y;

public:
	RendererForEnvelopes() = delete;

	// For the envelopeID String, use "lpf", "vca", or "env3"
	RendererForEnvelopes(String envelopeID, AudioProcessorValueTreeState* exposedParams);
	void sliderValueChanged(Slider* slider) override;

private:
	void set_attackStart_x();
	void set_decayStart_x();
	void set_sustainStart_x();
	void set_releaseStart_x();
	void set_releaseEnd_x();
	void set_sustain_y();
	void paint(Graphics& g) override;

public:
	~RendererForEnvelopes();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RendererForEnvelopes)
};