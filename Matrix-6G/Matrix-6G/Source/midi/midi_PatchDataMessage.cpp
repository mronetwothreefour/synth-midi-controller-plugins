#include "midi_PatchDataMessage.h"

#include "../midi/midi_OutgoingMidiBuffers.h"
#include "../midi/midi_SysExHelpers.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"



void PatchDataMessage::sendCurrentPatchDataMessageToOutgoingMidiBuffers(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, OutgoingMidiBuffers* outgoingBuffers) {
    auto patchDataMessage{ createSysExMessageFromCurrentPatchSettings(exposedParams, unexposedParams) };
    outgoingBuffers->addDataMessage(patchDataMessage);
}

void PatchDataMessage::sendDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(uint8 /*bank*/, uint8 /*slot*/, OutgoingMidiBuffers* /*outgoingBuffers*/) {
}

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
    uint8 checksum{ 0 };
    auto currentPatchOptions{ unexposedParams->currentPatchOptions_get() };
    auto currentPatchName{ currentPatchOptions->currentPatchName() };
    addPatchNameDataToVector(currentPatchName, dataVector, checksum);
    addExposedParamDataToVector(exposedParams, dataVector, checksum);
    addMatrixModDataToVector(unexposedParams, dataVector, checksum);
    dataVector[272] = checksum % (uint8)128;
}

void PatchDataMessage::addPatchNameDataToVector(String& patchName, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 8; ++i) {
        auto asciiValue{ (uint8)patchName[i] };
        auto truncatedValue{ truncateASCIIvalueToLowest6bits(asciiValue) };
        auto numberOfHeaderBytes{ 4 };
        auto lsbByteLocation{ numberOfHeaderBytes + (2 * i) };
        addValueToDataVectorAtLSBbyteLocation(truncatedValue, &dataVector[lsbByteLocation]);
        checksum += truncatedValue;
    }
}

uint8 PatchDataMessage::truncateASCIIvalueToLowest6bits(uint8 value) {
	auto truncatedValue{ uint8(value % 64) };
	return truncatedValue;
}

void PatchDataMessage::addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
        auto dataByteIndex{ info.dataByteIndexFor(paramIndex) };
        auto lsbByteLocation{ firstExposedParamDataByte + (dataByteIndex * 2) };
        auto rangeType{ info.rangeTypeFor(paramIndex) };
        if (rangeType == RangeType::signed6bitValue || rangeType == RangeType::signed7bitValue)
            paramValue = offsetValueInSignedRange(paramValue, rangeType);
        addValueToDataVectorAtLSBbyteLocation(paramValue, &dataVector[lsbByteLocation]);
        checksum += paramValue;
    }
}

void PatchDataMessage::addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 10; ++i) {
        auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
        auto modSource{ matrixModSettings->sourceSettingForModulation(i) };
        auto modAmount{ matrixModSettings->amountSettingForModulation(i) };
        offsetValueInSignedRange(modAmount, RangeType::signed7bitValue);
        auto modAmountWithOffset{ offsetValueInSignedRange(modAmount, RangeType::signed7bitValue) };
        auto modDestination{ matrixModSettings->destinationSettingForModulation(i) };
        auto lsbByteLocationForSource{ matrixModSettings->lsbByteLocationForModulation0Source + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modSource, &dataVector[lsbByteLocationForSource]);
        checksum += modSource;
        auto lsbByteLocationForAmount{ matrixModSettings->lsbByteLocationForModulation0Amount + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modAmountWithOffset, &dataVector[lsbByteLocationForAmount]);
        checksum += modAmountWithOffset;
        auto lsbByteLocationForDestination{ matrixModSettings->lsbByteLocationForModulation0Destination + (i * 6) };
        addValueToDataVectorAtLSBbyteLocation(modDestination, &dataVector[lsbByteLocationForDestination]);
        checksum += modDestination;
    }
}

uint8 PatchDataMessage::offsetValueInSignedRange(uint8& value, RangeType rangeType) {
    jassert(rangeType == RangeType::signed6bitValue || rangeType == RangeType::signed7bitValue);
    auto& info{ InfoForExposedParameters::get() };
    int8 rangeOffset{ rangeType == RangeType::signed6bitValue ? info.offsetForSigned6bitRange : info.offsetForSigned7bitRange };
    int valueWithOffset{ value - rangeOffset };
    if (valueWithOffset < 0) {
        int negativeValueOffset{ 256 };
        valueWithOffset += negativeValueOffset;
    }
    return (uint8)valueWithOffset;
}

void PatchDataMessage::addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation) {
	auto leastSignificantByte{ uint8(value % 16) };
	auto mostSignificantByte{ uint8(value / 16) };
	*lsbByteLocation = leastSignificantByte;
	*(lsbByteLocation + 1) = mostSignificantByte;
}

std::vector<uint8> PatchDataMessage::createSysExMessageFromPatchDataStoredInBankAndSlot(uint8 /*bank*/, uint8 /*slot*/) {
    return {};
}
