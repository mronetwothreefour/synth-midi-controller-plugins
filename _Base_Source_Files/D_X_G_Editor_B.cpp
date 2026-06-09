#include "D_X_G_Editor_B.h"

#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Editor_P.h"

Editor_B::Editor_B(Audio_Processor_P& processor, Data_Hub_P* hub) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    Data_User_P{ hub },
    l_a_f{ scale_factor }
{
    LookAndFeel::setDefaultLookAndFeel(&l_a_f);
    setWantsKeyboardFocus(true);
    setResizable(true, true);
    setSize(roundToInt(XYWH::gui_init_w * scale_factor), roundToInt(XYWH::gui_init_h * scale_factor));
    getConstrainer()->setFixedAspectRatio(XYWH::gui_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor_B::paint(Graphics& g) {
    g.addTransform(AffineTransform::scale(scale_factor));
    Draw_Paths_Editor_P::background(g);
}

void Editor_B::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor_B::~Editor_B() {
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}
