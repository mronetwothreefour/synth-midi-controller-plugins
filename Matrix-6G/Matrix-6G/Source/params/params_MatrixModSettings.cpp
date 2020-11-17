#include "params_MatrixModSettings.h"

#include "params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"




MatrixModSettings::MatrixModSettings(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	matrixModSettingsTree{ ID::matrixMod_Settings }
{
	fillMatrixModSettingsTreeWithProperties();
}

void MatrixModSettings::fillMatrixModSettingsTreeWithProperties() {
	for (auto i = 0; i != 10; ++i)
	{
		uint8 defaultSource{ (uint8)0 };
		uint8 defaultDestination{ (uint8)0 };
		switch (i)
		{
		case 0:
			defaultSource = (uint8)17;
			defaultDestination = (uint8)21;
			break;
		case 1:
			defaultSource = (uint8)11;
			defaultDestination = (uint8)9;
			break;
		case 2:
			defaultSource = (uint8)20;
			defaultDestination = (uint8)8;
			break;
		default:
			break;
		}
		matrixModSettingsTree.setProperty("matrixMod_SourceForMod_" + (String)i, defaultSource, nullptr);
		matrixModSettingsTree.setProperty("matrixMod_AmountForMod_" + (String)i, (int8)0, nullptr);
		matrixModSettingsTree.setProperty("matrixMod_DestinationForMod_" + (String)i, defaultDestination, nullptr);
	}
}

void MatrixModSettings::addListener(ValueTree::Listener* listener) {
	matrixModSettingsTree.addListener(listener);
}

void MatrixModSettings::removeListener(ValueTree::Listener* listener) {
	matrixModSettingsTree.removeListener(listener);
}

const uint8 MatrixModSettings::sourceSettingForModulation(int modNumber) {
	return (uint8)(int)matrixModSettingsTree.getProperty("matrixMod_SourceForMod_" + (String)modNumber);
}

void MatrixModSettings::setSourceForModulation(uint8 source, int modNumber) {
	jassert(source < 21);
	jassert(modNumber < 10);
	matrixModSettingsTree.setProperty("matrixMod_SourceForMod_" + (String)modNumber, source, unexposedParams->undoManager_get());
}

const int8 MatrixModSettings::amountSettingForModulation(int modNumber) {
	return (int8)(int)matrixModSettingsTree.getProperty("matrixMod_AmountForMod_" + (String)modNumber);
}

void MatrixModSettings::setAmountForModulation(int8 amount, int modNumber) {
	jassert(amount > -64 && amount < 64);
	jassert(modNumber < 10);
	matrixModSettingsTree.setProperty("matrixMod_AmountForMod_" + (String)modNumber, amount, unexposedParams->undoManager_get());
}

const uint8 MatrixModSettings::destinationSettingForModulation(int modNumber) {
	return (uint8)(int)matrixModSettingsTree.getProperty("matrixMod_DestinationForMod_" + (String)modNumber);
}

void MatrixModSettings::setDestinationForModulation(uint8 destination, int modNumber) {
	jassert(destination < 33);
	jassert(modNumber < 10);
	matrixModSettingsTree.setProperty("matrixMod_DestinationForMod_" + (String)modNumber, destination, unexposedParams->undoManager_get());
}
