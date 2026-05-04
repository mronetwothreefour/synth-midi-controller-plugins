#include "G _0_Editor.h"

#include "C_XYWH.h"
#include "G_Paint_Paths.h"

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
    auto scale_factor{ (float)getWidth() / XYWH::gui_init_w };
    g.addTransform(AffineTransform::scale(scale_factor));
    Paint_Paths::editor_background(g);
}

void Editor::resized() {
}

void Editor::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor::~Editor() {
}
