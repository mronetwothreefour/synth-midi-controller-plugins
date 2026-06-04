#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Editor_P.h"

Editor_P::Editor_P(Audio_Processor_P& processor, Data_Hub_P* hub) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    Data_User_P{ hub }
{
    setWantsKeyboardFocus(true);
    setResizable(true, true);
    setSize(XYWH::gui_init_w, XYWH::gui_init_h);
    getConstrainer()->setFixedAspectRatio(XYWH::gui_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor_P::paint(Graphics& g) {
    g.addTransform(AffineTransform::scale(scale_factor));
    Draw_Paths_Editor_P::background(g);
}

void Editor_P::resized() {
    scale_factor = (float)getWidth() / XYWH::gui_init_w;
}

void Editor_P::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor_P::~Editor_P() {
}
