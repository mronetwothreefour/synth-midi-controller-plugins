#include "pgmData_ProgramDataBank.h"

#include "pgmData_Constants.h"
#include "pgmData_FactoryPgmDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"

using namespace constants;



ProgramDataBank::ProgramDataBank() :
	pgmDataHexStrings{ ID::pgmData_Bank }
{
	fillPgmDataHexStrings();
}

void ProgramDataBank::fillPgmDataHexStrings() {
	auto& factoryPgmDataHexStrings{ FactoryProgramDataHexStrings::get() };
	auto factoryPgmDataBank{ factoryPgmDataHexStrings.getFactoryPgmDataBank() };
	for (uint8 pgmSlot = 0; pgmSlot != pgmSlotOutOfRange(); ++pgmSlot) {
		auto pgmDataHexString{ factoryPgmDataBank[pgmSlot] };
		pgmDataHexStrings.setProperty("pgm" + (String)pgmSlot, pgmDataHexString, nullptr);
	}
}

int ProgramDataBank::pgmSlotOutOfRange() {
	auto& factoryPgmDataHexStrings{ FactoryProgramDataHexStrings::get() };
	return factoryPgmDataHexStrings.pgmSlotOutOfRange();
}

const String ProgramDataBank::nameOfPgmInSlot(uint8 slot) {
	jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
	auto pgmDataHexString{ pgmDataHexStrings.getProperty("pgm" + (String)slot).toString() };
	auto nameString{ pgmDataHexString.substring(pgmData::indexOfFirstNameCharInPgmDataHexString) };
	return nameString;
}

void ProgramDataBank::setNameOfPgmInSlot(String newName, uint8 slot) {
	jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
	auto oldPgmDataHexString{ pgmDataHexStrings.getProperty("pgm" + (String)slot).toString() };
	auto newPgmDataHexString{ oldPgmDataHexString.substring(0, pgmData::indexOfFirstNameCharInPgmDataHexString) };
	newPgmDataHexString.append(newName, pgmData::maxLengthOfPgmName);
	pgmDataHexStrings.setProperty("pgm" + (String)slot, newPgmDataHexString, nullptr);
}

const String ProgramDataBank::getPgmDataHexStringFromSlot(uint8 slot) const {
	jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
	return pgmDataHexStrings.getProperty("pgm" + (String)slot).toString();
}

void ProgramDataBank::storePgmDataHexStringInSlot(String pgmDataHexString, uint8 slot) {
	jassert(slot < pgmData::numberOfSlotsInPgmDataBank);
	pgmDataHexStrings.setProperty("pgm" + (String)slot, pgmDataHexString, nullptr);
}

XmlElement* ProgramDataBank::getStateXml() {
	auto pgmDataBankStateXml{ pgmDataHexStrings.createXml() };
	pgmDataBankStateXml->setTagName(ID::state_PgmDataBank);
	return pgmDataBankStateXml.release();
}

void ProgramDataBank::replaceState(const ValueTree& newState) {
	pgmDataHexStrings.copyPropertiesAndChildrenFrom(newState, nullptr);
}
