#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor_P::Editor_P(Audio_Processor_P& processor/*, Data_Hub_P* hub*/) :
    Editor_G{ processor/*, hub*/ }
{
    resized();
}

void Editor_P::resized() {
    //scale_factor = (float)getWidth() / XYWH::gui_init_w;
    //layer_exp_ctrls.setBounds(getLocalBounds());
}
