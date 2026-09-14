#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub }/*,
    layer_envelopes{ hub },
    ctrls_mmod{ hub }*/
{
    //addAndMakeVisible(layer_envelopes);
    //addAndMakeVisible(ctrls_mmod);
    resized();
}

void Editor::resized() {
    auto new_scale_factor = (float)getWidth() / XYWH::editor_init_w;
    auto bounds = getLocalBounds();
    //ctrls_exp.setBounds(bounds);
    //layer_envelopes.setBounds(getLocalBounds());
    //ctrls_mmod.setBounds(bounds);
    app_p.set_scale_factor_excluding(new_scale_factor, this);
}

Editor::~Editor() {
}
