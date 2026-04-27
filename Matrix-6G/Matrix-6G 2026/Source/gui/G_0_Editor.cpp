#include "G_0_Editor.h"

#include "H_Paths_For_Editor.h"

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
    g.fillAll(COLOR::background);
    auto scale_factor{ (float)getWidth() / XYWH::gui_init_w };
    Paths_For_Editor::paint(g, scale_factor);
}

void Editor::resized() {
}

void Editor::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor::~Editor() {
}
