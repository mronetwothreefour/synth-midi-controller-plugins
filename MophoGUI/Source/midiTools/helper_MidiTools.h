#pragma once

#include <JuceHeader.h>

#include "midi_SysExHelpers.h"
#include "../helpers/helper_Identifiers.h"
#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "../banksWindow/banks_RawProgramData.h"
#include "../midiTools/midi_InternalMidiBuffers_Singleton.h"
#include "../midiTools/midi_NRPNbufferWithLeadingMSBs.h"
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
    public MultiTimer
{
    AudioProcessorValueTreeState* exposedParams;
    int nameCharCounter;
    int track1StepCounter;
    int track2StepCounter;
    int track3StepCounter;
    int track4StepCounter;
    const int millisecondsBtwnParamChanges;
    String programName;

    enum timerID { 
        pgmName, 
        clearSeqTrack1, 
        clearSeqTrack2, 
        clearSeqTrack3, 
        clearSeqTrack4 
    };

    void timerCallback(int timerID) override;
    void clearSequencerStepOnTrack(int stepNum, int trackNum);

public:
    OutgoingMidiGenerator() = delete;
    OutgoingMidiGenerator(AudioProcessorValueTreeState* exposedParams);
    ~OutgoingMidiGenerator();

    void updateProgramNameOnHardware(String newName);
    void clearSequencerTrack(int trackNum);
    void saveProgramToStorageBankSlot(uint8 bank, uint8 slot);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiGenerator)
};



