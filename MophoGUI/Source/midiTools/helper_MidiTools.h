#pragma once

#include <JuceHeader.h>

#include "midi_SysExHelpers.h"
#include "../helpers/helper_Identifiers.h"
#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "../banksWindow/banks_ProgramData.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_SpecialValueOffsets.h"
#include "../parameters/params_UnexposedParameters.h"



class IncomingMidiHandler
{
    AudioProcessorValueTreeState* exposedParams;

    void handleIncomingSysEx(const uint8* sysExData);

public:
    IncomingMidiHandler() = delete;
    IncomingMidiHandler(AudioProcessorValueTreeState* exposedParams);
    ~IncomingMidiHandler();

    MidiBuffer handle(const MidiBuffer& midiMessages);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingMidiHandler)
};



class OutgoingMidiGenerator :
    private AudioProcessorValueTreeState::Listener,
    public MultiTimer
{
    AudioProcessorValueTreeState* exposedParams;
    Array<MidiBuffer>* internalMidiBuffers;
    MidiBuffer internalMidiBuffer;
    int nameCharCounter;
    int track1StepCounter;
    int track2StepCounter;
    int track3StepCounter;
    int track4StepCounter;
    const int millisecondsBtwnParamChanges;
    String programName;

    enum timerID { 
        midiBuffer, 
        pgmName, 
        clearSeqTrack1, 
        clearSeqTrack2, 
        clearSeqTrack3, 
        clearSeqTrack4 
    };

    MidiBuffer createPgmEditBufferDump();
    void addPgmDataToBufferStartingAtByte(uint8* buffer, int startByte);
    void parameterChanged(const String& parameterID, float newValue) override;
    void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);
    void addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue);

    // Combines all MidiBuffers that get created within a
    // 10 ms slice of time into a single MidiBuffer
    void combineMidiBuffers(MidiBuffer& midiBuffer);

    void timerCallback(int timerID) override;
    void clearSequencerStepOnTrack(int stepNum, int trackNum);

public:
    OutgoingMidiGenerator() = delete;
    OutgoingMidiGenerator(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers);
    ~OutgoingMidiGenerator();

    void sendProgramEditBufferDumpRequest();
    void sendProgramEditBufferDump();
    void updateProgramNameOnHardware(String newName);
    void clearSequencerTrack(int trackNum);
    void saveProgramToStorageBankSlot(uint8 bank, uint8 slot);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiGenerator)
};



// In the MidiBuffer created by Juce's MidiRPNGenerator, the LSB
// messages come before the MSB messages. However, the Mopho sends
// out NRPN messages with the MSBs before the LSBs, and I think the
// NRPN messages sent to it should be ordered in the same way.
struct NRPNbufferWithLeadingMSBsGenerator
{
    static MidiBuffer generateFrom_NRPNindex_NewValue_andChannel(uint16 paramNRPN, uint8 newValue, uint8 midiChannel);

private:
    static MidiMessage createNRPNindexMSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel);
    static MidiMessage createNRPNindexLSBmessageForMidiChannel(uint16 paramNRPN, uint8 midiChannel);
    static MidiMessage createNRPNvalueMSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel);
    static MidiMessage createNRPNvalueLSBmessageForMidiChannel(uint8 newValue, uint8 midiChannel);
};
