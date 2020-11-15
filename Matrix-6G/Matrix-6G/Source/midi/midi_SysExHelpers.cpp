#include "midi_SysExHelpers.h"



bool SysExID::matchesHardwareSynthID(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        return (sysExData[1] == (uint8)TargetDevice::Manufacturer && sysExData[2] == (uint8)TargetDevice::Device);
    }
    else
        return false;
}

std::vector<uint8> SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType messageType) {
    int vectorSize;
    switch (messageType)
    {
    case SysExMessageType::patchData:
        vectorSize = 273;
        break;
    case SysExMessageType::splitData:
        vectorSize = 41;
        break;
    case SysExMessageType::masterData:
        vectorSize = 477;
        break;
    case SysExMessageType::dataDumpRequest:
        vectorSize = 5;
        break;
    case SysExMessageType::quickEditSelect:
        vectorSize = 3;
        break;
    case SysExMessageType::paramChange:
        vectorSize = 5;
        break;
    default:
        vectorSize = 0;
        break;
    }
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = (uint8)SysExID::TargetDevice::Manufacturer;
    rawDataVector[1] = (uint8)SysExID::TargetDevice::Device;
    return rawDataVector;
}
