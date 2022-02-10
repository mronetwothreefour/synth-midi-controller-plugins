#include "voices_VoicesBanks.h"

#include "voices_Constants.h"
#include "voices_FactoryVoiceDataHexStrings_Singleton.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"

using namespace constants;



VoicesBanks::VoicesBanks() :
	analogSynthsBankAvoiceNameStrings{ ID::bank_AnalogSynthsA_VoiceNameStrings },
	analogSynthsBankBvoiceNameStrings{ ID::bank_AnalogSynthsB_VoiceNameStrings },
	bassesBankVoiceNameStrings{ ID::bank_Basses_VoiceNameStrings },
	brassAndWoodwindsBankVoiceNameStrings{ ID::bank_BrassAndWoodwinds_VoiceNameStrings },
	customBankAvoiceDataHexStrings{ ID::bank_CustomA_VoiceDataHexStrings },
	customBankAvoiceNameStrings{ ID::bank_CustomA_VoiceNameStrings },
	customBankBvoiceDataHexStrings{ ID::bank_CustomB_VoiceDataHexStrings },
	customBankBvoiceNameStrings{ ID::bank_CustomB_VoiceNameStrings },
	fxAndPercussionBankVoiceNameStrings{ ID::bank_FXandPercussion_VoiceNameStrings },
	keyboardsBankAvoiceNameStrings{ ID::bank_KeyboardsA_VoiceNameStrings },
	keyboardsBankBvoiceNameStrings{ ID::bank_KeyboardsB_VoiceNameStrings },
	leadsBankVoiceNameStrings{ ID::bank_Leads_VoiceNameStrings },
	miscellaneousBankAvoiceNameStrings{ ID::bank_MiscellaneousA_VoiceNameStrings },
	miscellaneousBankBvoiceNameStrings{ ID::bank_MiscellaneousB_VoiceNameStrings },
	stringsBankVoiceNameStrings{ ID::bank_Strings_VoiceNameStrings }
{
	fillAllCustomVoiceDataBanks();
	fillAllVoiceNameBanks();
	customBankAvoiceDataHexStrings.addListener(this);
	customBankBvoiceDataHexStrings.addListener(this);
}

void VoicesBanks::fillAllCustomVoiceDataBanks() {
	for (uint8 slot = 0; slot != slotOutOfRange(); ++slot) {
		customBankAvoiceDataHexStrings.setProperty("voice" + (String)slot, voices::basicVoiceDataHexString, nullptr);
		customBankBvoiceDataHexStrings.setProperty("voice" + (String)slot, voices::basicVoiceDataHexString, nullptr);
	}
}

void VoicesBanks::fillAllVoiceNameBanks() {
	String voiceName;
	String voiceDataString;
	for (uint8 slot = 0; slot != slotOutOfRange(); ++slot) {
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::analogSynthsA, slot);
		voiceName = RawDataTools::RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		analogSynthsBankAvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::analogSynthsB, slot);
		voiceName = RawDataTools::RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		analogSynthsBankBvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::basses, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		bassesBankVoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::brassAndWoodwinds, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		brassAndWoodwindsBankVoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::fxAndPercussion, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		fxAndPercussionBankVoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::keyboardsA, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		keyboardsBankAvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::keyboardsB, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		keyboardsBankBvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::leads, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		leadsBankVoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::miscellaneousA, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		miscellaneousBankAvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::miscellaneousB, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		miscellaneousBankBvoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::strings, slot);
		voiceName = RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataString).data());
		stringsBankVoiceNameStrings.setProperty("voice" + (String)slot, voiceName, nullptr);

		customBankAvoiceNameStrings.setProperty("voice" + (String)slot, voices::basicVoiceNameString, nullptr);
		customBankBvoiceNameStrings.setProperty("voice" + (String)slot, voices::basicVoiceNameString, nullptr);
	}
}

int VoicesBanks::slotOutOfRange() {
	auto& factoryVoiceDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	return factoryVoiceDataHexStrings.slotOutOfRange();
}

