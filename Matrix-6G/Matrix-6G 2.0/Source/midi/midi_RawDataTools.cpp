#include "midi_RawDataTools.h"

#include "midi_Constants.h"
#include "../master/master_Constants.h"
#include "../voices/voices_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../splits/splits_Constants.h"

using namespace constants;



bool SysExID::matchesHardwareSynthID(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        return (sysExData[1] == (uint8)TargetDevice::Manufacturer && sysExData[2] == (uint8)TargetDevice::Device);
    }
    else
        return false;
}




std::vector<uint8> RawSysExDataVector::createParamChangeMessage(uint8 newValue, uint8 param) {
    auto messageVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfParamChangeVector) };
    messageVector[2] = MIDI::opcode_ParameterChange;
    messageVector[3] = param;
    messageVector[4] = newValue;
    return messageVector;
}

std::vector<uint8> RawSysExDataVector::initializeVoiceDataMessage(uint8 slot) {
    jassert(slot < voices::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfVoiceDataVector) };
    rawDataVector[2] = MIDI::opcode_VoiceData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createVoiceDataMessageHeader(uint8 slot) {
    jassert(slot < voices::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::numberOfHeaderBytesInDataDumpMessages) };
    rawDataVector[2] = MIDI::opcode_VoiceData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createVoiceDataRequestMessage(uint8 slot) {
    jassert(slot < voices::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfDataDumpRequestVector) };
    rawDataVector[2] = MIDI::opcode_DataRequest;
    rawDataVector[3] = MIDI::transmitCode_Voice;
    rawDataVector[4] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createActivateQuickEditMessage() {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfQuickEditSelectVector) };
    rawDataVector[2] = MIDI::opcode_ActivateQuickEdit;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::initializeSplitDataMessage(uint8 slot) {
    jassert(slot < splits::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfSplitDataVector) };
    rawDataVector[2] = MIDI::opcode_SplitData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createSplitDataMessageHeader(uint8 slot) {
    jassert(slot < splits::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::numberOfHeaderBytesInDataDumpMessages) };
    rawDataVector[2] = MIDI::opcode_SplitData;
    rawDataVector[3] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createSplitDataRequestMessage(uint8 slot) {
    jassert(slot < splits::numberOfSlotsInBank);
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfDataDumpRequestVector) };
    rawDataVector[2] = MIDI::opcode_DataRequest;
    rawDataVector[3] = MIDI::transmitCode_Split;
    rawDataVector[4] = slot;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createSwitchToSplitModeMessage() {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfSwitchToSplitModeVector) };
    rawDataVector[1] = MIDI::deviceID_OberheimXpander;
    rawDataVector[2] = MIDI::opcode_SwitchMode;
    rawDataVector[3] = MIDI::transmitCode_Split;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::initializeMasterOptionsDataMessage() {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfMasterDataVector) };
    rawDataVector[2] = MIDI::opcode_MasterData;
    rawDataVector[3] = 2;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createMasterOptionsDataRequestMessage() {
    auto rawDataVector{ createRawDataVectorWithSysExIDheaderBytes(MIDI::sizeOfDataDumpRequestVector) };
    rawDataVector[2] = MIDI::opcode_DataRequest;
    rawDataVector[3] = MIDI::transmitCode_Master;
    rawDataVector[4] = 0;
    return rawDataVector;
}

std::vector<uint8> RawSysExDataVector::createRawDataVectorWithSysExIDheaderBytes(int vectorSize) {
    jassert(vectorSize > 0);
    std::vector<uint8> rawDataVector(vectorSize);
    rawDataVector[0] = (uint8)SysExID::TargetDevice::Manufacturer;
    rawDataVector[1] = (uint8)SysExID::TargetDevice::Device;
    return rawDataVector;
}




const std::vector<uint8> RawDataTools::convertVoiceOrSplitHexStringToDataVector(const String& hexString) {
    std::vector<uint8> dataVector;
    auto indexOfChecksumByte{ hexString.length() - 2 };
    for (auto i = 0; i != indexOfChecksumByte; ++i) {
        auto hexValueString{ hexString.substring(i, i + 1) };
        dataVector.push_back((uint8)hexValueString.getHexValue32());
    }
    auto checksumHexValueString{ hexString.substring(indexOfChecksumByte, hexString.length()) };
    dataVector.push_back((uint8)checksumHexValueString.getHexValue32());
    return dataVector;
}

