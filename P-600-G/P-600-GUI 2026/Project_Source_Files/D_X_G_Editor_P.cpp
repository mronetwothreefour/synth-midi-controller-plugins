#include "D_X_G_Editor_P.h"

#include "C_XYWH_P.h"
#include "G_DRAW_Paths_Editor_P.h"

using namespace BinaryData;

Editor_P::Editor_P(Audio_Processor_P& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    MemoryInputStream texture_stream{ texture_jpg, texture_jpgSize, false };
    JPEGImageFormat img_format;
    background_texture = img_format.decodeImage(texture_stream);

    setWantsKeyboardFocus(true);
    setResizable(true, true);
    setSize(XYWH::gui_init_w, XYWH::gui_init_h);
    getConstrainer()->setFixedAspectRatio(XYWH::gui_aspect_ratio);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor_P::paint(Graphics& g) {
    auto scale_factor{ (float)getWidth() / XYWH::gui_init_w };
    g.addTransform(AffineTransform::scale(scale_factor));
    g.drawImageAt(background_texture, 0, 0);
    Draw_Paths_Editor_P::background(g);
}

void Editor_P::resized() {
}

void Editor_P::modifierKeysChanged(const ModifierKeys& /*mods*/) {
    repaint();
}

Editor_P::~Editor_P() {
}