const String VoicesBanks::nameOfVoiceInBankSlot(VoicesBank bank, uint8 slot) {
	jassert(slot < voices::numberOfSlotsInBank);
	switch (bank)
	{
	case VoicesBank::analogSynthsA:
		return analogSynthsBankAvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::analogSynthsB:
		return analogSynthsBankBvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::basses:
		return bassesBankVoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::brassAndWoodwinds:
		return brassAndWoodwindsBankVoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::customA:
		return customBankAvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::customB:
		return customBankBvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::fxAndPercussion:
		return fxAndPercussionBankVoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::keyboardsA:
		return keyboardsBankAvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::keyboardsB:
		return keyboardsBankBvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::leads:
		return leadsBankVoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::miscellaneousA:
		return miscellaneousBankAvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::miscellaneousB:
		return miscellaneousBankBvoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::strings:
		return stringsBankVoiceNameStrings.getProperty("voice" + (String)slot);
	default:
		return "error";
	}
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slot) const {
	jassert(slot < voices::numberOfSlotsInBank);
	auto& factoryVoiceDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	switch (bank)
	{
	case VoicesBank::analogSynthsA:
		return factoryVoiceDataHexStrings.getAnalogSynthsBankA()[slot];
	case VoicesBank::analogSynthsB:
		return factoryVoiceDataHexStrings.getAnalogSynthsBankB()[slot];
	case VoicesBank::basses:
		return factoryVoiceDataHexStrings.getBassesBank()[slot];
	case VoicesBank::brassAndWoodwinds:
		return factoryVoiceDataHexStrings.getBrassAndWoodwindsBank()[slot];
	case VoicesBank::customA:
		return customBankAvoiceDataHexStrings.getProperty("voice" + (String)slot);
	case VoicesBank::customB:
		return customBankBvoiceDataHexStrings.getProperty("voice" + (String)slot);
	case VoicesBank::fxAndPercussion:
		return factoryVoiceDataHexStrings.getFXandPercussionBank()[slot];
	case VoicesBank::keyboardsA:
		return factoryVoiceDataHexStrings.getKeyboardsBankA()[slot];
	case VoicesBank::keyboardsB:
		return factoryVoiceDataHexStrings.getKeyboardsBankB()[slot];
	case VoicesBank::leads:
		return factoryVoiceDataHexStrings.getLeadsBank()[slot];
	case VoicesBank::miscellaneousA:
		return factoryVoiceDataHexStrings.getMiscellaneousBankA()[slot];
	case VoicesBank::miscellaneousB:
		return factoryVoiceDataHexStrings.getMiscellaneousBankB()[slot];
	case VoicesBank::strings:
		return factoryVoiceDataHexStrings.getStringsBank()[slot];
	default:
		return "error";
	}
}

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slot) {
	jassert(bank == VoicesBank::customA || bank == VoicesBank::customB);
	jassert(slot < voices::numberOfSlotsInBank);
	switch (bank)
	{
	case VoicesBank::customA:
		customBankAvoiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
		break;
	case VoicesBank::customB:
		customBankBvoiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
		break;
	default:
		break;
	}
}

void VoicesBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::customA || bank == VoicesBank::customB);
	switch (bank)
	{
	case VoicesBank::customA:
		customBankAvoiceNameStrings.addListener(listener);
		break;
	case VoicesBank::customB:
		customBankBvoiceNameStrings.addListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::customA || bank == VoicesBank::customB);
	switch (bank)
	{
	case VoicesBank::customA:
		customBankAvoiceNameStrings.removeListener(listener);
		break;
	case VoicesBank::customB:
		customBankBvoiceNameStrings.removeListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("voice", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_CustomA_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::customA, slot) };
		auto voiceName{ RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataHexString).data()) };
		customBankAvoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
	if (tree.hasType(ID::bank_CustomB_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::customB, slot) };
		auto voiceName{ RawDataTools::extractVoiceNameFromRawVoiceData(RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataHexString).data()) };
		customBankBvoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
}

XmlElement* VoicesBanks::getStateXml() {
	auto customVoicesBanksStateXml{ std::make_unique<XmlElement>(ID::state_CustomVoicesBanks) };
	auto customBankAStateXml{ customBankAvoiceDataHexStrings.createXml() };
	auto customBankBStateXml{ customBankBvoiceDataHexStrings.createXml() };
	customBankAStateXml->setTagName(ID::state_CustomVoicesBankA);
	customBankBStateXml->setTagName(ID::state_CustomVoicesBankB);
	customVoicesBanksStateXml->addChildElement(customBankAStateXml.release());
	customVoicesBanksStateXml->addChildElement(customBankBStateXml.release());
	return customVoicesBanksStateXml.release();
}

void VoicesBanks::replaceState(const ValueTree& newState) {
	customBankAvoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBankA), nullptr);
	customBankBvoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBankB), nullptr);
}

VoicesBanks::~VoicesBanks() {
	customBankAvoiceDataHexStrings.removeListener(this);
	customBankBvoiceDataHexStrings.removeListener(this);
}