const String RawDataTools::convertVoiceOrSplitDataVectorToHexString(const std::vector<uint8>& dataVector) {
    String hexString{ "" };
    auto indexOfChecksumByte{ dataVector.size() - 1 };
    for (auto i = 0; i < indexOfChecksumByte; ++i) {
        auto byteString{ String::toHexString(&dataVector[i], 1, 0) };
        auto byteStringStrippedOfLeadingZero{ byteString[1] };
        hexString += byteStringStrippedOfLeadingZero;
    }
    hexString += String::toHexString(&dataVector[indexOfChecksumByte], 1, 0);
    return hexString;
}

void RawDataTools::addCurrentParameterSettingsToDataVector(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector) {
    uint8 checksum{ 0 };
    auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
    auto currentVoiceName{ currentVoiceOptions->currentVoiceName() };
    addVoiceOrSplitNameDataToVector(currentVoiceName, params::maxVoiceNameLength, dataVector, checksum);
    addExposedParamDataToVector(exposedParams, dataVector, checksum);
    addMatrixModDataToVector(unexposedParams, dataVector, checksum);
    dataVector[voices::rawVoiceDataVectorChecksumByteIndex] = checksum % (uint8)128;
}

void RawDataTools::addCurrentSplitSettingsToDataVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector) {
    uint8 checksum{ 0 };
    auto splitOptions{ unexposedParams->splitOptions_get() };
    auto splitName{ splitOptions->splitName() };
    addVoiceOrSplitNameDataToVector(splitName, params::maxSplitNameLength, dataVector, checksum);
    addSplitParamDataToVector(unexposedParams, dataVector, checksum);
    dataVector[splits::rawSplitDataVectorChecksumByteIndex] = checksum % (uint8)128;
}

void RawDataTools::applyVoiceDataVectorToGUI(const uint8 voiceNumber, std::vector<uint8>& voiceDataVector, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) {
    applyVoiceNumberToGUI(voiceNumber, unexposedParams);
    applyNameOfVoiceInRawDataToGUI(voiceDataVector.data(), unexposedParams);

    voiceDataVector.erase(voiceDataVector.begin(), voiceDataVector.begin() + voices::indexOfLastDataByteBeforeExposedParams);
    auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    applyRawVoiceDataToExposedParameters(voiceDataVector.data(), exposedParams);
    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();

    voiceDataVector.erase(voiceDataVector.begin(), voiceDataVector.begin() + voices::indexOfLastDataByteBeforeMatrixModSettings);
    applyRawVoiceDataToMatrixModParameters(voiceDataVector.data(), unexposedParams);
}

void RawDataTools::applySplitDataVectorToGUI(std::vector<uint8>& splitDataVector, UnexposedParameters* unexposedParams) {
    applyNameOfSplitInRawDataToGUI(splitDataVector.data(), unexposedParams);
    splitDataVector.erase(splitDataVector.begin(), splitDataVector.begin() + splits::indexOfLastDataByteBeforeSpltsParams);
    applyRawSplitDataToGUI(splitDataVector.data(), unexposedParams);
}

