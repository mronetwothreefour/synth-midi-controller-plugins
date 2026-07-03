#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor_P::Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub) :
    Editor_B{ processor, hub },
    switch_slider{ new Slider_Exposed_P{ 18, hub } },
    knob{ new Slider_Exposed_P{ 3, hub } }
{
    switch_slider->attach_to_param();
    addAndMakeVisible(switch_slider.get());
    knob->attach_to_param();
    addAndMakeVisible(knob.get());
    resized();
}

void Editor_P::resized() {
    scale_factor = (float)getWidth() / XYWH::gui_init_w;
    Rectangle<int> switch_bounds{ 0, 0, switch_w, switch_lpf_type_h };
    switch_bounds.setCentre(exp_info.ctrl_center_for(18));
    switch_slider->setBounds(switch_bounds.transformedBy(AffineTransform::scale(scale_factor)));
    Rectangle<int> knob_bounds{ 0, 0, knob_diameter, knob_diameter };
    knob_bounds.setCentre(exp_info.ctrl_center_for(3));
    knob->setBounds(knob_bounds.transformedBy(AffineTransform::scale(scale_factor)));
}
