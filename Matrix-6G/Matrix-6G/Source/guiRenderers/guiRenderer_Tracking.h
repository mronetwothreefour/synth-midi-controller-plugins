#pragma once

#include <JuceHeader.h>

using Attachment = AudioProcessorValueTreeState::SliderAttachment;



class RendererForTrackingGenerator :
	public Component,
	public Slider::Listener
{
	Slider point1;
	Slider point2;
	Slider point3;
	Slider point4;
	Slider point5;
	Attachment point1_Attachment;
	Attachment point2_Attachment;
	Attachment point3_Attachment;
	Attachment point4_Attachment;
	Attachment point5_Attachment;
	float point1_y;
	float point2_y;
	float point3_y;
	float point4_y;
	float point5_y;

public:
	RendererForTrackingGenerator() = delete;

	RendererForTrackingGenerator(AudioProcessorValueTreeState* exposedParams);
	void sliderValueChanged(Slider* slider) override;

private:
	void set_point1_y();
	void set_point2_y();
	void set_point3_y();
	void set_point4_y();
	void set_point5_y();
	void paint(Graphics& g) override;

public:
	~RendererForTrackingGenerator();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RendererForTrackingGenerator)
};