void RawDataTools::applyMasterOptionsRawDataToGUI(const uint8* masterOptionsData, UnexposedParameters* unexposedParams) {
    auto masterOptions{ unexposedParams->globalOptions_get() };
    masterOptions->setVibratoSpeed(masterOptionsData[master::indexOfVibratoSpeedLSByte] + (masterOptionsData[master::indexOfVibratoSpeedLSByte + 1] * 16));
    masterOptions->setVibratoSpeedModSource(masterOptionsData[master::indexOfVibratoSpeedModSourceLSByte]);
    masterOptions->setVibratoSpeedModAmount(masterOptionsData[master::indexOfVibratoSpeedModAmountLSByte] + (masterOptionsData[master::indexOfVibratoSpeedModAmountLSByte + 1] * 16));
    masterOptions->setVibratoWaveType(masterOptionsData[master::indexOfVibratoWaveTypeLSByte]);
    masterOptions->setVibratoAmplitude(masterOptionsData[master::indexOfVibratoAmplitudeLSByte] + (masterOptionsData[master::indexOfVibratoAmplitudeLSByte + 1] * 16));
    masterOptions->setVibratoAmplitudeModSource(masterOptionsData[master::indexOfVibratoAmplitudeModSourceLSByte]);
    masterOptions->setVibratoAmplitudeModAmount(masterOptionsData[master::indexOfVibratoAmplitudeModAmountLSByte] + (masterOptionsData[master::indexOfVibratoAmplitudeModAmountLSByte + 1] * 16));
    auto masterTune{ masterOptionsData[master::indexOfMasterTuneLSByte] + (masterOptionsData[master::indexOfMasterTuneLSByte + 1] * 16) };
    masterTune = RawDataTools::formatSigned7bitValueForStoringInPlugin(masterTune);
    masterOptions->setGlobalTune((uint8)masterTune);
    masterOptions->setBasicChannel(masterOptionsData[master::indexOfBasicChannelLSByte] + master::basicChannelOffset);
    masterOptions->setOmniModeEnabled(masterOptionsData[master::indexOfOmniModeEnableLSByte]);
    masterOptions->setControllersEnabled(masterOptionsData[master::indexOfControllersEnableLSByte]);
    masterOptions->setVoiceChangesEnabled(masterOptionsData[master::indexOfVoiceChangesEnableLSByte]);
    masterOptions->setSysExEnabled(masterOptionsData[master::indexOfSysExEnableLSByte]);
    masterOptions->setLocalControlEnabled(masterOptionsData[master::indexOfLocalControlEnableLSByte]);
    masterOptions->setPedal1ControllerNumber(masterOptionsData[master::indexOfPedal1ControllerNumber] + (masterOptionsData[master::indexOfPedal1ControllerNumber + 1] * 16));
    masterOptions->setPedal2ControllerNumber(masterOptionsData[master::indexOfPedal2ControllerNumber] + (masterOptionsData[master::indexOfPedal2ControllerNumber + 1] * 16));
    masterOptions->setLever2ControllerNumber(masterOptionsData[master::indexOfLever2ControllerNumber] + (masterOptionsData[master::indexOfLever2ControllerNumber + 1] * 16));
    masterOptions->setLever3ControllerNumber(masterOptionsData[master::indexOfLever3ControllerNumber] + (masterOptionsData[master::indexOfLever3ControllerNumber + 1] * 16));
    masterOptions->setDisplayBrightness(masterOptionsData[master::indexOfDisplayBrightnessLSByte] + (masterOptionsData[master::indexOfDisplayBrightnessLSByte + 1] * 16));
    masterOptions->setSQUICKenabled(masterOptionsData[master::indexOfSQUICKenableLSByte]);
    masterOptions->setVoicesMapEchoEnabled(masterOptionsData[master::indexOfVoicesMapEchoEnableLSByte]);
    masterOptions->setSplitStereoEnabled(masterOptionsData[master::indexOfSplitStereoEnableLSByte]);
    masterOptions->setSpilloverEnabled(masterOptionsData[master::indexOfSpilloverEnableLSByte]);
    masterOptions->setActiveSensingEnabled(masterOptionsData[master::indexOfActiveSenseEnableLSByte]);
    masterOptions->setMIDIechoEnabled(masterOptionsData[master::indexOfMIDIechoEnableLSByte]);
    masterOptions->setVoicesMapEnabled(masterOptionsData[master::indexOfVoicesMapEnableLSByte]);
    masterOptions->setMIDImonoEnabled(masterOptionsData[master::indexOfMIDImonoEnableLSByte]);
    for (uint8 i = 0; i != voices::numberOfSlotsInBank; ++i) {
        auto indexOfInputVoicelsByte{ master::indexOfFirstVoicesMapInputLSByte + (i * 2) };
        masterOptions->setVoicesMapInVoiceForProgramNumber(masterOptionsData[indexOfInputVoicelsByte] + (masterOptionsData[indexOfInputVoicelsByte + 1] * 16), i);
        auto indexOfOutputVoicelsByte{ master::indexOfFirstVoicesMapOutputLSByte + (i * 2) };
        masterOptions->setVoicesMapOutVoiceForProgramNumber(masterOptionsData[indexOfOutputVoicelsByte] + (masterOptionsData[indexOfOutputVoicelsByte + 1] * 16), i);
    }
}

