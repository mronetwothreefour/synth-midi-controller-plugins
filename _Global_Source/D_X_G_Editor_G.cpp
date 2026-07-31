#include "D_X_G_Editor_G.h"

#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Main_P.h"

Editor_G::Editor_G(Audio_Processor_P& processor, Data_Hub_P* hub) :
    AudioProcessorEditor{ &processor },
    processor{ processor },
    Data_User_P{ hub },
    layer_exp_ctrls{ hub },
    l_a_f{ scale_factor }
{
    LookAndFeel::setDefaultLookAndFeel(&l_a_f);
    addAndMakeVisible(layer_exp_ctrls);
    tip_win.setMillisecondsBeforeTipAppears(50);
    tip_win.setComponentEffect(nullptr);
    setWantsKeyboardFocus(true);
    app_options.add_listener(this);
    setResizable(true, true);
    setSize(roundToInt(XYWH::editor_init_w * scale_factor), roundToInt(XYWH::editor_init_h * scale_factor));
    getConstrainer()->setFixedAspectRatio(XYWH::editor_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor_G::paint(Graphics& g) {
    g.addTransform(AffineTransform::scale(scale_factor));
    Draw_Paths_Main_P::backdrop(g);
}

void Editor_G::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

void Editor_G::valueTreePropertyChanged(ValueTree& /*parent_tree*/, const Identifier& property_id) {
    if (property_id.toString() == String{(int)App_Option::scale_percentage}) {
        scale_factor = app_options.scale_percentage() * 0.01f;
        setSize(roundToInt(XYWH::editor_init_w * scale_factor), roundToInt(XYWH::editor_init_h * scale_factor));
    }
}

Editor_G::~Editor_G() {
    app_options.remove_listener(this);
    LookAndFeel::setDefaultLookAndFeel(nullptr);
}
