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
	const float sustainSegment_w{ 34.0f };
	const float envelopeStart_x{ 11.0f };
	const float envelopeEnd_x{ 217.0f };
	const float minimum_y{ 98.0f };
	const float maximum_y{ 10.0f };
	const float envelope_h{ minimum_y - maximum_y };
	float attackStart_x;
	float decayStart_x;
	float sustainStart_x;
	float releaseStart_x;
	float releaseEnd_x;
	float sustain_y;

public:
	RendererForEnvelopes() = delete;

	RendererForEnvelopes(int envelopeNumber, AudioProcessorValueTreeState* exposedParams);
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