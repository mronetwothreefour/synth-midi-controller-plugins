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
	Array<int> minValues;
	Array<int> maxValues;
	Array<int> defaultValues;
	Array<String> descriptions;
	Array<Point<int>> ctrlCenterPoints;
	Array<int> ctrlWidths;
	Array<int> ctrlHeights;
	Array<uint16> lsbByteLocations;

	InfoForExposedParameters();
	void fillAllInfoContainers();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint16 paramIndex) const;
	String exposedNameFor(uint16 paramIndex) const;
	ControlType controlTypeFor(uint16 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint16 paramIndex) const;
	int minValueFor(uint16 paramIndex) const;
	int maxValueFor(uint16 paramIndex) const;
	int defaultValueFor(uint16 paramIndex) const;
	int numberOfStepsFor(uint16 paramIndex) const;
	String descriptionFor(uint16 paramIndex) const;
	Point<int> ctrlCenterPointFor(uint16 paramIndex) const;
	int ctrlWidthFor(uint16 paramIndex) const;
	int ctrlHeightFor(uint16 paramIndex) const;
	uint16 indexForParamID(const String& parameterID) const;
	uint16 lsbByteLocationFor(uint16 paramIndex) const;
	uint16 msbByteLocationFor(uint16 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};