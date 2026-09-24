#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"

using namespace XYWH;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub }
{
    resized();
}

void Editor::resized() {
    scale_f = (float)getWidth() / editor_init_w;
    auto bounds = getLocalBounds();
    ctrls_exp.setBounds(bounds);
}
