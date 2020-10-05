#pragma once

#include <JuceHeader.h>



enum class ControlType;
struct IntToContextualStringConverter;

class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<uint8> paramNumbers;
	Array<ControlType> controlTypes;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValueDisplayLengths;
	Array<int8> minValues;
	Array<uint8> maxValues;
	Array<int8> defaultValues;
	Array<String> descriptions;
	Array<int> controlWidths;
	Array<Point<int>> controlCenterPoints;
	Array<uint16> lsbByteLocations;

	InfoForExposedParameters();
	void fillAllInfoContainers();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	uint8 maxValueDisplayLengthFor(uint8 paramIndex) const;
	int8 minValueFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	int8 defaultValueFor(uint8 paramIndex) const;
	uint8 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> controlCenterPointFor(uint8 paramIndex) const;
	int controlWidthFor(uint8 paramIndex) const;
	uint8 indexForParamID(const String& parameterID) const;
	uint16 lsbByteLocationFor(uint8 paramIndex) const;
	uint16 msbByteLocationFor(uint8 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};
