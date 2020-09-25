#pragma once

#include <JuceHeader.h>



enum class SysExMessageType {
    patchData = 1,
    splitData = 2,
    masterData = 3,
    dataDumpRequest = 4,
    quickEditSelect = 5,
    paramChange = 6
};



enum class DataDumpType {
    all = 0,
    patch,
    split,
    master
};



struct SysExID {
    enum class TargetDevice {
        Manufacturer = (char)16,    // Oberheim
        Device = (char)6            // Matrix-6
    };

    static bool matchesHardwareSynthID(const MidiMessage& midiMessage);
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes();
};

