#include "midi_PatchDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



std::vector<uint8> PatchDataMessage::createSysExMessageFromCurrentPatchSettings(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
	auto dataVector{ SysExID::createRawDataVectorWithSysExIDheaderBytes(SysExMessageType::patchData) };
    uint8 patchDataOpcode{ 1 };
    dataVector[2] = patchDataOpcode;
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchNumber{ currentPatchOptions->currentPatchNumber() };
    dataVector[3] = currentPatchNumber;
	addCurrentSettingsDataToVector(exposedParams, unexposedParams, dataVector);
    return dataVector;
}

void PatchDataMessage::addCurrentSettingsDataToVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector) {
    uint8 checkSum{ 0 };
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchName{ currentPatchOptions->currentPatchName() };
    for (auto i = 0; i != 16; i += 2) {
        auto asciiValue{ (uint8)currentPatchName[i] };
        auto truncatedValue{ truncateASCIIvalueToLowest6bits(asciiValue) };
        auto numberOfHeaderBytes{ 4 };
        auto lsbByteLocation{ i + numberOfHeaderBytes };
        addValueToDataVectorAtLSBbyteLocation(truncatedValue, &dataVector[lsbByteLocation]);
        checkSum += truncatedValue;
    }
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
        auto lsbByteLocation{ info.lsbByteLocationFor(paramIndex) };
        if (paramValue < 0)
            paramValue += (uint8)256;
        addValueToDataVectorAtLSBbyteLocation(paramValue, &dataVector[lsbByteLocation]);
        checkSum += paramValue;
    }
    dataVector[273] = checkSum % 128;
}

uint8 PatchDataMessage::truncateASCIIvalueToLowest6bits(uint8 value) {
	auto truncatedValue{ uint8(value % 64) };
	return truncatedValue;
}

void PatchDataMessage::addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation) {
	auto leastSignificantByte{ uint8(value % 16) };
	auto mostSignificantByte{ uint8(value / 16) };
	*lsbByteLocation = leastSignificantByte;
	*(lsbByteLocation + 1) = mostSignificantByte;
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 bank, uint8 slot) {
}
