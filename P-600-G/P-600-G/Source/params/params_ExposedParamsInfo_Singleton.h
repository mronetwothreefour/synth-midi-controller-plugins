#pragma once

#include <JuceHeader.h>



enum class ControlType;

class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<ControlType> controlTypes;
	Array<String> descriptions;
	Array<Point<int>> controlCenterPoints;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<uint8> firstNybbleIndices;
	Array<uint8> firstBitIndices;

	InfoForExposedParameters();
	void fillAllInfoContainers();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;
};