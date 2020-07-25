#pragma once

#include <JuceHeader.h>

#include "helper_Identifiers.h"
#include "helper_NRPNgenerator.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"



class MidiHandler  :
    private AudioProcessorValueTreeState::Listener,
    public MultiTimer
{
    AudioProcessorValueTreeState* exposedParams;
    Array<MidiBuffer>* internalMidiBuffers;
    bool paramChangeEchoIsBlocked;
    MidiBuffer internalMidiBuffer;
    int nameCharCounter;
    int track1StepCounter;
    int track2StepCounter;
    int track3StepCounter;
    int track4StepCounter;
    const int millisecondsBtwnParamChanges;
    String programName;
    const char sysExManufacturerID;
    const char sysExDeviceID;

    enum timerType { 
        midiBufferTimer, 
        pgmNameTimer, 
        clearSeqTrack1Timer, 
        clearSeqTrack2Timer, 
        clearSeqTrack3Timer, 
        clearSeqTrack4Timer 
    };

    enum sysExMessageType {
        programDump = 2,
        programEditBufferDump = 3,
        programDumpRequest = 5,
        programEditBufferDumpRequest = 6
    };

    void parameterChanged(const String& parameterID, float newValue) override;
    uint8 addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue);
    void addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue);
    void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);
    MidiBuffer createPgmEditBufferDump();
    void addParamValueBytesToBufferStartingAtOffset(uint8* buffer, int offset);
    bool isKnobAssignParameter(uint8 paramIndex);
    uint8 subtractUnusedParamsOffsetFromKnobAssignValue(uint8 paramValue);
    // Combines all MidiBuffers that get created within a
    // 10 ms slice of time into a single MidiBuffer
    void combineMidiBuffers(MidiBuffer& midiBuffer);
    void timerCallback(int timerID) override;
    void clearSequencerStepOnTrack(int stepNum, int trackNum);
    bool isSysExFromDSIMopho(const MidiMessage & midiMessage);
    void handleIncomingSysEx(const uint8* sysExData);
    void applyProgramDumpToPlugin(const uint8* dumpData);
    uint8 addUnusedParamsOffsetToKnobAssignValue(uint8 paramValue);

public:
    MidiHandler() = delete;
    MidiHandler(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers);
    ~MidiHandler();

    void updateProgramNameOnHardware(String newName);
    void clearSequencerTrack(int trackNum);
    void sendProgramEditBufferDumpRequest();
    void sendProgramEditBufferDump();
    MidiBuffer handleIncomingMidiMessages(const MidiBuffer& midiMessages);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiHandler)
};