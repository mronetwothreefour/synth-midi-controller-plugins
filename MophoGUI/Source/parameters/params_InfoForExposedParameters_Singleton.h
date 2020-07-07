#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"



class InfoForExposedParameters_Singleton
{
	std::map<Identifier, uint8> identifierToIndexMap;
	Array<String> publicNames;
	Array<ControlType> controlTypes;
	Array<uint16> NRPNs;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<String> descriptions;
	Array<Point<int>> ctrlCenterPoint;
	Array<int> ctrlWidths;
	Array<int> ctrlHeights;

	InfoForExposedParameters_Singleton();
	~InfoForExposedParameters_Singleton();

	void fillAllInfoContainers();

public:
	InfoForExposedParameters_Singleton(InfoForExposedParameters_Singleton&&) = delete;
	InfoForExposedParameters_Singleton& operator=(InfoForExposedParameters_Singleton&&) = delete;

	static InfoForExposedParameters_Singleton& get();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters_Singleton)
};