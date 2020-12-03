#include "guiRenderer_Tracking.h"

#include "../gui/gui_Colors.h"



RendererForTrackingGenerator::RendererForTrackingGenerator(AudioProcessorValueTreeState* exposedParams) :
	point1_Attachment{ *exposedParams, "track_Point1", point1 },
	point2_Attachment{ *exposedParams, "track_Point2", point2 },
	point3_Attachment{ *exposedParams, "track_Point3", point3 },
	point4_Attachment{ *exposedParams, "track_Point4", point4 },
	point5_Attachment{ *exposedParams, "track_Point5", point5 }
{
	point1.addListener(this);
	point2.addListener(this);
	point3.addListener(this);
	point4.addListener(this);
	point5.addListener(this);
	set_point1_y();
	set_point2_y();
	set_point3_y();
	set_point4_y();
	set_point5_y();
	auto trackingGeneratorRenderer_w{ 150 };
	auto trackingGeneratorRenderer_h{ 80 };
	setSize(trackingGeneratorRenderer_w, trackingGeneratorRenderer_h);
}

void RendererForTrackingGenerator::sliderValueChanged(Slider* /*slider*/) {
	set_point1_y();
	set_point2_y();
	set_point3_y();
	set_point4_y();
	set_point5_y();
	repaint();
}

void RendererForTrackingGenerator::set_point1_y() {
	point1_y = minimum_y - (((float)point1.getValue() / 63.0f) * envelope_h);
}

void RendererForTrackingGenerator::set_point2_y() {
	point2_y = minimum_y - (((float)point2.getValue() / 63.0f) * envelope_h);
}

void RendererForTrackingGenerator::set_point3_y() {
	point3_y = minimum_y - (((float)point3.getValue() / 63.0f) * envelope_h);
}

void RendererForTrackingGenerator::set_point4_y() {
	point4_y = minimum_y - (((float)point4.getValue() / 63.0f) * envelope_h);
}

void RendererForTrackingGenerator::set_point5_y() {
	point5_y = minimum_y - (((float)point5.getValue() / 63.0f) * envelope_h);
}

void RendererForTrackingGenerator::paint(Graphics& g) {
	g.setColour(Color::led_blue);
	Path path;
	path.startNewSubPath(point1_x, point1_y);
	path.lineTo(point2_x, point2_y);
	path.lineTo(point3_x, point3_y);
	path.lineTo(point4_x, point4_y);
	path.lineTo(point5_x, point5_y);
	PathStrokeType strokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded };
	g.strokePath(path, strokeType);
}

RendererForTrackingGenerator::~RendererForTrackingGenerator() {
	point5.removeListener(this);
	point4.removeListener(this);
	point3.removeListener(this);
	point2.removeListener(this);
	point1.removeListener(this);
}
