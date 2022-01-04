#include "midi_RawDataTools.h"

#include "midi_Constants.h"
#include "../pgmData/pgmData_Constants.h"

using namespace constants;



std::vector<uint8> RawSysExDataVector::createPgmDataRequestMessage(uint8 slot)
{
    jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
    auto rawDataVector{ createRawDataVectorWithManufacturerIDheaderByte(MIDI::sizeOfPgmDataDumpRequestVector) };
    rawDataVector[1] = MIDI::opcode_RequestPgmDataDump;
    rawDataVector[2] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createRawDataVectorWithManufacturerIDheaderByte(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = MIDI::manufacturerID;
    return rawDataVector;
}