const String RawDataTools::extractVoiceNameFromRawVoiceData(const uint8* voiceData) {
    String voiceName{ "" };
    for (auto byte = 0; byte != (2 * params::maxVoiceNameLength); byte += 2) {
        auto lsbByteValue{ (uint8)voiceData[byte] };
        auto msbByteValue{ (uint8)voiceData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        voiceName += convertStoredASCIIvalueToString(storedASCIIvalue);
    }
    return voiceName;
}

const String RawDataTools::extractSplitNameFromRawSplitData(const uint8* splitData) {
    String splitName{ "" };
    for (auto byte = 0; byte != (2 * params::maxSplitNameLength); byte += 2) {
        auto lsbByteValue{ (uint8)splitData[byte] };
        auto msbByteValue{ (uint8)splitData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        splitName += convertStoredASCIIvalueToString(storedASCIIvalue);
    }
    return splitName;
}

void RawDataTools::addCurrentMasterSettingsToDataVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector) {
    uint8 checksum{ 0 };
    addMasterOptionsDataToVector(unexposedParams, dataVector, checksum);
    dataVector[master::indexOfChecksumByte] = checksum % (uint8)128;
}

void RawDataTools::applyVoiceNumberToGUI(const uint8 voiceNumber, UnexposedParameters* unexposedParams) {
    auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
    currentVoiceOptions->setCurrentVoiceNumber(voiceNumber);
}

void RawDataTools::applyNameOfVoiceInRawDataToGUI(const uint8* voiceData, UnexposedParameters* unexposedParams) {
    auto voiceNameString{ extractVoiceNameFromRawVoiceData(voiceData) };
    auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
    currentVoiceOptions->setCurrentVoiceName(voiceNameString);
}

void RawDataTools::applyNameOfSplitInRawDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams) {
    auto splitNameString{ extractSplitNameFromRawSplitData(splitData) };
    auto splitOptions{ unexposedParams->splitOptions_get() };
    splitOptions->setSplitName(splitNameString);
}

void RawDataTools::applyRawVoiceDataToExposedParameters(const uint8* voiceData, AudioProcessorValueTreeState* exposedParams) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
        auto paramID{ info.IDfor(param) };
        auto lsByteLocation{ info.dataByteIndexFor(param) * 2 };
        auto lsByteValue{ voiceData[lsByteLocation] };
        auto msByteValue{ voiceData[lsByteLocation + 1] * 16 };
        auto newValue{ lsByteValue + msByteValue };
        if (info.rangeTypeFor(param) == RangeType::signed6bitValue)
            newValue = { formatSigned6bitValueForStoringInPlugin(newValue) };
        if (info.rangeTypeFor(param) == RangeType::signed7bitValue)
            newValue = { formatSigned7bitValueForStoringInPlugin(newValue) };
        auto normalizedValue{ (float)newValue / (float)info.maxValueFor(param) };
        exposedParams->getParameter(paramID)->setValueNotifyingHost(normalizedValue);
    }
}

void RawDataTools::applyRawSplitDataToGUI(const uint8* splitData, UnexposedParameters* unexposedParams) {
    auto splitOptions{ unexposedParams->splitOptions_get() };
    splitOptions->setLowerZoneLimit(splitData[splits::indexOfLowerZoneLimitLSByte] + (splitData[splits::indexOfLowerZoneLimitLSByte + 1] * 16));
    auto lowerZoneTranspose{ splitData[splits::indexOfLowerZoneTransposeLSByte] + (splitData[splits::indexOfLowerZoneTransposeLSByte + 1] * 16) };
    lowerZoneTranspose = RawDataTools::formatSignedZoneTransposeValueForStoringInPlugin(lowerZoneTranspose);
    splitOptions->setLowerZoneTranspose((uint8)lowerZoneTranspose);
    splitOptions->setLowerZoneMidiOut(splitData[splits::indexOfLowerZoneMIDIoutLSByte] + (splitData[splits::indexOfLowerZoneMIDIoutLSByte + 1] * 16));
    splitOptions->setUpperZoneLimit(splitData[splits::indexOfUpperZoneLimitLSByte] + (splitData[splits::indexOfUpperZoneLimitLSByte + 1] * 16));
    auto upperZoneTranspose{ splitData[splits::indexOfUpperZoneTransposeLSByte] + (splitData[splits::indexOfUpperZoneTransposeLSByte + 1] * 16) };
    upperZoneTranspose = RawDataTools::formatSignedZoneTransposeValueForStoringInPlugin(upperZoneTranspose);
    splitOptions->setUpperZoneTranspose((uint8)upperZoneTranspose);
    splitOptions->setUpperZoneMidiOut(splitData[splits::indexOfUpperZoneMIDIoutLSByte] + (splitData[splits::indexOfUpperZoneMIDIoutLSByte + 1] * 16));
    auto zoneVolumeBalance{ splitData[splits::indexOfZoneVolumeBalanceLSByte] + (splitData[splits::indexOfZoneVolumeBalanceLSByte + 1] * 16) };
    zoneVolumeBalance = RawDataTools::formatSigned6bitValueForStoringInPlugin(zoneVolumeBalance);
    splitOptions->setZoneVolumeBalance((uint8)zoneVolumeBalance);
    splitOptions->setZoneVoiceAssignment(splitData[splits::indexOfZoneVoiceAssignmentLSByte] + (splitData[splits::indexOfZoneVoiceAssignmentLSByte + 1] * 16));
    splitOptions->setLowerZoneVoiceNumber(splitData[splits::indexOfLowerZoneVoiceNumberLSByte] + (splitData[splits::indexOfLowerZoneVoiceNumberLSByte + 1] * 16));
    splitOptions->setUpperZoneVoiceNumber(splitData[splits::indexOfUpperZoneVoiceNumberLSByte] + (splitData[splits::indexOfUpperZoneVoiceNumberLSByte + 1] * 16));
}

