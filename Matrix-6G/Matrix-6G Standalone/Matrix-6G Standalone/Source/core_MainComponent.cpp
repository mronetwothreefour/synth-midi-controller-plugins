#include "core_MainComponent.h"

#include "gui/gui_Constants.h"
//#include "gui/gui_Layer_Buttons.h"
//#include "gui/gui_Layer_EnvelopeRenderers.h"
//#include "gui/gui_Layer_ExposedParamsControls.h"
//#include "gui/gui_Layer_MatrixMod.h"
//#include "gui/gui_Layer_PatchNumberAndName.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"
#include "params/params_ParametersFacade.h"

using namespace constants;



MainComponent::MainComponent() :
    parameters{ new ParametersFacade },
    lookAndFeel{ new GUILookAndFeel() }
{
    setAudioChannels(0, 0);

    LookAndFeel::setDefaultLookAndFeel(lookAndFeel.get());

    setSize(GUI::editor_w, GUI::editor_h);
    setOpaque(true);
    addToDesktop(0);
}

void MainComponent::prepareToPlay(int /*samplesPerBlockExpected*/, double /*sampleRate*/) {
}

void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) {
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources() {
}

void MainComponent::handleIncomingMidiMessage(MidiInput* /*source*/, const MidiMessage& /*message*/) {
}

void MainComponent::paint(Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::Matrix6GMainWindowBackground_png, BinaryData::Matrix6GMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void MainComponent::resized() {
}

MainComponent::~MainComponent() {
    shutdownAudio();
    parameters->undoManager_get()->clearUndoHistory();
    parameters = nullptr;
}
