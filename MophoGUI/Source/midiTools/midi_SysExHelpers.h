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

    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes() {
        std::vector<uint8> rawDataVector;
        rawDataVector.push_back((uint8)SysExID::TargetDevice::Manufacturer);
        rawDataVector.push_back((uint8)SysExID::TargetDevice::Device);
        return rawDataVector;
    }
};

