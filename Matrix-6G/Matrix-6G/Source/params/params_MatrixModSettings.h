#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class MatrixModSettings
{
	UnexposedParameters* unexposedParams;
	ValueTree matrixModSettingsTree;

public:
	MatrixModSettings() = delete;

	explicit MatrixModSettings(UnexposedParameters* unexposedParams);

private:
	void fillMatrixModSettingsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 sourceSettingForModulation(int modNumber);
	void setSourceForModulation(uint8 source, int modNumber);
	const int8 amountSettingForModulation(int modNumber);
	void setAmountForModulation(int8 amount, int modNumber);
	const uint8 destinationSettingForModulation(int modNumber);
	void setDestinationForModulation(uint8 destination, int modNumber);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModSettings)
};