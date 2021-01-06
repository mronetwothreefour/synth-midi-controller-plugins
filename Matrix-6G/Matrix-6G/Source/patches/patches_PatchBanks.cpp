#include "patches_PatchBanks.h"

#include "patches_Constants.h"
#include "patches_FactoryPatchDataHexStrings_Singleton.h"
#include "patches_RawPatchData.h"
#include "../params/params_Identifiers.h"

using namespace constants;



PatchBanks::PatchBanks() :
	analogSynthsBankApatchNameStrings{ ID::bank_AnalogSynthsA_PatchNameStrings },
	analogSynthsBankBpatchNameStrings{ ID::bank_AnalogSynthsB_PatchNameStrings },
	bassesBankPatchNameStrings{ ID::bank_Basses_PatchNameStrings },
	brassAndWoodwindsBankPatchNameStrings{ ID::bank_BrassAndWoodwinds_PatchNameStrings },
	customBankApatchDataHexStrings{ ID::bank_CustomA_PatchDataHexStrings },
	customBankApatchNameStrings{ ID::bank_CustomA_PatchNameStrings },
	customBankBpatchDataHexStrings{ ID::bank_CustomB_PatchDataHexStrings },
	customBankBpatchNameStrings{ ID::bank_CustomB_PatchNameStrings },
	fxAndPercussionBankPatchNameStrings{ ID::bank_FXandPercussion_PatchNameStrings },
	keyboardsBankApatchNameStrings{ ID::bank_KeyboardsA_PatchNameStrings },
	keyboardsBankBpatchNameStrings{ ID::bank_KeyboardsB_PatchNameStrings },
	leadsBankPatchNameStrings{ ID::bank_Leads_PatchNameStrings },
	miscellaneousBankApatchNameStrings{ ID::bank_MiscellaneousA_PatchNameStrings },
	miscellaneousBankBpatchNameStrings{ ID::bank_MiscellaneousB_PatchNameStrings },
	stringsBankPatchNameStrings{ ID::bank_Strings_PatchNameStrings }
{
	fillAllCustomPatchDataBanks();
	fillAllPatchNameBanks();
	customBankApatchDataHexStrings.addListener(this);
	customBankBpatchDataHexStrings.addListener(this);
}

void PatchBanks::fillAllCustomPatchDataBanks() {
	for (uint8 patchSlot = 0; patchSlot != patchSlotOutOfRange(); ++patchSlot) {
		customBankApatchDataHexStrings.setProperty("pgm" + (String)patchSlot, patches::basicPatchDataHexString, nullptr);
		customBankBpatchDataHexStrings.setProperty("pgm" + (String)patchSlot, patches::basicPatchDataHexString, nullptr);
	}
}

void PatchBanks::fillAllPatchNameBanks() {
	String patchName;
	String patchDataString;
	for (uint8 programSlot = 0; programSlot != patchSlotOutOfRange(); ++programSlot) {
		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsA, programSlot);
		patchName = RawPatchData::RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		analogSynthsBankApatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsB, programSlot);
		patchName = RawPatchData::RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		analogSynthsBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::basses, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		bassesBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::brassAndWoodwinds, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		brassAndWoodwindsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::fxAndPercussion, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		fxAndPercussionBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsA, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		keyboardsBankApatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsB, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		keyboardsBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::leads, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		leadsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::miscellaneousA, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		miscellaneousBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::strings, programSlot);
		patchName = RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataString).data());
		stringsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		customBankApatchNameStrings.setProperty("pgm" + (String)programSlot, patches::basicPatchNameString, nullptr);
		customBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patches::basicPatchNameString, nullptr);
	}
}

int PatchBanks::patchSlotOutOfRange() {
	auto& factoryPatchDataHexStrings{ FactoryPatchDataHexStrings::get() };
	return factoryPatchDataHexStrings.patchSlotOutOfRange();
}

const String PatchBanks::nameOfPatchInBankSlot(PatchBank bank, uint8 slot) {
	jassert(slot < 128);
	switch (bank)
	{
	case PatchBank::analogSynthsA:
		return analogSynthsBankApatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::analogSynthsB:
		return analogSynthsBankBpatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::basses:
		return bassesBankPatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::brassAndWoodwinds:
		return brassAndWoodwindsBankPatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::customA:
		return customBankApatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::customB:
		return customBankBpatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::fxAndPercussion:
		return fxAndPercussionBankPatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::keyboardsA:
		return keyboardsBankApatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::keyboardsB:
		return keyboardsBankBpatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::leads:
		return leadsBankPatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::miscellaneousA:
		return miscellaneousBankApatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::miscellaneousB:
		return miscellaneousBankBpatchNameStrings.getProperty("pgm" + (String)slot);
	case PatchBank::strings:
		return stringsBankPatchNameStrings.getProperty("pgm" + (String)slot);
	default:
		return "error";
	}
}

