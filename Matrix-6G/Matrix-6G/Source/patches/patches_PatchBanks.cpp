#include "patches_PatchBanks.h"

#include "patches_ConvertRawPatchDataFormat.h"
#include "patches_FactoryPatchDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"



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
		customBankApatchDataHexStrings.setProperty("pgm" + (String)patchSlot, basicPatchDataHexString, nullptr);
		customBankBpatchDataHexStrings.setProperty("pgm" + (String)patchSlot, basicPatchDataHexString, nullptr);
	}
}

void PatchBanks::fillAllPatchNameBanks() {
	String patchName;
	String patchDataString;
	for (uint8 programSlot = 0; programSlot != patchSlotOutOfRange(); ++programSlot) {
		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsA, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		analogSynthsBankApatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::analogSynthsB, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		analogSynthsBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::basses, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		bassesBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::brassAndWoodwinds, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		brassAndWoodwindsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::fxAndPercussion, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		fxAndPercussionBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsA, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		keyboardsBankApatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::keyboardsB, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		keyboardsBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::leads, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		leadsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::miscellaneousA, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		miscellaneousBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		patchDataString = getPatchDataHexStringFromBankSlot(PatchBank::strings, programSlot);
		patchName = extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataString));
		stringsBankPatchNameStrings.setProperty("pgm" + (String)programSlot, patchName, nullptr);

		customBankApatchNameStrings.setProperty("pgm" + (String)programSlot, basicPatchNameString, nullptr);
		customBankBpatchNameStrings.setProperty("pgm" + (String)programSlot, basicPatchNameString, nullptr);
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
		analogSynthsBankApatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::analogSynthsB:
		analogSynthsBankBpatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::basses:
		bassesBankPatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::brassAndWoodwinds:
		brassAndWoodwindsBankPatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::customA:
		customBankApatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::customB:
		customBankBpatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::fxAndPercussion:
		fxAndPercussionBankPatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::keyboardsA:
		keyboardsBankApatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::keyboardsB:
		keyboardsBankBpatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::leads:
		leadsBankPatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::miscellaneousA:
		miscellaneousBankApatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::miscellaneousB:
		miscellaneousBankBpatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::strings:
		stringsBankPatchNameStrings.getProperty("pgm" + (String)slot);
		break;
	default:
		return "error";
		break;
	}
}

const String PatchBanks::getPatchDataHexStringFromBankSlot(PatchBank bank, uint8 slot) const {
	jassert(slot < 128);
	auto& factoryPatchDataHexStrings{ FactoryPatchDataHexStrings::get() };
	String patchDataHexString;
	switch (bank)
	{
	case PatchBank::analogSynthsA:
		patchDataHexString = factoryPatchDataHexStrings.getAnalogSynthsBankA()[slot];
		break;
	case PatchBank::analogSynthsB:
		patchDataHexString = factoryPatchDataHexStrings.getAnalogSynthsBankB()[slot];
		break;
	case PatchBank::basses:
		patchDataHexString = factoryPatchDataHexStrings.getBassesBank()[slot];
		break;
	case PatchBank::brassAndWoodwinds:
		patchDataHexString = factoryPatchDataHexStrings.getBrassAndWoodwindsBank()[slot];
		break;
	case PatchBank::customA:
		patchDataHexString = customBankApatchDataHexStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::customB:
		patchDataHexString = customBankBpatchDataHexStrings.getProperty("pgm" + (String)slot);
		break;
	case PatchBank::fxAndPercussion:
		patchDataHexString = factoryPatchDataHexStrings.getFXandPercussionBank()[slot];
		break;
	case PatchBank::keyboardsA:
		patchDataHexString = factoryPatchDataHexStrings.getKeyboardsBankA()[slot];
		break;
	case PatchBank::keyboardsB:
		patchDataHexString = factoryPatchDataHexStrings.getKeyboardsBankB()[slot];
		break;
	case PatchBank::leads:
		patchDataHexString = factoryPatchDataHexStrings.getLeadsBank()[slot];
		break;
	case PatchBank::miscellaneousA:
		patchDataHexString = factoryPatchDataHexStrings.getMiscellaneousBankA()[slot];
		break;
	case PatchBank::miscellaneousB:
		patchDataHexString = factoryPatchDataHexStrings.getMiscellaneousBankB()[slot];
		break;
	case PatchBank::strings:
		patchDataHexString = factoryPatchDataHexStrings.getStringsBank()[slot];
		break;
	default:
		return {};
	}
	return patchDataHexString;
}

const String PatchBanks::extractPatchNameFromDataVector(const std::vector<uint8>& dataVector) {
	String patchName{ "" };
	auto data{ dataVector.data() };
	for (auto byte = 0; byte != 16; byte += 2) {
		auto lsbByteValue{ (char)data[byte] };
		auto msbByteValue{ (char)data[byte + 1] };
		auto asciiValueTruncatedToLowest6Bits{ char(lsbByteValue + (msbByteValue * 16)) };
		auto matrixValueForBarSymbol{ (char)29 };
		if (asciiValueTruncatedToLowest6Bits == matrixValueForBarSymbol)
			patchName += "|";
		else {
			auto offsetForTruncatedASCII{ (char)64 };
			auto patchNameCharASCIIValue = char(asciiValueTruncatedToLowest6Bits + offsetForTruncatedASCII);
			patchName += (String)std::string(1, patchNameCharASCIIValue);
		}
	}
	return patchName;
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
		customBankApatchNameStrings.addListener(this);
		break;
	case PatchBank::customB:
		customBankBpatchNameStrings.addListener(this);
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
		customBankApatchNameStrings.removeListener(this);
		break;
	case PatchBank::customB:
		customBankBpatchNameStrings.removeListener(this);
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
		auto patchName{ extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataHexString)) };
		customBankApatchNameStrings.setProperty(property, patchName, nullptr);
	}
	if (tree.hasType(ID::bank_CustomB_PatchDataHexStrings)) {
		auto patchDataHexString{ getPatchDataHexStringFromBankSlot(PatchBank::customB, slot) };
		auto patchName{ extractPatchNameFromDataVector(ConvertRawPatchDataFormat::hexStringToDataVector(patchDataHexString)) };
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
