#include "D_X_G_Editor_P.h"

#include "C_ID_A.h"
#include "C_GET_P.h"

using namespace ID;

Editor::Editor(Audio_Processor& processor, Data_Hub_P* hub) :
    Editor_A{ processor, hub }
{
    resized();
}

void Editor::resized() {
    scale_factor = (float)getWidth() / Get::init_w_for(gui_editor);
    //layer_exp_ctrls.setBounds(getLocalBounds());
    //app_options.set_scale_percentage_excluding(roundToInt(scale_factor * 100), this);
}
