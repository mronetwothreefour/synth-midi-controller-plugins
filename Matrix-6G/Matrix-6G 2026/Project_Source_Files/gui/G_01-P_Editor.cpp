#include "G_01-P_Editor.h"

#include "C_11-P_XYWH.h"
#include "G_05-P_Paint_Paths.h"
#include "H_10-P_Describe_Exp_Param.h"

Editor::Editor(Processor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    setWantsKeyboardFocus(true);
    setResizable(true, true);
    setSize(XYWH::gui_init_w, XYWH::gui_init_h);
    getConstrainer()->setFixedAspectRatio(XYWH::gui_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor::paint(Graphics& g) {
    //auto scale_factor{ (float)getWidth() / XYWH::gui_init_w };
    //g.addTransform(AffineTransform::scale(scale_factor));
    //Paint_Paths::editor_background(g);
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.setFont(Font{ "Arial", 16.0f, 0 });
    g.drawMultiLineText(Describe_Exp_Param::porta_velo(), 15, 20, 600, Justification::centred);
}

void Editor::resized() {
}

void Editor::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor::~Editor() {
}
