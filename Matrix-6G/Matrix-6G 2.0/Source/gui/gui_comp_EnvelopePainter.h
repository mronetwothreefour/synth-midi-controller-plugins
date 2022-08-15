#pragma once

#include <JuceHeader.h>

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class ExposedParameters;

class EnvelopePainter :
	public Component,
	public Slider::Listener
	// Note: listening to a slider with an exposed parameter attachment is
	// much, much faster than listening directly to an exposed parameter
{
	Slider delay;
	Slider attack;
	Slider decay;
	Slider sustain;
	Slider release;
	std::unique_ptr<SliderAttachment> delayAttachment;
	std::unique_ptr<SliderAttachment> attackAttachment;
	std::unique_ptr<SliderAttachment> decayAttachment;
	std::unique_ptr<SliderAttachment> sustainAttachment;
	std::unique_ptr<SliderAttachment> releaseAttachment;
	float attackStart_x;
	float decayStart_x;
	float sustainStart_x;
	float sustain_y;
	float releaseStart_x;
	float releaseEnd_x;
	const float envStart_x{ 11.0f };
	const float envEnd_x{ 217.0f };
	const float envMax_y{ 10.0f };
	const float envMin_y{ 98.0f };
	const float env_h{ envMin_y - envMax_y };
	const float envSegmentMax_w{ 43.0f };
	const float sustainSegment_w{ 34.0f };
	const int envelopePainters_w{ 228 };
	const int envelopePainters_h{ 108 };

public:
	EnvelopePainter() = delete;

	EnvelopePainter(const int envNum, ExposedParameters* exposedParams);
	void sliderValueChanged(Slider* slider) override;

private:
	void setEnvelopeCoordinates();
	void paint(Graphics& g) override;

public:
	void deleteAttachmentsBeforeSlidersToPreventMemLeaks();
	~EnvelopePainter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopePainter)
};