#pragma once

#include <JuceHeader.h>



enum class ControlType;
struct IntToContextualStringConverter;

class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<ControlType> controlTypes;
	Array<IntToContextualStringConverter*> converters;
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

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	uint8 defaultValueFor(uint8 paramIndex) const;
	uint8 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> controlCenterPointFor(uint8 paramIndex) const;
	uint8 firstNybbleIndexFor(uint8 paramIndex) const;
	uint8 firstBitIndexFor(uint8 paramIndex) const;
	uint8 indexForParamID(const String& parameterID) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};