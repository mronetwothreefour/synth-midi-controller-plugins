#include "D_X_G_Editor_P.h"

//#include "C_XYWH_P.h"

//using namespace XYWH;

Editor::Editor(Audio_Processor& processor/*, Data_Hub_P* hub*/) :
    Editor_A{ processor, /*hub*/ }/*,*/
    //layer_envelopes{ hub }
{
    //addAndMakeVisible(layer_envelopes);
    resized();
}

void Editor::resized() {
    //scale_factor = (float)getWidth() / editor_init_w;
    //layer_exp_ctrls.setBounds(getLocalBounds());
    //layer_envelopes.setBounds(getLocalBounds());
    //app_options.set_scale_percentage_excluding(roundToInt(scale_factor * 100), this);
}

Editor::~Editor() {
}
