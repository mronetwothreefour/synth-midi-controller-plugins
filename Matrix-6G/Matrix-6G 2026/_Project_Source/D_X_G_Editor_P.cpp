#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub }/*,
    layer_envelopes{ hub }*/,
    ctrls_mmod{ hub }
{
    //addAndMakeVisible(layer_envelopes);
    addAndMakeVisible(ctrls_mmod);
    resized();
}

void Editor::resized() {
    scale_f = (float)getWidth() / editor_init_w;
    auto bounds = getLocalBounds();
    ctrls_exp.setBounds(bounds);
    //layer_envelopes.setBounds(getLocalBounds());
    ctrls_mmod.setBounds(bounds);
    app_p.set_scale_i_excluding(roundToInt(scale_f * 100), this);
}

Editor::~Editor() {
}
