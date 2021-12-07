#include "core_MainComponent.h"

#include "gui/gui_Constants.h"
//#include "gui/gui_Layer_Buttons.h"
//#include "gui/gui_Layer_EnvelopeRenderers.h"
//#include "gui/gui_Layer_ExposedParamControls.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"
//#include "params/params_UnexposedParameters_Facade.h"

using namespace constants;



MainComponent::MainComponent() {
    setSize (GUI::editor_w, GUI::editor_h);
    setOpaque(true);
    addToDesktop(0);

    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && !RuntimePermissions::isGranted (RuntimePermissions::recordAudio)) {
        RuntimePermissions::request (RuntimePermissions::recordAudio, [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else {
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent() {
    shutdownAudio();
}

void MainComponent::prepareToPlay (int /*samplesPerBlockExpected*/, double /*sampleRate*/) {
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources() {
}

void MainComponent::handleIncomingMidiMessage(MidiInput* /*source*/, const MidiMessage& /*message*/) {
}

void MainComponent::paint (Graphics& g) {
    MemoryInputStream memInputStream{ BinaryData::MophoGUIMainWindowBackground_png, BinaryData::MophoGUIMainWindowBackground_pngSize, false };
    PNGImageFormat imageFormat;
    auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
    g.drawImageAt(backgroundImage, 0, 0);
}

void MainComponent::resized() {
}