void RawDataTools::applyRawVoiceDataToMatrixModParameters(const uint8* voiceData, UnexposedParameters* unexposedParams) {
    for (auto i = 0; i != 10; ++i) {
        auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
        auto modSourceLSByteValue{ voiceData[i * 6] };
        auto modSourceMSByteValue{ voiceData[(i * 6) + 1] * 16 };
        auto modSource{ modSourceLSByteValue + modSourceMSByteValue };
        matrixModSettings->setSourceForModulation((uint8)modSource, i);
        auto modAmountLSByteValue{ voiceData[(i * 6) + 2] };
        auto modAmountMSByteValue{ voiceData[(i * 6) + 3] * 16 };
        auto modAmount{ modAmountLSByteValue + modAmountMSByteValue };
        matrixModSettings->setAmountForModulation(formatSigned7bitValueForStoringInPlugin(modAmount), i);
        auto modDestinationLSByteValue{ voiceData[(i * 6) + 4] };
        auto modDestinationMSByteValue{ voiceData[(i * 6) + 5] * 16 };
        auto modDestination{ modDestinationLSByteValue + modDestinationMSByteValue };
        matrixModSettings->setDestinationForModulation((uint8)modDestination, i);
    }
}

void RawDataTools::addVoiceOrSplitNameDataToVector(String & name, int maxLength, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != maxLength; ++i) {
        auto asciiValue{ (uint8)name[i] };
        auto truncatedValue{ truncateASCIIvalueToLowest6bits(asciiValue) };
        auto lsbByteLocation{ params::numberOfHeaderBytesInDataDumpMessages + (2 * i) };
        addValueToDataVectorAtLSBbyteLocation(truncatedValue, &dataVector[lsbByteLocation]);
        checksum += truncatedValue;
    }
}

uint8 RawDataTools::truncateASCIIvalueToLowest6bits(uint8 value) {
    auto truncatedValue{ uint8(value % params::seventhBit) };
    if (value == params::valueForBarSymbol_ASCII) {
        truncatedValue = params::valueForBarSymbol_Matrix;
    }
    return truncatedValue;
}

void RawDataTools::restoreTruncated7thBitToASCIIvalue(uint8& value) {
    value += params::seventhBit;
}

String RawDataTools::convertStoredASCIIvalueToString(const uint8& value) {
    String characterString;
    if (value == params::valueForBarSymbol_Matrix)
        characterString = "|";
    else {
        auto splitNameCharASCIIValue{ value };
        if (splitNameCharASCIIValue < params::sixthBit)
            restoreTruncated7thBitToASCIIvalue(splitNameCharASCIIValue);
        characterString = (String)std::string(1, splitNameCharASCIIValue);
    }
    return characterString;
}

void RawDataTools::addExposedParamDataToVector(AudioProcessorValueTreeState* exposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != info.paramOutOfRange(); ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto param{ exposedParams->getParameter(paramID) };
        auto paramValue{ uint8(param->getValue() * info.maxValueFor(paramIndex)) };
        auto dataByteIndex{ info.dataByteIndexFor(paramIndex) };
        auto lsbByteLocation{ indexOfFirstVoiceOrSplitParamDataLSByte + (dataByteIndex * 2) };
        auto rangeType{ info.rangeTypeFor(paramIndex) };
        if (rangeType == RangeType::signed6bitValue)
            paramValue = formatSigned6bitValueForSendingToMatrix(paramValue);
        if (rangeType == RangeType::signed7bitValue)
            paramValue = formatSigned7bitValueForSendingToMatrix(paramValue);
        addValueToDataVectorAtLSBbyteLocation(paramValue, &dataVector[lsbByteLocation]);
        checksum += paramValue;
    }
}

