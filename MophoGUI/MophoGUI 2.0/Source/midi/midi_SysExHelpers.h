#pragma once

#include <JuceHeader.h>



enum class SysExMessageType {
    voiceData = 2,
    editBufferData = 3,
    voiceDataRequest = 5,
    editBufferDataRequest = 6,
    globalParametersDataRequest = 14,
    globalParametersData = 15
};



struct SysExID {
    enum class TargetDevice {
        Manufacturer = (char)1,   // Dave Smith Instruments
        Device = (char)37         // Mopho
    };

    static bool matchesHardwareSynthID(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes();
};

