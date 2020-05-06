#pragma once

#include <JuceHeader.h>

#include "helpers/Identifiers.h"
#include "parameters/PublicParameters.h"
#include "parameters/PrivateParameters.h"
#include "helpers/ValueConverters.h"

class PluginProcessor : 
    public AudioProcessor,
    public AudioProcessorParameter::Listener,
    public Timer,
    public MultiTimer
{
public:
    PluginProcessor();
    ~PluginProcessor();

    //==============================================================================
    const String getName() const override { return JucePlugin_Name; }

    //==============================================================================
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return true; }
    bool isMidiEffect() const override { return true; }
    
    //==============================================================================
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int /*index*/) override {}
    const String getProgramName(int /*index*/) override { return {}; }
    void changeProgramName(int /*index*/, const String& /*newName*/) override {}

    //==============================================================================
    bool isBusesLayoutSupported(const BusesLayout& /*layouts*/) const override { return true; }
    void prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/) override {}
    void releaseResources() override {}
    double getTailLengthSeconds() const override { return 0.0; }
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages) override;

    //==============================================================================
    bool hasEditor() const override { return true; }
    AudioProcessorEditor* createEditor() override;

    //==============================================================================
    void getStateInformation(MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    //==============================================================================
    void parameterValueChanged(int parameterIndex, float newValue) override;
    void parameterGestureChanged(int /*parameterIndex*/, bool /*gestureIsStarting*/) override {}

    //==============================================================================
    // Sends a SysEx message to the hardware requesting a dump of the
    // parameter data currently in the Mopho's program edit buffer
    void sendPgmEditBufferDumpRequest();

    // Creates a SysEx message which tells the Mopho hardware to load
    // the enclosed parameter data into its program edit buffer
    void sendPgmEditBufferDump();

    // The program data in the specified slot in the plugin's storage banks is applied to
    // the plugin's public parameters and also sent to the Mopho's program edit buffer
    void loadProgramFromStorage(int bank, int pgmSlot);

    // Saves the current settings for the plugin's public parameters 
    // in the specified slot in the plugin's storage banks.
    void saveProgramToStorage(int bank, int pgmSlot);

    // Creates a SysEx message from the program settings stored in the
    // specified slot in the plugin's storage banks. This is sent to the Mopho,
    // and the program is stored in the corresponding hardware storage slot.
    void pushpProgramToHardwareStorage(int bank, int pgmSlot);

    // A request is sent to the Mopho for a dump of the program data stored in the
    // specified hardware storage slot. The program data is extracted from the dump
    // and saved in the corresponding slot in the plugin's storage banks.
    void pullProgramFromHardwareStorage(int bank, int pgmSlot);

    //==============================================================================
    // This ensures that, when the program name is changed, NRPN update messages
    // are sent to the Mopho for all the characters in the name, including any  
    // characters that were not actually changed.
    void updateProgramName(String newName);

    // This ensures that, when a sequencer track is cleared, NRPN update messages
    // are sent to the Mopho for all the steps in the track, including any  
    // steps that were already set to 0 (or rest for track 1).
    void clearSequencerTrack(int trackNum);

    //==============================================================================
    void timerCallback() override {}
    void timerCallback(int timerID) override;

private:
    std::unique_ptr<AudioProcessorValueTreeState> apvts;

    std::unique_ptr<PublicParameters> publicParams;

    std::unique_ptr<PrivateParameters> privateParams;

    std::unique_ptr<ValueConverters> valueConverters;

    enum timerIDs
    {
        programNameTimer = 0,
        programBankTimer,
        sequencerTrack1StepTimer,
        sequencerTrack2StepTimer,
        sequencerTrack3StepTimer,
        sequencerTrack4StepTimer
    };

    // MIDI messages that are generated by the plugin itself are added
    // to this buffer. If this buffer is not empty, processBlock() will
    // add the messages that are in it to the outgoing MIDI buffer.
    MidiBuffer internalMidiBuf;

    // Used to block parameter change messages from being sent out (e.g. when a
    // program dump from the hardware is being applied to the GUI or when parameter
    // change messages are received from the Mopho's hardware knobs).
    bool nrpnOutputIsAllowed;

    // Used in timerCallback() to space out sending the NRPN messages
    // for updating the individual name characters
    int nameCharCounter{ 0 };
    int track1StepCounter{ 0 };
    int track2StepCounter{ 0 };
    int track3StepCounter{ 0 };
    int track4StepCounter{ 0 };
    int pgmNameTimerInterval{ 80 };
    int sequencerStepTimerInterval{ 80 };
    String programName{ "Mopho Gooey!!!!!" };

    //==============================================================================
    // Extracts the parameter values from a program data dump received
    // from the Mopho and applies them to the plugin's parameter settings
    // (without sending parameter change messages back to the Mopho)
    void applyPgmDumpDataToPlugin(const uint8* dumpData);

    // Calculates LSB and MS bit values for each parameter and adds them to the
    // appropriate bytes in the buffer, starting from the byte specified by offset
    void addParamDataToDumpBuffer(uint8* buffer, int offset);

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};

