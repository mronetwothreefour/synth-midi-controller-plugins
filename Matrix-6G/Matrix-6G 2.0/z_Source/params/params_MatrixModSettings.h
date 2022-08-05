#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class MatrixModSettings
{
	UnexposedParameters* unexposedParams;
	ValueTree matrixModSettingsTree;

public:
	const int lsbByteLocationForModulation0Source{ 212 };
	const int lsbByteLocationForModulation0Amount{ 214 };
	const int lsbByteLocationForModulation0Destination{ 216 };

	MatrixModSettings() = delete;

	explicit MatrixModSettings(UnexposedParameters* unexposedParams);

private:
	void fillMatrixModSettingsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 sourceSettingForModulation(int modNumber);
	void setSourceForModulation(uint8 source, int modNumber);
	const uint8 amountSettingForModulation(int modNumber);
	void setAmountForModulation(uint8 amount, int modNumber);
	const uint8 destinationSettingForModulation(int modNumber);
	void setDestinationForModulation(uint8 destination, int modNumber);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MatrixModSettings)
};