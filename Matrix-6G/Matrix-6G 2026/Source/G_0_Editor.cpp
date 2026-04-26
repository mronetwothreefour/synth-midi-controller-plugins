#include "A_0_Processor.h"

#include "G_0_Editor.h"

Editor::Editor(Processor& processor) :
    AudioProcessorEditor{ &processor },
    processor{ processor }
{
    setSize(400, 300);
    Timer::callAfterDelay(50, [this] { grabKeyboardFocus(); });
}

void Editor::paint(Graphics& g) {
    g.fillAll(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour(Colours::white);
    g.setFont(FontOptions (15.0f));
    g.drawFittedText("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Editor::resized() {
}

Editor::~Editor() {
}
