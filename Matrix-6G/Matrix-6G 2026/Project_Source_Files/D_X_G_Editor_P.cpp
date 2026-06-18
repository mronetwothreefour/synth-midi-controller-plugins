#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor_P::Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub) :
    Editor_B{ processor, hub },
    knob{ new Knob_Exposed_B{ 0, hub } }
{
    knob->attach_to_param();
    knob->set_modifying_pitch(true);
    addAndMakeVisible(knob.get());
    resized();
}

void Editor_P::resized() {
    scale_factor = (float)getWidth() / XYWH::gui_init_w;
    Rectangle<int> knob_bounds{ osc_col_1_x, ctrl_row_01_y, osc_ctrl_w, ctrl_h };
    knob->setBounds(knob_bounds.transformedBy(AffineTransform::scale(scale_factor)));
}

Editor_P::~Editor_P() {
    knob->remove_attachment();
    knob = nullptr;
}
