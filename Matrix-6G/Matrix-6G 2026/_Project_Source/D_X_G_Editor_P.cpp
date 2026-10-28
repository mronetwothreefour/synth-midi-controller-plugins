#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub },
    envelopes{ hub },
    ctrls_mmod{ hub },
    pgm_num_and_name{ hub },
    buttons{ hub }
{
    addAndMakeVisible(envelopes);
    addAndMakeVisible(ctrls_mmod);
    addAndMakeVisible(pgm_num_and_name);
    addAndMakeVisible(buttons);
    resized();
}

void Editor::resized() {
    scale_f = (float)getWidth() / editor_init_w;
    auto bounds = getLocalBounds();
    ctrls_exp.setBounds(bounds);
    envelopes.setBounds(bounds);
    ctrls_mmod.setBounds(bounds);
    pgm_num_and_name.setBounds(bounds);
    buttons.setBounds(bounds);
    app_p.set_scale_i_excluding(roundToInt(scale_f * 100), this);
}

Editor::~Editor() {
}
