#include "midi_0_RawDataTools.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Global.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_0_tree_MatrixModOptions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_GlobalOptions.h"
#include "../unexposedParameters/up_0_tree_SplitOptions.h"
#include "../unexposedParameters/up_0_tree_VoiceTransmissionOptions.h"

using namespace Matrix_6G_Constants;

bool RawDataTools::midiMessageIsSysExForMatrix(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        auto manufacturerID{ sysExData[1] };
        auto synthID{ sysExData[2] };
        return (manufacturerID == oberheim_ID && synthID == matrix_ID);
    }
    else
        return false;
}

std::vector<uint8> RawDataTools::createRawDataVectorWithMatrix_6_SysExID() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back(oberheim_ID);
    rawDataVector.push_back(matrix_ID);
    return rawDataVector;
}

std::vector<uint8> RawDataTools::createRawDataVectorWithXpander_SysExID_ForSwitchingToSplitMode() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back(oberheim_ID);
    rawDataVector.push_back(xpander_ID);
    return rawDataVector;
}

const std::vector<uint8> RawDataTools::convertHexStringToDataVector(const String& hexString) {
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

const String RawDataTools::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
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

void RawDataTools::applyRawVoiceDataTo_GUI(const uint8 voiceNum, const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions) {
    auto currentVoiceOptions{ exposedParams->currentVoiceOptions.get() };
    currentVoiceOptions->setCurrentVoiceNumber(voiceNum);

    String voiceName{ "" };
    for (auto byte = 0; byte != VCS::numberOfCharsInVoiceName * 2; byte += 2) {
        auto lsbByteValue{ (uint8)voiceData[byte] };
        auto msbByteValue{ (uint8)voiceData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        restoreSeventhBitTo_ASCII_Value(storedASCIIvalue);
        voiceName += convertStored_ASCII_ValueToString(storedASCIIvalue);
    }
    currentVoiceOptions->setCurrentVoiceName(voiceName);

    applyRawVoiceDataToExposedParameters(voiceData + VCS::indexOfFirstExposedParamsDataByte, exposedParams, transmitOptions);

    auto matrixModOptions{ exposedParams->matrixModOptions.get() };
    applyRawVoiceDataToMatrixModOptions(voiceData + VCS::indexOfFirstMatrixModDataByte, matrixModOptions);
}

const std::vector<uint8> RawDataTools::extractRawVoiceDataFrom_GUI(ExposedParameters* exposedParams) {
    std::vector<uint8> voiceData;
    uint8 checksum{ 0 };
    auto currentVoiceName{ exposedParams->currentVoiceOptions->currentVoiceName() };
    addVoiceOrSplitNameDataToVectorAndUpdateChecksum(true, currentVoiceName, voiceData, checksum);
    addExposedParamDataToVectorAndUpdateChecksum(exposedParams, voiceData, checksum);
    addMatrixModDataToVectorAndUpdateChecksum(exposedParams->matrixModOptions.get(), voiceData, checksum);
    for (auto i = voiceData.size(); i < voiceDataSize; ++i)
        voiceData.push_back((uint8)0);
    voiceData.push_back(checksum % (uint8)128);
    return voiceData;
}

bool RawDataTools::isValidVoiceDataHexString(const String& hexString) {
    auto isNotCorrectLength{ hexString.length() != VCS::lengthOfVoiceDataHexString };
    if (isNotCorrectLength)
        return false;
    else
        return true;
}

void RawDataTools::applyRawSplitDataTo_GUI(const uint8* splitData, SplitOptions* splitOptions) {
    String splitName{ "" };
    for (auto byte = 0; byte != SPLT::numberOfCharsInSplitName * 2; byte += 2) {
        auto lsbByteValue{ (uint8)splitData[byte] };
        auto msbByteValue{ (uint8)splitData[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        restoreSeventhBitTo_ASCII_Value(storedASCIIvalue);
        splitName += convertStored_ASCII_ValueToString(storedASCIIvalue);
    }
    splitOptions->setSplitName(splitName);

    auto lowerZoneLimit{ uint8(splitData[SPLT::indexOfLowerZoneLimitLSByte] + (splitData[SPLT::indexOfLowerZoneLimitLSByte + 1] * 16)) };
    splitOptions->setZoneLimit(SplitZone::lower, lowerZoneLimit);

    auto lowerZoneTranspose{ uint8(splitData[SPLT::indexOfLowerZoneTransposeLSByte] + (splitData[SPLT::indexOfLowerZoneTransposeLSByte + 1] * 16)) };
    formatSignedZoneTransposeValueForStoringInPlugin(lowerZoneTranspose);
    splitOptions->setZoneTranspose(SplitZone::lower, lowerZoneTranspose);

    auto lowerZone_MIDI_OutIsEnabled{ splitData[SPLT::indexOfLowerZoneMIDIoutLSByte] == (uint8)1 ? true : false };
    splitOptions->setZone_MIDI_OutIsEnabled(SplitZone::lower, lowerZone_MIDI_OutIsEnabled);

    auto upperZoneLimit{ uint8(splitData[SPLT::indexOfUpperZoneLimitLSByte] + (splitData[SPLT::indexOfUpperZoneLimitLSByte + 1] * 16)) };
    splitOptions->setZoneLimit(SplitZone::upper, upperZoneLimit);

    auto upperZoneTranspose{ uint8(splitData[SPLT::indexOfUpperZoneTransposeLSByte] + (splitData[SPLT::indexOfUpperZoneTransposeLSByte + 1] * 16)) };
    formatSignedZoneTransposeValueForStoringInPlugin(upperZoneTranspose);
    splitOptions->setZoneTranspose(SplitZone::upper, upperZoneTranspose);

    auto upperZone_MIDI_OutIsEnabled{ splitData[SPLT::indexOfUpperZoneMIDIoutLSByte] == (uint8)1 ? true : false };
    splitOptions->setZone_MIDI_OutIsEnabled(SplitZone::upper, upperZone_MIDI_OutIsEnabled);

    auto zoneVolumeBalance{ uint8(splitData[SPLT::indexOfZoneVolumeBalanceLSByte] + (splitData[SPLT::indexOfZoneVolumeBalanceLSByte + 1] * 16)) };
    formatSignedValueForStoringInPlugin(uses_6_bits, zoneVolumeBalance);
    splitOptions->setZoneVolumeBalance((uint8)zoneVolumeBalance);

    auto zoneVoiceAssignment{ SplitZoneVoiceAssignment{ splitData[SPLT::indexOfZoneVoiceAssignmentLSByte] } };
    splitOptions->setZoneVoiceAssignment(zoneVoiceAssignment);

    auto lowerZoneVoiceNumber{ uint8(splitData[SPLT::indexOfLowerZoneVoiceNumberLSByte] + (splitData[SPLT::indexOfLowerZoneVoiceNumberLSByte + 1] * 16)) };
    splitOptions->setZoneVoiceNumber(SplitZone::lower, lowerZoneVoiceNumber);

    auto upperZoneVoiceNumber{ uint8(splitData[SPLT::indexOfUpperZoneVoiceNumberLSByte] + (splitData[SPLT::indexOfUpperZoneVoiceNumberLSByte + 1] * 16)) };
    splitOptions->setZoneVoiceNumber(SplitZone::upper, upperZoneVoiceNumber);
}

const std::vector<uint8> RawDataTools::extractRawSplitDataFrom_GUI(SplitOptions* splitOptions)
{
    std::vector<uint8> splitData;
    uint8 checksum{ 0 };

    auto splitName{ splitOptions->splitName() };
    addVoiceOrSplitNameDataToVectorAndUpdateChecksum(false, splitName, splitData, checksum);

    for (auto i = 0; i != numberOfUnusedSplitBytes; ++i)
        splitData.push_back((uint8)0);

    auto lowerZoneLimit{ splitOptions->zoneLimit(SplitZone::lower) };
    splitData.push_back(lowerZoneLimit % 16);
    splitData.push_back(lowerZoneLimit / 16);
    checksum += lowerZoneLimit;

    auto lowerZoneTranspose{ splitOptions->zoneTranspose(SplitZone::lower) };
    formatSignedZoneTransposeValueForSendingToMatrix(lowerZoneTranspose);
    splitData.push_back(lowerZoneTranspose % 16);
    splitData.push_back(lowerZoneTranspose / 16);
    checksum += lowerZoneTranspose;

    auto lowerZone_MIDI_OutIsEnabled{ splitOptions->zone_MIDI_OutIsEnabled(SplitZone::lower) };
    splitData.push_back(lowerZone_MIDI_OutIsEnabled ? 1 : 0);
    splitData.push_back(0);
    checksum += lowerZone_MIDI_OutIsEnabled ? 1 : 0;

    auto upperZoneLimit{ splitOptions->zoneLimit(SplitZone::upper) };
    splitData.push_back(upperZoneLimit % 16);
    splitData.push_back(upperZoneLimit / 16);
    checksum += upperZoneLimit;

    auto upperZoneTranspose{ splitOptions->zoneTranspose(SplitZone::upper) };
    formatSignedZoneTransposeValueForSendingToMatrix(upperZoneTranspose);
    splitData.push_back(upperZoneTranspose % 16);
    splitData.push_back(upperZoneTranspose / 16);
    checksum += upperZoneTranspose;

    auto upperZone_MIDI_OutIsEnabled{ splitOptions->zone_MIDI_OutIsEnabled(SplitZone::upper) };
    splitData.push_back(upperZone_MIDI_OutIsEnabled ? 1 : 0);
    splitData.push_back(0);
    checksum += upperZone_MIDI_OutIsEnabled ? 1 : 0;

    auto zoneVolumeBalance{ splitOptions->zoneVolumeBalance() };
    formatSignedValueForSendingToMatrix(uses_6_bits, zoneVolumeBalance);
    splitData.push_back(zoneVolumeBalance % 16);
    splitData.push_back(zoneVolumeBalance / 16);
    checksum += zoneVolumeBalance;

    auto zoneVoiceAssignment{ (uint8)(int)splitOptions->zoneVoiceAssignment() };
    splitData.push_back(zoneVoiceAssignment);
    splitData.push_back(0);
    checksum += zoneVoiceAssignment;

    auto lowerZoneVoiceNumber{ splitOptions->zoneVoiceNumber(SplitZone::lower) };
    splitData.push_back(lowerZoneVoiceNumber % 16);
    splitData.push_back(lowerZoneVoiceNumber / 16);
    checksum += lowerZoneVoiceNumber;

    auto upperZoneVoiceNumber{ splitOptions->zoneVoiceNumber(SplitZone::upper) };
    splitData.push_back(upperZoneVoiceNumber % 16);
    splitData.push_back(upperZoneVoiceNumber / 16);
    checksum += upperZoneVoiceNumber;

    splitData.push_back(checksum % (uint8)128);

    return splitData;
}

void RawDataTools::applyRawGlobalDataTo_GUI(const uint8* globalData, GlobalOptions* globalOptions) {
    auto vibratoSpeed{ uint8(globalData[GLBL::indexOfVibratoSpeedLSByte] + (globalData[GLBL::indexOfVibratoSpeedLSByte + 1] * 16)) };
    globalOptions->setVibratoSpeed(vibratoSpeed);

    globalOptions->setVibratoSpeedModSource(VibratoModSource{ globalData[GLBL::indexOfVibratoSpeedModSourceLSByte] });

    auto vibSpeedModAmount{ uint8(globalData[GLBL::indexOfVibratoSpeedModAmountLSByte] + (globalData[GLBL::indexOfVibratoSpeedModAmountLSByte + 1] * 16)) };
    globalOptions->setVibratoSpeedModAmount(vibSpeedModAmount);

    globalOptions->setVibratoWaveType(VibratoWaveType{ globalData[GLBL::indexOfVibratoWaveTypeLSByte] });

    auto vibratoAmplitude{ uint8(globalData[GLBL::indexOfVibratoAmplitudeLSByte] + (globalData[GLBL::indexOfVibratoAmplitudeLSByte + 1] * 16)) };
    globalOptions->setVibratoAmplitude(vibratoAmplitude);

    globalOptions->setVibratoAmpModSource(VibratoModSource{ globalData[GLBL::indexOfVibratoAmpModSourceLSByte] });

    auto vibAmpModAmount{ uint8(globalData[GLBL::indexOfVibratoAmpModAmountLSByte] + (globalData[GLBL::indexOfVibratoAmpModAmountLSByte + 1] * 16)) };
    globalOptions->setVibratoAmpModAmount(vibAmpModAmount);

    auto globalTune{ uint8(globalData[GLBL::indexOfGlobalTuneLSByte] + (globalData[GLBL::indexOfGlobalTuneLSByte + 1] * 16)) };
    formatSignedValueForStoringInPlugin(uses_7_bits, globalTune);
    globalOptions->setGlobalTune((uint8)globalTune);

    globalOptions->setBasicChannel(globalData[GLBL::indexOfBasicChannelLSByte] + GLBL::basicChannelOffset);

    globalOptions->setOmniModeIsEnabled(globalData[GLBL::indexOfOmniModeEnableLSByte] == 1 ? true : false);

    globalOptions->setControllersAreEnabled(globalData[GLBL::indexOfControllersEnableLSByte] == 1 ? true : false);

    globalOptions->setVoiceChangesAreEnabled(globalData[GLBL::indexOfVoiceChangesEnableLSByte] == 1 ? true : false);

    globalOptions->setSysExIsEnabled(globalData[GLBL::indexOfSysExEnableLSByte] == 1 ? true : false);

    globalOptions->setLocalControIsEnabled(globalData[GLBL::indexOfLocalControlEnableLSByte] == 1 ? true : false);

    auto pedal_1_ControllerNumber{ uint8(globalData[GLBL::indexOfPedal_1_ControllerNumber] + (globalData[GLBL::indexOfPedal_1_ControllerNumber + 1] * 16)) };
    globalOptions->setPedal_1_ControllerNumber(pedal_1_ControllerNumber);

    auto pedal_2_ControllerNumber{ uint8(globalData[GLBL::indexOfPedal_2_ControllerNumber] + (globalData[GLBL::indexOfPedal_2_ControllerNumber + 1] * 16)) };
    globalOptions->setPedal_2_ControllerNumber(pedal_2_ControllerNumber);

    auto lever_2_ControllerNumber{ uint8(globalData[GLBL::indexOfLever_2_ControllerNumber] + (globalData[GLBL::indexOfLever_2_ControllerNumber + 1] * 16)) };
    globalOptions->setLever_2_ControllerNumber(lever_2_ControllerNumber);

    auto lever_3_ControllerNumber{ uint8(globalData[GLBL::indexOfLever_3_ControllerNumber] + (globalData[GLBL::indexOfLever_3_ControllerNumber + 1] * 16)) };
    globalOptions->setLever_3_ControllerNumber(lever_3_ControllerNumber);

    auto displayBrightness{ uint8(globalData[GLBL::indexOfDisplayBrightnessLSByte] + (globalData[GLBL::indexOfDisplayBrightnessLSByte + 1] * 16)) };
    globalOptions->setDisplayBrightness(displayBrightness);

    globalOptions->set_SQUICK_IsEnabled(globalData[GLBL::indexOf_SQUICK_EnableLSByte] == 1 ? true : false);

    globalOptions->setVoiceMapEchoIsEnabled(globalData[GLBL::indexOfVoiceMapEchoEnableLSByte] == 1 ? true : false);

    globalOptions->setSplitStereoIsEnabled(globalData[GLBL::indexOfSplitStereoEnableLSByte] == 1 ? true : false);

    globalOptions->setSpilloverIsEnabled(globalData[GLBL::indexOfSpilloverEnableLSByte] == 1 ? true : false);

    globalOptions->setActiveSensingIsEnabled(globalData[GLBL::indexOfActiveSenseEnableLSByte] == 1 ? true : false);

    globalOptions->set_MIDI_EchoIsEnabled(globalData[GLBL::indexOf_MIDI_EchoEnableLSByte] == 1 ? true : false);

    globalOptions->setVoiceMapIsEnabled(globalData[GLBL::indexOfVoiceMapEnableLSByte] == 1 ? true : false);

    globalOptions->set_MIDI_MonoIsEnabled(globalData[GLBL::indexOf_MIDI_MonoEnableLSByte] == 1 ? true : false);

    for (uint8 i = 0; i != VCS::numberOfSlotsInVoicesBank; ++i) {
        auto indexOfInVoiceLSByte{ GLBL::indexOfFirstVoicesMapInVoiceLSByte + (i * 2) };
        globalOptions->setInVoiceForVoiceMapSlot(globalData[indexOfInVoiceLSByte] + (globalData[indexOfInVoiceLSByte + 1] * 16), i);
        auto indexOfOutVoiceLSByte{ GLBL::indexOfFirstVoicesMapOutVoiceLSByte + (i * 2) };
        globalOptions->setOutVoiceForVoiceMapSlot(globalData[indexOfOutVoiceLSByte] + (globalData[indexOfOutVoiceLSByte + 1] * 16), i);
    }
}

const std::vector<uint8> RawDataTools::extractRawGlobalDataFrom_GUI(GlobalOptions* globalOptions) {
    std::vector<uint8> globalData;
    uint8 checksum{ 0 };

    auto vibratoSpeed{ globalOptions->vibratoSpeed() };
    globalData.push_back(vibratoSpeed % 16);
    globalData.push_back(vibratoSpeed / 16);
    checksum += vibratoSpeed;

    auto vibratoSpeedModSource{ (uint8)(int)globalOptions->vibratoSpeedModSource() };
    globalData.push_back(vibratoSpeedModSource);
    globalData.push_back(0);
    checksum += vibratoSpeedModSource;

    auto vibratoSpeedModAmount{ globalOptions->vibratoSpeedModAmount() };
    globalData.push_back(vibratoSpeedModAmount % 16);
    globalData.push_back(vibratoSpeedModAmount / 16);
    checksum += vibratoSpeedModAmount;

    auto vibratoWaveType{ (uint8)(int)globalOptions->vibratoWaveType() };
    globalData.push_back(vibratoWaveType);
    globalData.push_back(0);
    checksum += vibratoWaveType;

    auto vibratoAmplitude{ globalOptions->vibratoAmplitude() };
    globalData.push_back(vibratoAmplitude % 16);
    globalData.push_back(vibratoAmplitude / 16);
    checksum += vibratoAmplitude;

    auto vibratoAmpModSource{ (uint8)(int)globalOptions->vibratoAmpModSource() };
    globalData.push_back(vibratoAmpModSource);
    globalData.push_back(0);
    checksum += vibratoAmpModSource;

    auto vibratoAmpModAmount{ globalOptions->vibratoAmpModAmount() };
    globalData.push_back(vibratoAmpModAmount % 16);
    globalData.push_back(vibratoAmpModAmount / 16);
    checksum += vibratoAmpModAmount;

    auto globalTune{ globalOptions->globalTune() };
    formatSignedValueForSendingToMatrix(uses_7_bits, globalTune);
    globalData.push_back(globalTune % 16);
    globalData.push_back(globalTune / 16);
    checksum += globalTune;

    globalData.push_back(GLBL::velocitySensitivity_Unused % 16);
    globalData.push_back(GLBL::velocitySensitivity_Unused / 16);
    checksum += GLBL::velocitySensitivity_Unused;

    auto basicChannel_DisplayedValue{ globalOptions->basicChannel() };
    auto basicChannel_DataValue{ uint8(basicChannel_DisplayedValue - GLBL::basicChannelOffset) };
    globalData.push_back(basicChannel_DataValue % 16);
    globalData.push_back(basicChannel_DataValue / 16);
    checksum += basicChannel_DataValue;

    auto omniModeIsEnabled{ globalOptions->omniModeIsEnabled() };
    globalData.push_back(omniModeIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += omniModeIsEnabled ? 1 : 0;

    auto controllersAreEnabled{ globalOptions->controllersAreEnabled() };
    globalData.push_back(controllersAreEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += controllersAreEnabled ? 1 : 0;

    auto voiceChangesAreEnabled{ globalOptions->voiceChangesAreEnabled() };
    globalData.push_back(voiceChangesAreEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += voiceChangesAreEnabled ? 1 : 0;

    auto sysExIsEnabled{ globalOptions->sysExIsEnabled() };
    globalData.push_back(sysExIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += sysExIsEnabled ? 1 : 0;

    auto localControlIsEnabled{ globalOptions->localControlIsEnabled() };
    globalData.push_back(localControlIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += localControlIsEnabled ? 1 : 0;

    auto pedal_1_ControllerNumber{ globalOptions->pedal_1_ControllerNumber() };
    globalData.push_back(pedal_1_ControllerNumber % 16);
    globalData.push_back(pedal_1_ControllerNumber / 16);
    checksum += pedal_1_ControllerNumber;

    auto pedal_2_ControllerNumber{ globalOptions->pedal_2_ControllerNumber() };
    globalData.push_back(pedal_2_ControllerNumber % 16);
    globalData.push_back(pedal_2_ControllerNumber / 16);
    checksum += pedal_2_ControllerNumber;

    auto lever_2_ControllerNumber{ globalOptions->lever_2_ControllerNumber() };
    globalData.push_back(lever_2_ControllerNumber % 16);
    globalData.push_back(lever_2_ControllerNumber / 16);
    checksum += lever_2_ControllerNumber;

    auto lever_3_ControllerNumber{ globalOptions->lever_3_ControllerNumber() };
    globalData.push_back(lever_3_ControllerNumber % 16);
    globalData.push_back(lever_3_ControllerNumber / 16);
    checksum += lever_3_ControllerNumber;

    auto displayBrightness{ globalOptions->displayBrightness() };
    globalData.push_back(displayBrightness % 16);
    globalData.push_back(displayBrightness / 16);
    checksum += displayBrightness;

    auto squickIsEnabled{ globalOptions->squickIsEnabled() };
    globalData.push_back(squickIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += squickIsEnabled ? 1 : 0;

    auto voiceMapEchoIsEnabled{ globalOptions->voiceMapEchoIsEnabled() };
    globalData.push_back(voiceMapEchoIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += voiceMapEchoIsEnabled ? 1 : 0;

    auto splitStereoIsEnabled{ globalOptions->splitStereoIsEnabled() };
    globalData.push_back(splitStereoIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += splitStereoIsEnabled ? 1 : 0;

    globalData.push_back(basicChannel_DisplayedValue % 16);
    globalData.push_back(basicChannel_DisplayedValue / 16);
    checksum += basicChannel_DisplayedValue;

    auto spilloverIsEnabled{ globalOptions->spilloverIsEnabled() };
    globalData.push_back(spilloverIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += spilloverIsEnabled ? 1 : 0;

    auto undefinedByte{ 0 };
    globalData.push_back(undefinedByte);
    globalData.push_back(undefinedByte);

    auto activeSensingIsEnabled{ globalOptions->activeSensingIsEnabled() };
    globalData.push_back(activeSensingIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += activeSensingIsEnabled ? 1 : 0;

    auto midiEchoIsEnabled{ globalOptions->midiEchoIsEnabled() };
    globalData.push_back(midiEchoIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += midiEchoIsEnabled ? 1 : 0;

    auto voiceMapIsEnabled{ globalOptions->voiceMapIsEnabled() };
    globalData.push_back(voiceMapIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += voiceMapIsEnabled ? 1 : 0;

    globalData.push_back(undefinedByte);
    globalData.push_back(undefinedByte);

    auto midiMonoIsEnabled{ globalOptions->midiMonoIsEnabled() };
    globalData.push_back(midiMonoIsEnabled ? 1 : 0);
    globalData.push_back(0);
    checksum += midiMonoIsEnabled ? 1 : 0;

    for (uint8 i = 0; i != VCS::numberOfSlotsInVoicesBank; ++i) {
        auto voiceMapInVoice{ globalOptions->inVoiceForVoiceMapSlot(i) };
        globalData.push_back(voiceMapInVoice % 16);
        globalData.push_back(voiceMapInVoice / 16);
        checksum += voiceMapInVoice;

        auto voiceMapOutVoice{ globalOptions->outVoiceForVoiceMapSlot(i) };
        globalData.push_back(voiceMapOutVoice % 16);
        globalData.push_back(voiceMapOutVoice / 16);
        checksum += voiceMapOutVoice;
    }

    globalData.push_back(checksum % (uint8)128);

    return globalData;
}

void RawDataTools::removeSeventhBitFrom_ASCII_Value(uint8& value) {
    value %= 64;
}

void RawDataTools::restoreSeventhBitTo_ASCII_Value(uint8& value) {
    if (value < 32 && value != valueForBarSymbol)
        value += 64;
}

void RawDataTools::applyRawVoiceDataToExposedParameters(const uint8* voiceData, ExposedParameters* exposedParams, VoiceTransmissionOptions* transmitOptions) {
    transmitOptions->setParamChangesShouldBeTransmitted(false);
    auto info{ exposedParams->info.get() };
    for (uint8 param = 0; param != EP::numberOfExposedParams; ++param) {
        auto paramID{ info->IDfor(param) };
        auto lsByteLocation{ info->dataByteIndexFor(param) * 2 };
        auto lsByteValue{ voiceData[lsByteLocation] };
        auto msByteValue{ voiceData[lsByteLocation + 1] * 16 };
        auto newValue{ uint8(lsByteValue + msByteValue) };
        if (info->rangeTypeFor(param) == RangeType::signed_6_bitValue)
            formatSignedValueForStoringInPlugin(uses_6_bits, newValue);
        if (info->rangeTypeFor(param) == RangeType::signed_7_bitValue)
            formatSignedValueForStoringInPlugin(uses_7_bits, newValue);
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newValue));
    }
    transmitOptions->setParamChangesShouldBeTransmitted(true);
}

void RawDataTools::applyRawVoiceDataToMatrixModOptions(const uint8* voiceData, MatrixModOptions* matrixModOptions) {
    for (auto modNum = 0; modNum != 10; ++modNum) {
        auto modSource_LS_ByteValue{ voiceData[modNum * 6] };
        auto modSource_MS_ByteValue{ voiceData[(modNum * 6) + 1] * 16 };
        auto modSource{ modSource_LS_ByteValue + modSource_MS_ByteValue };
        matrixModOptions->setModSource(modNum, (uint8)modSource);

        auto modAmount_LS_ByteValue{ voiceData[(modNum * 6) + 2] };
        auto modAmount_MS_ByteValue{ voiceData[(modNum * 6) + 3] * 16 };
        auto modAmount{ uint8(modAmount_LS_ByteValue + modAmount_MS_ByteValue) };
        formatSignedValueForStoringInPlugin(uses_7_bits, modAmount);
        matrixModOptions->setModAmount(modNum, modAmount);

        auto modDest_LS_ByteValue{ voiceData[(modNum * 6) + 4] };
        auto modDest_MS_ByteValue{ voiceData[(modNum * 6) + 5] * 16 };
        auto modDest{ modDest_LS_ByteValue + modDest_MS_ByteValue };
        matrixModOptions->setModDest(modNum, (uint8)modDest);
    }
}

void RawDataTools::addVoiceOrSplitNameDataToVectorAndUpdateChecksum(bool isVoiceName, String& name, std::vector<uint8>& dataVector, uint8& checksum) {
    auto maxLength{ isVoiceName ? 8 : 6 };
    for (auto charNum = 0; charNum != maxLength; ++charNum) {
        auto asciiValue{ (uint8)name[charNum] };
        removeSeventhBitFrom_ASCII_Value(asciiValue);
        dataVector.push_back(asciiValue % 16);
        dataVector.push_back(asciiValue / 16);
        checksum += asciiValue;
    }
}

void RawDataTools::addExposedParamDataToVectorAndUpdateChecksum(ExposedParameters* exposedParams, std::vector<uint8>& dataVector, uint8& checksum) {
    std::vector<uint8> exposedParamsData;
    for (auto i = 0; i != exposedParamsDataSize; ++i)
        exposedParamsData.push_back((uint8)0);
    auto info{ exposedParams->info.get() };
    for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
        auto paramID{ info->IDfor(paramIndex) };
        auto paramPtr{ exposedParams->state->getParameter(paramID) };
        auto paramValue{ (uint8)roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
        auto dataByteIndex{ info->dataByteIndexFor(paramIndex) };
        auto lsbByteLocation{ dataByteIndex * 2 };
        auto rangeType{ info->rangeTypeFor(paramIndex) };
        if (rangeType == RangeType::signed_6_bitValue)
            formatSignedValueForSendingToMatrix(uses_6_bits, paramValue);
        if (rangeType == RangeType::signed_7_bitValue)
            formatSignedValueForSendingToMatrix(uses_7_bits, paramValue);
        exposedParamsData[lsbByteLocation] = uint8(paramValue % 16);
        exposedParamsData[lsbByteLocation + 1] = uint8(paramValue / 16);
        checksum += paramValue;
    }
    for (auto dataByte : exposedParamsData)
        dataVector.push_back(dataByte);
}

void RawDataTools::addMatrixModDataToVectorAndUpdateChecksum(MatrixModOptions* matrixModOptions, std::vector<uint8>& dataVector, uint8& checksum) {
    std::vector<uint8> exposedParamsData;
    for (auto modNum = 0; modNum != 10; ++modNum) {
        auto modSource{ matrixModOptions->modSource(modNum) };
        dataVector.push_back(modSource % 16);
        dataVector.push_back(modSource / 16);
        checksum += modSource;

        auto modAmount{ matrixModOptions->modAmount(modNum) };
        formatSignedValueForSendingToMatrix(uses_7_bits, modAmount);
        dataVector.push_back(modAmount % 16);
        dataVector.push_back(modAmount / 16);
        checksum += modAmount;

        auto modDest{ matrixModOptions->modDest(modNum) };
        dataVector.push_back(modDest % 16);
        dataVector.push_back(modDest / 16);
        checksum += modDest;
    }
}

void RawDataTools::formatSignedValueForSendingToMatrix(bool is_7_bit, uint8& value) {
    auto valueWithOffset{ value - (is_7_bit ? EP::offsetForSigned_7_BitRange : EP::offsetForSigned_6_BitRange) };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    value = (uint8)valueWithOffset;
}

void RawDataTools::formatSignedValueForStoringInPlugin(bool is_7_bit, uint8& value) {
    int valueWithOffset{ value };
    if (valueWithOffset > 127)
        valueWithOffset -= negativeValueOffset;
    valueWithOffset += (is_7_bit ? EP::offsetForSigned_7_BitRange : EP::offsetForSigned_6_BitRange);
    value = (uint8)valueWithOffset;
}

void RawDataTools::formatSignedZoneTransposeValueForSendingToMatrix(uint8& value) {
    auto valueWithOffset{ value - SPLT::offsetForSignedZoneTransposeRange };
    if (valueWithOffset < 0)
        valueWithOffset += negativeValueOffset;
    value = (uint8)valueWithOffset;
}

void RawDataTools::formatSignedZoneTransposeValueForStoringInPlugin(uint8& value) {
    int valueWithOffset{ value };
    if (valueWithOffset > 127)
        valueWithOffset -= negativeValueOffset;
    valueWithOffset += SPLT::offsetForSignedZoneTransposeRange;
    value = (uint8)valueWithOffset;
}

String RawDataTools::convertStored_ASCII_ValueToString(const uint8& value) {
    String characterString;
    if (value == valueForBarSymbol)
        characterString = "|";
    else {
        auto splitNameCharASCIIValue{ value };
        restoreSeventhBitTo_ASCII_Value(splitNameCharASCIIValue);
        characterString = (String)std::string(1, splitNameCharASCIIValue);
    }
    return characterString;
}

