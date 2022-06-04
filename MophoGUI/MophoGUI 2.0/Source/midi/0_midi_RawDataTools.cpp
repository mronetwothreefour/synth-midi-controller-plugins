#include "0_midi_RawDataTools.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



const std::vector<uint8> RawDataTools::convertHexStringToDataVector(const String& hexString) {
    std::vector<uint8> voiceData;
    for (auto i = 0; i != hexString.length(); i += 2) {
        auto hexValueString{ hexString.substring(i, i + 2) };
        voiceData.push_back((uint8)hexValueString.getHexValue32());
    }
    return voiceData;
}

const String RawDataTools::convertDataVectorToHexString(const std::vector<uint8>& dataVector) {
    auto hexString{ String::toHexString(dataVector.data(), (int)dataVector.size(), 0) };
    return hexString;
}

bool RawDataTools::isValidVoiceDataHexString(const String& hexString) {
    auto hexStringStrippedOfNonHexCharacters{ hexString.initialSectionContainingOnly("1234567890ABCDEFabcdef") };
    auto isNotCorrectLength{ hexStringStrippedOfNonHexCharacters.length() != VCS::lengthOfVoiceDataHexString };
    if (isNotCorrectLength)
        return false;
    else
        return true;
}

void RawDataTools::applyRawDataToExposedParameters(
    const uint8* dumpData, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) 
{
    auto voiceTransmissionOptions{ unexposedParams->getVoiceTransmissionOptions() };
    voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 param = 0; param != EP::numberOfExposedParams; ++param) {
        auto paramID{ info.IDfor(param) };
        auto lsByteLocation{ info.lsByteLocationFor(param) };
        auto msBitLocation{ info.msBitPackedByteLocationFor(param) };
        auto msBitMask{ info.msBitMaskFor(param) };
        auto newValue{ *(dumpData + lsByteLocation) };
        auto msBitIsFlagged{ *(dumpData + msBitLocation) & msBitMask };
        if (msBitIsFlagged)
            newValue += 128;
        if (paramID == ID::ep_095_ClockTempo)
            newValue -= EP::clockTempoOffset;
        if (paramID.toString().contains("_AssignKnob_") && newValue >= EP::lastUnassignedParamNumber)
            newValue -= EP::knobAssignAndUnassignedParamsOffset;
        auto paramPtr{ exposedParams->getParameter(paramID) };
        paramPtr->setValueNotifyingHost(paramPtr->convertTo0to1(newValue));
    }
    voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

const std::vector<uint8> RawDataTools::extractRawDataFromExposedParameters(AudioProcessorValueTreeState* exposedParams) {
    std::vector<uint8> voiceData;
    for (auto i = 0; i != rawVoiceDataSize; ++i) {
        voiceData.push_back((uint8)0);
    }
    auto& info{ InfoForExposedParameters::get() };
    for (uint8 paramIndex = 0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
        auto paramID{ info.IDfor(paramIndex) };
        auto paramPtr{ exposedParams->getParameter(paramID) };
        auto paramValue{ roundToInt(paramPtr->convertFrom0to1(paramPtr->getValue())) };
        if (paramID == ID::ep_095_ClockTempo)
            paramValue += EP::clockTempoOffset;
        if (paramID.toString().contains("_AssignKnob_") && paramValue >= EP::firstKnobAssignParamNumber)
            paramValue += EP::knobAssignAndUnassignedParamsOffset;
        auto msbLocation{ info.msBitPackedByteLocationFor(paramIndex) };
        auto lsbLocation{ info.lsByteLocationFor(paramIndex) };
        if (paramValue > 127) {
            voiceData[msbLocation] += info.msBitMaskFor(paramIndex);
        }
        voiceData[lsbLocation] = paramValue % 128;
    }
    return voiceData;
}

bool RawDataTools::midiMessageIsSysExForMopho(const MidiMessage& midiMessage) {
    if (midiMessage.isSysEx()) {
        auto sysExData{ midiMessage.getSysExData() };
        auto manufacturerID{ sysExData[1] };
        auto synthID{ sysExData[2] };
        return (manufacturerID == daveSmithInstrumentsID && synthID == mophoID);
    }
    else
        return false;
}

std::vector<uint8> RawDataTools::createRawDataVectorWithSysExIDheaderBytesForMopho() {
    std::vector<uint8> rawDataVector;
    rawDataVector.push_back(daveSmithInstrumentsID);
    rawDataVector.push_back(mophoID);
    return rawDataVector;
}
