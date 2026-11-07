#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Main_P.h"

using namespace DRAW;
using namespace XYWH;

Editor::Editor(Audio_Processor& processor, Data_Hub* hub) :
    Editor_A{ processor, hub },
    pgm_num{ hub }
{
    addAndMakeVisible(pgm_num);
    resized();
}

void Editor::resized() {
    scale_f = (float)getWidth() / editor_init_w;
    auto bounds = getLocalBounds();
    ctrls_exp.setBounds(bounds);
    pgm_num.setBounds(bounds);
    app_p.set_scale_i_excluding(roundToInt(scale_f * 100), this);
}

void Editor::paint(Graphics& g) {
    g.addTransform(AffineTransform::scale(scale_f));
    g.drawImageAt(texture, 0, 0);
    DRAW::Paths_Main::backdrop(g);
}
