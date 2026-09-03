#include "D_X_G_Editor_P.h"

#include "C_ID_A.h"
#include "C_GET_P.h"

using namespace ID;

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
    scale_factor = (float)getWidth() / GET::init_w_for(gui_editor);
    auto bounds = getLocalBounds();
    //layer_envelopes.setBounds(bounds);
    ctrls_exp.setBounds(bounds);
    ctrls_aux_voice.setBounds(bounds);
    //app_options.set_scale_percentage_excluding(roundToInt(scale_factor * 100), this);
}
