#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor_P::Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub) :
    Editor_B{ processor, hub },
    knob_1{ new Slider_Exposed_P{ 20, hub } },
    knob_2{ new Slider_Exposed_P{ 41, hub } }
{
    knob_1->attach_to_param();
    addAndMakeVisible(knob_1.get());
    knob_2->attach_to_param();
    addAndMakeVisible(knob_2.get());
    resized();
}

void Editor_P::resized() {
    scale_factor = (float)getWidth() / XYWH::gui_init_w;
    Rectangle<int> knob_bounds{ 0, 0, knob_diameter, knob_diameter };
    knob_bounds.setCentre(exp_info.ctrl_center_for(20));
    knob_1->setBounds(knob_bounds.transformedBy(AffineTransform::scale(scale_factor)));
    knob_bounds.setCentre(exp_info.ctrl_center_for(41));
    knob_2->setBounds(knob_bounds.transformedBy(AffineTransform::scale(scale_factor)));
}

Editor_P::~Editor_P() {
    knob_1->remove_attachment();
    knob_1 = nullptr;
    knob_2->remove_attachment();
    knob_2 = nullptr;
}
