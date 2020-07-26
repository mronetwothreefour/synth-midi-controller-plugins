#pragma once

#include <JuceHeader.h>

#include "helper_Identifiers.h"
#include "helper_NRPNgenerator.h"
#include "../parameters/params_InfoForExposedParameters_Singleton.h"
#include "../parameters/params_UnexposedParameters.h"



enum class SysExID {
    Manufacturer = (char)1,   // Dave Smith Instruments
    Device = (char)37         // Mopho
};



enum class SysExMessageType {
    programDump = 2,
    programEditBufferDump = 3,
    programDumpRequest = 5,
    programEditBufferDumpRequest = 6
};



class IncomingMidiHandler
{
    AudioProcessorValueTreeState* exposedParams;

    void handleIncomingSysEx(const uint8* sysExData);
    bool isKnobAssignParameter(uint8 paramIndex);
    bool isSysExFromDSIMopho(const MidiMessage & midiMessage);
    void applyProgramDumpToPlugin(const uint8* dumpData);
    uint8 subtractUnusedParamsOffsetFromKnobAssignValue(uint8 paramValue);

public:
    IncomingMidiHandler() = delete;
    IncomingMidiHandler(AudioProcessorValueTreeState* exposedParams);
    ~IncomingMidiHandler();

    MidiBuffer handle(const MidiBuffer& midiMessages);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingMidiHandler)
};



class MidiGenerator :
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
    uint8 addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue);
    bool isClockTempoParameter(uint8 paramIndex);
    uint8 addOffsetToClockTempoValue(uint8 paramValue);
    bool isKnobAssignParameter(uint8 paramIndex);
    uint8 addUnusedParamsOffsetToKnobAssignValue(uint8 paramValue);
    void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);
    void addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue);

    // Combines all MidiBuffers that get created within a
    // 10 ms slice of time into a single MidiBuffer
    void combineMidiBuffers(MidiBuffer& midiBuffer);

    void timerCallback(int timerID) override;
    void clearSequencerStepOnTrack(int stepNum, int trackNum);

public:
    MidiGenerator() = delete;
    MidiGenerator(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers);
    ~MidiGenerator();

    void sendProgramEditBufferDumpRequest();
    void sendProgramEditBufferDump();
    void updateProgramNameOnHardware(String newName);
    void clearSequencerTrack(int trackNum);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiGenerator)
};