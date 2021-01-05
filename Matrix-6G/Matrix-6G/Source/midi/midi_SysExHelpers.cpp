#include "midi_SysExHelpers.h"

#include "midi_Constants.h"

using namespace constants;



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
        vectorSize = MIDI::sizeOfPatchDataVector;
        break;
    case SysExMessageType::splitData:
        vectorSize = MIDI::sizeOfSplitDataVector;
        break;
    case SysExMessageType::masterData:
        vectorSize = MIDI::sizeOfMasterDataVector;
        break;
    case SysExMessageType::dataDumpRequest:
        vectorSize = MIDI::sizeOfDataDumpRequestVector;
        break;
    case SysExMessageType::quickEditSelect:
        vectorSize = MIDI::sizeOfQuickEditSelectVector;
        break;
    case SysExMessageType::paramChange:
        vectorSize = MIDI::sizeOfParamChangeVector;
        break;
    default:
        vectorSize = 0;
        break;
    }
    if (vectorSize != 0) {
        std::vector<uint8> rawDataVector(vectorSize);
        rawDataVector[0] = (uint8)SysExID::TargetDevice::Manufacturer;
        rawDataVector[1] = (uint8)SysExID::TargetDevice::Device;
        return rawDataVector;
    }
    else
        return {};
}
