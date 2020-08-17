#pragma once

#include <JuceHeader.h>



enum class SysExMessageType {
    programDump = 2,
    programEditBufferDump = 3,
    programDumpRequest = 5,
    programEditBufferDumpRequest = 6,
    globalParametersDumpRequest = 14,
    globalParametersDump = 15
};



struct SysExID {
    enum class TargetDevice {
        Manufacturer = (char)1,   // Dave Smith Instruments
        Device = (char)37         // Mopho
    };

    static bool matchesHardwareSynthID(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes();
};

