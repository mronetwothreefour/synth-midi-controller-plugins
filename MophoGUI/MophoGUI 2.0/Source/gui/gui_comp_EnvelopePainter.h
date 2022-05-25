#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class EnvelopePainter :
	public Component,
	public AudioProcessorParameter::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	Identifier delayParamID;
	Identifier attackParamID;
	Identifier decayParamID;
	Identifier sustainParamID;
	Identifier releaseParamID;
	int delayParamIndex;
	int attackParamIndex;
	int decayParamIndex;
	int sustainParamIndex;
	int releaseParamIndex;
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

public:
	EnvelopePainter() = delete;

	EnvelopePainter(EnvelopeType envType, AudioProcessorValueTreeState* exposedParams);
	void parameterValueChanged(int changedParamIndex, float newValue);
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting);

private:
	void setEnvelopeCoordinates();
	void paint(Graphics& g) override;

public:
	~EnvelopePainter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvelopePainter)
};