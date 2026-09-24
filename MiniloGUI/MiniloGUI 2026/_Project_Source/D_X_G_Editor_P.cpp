#include "D_X_G_Editor_P.h"

#include "C_ID_A.h"
#include "C_GET_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub },
    ctrls_aux_voice{ hub }/*,*/
    //layer_envelopes{ hub }
{
    //addAndMakeVisible(layer_envelopes);
    //layer_envelopes.toBehind(ctrls_exp);
    addAndMakeVisible(ctrls_aux_voice);
    resized();
}

void Editor::resized() {
    scale_f = (float)getWidth() / editor_init_w;
    auto bounds = getLocalBounds();
    //layer_envelopes.setBounds(bounds);
    ctrls_exp.setBounds(bounds);
    ctrls_aux_voice.setBounds(bounds);
    app_p.set_scale_i_excluding(roundToInt(scale_f * 100), this);
}
