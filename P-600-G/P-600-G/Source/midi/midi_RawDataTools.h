#pragma once

#include <JuceHeader.h>



struct RawSysExDataVector {
    static std::vector<uint8> createPgmDataRequestMessage(uint8 slot);

private:
    static std::vector<uint8> createRawDataVectorWithManufacturerIDheaderByte(int vectorSize);
};