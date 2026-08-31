#include "D_X_G_Editor_P.h"

#include "C_ID_A.h"
#include "C_GET_P.h"

using namespace ID;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub },
    //layer_envelopes{ hub },
    ctrls_mmod{ hub }
{
    //addAndMakeVisible(layer_envelopes);
    addAndMakeVisible(ctrls_mmod);
    resized();
}

void Editor::resized() {
    scale_factor = (float)getWidth() / GET::init_w_for(gui_editor);
    auto bounds = getLocalBounds();
    ctrls_exp.setBounds(bounds);
    //layer_envelopes.setBounds(getLocalBounds());
    ctrls_mmod.setBounds(bounds);
    //app_options.set_scale_percentage_excluding(roundToInt(scale_factor * 100), this);
}

Editor::~Editor() {
}
