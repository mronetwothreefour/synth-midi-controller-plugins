#include "core_MainComponent.h"

#include "gui/gui_Constants.h"

using namespace constants;



MainComponent::MainComponent() {
    setSize (GUI::editor_w, GUI::editor_h);

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

void MainComponent::paint (Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
}
