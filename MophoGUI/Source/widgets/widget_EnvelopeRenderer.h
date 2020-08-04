#pragma once

#include <JuceHeader.h>

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
	EnvelopeRenderer() = delete;

	EnvelopeRenderer(String envelopeID, AudioProcessorValueTreeState* exposedParams);
	~EnvelopeRenderer();
	void sliderValueChanged(Slider* /*slider*/) override;
	float set_attackStart_x();
	float set_decayStart_x();
	float set_sustainStart_x();
	float set_releaseStart_x();
	float set_releaseEnd_x();
	float set_sustain_y();
	void paint(Graphics& g) override;
	void paintBaseline(Graphics& g);
	void paintEnvelope(Graphics& g);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopeRenderer)
};