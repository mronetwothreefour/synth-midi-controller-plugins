#include "gui_layer_TrackingGraphPainter.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace Matrix_6G_Constants;

GUI_Layer_TrackingGraphPainter::GUI_Layer_TrackingGraphPainter(ExposedParameters* exposedParams) :
	point_1_y{ 0.0f },
	point_2_y{ 0.0f },
	point_3_y{ 0.0f },
	point_4_y{ 0.0f },
	point_5_y{ 0.0f }
{
	setInterceptsMouseClicks(false, false);

	String point_1_ParamID{ ID::ep_61_TrackPoint_1.toString() };
	String point_2_ParamID{ ID::ep_62_TrackPoint_2.toString() };
	String point_3_ParamID{ ID::ep_63_TrackPoint_3.toString() };
	String point_4_ParamID{ ID::ep_64_TrackPoint_4.toString() };
	String point_5_ParamID{ ID::ep_65_TrackPoint_5.toString() };

	point_1.addListener(this);
	point_2.addListener(this);
	point_3.addListener(this);
	point_4.addListener(this);
	point_5.addListener(this);

	auto state{ exposedParams->state.get() };
	point_1_Attachment.reset(new SliderAttachment{ *state, point_1_ParamID, point_1 });
	point_2_Attachment.reset(new SliderAttachment{ *state, point_2_ParamID, point_2 });
	point_3_Attachment.reset(new SliderAttachment{ *state, point_3_ParamID, point_3 });
	point_4_Attachment.reset(new SliderAttachment{ *state, point_4_ParamID, point_4 });
	point_5_Attachment.reset(new SliderAttachment{ *state, point_5_ParamID, point_5 });

	sliderValueChanged(&point_1);
}

void GUI_Layer_TrackingGraphPainter::sliderValueChanged(Slider* /*slider*/) {
	setPointCoordinates();
	repaint();
}

void GUI_Layer_TrackingGraphPainter::setPointCoordinates() {
	point_1_y = graphMin_y - (((float)point_1.getValue() / 63.0f) * graph_h);
	point_2_y = graphMin_y - (((float)point_2.getValue() / 63.0f) * graph_h);
	point_3_y = graphMin_y - (((float)point_3.getValue() / 63.0f) * graph_h);
	point_4_y = graphMin_y - (((float)point_4.getValue() / 63.0f) * graph_h);
	point_5_y = graphMin_y - (((float)point_5.getValue() / 63.0f) * graph_h);
}

void GUI_Layer_TrackingGraphPainter::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	Path path;
	path.startNewSubPath(point_1_x, point_1_y);
	path.lineTo(point_2_x, point_2_y);
	path.lineTo(point_3_x, point_3_y);
	path.lineTo(point_4_x, point_4_y);
	path.lineTo(point_5_x, point_5_y);
	g.strokePath(path, PathStrokeType{ 2.0f, PathStrokeType::JointStyle::curved, PathStrokeType::EndCapStyle::rounded });
}

void GUI_Layer_TrackingGraphPainter::deleteAttachmentsBeforeSlidersToPreventMemLeaks() {
	point_1_Attachment = nullptr;
	point_2_Attachment = nullptr;
	point_3_Attachment = nullptr;
	point_4_Attachment = nullptr;
	point_5_Attachment = nullptr;
}

GUI_Layer_TrackingGraphPainter::~GUI_Layer_TrackingGraphPainter() {
	point_1.removeListener(this);
	point_2.removeListener(this);
	point_3.removeListener(this);
	point_4.removeListener(this);
	point_5.removeListener(this);
}