void RawDataTools::addMatrixModDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    for (auto i = 0; i != 10; ++i) {
        auto matrixModSettings{ unexposedParams->matrixModSettings_get() };
        auto modSource{ matrixModSettings->sourceSettingForModulation(i) };
        auto modAmount{ matrixModSettings->amountSettingForModulation(i) };
        auto modAmountWithOffset{ formatSigned7bitValueForSendingToMatrix(modAmount) };
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

void RawDataTools::addSplitParamDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    auto splitOptions{ unexposedParams->splitOptions_get() };
    auto lowerZoneLimit{ splitOptions->lowerZoneLimit() };
    addValueToDataVectorAtLSBbyteLocation(lowerZoneLimit, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfLowerZoneLimitLSByte]);
    checksum += lowerZoneLimit;
    auto lowerZoneTranspose{ splitOptions->lowerZoneTranspose() };
    lowerZoneTranspose = RawDataTools::formatSignedZoneTransposeValueForSendingToMatrix(lowerZoneTranspose);
    addValueToDataVectorAtLSBbyteLocation(lowerZoneTranspose, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfLowerZoneTransposeLSByte]);
    checksum += lowerZoneTranspose;
    auto lowerZoneMidiOut{ splitOptions->lowerZoneMidiOut() };
    addValueToDataVectorAtLSBbyteLocation(lowerZoneMidiOut, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfLowerZoneMIDIoutLSByte]);
    checksum += lowerZoneMidiOut;
    auto upperZoneLimit{ splitOptions->upperZoneLimit() };
    addValueToDataVectorAtLSBbyteLocation(upperZoneLimit, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfUpperZoneLimitLSByte]);
    checksum += upperZoneLimit;
    auto upperZoneTranspose{ splitOptions->upperZoneTranspose() };
    upperZoneTranspose = RawDataTools::formatSignedZoneTransposeValueForSendingToMatrix(upperZoneTranspose);
    addValueToDataVectorAtLSBbyteLocation(upperZoneTranspose, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfUpperZoneTransposeLSByte]);
    checksum += upperZoneTranspose;
    auto upperZoneMidiOut{ splitOptions->upperZoneMidiOut() };
    addValueToDataVectorAtLSBbyteLocation(upperZoneMidiOut, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfUpperZoneMIDIoutLSByte]);
    checksum += upperZoneMidiOut;
    auto zoneVolumeBalance{ splitOptions->zoneVolumeBalance() };
    zoneVolumeBalance = RawDataTools::formatSigned6bitValueForSendingToMatrix(zoneVolumeBalance);
    addValueToDataVectorAtLSBbyteLocation(zoneVolumeBalance, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfZoneVolumeBalanceLSByte]);
    checksum += zoneVolumeBalance;
    auto zoneVoiceAssignment{ splitOptions->zoneVoiceAssignment() };
    addValueToDataVectorAtLSBbyteLocation(zoneVoiceAssignment, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfZoneVoiceAssignmentLSByte]);
    checksum += zoneVoiceAssignment;
    auto lowerZoneVoiceNumber{ splitOptions->lowerZoneVoiceNumber() };
    addValueToDataVectorAtLSBbyteLocation(lowerZoneVoiceNumber, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfLowerZoneVoiceNumberLSByte]);
    checksum += lowerZoneVoiceNumber;
    auto upperZoneVoiceNumber{ splitOptions->upperZoneVoiceNumber() };
    addValueToDataVectorAtLSBbyteLocation(upperZoneVoiceNumber, &dataVector[indexOfFirstVoiceOrSplitParamDataLSByte + splits::indexOfUpperZoneVoiceNumberLSByte]);
    checksum += upperZoneVoiceNumber;
}