const String PatchBanks::getPatchDataHexStringFromBankSlot(PatchBank bank, uint8 slot) const {
	jassert(slot < 128);
	auto& factoryPatchDataHexStrings{ FactoryPatchDataHexStrings::get() };
	switch (bank)
	{
	case PatchBank::analogSynthsA:
		return factoryPatchDataHexStrings.getAnalogSynthsBankA()[slot];
	case PatchBank::analogSynthsB:
		return factoryPatchDataHexStrings.getAnalogSynthsBankB()[slot];
	case PatchBank::basses:
		return factoryPatchDataHexStrings.getBassesBank()[slot];
	case PatchBank::brassAndWoodwinds:
		return factoryPatchDataHexStrings.getBrassAndWoodwindsBank()[slot];
	case PatchBank::customA:
		return customBankApatchDataHexStrings.getProperty("pgm" + (String)slot);
	case PatchBank::customB:
		return customBankBpatchDataHexStrings.getProperty("pgm" + (String)slot);
	case PatchBank::fxAndPercussion:
		return factoryPatchDataHexStrings.getFXandPercussionBank()[slot];
	case PatchBank::keyboardsA:
		return factoryPatchDataHexStrings.getKeyboardsBankA()[slot];
	case PatchBank::keyboardsB:
		return factoryPatchDataHexStrings.getKeyboardsBankB()[slot];
	case PatchBank::leads:
		return factoryPatchDataHexStrings.getLeadsBank()[slot];
	case PatchBank::miscellaneousA:
		return factoryPatchDataHexStrings.getMiscellaneousBankA()[slot];
	case PatchBank::miscellaneousB:
		return factoryPatchDataHexStrings.getMiscellaneousBankB()[slot];
	case PatchBank::strings:
		return factoryPatchDataHexStrings.getStringsBank()[slot];
	default:
		return "error";
	}
}

void PatchBanks::storePatchDataHexStringInCustomBankSlot(String patchDataHexString, PatchBank bank, uint8 slot) {
	jassert(bank == PatchBank::customA || bank == PatchBank::customB);
	jassert(slot < 100);
	switch (bank)
	{
	case PatchBank::customA:
		customBankApatchDataHexStrings.setProperty("pgm" + (String)slot, patchDataHexString, nullptr);
		break;
	case PatchBank::customB:
		customBankBpatchDataHexStrings.setProperty("pgm" + (String)slot, patchDataHexString, nullptr);
		break;
	default:
		break;
	}
}

void PatchBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, PatchBank bank) {
	jassert(bank == PatchBank::customA || bank == PatchBank::customB);
	switch (bank)
	{
	case PatchBank::customA:
		customBankApatchNameStrings.addListener(listener);
		break;
	case PatchBank::customB:
		customBankBpatchNameStrings.addListener(listener);
		break;
	default:
		break;
	}
}

void PatchBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, PatchBank bank) {
	jassert(bank == PatchBank::customA || bank == PatchBank::customB);
	switch (bank)
	{
	case PatchBank::customA:
		customBankApatchNameStrings.removeListener(listener);
		break;
	case PatchBank::customB:
		customBankBpatchNameStrings.removeListener(listener);
		break;
	default:
		break;
	}
}

void PatchBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_CustomA_PatchDataHexStrings)) {
		auto patchDataHexString{ getPatchDataHexStringFromBankSlot(PatchBank::customA, slot) };
		auto patchName{ RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataHexString).data()) };
		customBankApatchNameStrings.setProperty(property, patchName, nullptr);
	}
	if (tree.hasType(ID::bank_CustomB_PatchDataHexStrings)) {
		auto patchDataHexString{ getPatchDataHexStringFromBankSlot(PatchBank::customB, slot) };
		auto patchName{ RawPatchData::extractPatchNameFromRawPatchData(RawPatchData::convertHexStringToDataVector(patchDataHexString).data()) };
		customBankBpatchNameStrings.setProperty(property, patchName, nullptr);
	}
}

XmlElement* PatchBanks::getStateXml() {
	auto customPatchBanksStateXml{ std::make_unique<XmlElement>(ID::state_CustomPatchBanks) };
	auto customBankAStateXml{ customBankApatchDataHexStrings.createXml() };
	auto customBankBStateXml{ customBankBpatchDataHexStrings.createXml() };
	customBankAStateXml->setTagName(ID::state_CustomPatchBankA);
	customBankBStateXml->setTagName(ID::state_CustomPatchBankB);
	customPatchBanksStateXml->addChildElement(customBankAStateXml.release());
	customPatchBanksStateXml->addChildElement(customBankBStateXml.release());
	return customPatchBanksStateXml.release();
}

void PatchBanks::replaceState(const ValueTree& newState) {
	customBankApatchDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomPatchBankA), nullptr);
	customBankBpatchDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomPatchBankB), nullptr);
}

PatchBanks::~PatchBanks() {
	customBankApatchDataHexStrings.removeListener(this);
	customBankBpatchDataHexStrings.removeListener(this);
}
