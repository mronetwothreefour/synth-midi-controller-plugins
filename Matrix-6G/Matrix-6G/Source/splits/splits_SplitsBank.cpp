#include "splits_SplitsBank.h"

#include "splits_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"

using namespace constants;



SplitsBank::SplitsBank() :
	splitsDataHexStrings{ ID::splits_DataHexStrings },
	splitsNameStrings{ ID::splits_NameStrings }
{
	fillSplitsHexDataStrings();
	fillSplitsNameStrings();
	splitsDataHexStrings.addListener(this);
}

void SplitsBank::fillSplitsHexDataStrings() {
	for (uint8 splitSlot = 0; splitSlot != splitSlotOutOfRange(); ++splitSlot) {
		splitsDataHexStrings.setProperty("split" + (String)splitSlot, splits::initialSplitDataHexString, nullptr);
	}
}

void SplitsBank::fillSplitsNameStrings() {
	for (uint8 splitSlot = 0; splitSlot != splitSlotOutOfRange(); ++splitSlot) {
		splitsNameStrings.setProperty("split" + (String)splitSlot, splits::initialSplitNameString, nullptr);
	}
}

int SplitsBank::splitSlotOutOfRange() {
	return splits::numberOfSlotsInBank;
}

const String SplitsBank::nameOfSplitInSlot(uint8 slot) {
	jassert(slot < splits::numberOfSlotsInBank);
	return splitsNameStrings.getProperty("split" + (String)slot);
}

const String SplitsBank::getSplitDataHexStringFromSlot(uint8 slot) const {
	jassert(slot < splits::numberOfSlotsInBank);
	return splitsDataHexStrings.getProperty("split" + (String)slot);
}

void SplitsBank::storeSplitDataHexStringInSlot(String splitDataHexString, uint8 slot) {
	jassert(slot < splits::numberOfSlotsInBank);
	splitsDataHexStrings.setProperty("split" + (String)slot, splitDataHexString, nullptr);
}

void SplitsBank::addListenerToSplitsNameStrings(ValueTree::Listener* listener) {
	splitsNameStrings.addListener(listener);
}

void SplitsBank::removeListenerFromSplitsNameStrings(ValueTree::Listener* listener) {
	splitsNameStrings.removeListener(listener);
}

void SplitsBank::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (tree.hasType(ID::splits_DataHexStrings)) {
		auto propertyName{ property.toString() };
		auto slotString{ propertyName.fromLastOccurrenceOf("split", false, true) };
		auto slot{ (uint8)slotString.getIntValue() };
		auto splitDataHexString{ getSplitDataHexStringFromSlot(slot) };
		auto splitName{ RawDataTools::extractSplitNameFromRawSplitData(RawDataTools::convertPatchOrSplitHexStringToDataVector(splitDataHexString).data()) };
		splitsNameStrings.setProperty(property, splitName, nullptr);
	}
}

XmlElement* SplitsBank::getStateXml() {
	auto splitBankStateXml{ splitsDataHexStrings.createXml() };
	splitBankStateXml->setTagName(ID::state_SplitBanks);
	return splitBankStateXml.release();
}

void SplitsBank::replaceState(const ValueTree& newState) {
	splitsDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_SplitBanks), nullptr);
}

SplitsBank::~SplitsBank() {
	splitsDataHexStrings.removeListener(this);
}
