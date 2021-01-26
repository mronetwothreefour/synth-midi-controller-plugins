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




std::vector<uint8> RawDataVector::createParamChangeMessage(uint8 newValue, uint8 param) {
    auto messageVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfParamChangeVector) };
    messageVector[2] = MIDI::opcode_ParameterChange;
    messageVector[3] = param;
    messageVector[4] = newValue;
    return messageVector;
}

std::vector<uint8> RawDataVector::initializePatchDataMessage(uint8 slot) {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfPatchDataVector) };
    rawDataVector[2] = MIDI::opcode_PatchData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawDataVector::createPatchDataMessageHeader(uint8 slot) {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::numberOfHeaderBytesInPatchDataMessage) };
    rawDataVector[2] = MIDI::opcode_PatchData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawDataVector::createPatchDataRequestMessage(uint8 slot) {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfDataDumpRequestVector) };
    rawDataVector[2] = MIDI::opcode_DataRequest;
    rawDataVector[3] = MIDI::transmitCode_Patch;
    rawDataVector[4] = slot;
    return rawDataVector;
}

std::vector<uint8> RawDataVector::createActivateQuickPatchEditingMessage() {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfQuickEditSelectVector) };
    rawDataVector[2] = MIDI::opcode_ActivateQuickEdit;
    return rawDataVector;
}

std::vector<uint8> RawDataVector::createRawDataVectorWithSysExIDheaderBytes(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = (uint8)SysExID::TargetDevice::Manufacturer;
    rawDataVector[1] = (uint8)SysExID::TargetDevice::Device;
    return rawDataVector;
}
