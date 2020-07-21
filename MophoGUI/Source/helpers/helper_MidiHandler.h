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
    bool nrpnOutputIsAllowed;
    MidiBuffer internalMidiBuffer;
    int nameCharCounter;
    const int millisecondsBtwnParamChanges;
    String programName;

    enum timerType { 
        midiBufferTimer, 
        pgmNameTimer, 
        clearSeqTrack1Timer, 
        clearSeqTrack2Timer, 
        clearSeqTrack3Timer, 
        clearSeqTrack4Timer 
    };

    void parameterChanged(const String& parameterID, float newValue) override;
    uint8 addAnyParamSpecificOffsetsToOutputValue(uint8 param, uint8 outputValue);
    void addParamChangedMessageToMidiBuffer(uint16 paramNRPN, uint8 newValue);
    void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);
    // Combines all MidiBuffers that get created within a
    // 10 ms slice of time into a single MidiBuffer
    void combineMidiBuffers(MidiBuffer& midiBuffer);
    void timerCallback(int timerID) override;

public:
    MidiHandler() = delete;

    MidiHandler(AudioProcessorValueTreeState* exposedParams, Array<MidiBuffer>* internalMidiBuffers);

    ~MidiHandler();

    void updateProgramNameOnHardware(String newName);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiHandler)
};