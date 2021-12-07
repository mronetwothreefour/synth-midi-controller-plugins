#include "core_MainComponent.h"

#include "gui/gui_Constants.h"
//#include "gui/gui_Layer_Buttons.h"
//#include "gui/gui_Layer_EnvelopeRenderers.h"
//#include "gui/gui_Layer_ExposedParamControls.h"
#include "gui/gui_LookAndFeel.h"
#include "params/params_Identifiers.h"
//#include "params/params_UnexposedParameters_Facade.h"

using namespace constants;



MainComponent::MainComponent() :
    lastInputIndex{ 0 },
    lastOutputIndex{ 0 }
{
    setAudioChannels(0, 0);
    
    addAndMakeVisible(comboBox_ForMidiIn);
    comboBox_ForMidiIn.setTextWhenNoChoicesAvailable("No MIDI Inputs Enabled");
    auto availableMidiInputs{ MidiInput::getAvailableDevices() };
    StringArray midiInputNames;
    for (auto input : availableMidiInputs) {
        midiInputNames.add(input.name);
    }
    comboBox_ForMidiIn.addItemList(midiInputNames, 1);
    comboBox_ForMidiIn.onChange = [this] { setMidiInput(comboBox_ForMidiIn.getSelectedItemIndex()); };
    for (auto input : availableMidiInputs) {
        if (deviceManager.isMidiInputDeviceEnabled(input.identifier)) {
            setMidiInput(availableMidiInputs.indexOf(input));
            break;
        }
    }
    if (comboBox_ForMidiIn.getSelectedId() == 0) {
        setMidiInput(0);
    }

    addAndMakeVisible(comboBox_ForMidiOut);
    comboBox_ForMidiOut.setTextWhenNoChoicesAvailable("No MIDI Outputs Enabled");
    auto availableMidiOutputs{ MidiOutput::getAvailableDevices() };
    StringArray midiOutputNames;
    for (auto input : availableMidiOutputs) {
        midiOutputNames.add(input.name);
    }
    comboBox_ForMidiOut.addItemList(midiOutputNames, 1);


    setSize (GUI::editor_w, GUI::editor_h);
    setOpaque(true);
    addToDesktop(0);
}

void MainComponent::prepareToPlay (int /*samplesPerBlockExpected*/, double /*sampleRate*/) {
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources() {
}

void MainComponent::setMidiInput(int index) {
    auto availableDevices{ MidiInput::getAvailableDevices() };
    deviceManager.removeMidiInputDeviceCallback(availableDevices[lastInputIndex].identifier, this);
    auto newInput{ availableDevices[index] };
    if (!deviceManager.isMidiInputDeviceEnabled(newInput.identifier))
        deviceManager.setMidiInputDeviceEnabled(newInput.identifier, true);
    deviceManager.addMidiInputDeviceCallback(newInput.identifier, this);
    comboBox_ForMidiIn.setSelectedId(index + 1, juce::dontSendNotification);
    lastInputIndex = index;
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
    comboBox_ForMidiIn.setBounds(GUI::bounds_MidiInComboBox);
    comboBox_ForMidiOut.setBounds(GUI::bounds_MidiOutComboBox);
}

MainComponent::~MainComponent() {
    shutdownAudio();
    deviceManager.removeMidiInputDeviceCallback(MidiInput::getAvailableDevices()[comboBox_ForMidiIn.getSelectedItemIndex()].identifier, this);
}
