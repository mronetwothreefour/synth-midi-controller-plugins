#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"



class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<ControlType> controlTypes;
	Array<uint16> NRPNs;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<String> descriptions;
	Array<Point<int>> ctrlCenterPoints;
	Array<int> ctrlWidths;
	Array<int> ctrlHeights;

	InfoForExposedParameters();
	void fillAllInfoContainers();
	~InfoForExposedParameters();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	uint16 NRPNfor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	uint8 defaultValueFor(uint8 paramIndex) const;
	uint16 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> ctrlCenterPointFor(uint8 paramIndex) const;
	int ctrlWidthFor(uint8 paramIndex) const;
	int ctrlHeightFor(uint8 paramIndex) const;
	uint8 indexFor(const String& parameterID) const noexcept;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};