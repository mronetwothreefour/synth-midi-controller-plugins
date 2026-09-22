#include "D_X_G_Editor_A.h"

#include "C_GET_P.h"
#include "C_ID_A.h"
#include "C_NAME_P.h"
#include "C_MISC_P.h"
#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Main_P.h"

using namespace MISC;
using namespace NAME;
using namespace XYWH;

Editor_A::Editor_A(Audio_Processor& processor, Data_Hub* hub) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    Data_User{ hub },
    ctrls_exp{ hub },
    l_a_f{ scale_f }
{
    LookAndFeel::setDefaultLookAndFeel(&l_a_f);
    addAndMakeVisible(ctrls_exp);
    tip_win.setMillisecondsBeforeTipAppears(50);
    tip_win.setComponentEffect(nullptr);
    setWantsKeyboardFocus(true);
    app_p.add_listener(this);
    setResizable(true, true);
    setSize(roundToInt(editor_init_w * scale_f), roundToInt(editor_init_h * scale_f));
    getConstrainer()->setFixedAspectRatio(editor_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor_A::paint(Graphics& g) {
    g.addTransform(AffineTransform::scale(scale_f));
    DRAW::Paths_Main::backdrop(g);
}

void Editor_A::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

void Editor_A::valueTreePropertyChanged(ValueTree& /*parent_tree*/, const Identifier& id) {
    if (id.toString() == ID::app_scale_i) {
        scale_f = app_p.scale_i() * 0.01f;
        setSize(roundToInt(editor_init_w * scale_f), roundToInt(editor_init_h * scale_f));
    }
}

Editor_A::~Editor_A() {
    app_p.remove_listener(this);
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}
