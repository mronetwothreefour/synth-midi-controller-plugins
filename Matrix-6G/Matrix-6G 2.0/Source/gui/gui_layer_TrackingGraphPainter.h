#pragma once

#include <JuceHeader.h>

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class ExposedParameters;

class GUI_Layer_TrackingGraphPainter :
	public Component,
	public Slider::Listener
	// Note: listening to a slider with an exposed parameter attachment is
	// much, much faster than listening directly to an exposed parameter
{
	Slider point_1;
	Slider point_2;
	Slider point_3;
	Slider point_4;
	Slider point_5;
	std::unique_ptr<SliderAttachment> point_1_Attachment;
	std::unique_ptr<SliderAttachment> point_2_Attachment;
	std::unique_ptr<SliderAttachment> point_3_Attachment;
	std::unique_ptr<SliderAttachment> point_4_Attachment;
	std::unique_ptr<SliderAttachment> point_5_Attachment;
	float point_1_y;
	float point_2_y;
	float point_3_y;
	float point_4_y;
	float point_5_y;
	const float segment_w{ 33.0f };
	const float point_1_x{ 849.0f };
	const float point_2_x{ point_1_x + segment_w };
	const float point_3_x{ point_2_x + segment_w };
	const float point_4_x{ point_3_x + segment_w };
	const float point_5_x{ point_4_x + segment_w };
	const float graphMax_y{ 193.0f };
	const float graphMin_y{ 253.0f };
	const float graph_h{ graphMin_y - graphMax_y };

public:
	GUI_Layer_TrackingGraphPainter() = delete;

	explicit GUI_Layer_TrackingGraphPainter(ExposedParameters* exposedParams);
	void sliderValueChanged(Slider* slider) override;

private:
	void setPointCoordinates();
	void paint(Graphics& g) override;

public:
	void deleteAttachmentsBeforeSlidersToPreventMemLeaks();
	~GUI_Layer_TrackingGraphPainter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_TrackingGraphPainter)
};