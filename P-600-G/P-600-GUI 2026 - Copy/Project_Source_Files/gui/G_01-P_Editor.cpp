#include "G_01-P_Editor.h"

#include "A_00-P_Processor.h"
#include "C_11-P_XYWH.h"

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
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.setFont (FontOptions ("Arial", 16.0f, 0));
    g.drawFittedText(String{ u8R"(‘Assign’)" }, getLocalBounds(), juce::Justification::centred, 1);
}

void Editor::resized() {
}

void Editor::modifierKeysChanged(const ModifierKeys& mods) {
}

Editor::~Editor() {
}
