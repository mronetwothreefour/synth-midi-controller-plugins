#pragma once

#include <JuceHeader.h>



enum class ControlType;
enum class RangeType;
struct IntToContextualStringConverter;

class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<uint8> paramNumbers;
	Array<bool> isQuickEditEnabled;
	Array<ControlType> controlTypes;
	Array<RangeType> rangeTypes;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<String> descriptions;
	Array<int> controlWidths;
	Array<Point<int>> controlCenterPoints;
	Array<uint16> dataByteIndices;

	InfoForExposedParameters();
	void fillAllInfoContainers();

public:
	const int8 offsetForSigned6bitRange{ 31 };
	const int8 offsetForSigned7bitRange{ 63 };

	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	uint8 paramNumberFor(uint8 paramIndex) const;
	bool isQuickEditable(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	RangeType rangeTypeFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	uint8 defaultValueFor(uint8 paramIndex) const;
	uint8 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> controlCenterPointFor(uint8 paramIndex) const;
	int controlWidthFor(uint8 paramIndex) const;
	uint8 indexForParamID(const String& parameterID) const;
	uint16 dataByteIndexFor(uint8 paramIndex) const;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};
