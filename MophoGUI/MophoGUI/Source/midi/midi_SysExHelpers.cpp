#include "midi_SysExHelpers.h"



bool SysExID::matchesHardwareSynthID(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        return (sysExData[1] == (uint8)TargetDevice::Manufacturer && sysExData[2] == (uint8)TargetDevice::Device);
    }
    else
        return false;
}

std::vector<uint8> SysExID::createRawDataVectorWithSysExIDheaderBytes() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back((uint8)SysExID::TargetDevice::Manufacturer);
    rawDataVector.push_back((uint8)SysExID::TargetDevice::Device);
    return rawDataVector;
}
