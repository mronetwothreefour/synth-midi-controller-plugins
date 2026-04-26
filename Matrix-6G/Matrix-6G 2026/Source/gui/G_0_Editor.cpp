#include "G_0_Editor.h"

#include "H_Paint_Path.h"

Editor::Editor(Processor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    setResizable(true, true);
    setSize(XYWH::gui_init_w, XYWH::gui_init_h);
    getConstrainer()->setFixedAspectRatio(XYWH::gui_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor::paint(Graphics& g) {
    g.fillAll(COLOR::background);
    auto scale_factor{ (float)getWidth() / XYWH::gui_init_w };
    Paint_Path::editor_black(g, scale_factor);
    Paint_Path::editor_blue(g, scale_factor);
}

void Editor::resized() {
}

Editor::~Editor() {
}
