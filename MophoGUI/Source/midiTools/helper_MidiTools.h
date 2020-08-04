#pragma once

#include <JuceHeader.h>

#include "midi_SysExHelpers.h"
#include "../helpers/helper_Identifiers.h"
#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "../banksWindow/banks_ProgramNameStrings_Singleton.h"
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
    const int millisecondsBtwnParamChanges;
    String programName;

    enum timerID { 
        pgmName
    };

    void timerCallback(int timerID) override;

public:
    OutgoingMidiGenerator() = delete;
    OutgoingMidiGenerator(AudioProcessorValueTreeState* exposedParams);
    ~OutgoingMidiGenerator();

    void updateProgramNameOnHardware(String newName);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OutgoingMidiGenerator)
};



