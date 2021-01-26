#pragma once

#include <JuceHeader.h>



struct SysExID {
    enum class TargetDevice {
        Manufacturer = (char)16,    // Oberheim
        Device = (char)6            // Matrix-6
    };

    static bool matchesHardwareSynthID(const MidiMessage& midiMessage);
};



struct RawDataVector {
    static std::vector<uint8> createParamChangeMessage(uint8 newValue, uint8 param);
    static std::vector<uint8> initializePatchDataMessage(uint8 slot);
    static std::vector<uint8> createPatchDataMessageHeader(uint8 slot);
    static std::vector<uint8> createPatchDataRequestMessage(uint8 slot);
    static std::vector<uint8> createActivateQuickPatchEditingMessage();

private:
    static std::vector<uint8> createRawDataVectorWithSysExIDheaderBytes(int vectorSize);
};