void RawDataTools::addMasterOptionsDataToVector(UnexposedParameters* unexposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    auto masterOptions{ unexposedParams->globalOptions_get() };

    auto vibratoSpeed{ masterOptions->vibratoSpeed() };
    addValueToDataVectorAtLSBbyteLocation(vibratoSpeed, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoSpeedLSByte]);
    checksum += vibratoSpeed;

    auto vibratoSpeedModSource{ masterOptions->vibratoSpeedModSource() };
    addValueToDataVectorAtLSBbyteLocation(vibratoSpeedModSource, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoSpeedModSourceLSByte]);
    checksum += vibratoSpeedModSource;

    auto vibratoSpeedModAmount{ masterOptions->vibratoSpeedModAmount() };
    addValueToDataVectorAtLSBbyteLocation(vibratoSpeedModAmount, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoSpeedModAmountLSByte]);
    checksum += vibratoSpeedModAmount;

    auto vibratoWaveType{ masterOptions->vibratoWaveType() };
    addValueToDataVectorAtLSBbyteLocation(vibratoWaveType, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoWaveTypeLSByte]);
    checksum += vibratoWaveType;

    auto vibratoAmplitude{ masterOptions->vibratoAmplitude() };
    addValueToDataVectorAtLSBbyteLocation(vibratoAmplitude, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoAmplitudeLSByte]);
    checksum += vibratoAmplitude;

    auto vibratoAmplitudeModSource{ masterOptions->vibratoAmplitudeModSource() };
    addValueToDataVectorAtLSBbyteLocation(vibratoAmplitudeModSource, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoAmplitudeModSourceLSByte]);
    checksum += vibratoAmplitudeModSource;

    auto vibratoAmplitudeModAmount{ masterOptions->vibratoAmplitudeModAmount() };
    addValueToDataVectorAtLSBbyteLocation(vibratoAmplitudeModAmount, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVibratoAmplitudeModAmountLSByte]);
    checksum += vibratoAmplitudeModAmount;

    auto masterTune{ masterOptions->globalTune() };
    masterTune = RawDataTools::formatSigned7bitValueForSendingToMatrix(masterTune);
    addValueToDataVectorAtLSBbyteLocation(masterTune, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfMasterTuneLSByte]);
    checksum += masterTune;

    addValueToDataVectorAtLSBbyteLocation(master::velocitySensitivity_Unused, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVelocitySensitivityLSByte_Unused]);
    checksum += master::velocitySensitivity_Unused;

    auto basicChannel_DisplayedValue{ masterOptions->basicChannel() };
    auto basicChannel_DataValue{ uint8(basicChannel_DisplayedValue - master::basicChannelOffset) };
    addValueToDataVectorAtLSBbyteLocation(basicChannel_DataValue, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfBasicChannelLSByte]);
    checksum += basicChannel_DataValue;

    auto omniModeEnabled{ masterOptions->omniModeEnabled() };
    addValueToDataVectorAtLSBbyteLocation(omniModeEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfOmniModeEnableLSByte]);
    checksum += omniModeEnabled;

    auto controllersEnabled{ masterOptions->controllersEnabled() };
    addValueToDataVectorAtLSBbyteLocation(controllersEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfControllersEnableLSByte]);
    checksum += controllersEnabled;

    auto voiceChangesEnabled{ masterOptions->voiceChangesEnabled() };
    addValueToDataVectorAtLSBbyteLocation(voiceChangesEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVoiceChangesEnableLSByte]);
    checksum += voiceChangesEnabled;

    auto sysExEnabled{ masterOptions->sysExEnabled() };
    addValueToDataVectorAtLSBbyteLocation(sysExEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfSysExEnableLSByte]);
    checksum += sysExEnabled;

    auto localControlEnabled{ masterOptions->localControlEnabled() };
    addValueToDataVectorAtLSBbyteLocation(localControlEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfLocalControlEnableLSByte]);
    checksum += localControlEnabled;

    auto pedal1ControllerNumber{ masterOptions->pedal1ControllerNumber() };
    addValueToDataVectorAtLSBbyteLocation(pedal1ControllerNumber, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfPedal1ControllerNumber]);
    checksum += pedal1ControllerNumber;

    auto pedal2ControllerNumber{ masterOptions->pedal2ControllerNumber() };
    addValueToDataVectorAtLSBbyteLocation(pedal2ControllerNumber, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfPedal2ControllerNumber]);
    checksum += pedal2ControllerNumber;

    auto lever2ControllerNumber{ masterOptions->lever2ControllerNumber() };
    addValueToDataVectorAtLSBbyteLocation(lever2ControllerNumber, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfLever2ControllerNumber]);
    checksum += lever2ControllerNumber;

    auto lever3ControllerNumber{ masterOptions->lever3ControllerNumber() };
    addValueToDataVectorAtLSBbyteLocation(lever3ControllerNumber, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfLever3ControllerNumber]);
    checksum += lever3ControllerNumber;

    auto displayBrightness{ masterOptions->displayBrightness() };
    addValueToDataVectorAtLSBbyteLocation(displayBrightness, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfDisplayBrightnessLSByte]);
    checksum += displayBrightness;

    auto squickEnabled{ masterOptions->squickEnabled() };
    addValueToDataVectorAtLSBbyteLocation(squickEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfSQUICKenableLSByte]);
    checksum += squickEnabled;

    auto voicesMapEchoEnabled{ masterOptions->voicesMapEchoEnabled() };
    addValueToDataVectorAtLSBbyteLocation(voicesMapEchoEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVoicesMapEchoEnableLSByte]);
    checksum += voicesMapEchoEnabled;

    auto splitStereoEnabled{ masterOptions->splitStereoEnabled() };
    addValueToDataVectorAtLSBbyteLocation(splitStereoEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfSplitStereoEnableLSByte]);
    checksum += splitStereoEnabled;

    addValueToDataVectorAtLSBbyteLocation(basicChannel_DisplayedValue, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfBasicChannelDisplayedValueLSByte]);
    checksum += basicChannel_DisplayedValue;

    auto spilloverEnabled{ masterOptions->spilloverEnabled() };
    addValueToDataVectorAtLSBbyteLocation(spilloverEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfSpilloverEnableLSByte]);
    checksum += spilloverEnabled;

    auto activeSensingEnabled{ masterOptions->activeSensingEnabled() };
    addValueToDataVectorAtLSBbyteLocation(activeSensingEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfActiveSenseEnableLSByte]);
    checksum += activeSensingEnabled;

    auto midiEchoEnabled{ masterOptions->midiEchoEnabled() };
    addValueToDataVectorAtLSBbyteLocation(midiEchoEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfMIDIechoEnableLSByte]);
    checksum += midiEchoEnabled;

    auto voicesMapEnabled{ masterOptions->voicesMapEnabled() };
    addValueToDataVectorAtLSBbyteLocation(voicesMapEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfVoicesMapEnableLSByte]);
    checksum += voicesMapEnabled;

    auto midiMonoEnabled{ masterOptions->midiMonoEnabled() };
    addValueToDataVectorAtLSBbyteLocation(midiMonoEnabled, &dataVector[indexOfFirstMasterOptionDataLSByte + master::indexOfMIDImonoEnableLSByte]);
    checksum += midiMonoEnabled;

    for (uint8 i = 0; i != voices::numberOfSlotsInBank; ++i) {
        auto voicesMapInPatch{ masterOptions->voicesMapInVoiceForProgramNumber(i) };
        addValueToDataVectorAtLSBbyteLocation(voicesMapInPatch, &dataVector[(int)indexOfFirstMasterOptionDataLSByte + (int)master::indexOfFirstVoicesMapInputLSByte + (i * 2)]);
        checksum += voicesMapInPatch;

        auto voicesMapOutPatch{ masterOptions->voicesMapOutVoiceForProgramNumber(i) };
        addValueToDataVectorAtLSBbyteLocation(voicesMapOutPatch, &dataVector[(int)indexOfFirstMasterOptionDataLSByte + (int)master::indexOfFirstVoicesMapOutputLSByte + (i * 2)]);
        checksum += voicesMapOutPatch;
    }
}

