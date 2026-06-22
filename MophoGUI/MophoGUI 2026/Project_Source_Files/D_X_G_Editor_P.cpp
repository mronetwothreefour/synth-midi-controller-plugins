#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor_P::Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub) :
    Editor_B{ processor, hub },
    knob{ new Knob_Exposed_B{ 1, hub } }
{
    knob->attach_to_param();
    knob->set_modifying_pitch(true);
    addAndMakeVisible(knob.get());
    resized();
}

void Editor_P::resized() {
    scale_factor = (float)getWidth() / XYWH::gui_init_w;
    Rectangle<int> knob_bounds{ 0, 0, knob_diameter, knob_diameter };
    knob_bounds.setCentre(exp_info.ctrl_center_for(1));
    knob->setBounds(knob_bounds.transformedBy(AffineTransform::scale(scale_factor)));
}

Editor_P::~Editor_P() {
    knob->remove_attachment();
    knob = nullptr;
}
