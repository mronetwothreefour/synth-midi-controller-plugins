#include "splits_0_tree_SplitsBank.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../midi/midi_0_RawDataTools.h"

using namespace Matrix_6G_Constants;

SplitsBank::SplitsBank() :
	splitDataHexStrings{ ID::splitsBank_DataHexStrings},
	splitNameStrings{ ID::splitsBank_NameStrings }
{
	for (auto slotNum = (uint8)0; slotNum < SPLT::numberOfSlotsInSplitsBank; ++slotNum) {
		auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
		splitDataHexStrings.setProperty(slotName, SPLT::initialSplitDataHexString, nullptr);
		splitNameStrings.setProperty(slotName, SPLT::initialSplitNameString, nullptr);
	}
	splitDataHexStrings.addListener(this);
}

const String SplitsBank::nameOfSplitInSlot(const uint8 slotNum) const {
	jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
	return splitNameStrings.getProperty("slot_" + String(slotNum).paddedLeft('0', 2));
}

const String SplitsBank::getSplitDataHexStringFromSlot(const uint8 slotNum) const {
	jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
	return splitDataHexStrings.getProperty("slot_" + String(slotNum).paddedLeft('0', 2));
}

const String SplitsBank::extractSplitNameFromDataVector(const std::vector<uint8>& dataVector) {
	String splitName{ "" };
	for (auto byte = 0; byte != (2 * SPLT::numberOfCharsInSplitName); byte += 2) {
		auto lsbByteValue{ (uint8)dataVector[byte] };
		auto msbByteValue{ (uint8)dataVector[byte + 1] };
		auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
		if (storedASCIIvalue == RawDataTools::valueForBarSymbol)
			splitName += "|";
		else {
			RawDataTools::restoreSeventhBitTo_ASCII_Value(storedASCIIvalue);
			splitName += (String)std::string(1, storedASCIIvalue);
		}
	}
	return splitName;
}

void SplitsBank::storeSplitDataHexStringInSlot(const String splitDataHexString, const uint8 slotNum) {
	jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
	auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
	splitDataHexStrings.setProperty(slotName, splitDataHexString, nullptr);
}

Value SplitsBank::getSplitNameAsValueForSlot(const uint8 slotNum) {
	jassert(slotNum < SPLT::numberOfSlotsInSplitsBank);
	auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
	return splitNameStrings.getPropertyAsValue(slotName, nullptr);
}

void SplitsBank::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto propertyName{ propertyID.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
	auto slotNum{ (uint8)slotString.getIntValue() };
	auto splitDataHexString{ getSplitDataHexStringFromSlot(slotNum) };
	auto splitName{ extractSplitNameFromDataVector(RawDataTools::convertHexStringToDataVector(splitDataHexString)) };
	splitNameStrings.setProperty(propertyID, splitName, nullptr);
}

std::unique_ptr<XmlElement> SplitsBank::getStateXml() {
	auto splitsBankStateXml{ std::make_unique<XmlElement>(ID::state_SplitsBank) };

	auto splitDataHexStringsXml{ splitDataHexStrings.createXml() };
	if (splitDataHexStringsXml != nullptr) {
		splitDataHexStringsXml->setTagName(ID::state_SplitDataHexStrings);
		splitsBankStateXml->addChildElement(splitDataHexStringsXml.release());
	}

	auto splitNameStringsXml{ splitNameStrings.createXml() };
	if (splitNameStringsXml != nullptr) {
		splitNameStringsXml->setTagName(ID::state_SplitNameStrings);
		splitsBankStateXml->addChildElement(splitNameStringsXml.release());
	}

	return splitsBankStateXml;
}

void SplitsBank::replaceState(const ValueTree& newState) {
	if (newState.isValid()) {
		auto splitDataHexStringsState{ newState.getChildWithName(ID::state_SplitDataHexStrings) };
		if (splitDataHexStringsState.isValid())
			splitDataHexStrings.copyPropertiesAndChildrenFrom(splitDataHexStringsState, nullptr);

		auto splitNameStringsState{ newState.getChildWithName(ID::state_SplitNameStrings) };
		if (splitNameStringsState.isValid())
			splitNameStrings.copyPropertiesAndChildrenFrom(splitNameStringsState, nullptr);
	}
}

SplitsBank::~SplitsBank() {
	splitDataHexStrings.removeListener(this);
}