uint8 RawDataTools::formatSigned6bitValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value - params::offsetForSigned6bitRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    return (uint8)valueWithOffset;
}

uint8 RawDataTools::formatSigned7bitValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value - params::offsetForSigned7bitRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    return (uint8)valueWithOffset;
}

uint8 RawDataTools::formatSignedZoneTransposeValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value - params::offsetForSignedZoneTransposeRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    return (uint8)valueWithOffset;
}

uint8 RawDataTools::formatSigned6bitValueForStoringInPlugin(int& value) {
    if (value > 127)
        value -= negativeValueOffset;
    auto valueWithOffset{ value + params::offsetForSigned6bitRange };
    return (uint8)valueWithOffset;
}

uint8 RawDataTools::formatSigned7bitValueForStoringInPlugin(int& value) {
    if (value > 127)
        value -= negativeValueOffset;
    auto valueWithOffset{ value + params::offsetForSigned7bitRange };
    return (uint8)valueWithOffset;
}

uint8 RawDataTools::formatSignedZoneTransposeValueForStoringInPlugin(int& value) {
    if (value > 127)
        value -= negativeValueOffset;
    auto valueWithOffset{ value + params::offsetForSignedZoneTransposeRange };
    return (uint8)valueWithOffset;
}

void RawDataTools::addValueToDataVectorAtLSBbyteLocation(uint8 value, uint8* lsbByteLocation) {
    auto leastSignificantByte{ uint8(value % 16) };
    auto mostSignificantByte{ uint8(value / 16) };
    *lsbByteLocation = leastSignificantByte;
    *(lsbByteLocation + 1) = mostSignificantByte;
}
