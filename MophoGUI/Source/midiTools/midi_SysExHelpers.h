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

    static bool matchesTargetDevice(const MidiMessage& midiMessage) {
        if (midiMessage.isSysEx()) {
            auto sysExData{ midiMessage.getSysExData() };
            return (sysExData[1] == (uint8)TargetDevice::Manufacturer && sysExData[2] == (uint8)TargetDevice::Device);
        }
        else
            return false;
    }
};
