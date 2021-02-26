#include "patches_PatchBanks.h"

#include "patches_Constants.h"
#include "patches_FactoryPatchDataHexStrings_Singleton.h"
#include "../midi/midi_RawDataTools.h"
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
		customBankApatchDataHexStrings.setProperty("patch" + (String)patchSlot, patches::basicPatchDataHexString, nullptr);
		customBankBpatchDataHexStrings.setProperty("patch" + (String)patchSlot, patches::basicPatchDataHexString, nullptr);
	}
}

void PatchBanks::fillAllPatchNameBanks() {
	String patchName;
	String patchDataString;
	for (uint8 patchSlot = 0; patchSlot != patchSlotOutOfRange(); ++patchSlot) {
		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsA, patchSlot);
		patchName = RawDataTools::RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		analogSynthsBankApatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsB, patchSlot);
		patchName = RawDataTools::RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		analogSynthsBankBpatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::basses, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		bassesBankPatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::brassAndWoodwinds, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		brassAndWoodwindsBankPatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::fxAndPercussion, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		fxAndPercussionBankPatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsA, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		keyboardsBankApatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsB, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		keyboardsBankBpatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::leads, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		leadsBankPatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::miscellaneousA, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		miscellaneousBankBpatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::strings, patchSlot);
		patchName = RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataString).data());
		stringsBankPatchNameStrings.setProperty("patch" + (String)patchSlot, patchName, nullptr);

		customBankApatchNameStrings.setProperty("patch" + (String)patchSlot, patches::basicPatchNameString, nullptr);
		customBankBpatchNameStrings.setProperty("patch" + (String)patchSlot, patches::basicPatchNameString, nullptr);
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
		return analogSynthsBankApatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::analogSynthsB:
		return analogSynthsBankBpatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::basses:
		return bassesBankPatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::brassAndWoodwinds:
		return brassAndWoodwindsBankPatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::customA:
		return customBankApatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::customB:
		return customBankBpatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::fxAndPercussion:
		return fxAndPercussionBankPatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::keyboardsA:
		return keyboardsBankApatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::keyboardsB:
		return keyboardsBankBpatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::leads:
		return leadsBankPatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::miscellaneousA:
		return miscellaneousBankApatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::miscellaneousB:
		return miscellaneousBankBpatchNameStrings.getProperty("patch" + (String)slot);
	case PatchBank::strings:
		return stringsBankPatchNameStrings.getProperty("patch" + (String)slot);
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
		return customBankApatchDataHexStrings.getProperty("patch" + (String)slot);
	case PatchBank::customB:
		return customBankBpatchDataHexStrings.getProperty("patch" + (String)slot);
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
		customBankApatchDataHexStrings.setProperty("patch" + (String)slot, patchDataHexString, nullptr);
		break;
	case PatchBank::customB:
		customBankBpatchDataHexStrings.setProperty("patch" + (String)slot, patchDataHexString, nullptr);
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
	auto slotString{ propertyName.fromLastOccurrenceOf("patch", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_CustomA_PatchDataHexStrings)) {
		auto patchDataHexString{ getPatchDataHexStringFromBankSlot(PatchBank::customA, slot) };
		auto patchName{ RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataHexString).data()) };
		customBankApatchNameStrings.setProperty(property, patchName, nullptr);
	}
	if (tree.hasType(ID::bank_CustomB_PatchDataHexStrings)) {
		auto patchDataHexString{ getPatchDataHexStringFromBankSlot(PatchBank::customB, slot) };
		auto patchName{ RawDataTools::extractPatchNameFromRawPatchData(RawDataTools::convertHexStringToDataVector(patchDataHexString).data()) };
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
