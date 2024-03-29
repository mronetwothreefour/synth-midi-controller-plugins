#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class ExposedParameters;

class EnvelopePainter :
	public Component
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
	const float envStart_x{ 5.0f };
	const float envEnd_x{ 205.0f };
	const float envMax_y{ 15.0f };
	const float envMin_y{ 75.0f };
	const float env_h{ envMin_y - envMax_y };
	const float envSegmentMax_w{ 43.0f };
	const float sustainSegment_w{ 28.0f };
	const int envelopePainters_w{ 210 };
	const int envelopePainters_h{ 90 };

public:
	EnvelopePainter() = delete;

	EnvelopePainter(const EnvelopeType envType, ExposedParameters* exposedParams);

private:
	void setEnvelopeCoordinates();
	void paint(Graphics& g) override;

public:
	void deleteAttachmentsBeforeKnobsToPreventMemLeaks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopePainter)
};