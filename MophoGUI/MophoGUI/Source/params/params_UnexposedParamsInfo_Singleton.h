#pragma once

#include <JuceHeader.h>



enum class ControlType;
struct IntToContextualStringConverter;
enum class OptionsType;

class InfoForUnexposedParameters
{
	Array<Identifier> identifiers;
	Array<OptionsType> optionsTypes;
	Array<ControlType> controlTypes;
	Array<uint16> NRPNs;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<String> descriptions;
	Array<Point<int>> ctrlCenterPoints;
	Array<int> ctrlWidths;
	Array<int> ctrlHeights;
	Array<uint8> lsByteLocations;
	Array<uint8> msByteLocations;

	InfoForUnexposedParameters();
	void fillAllInfoContainers();

public:
	InfoForUnexposedParameters(InfoForUnexposedParameters&&) = delete;
	InfoForUnexposedParameters& operator=(InfoForUnexposedParameters&&) = delete;

	static InfoForUnexposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	OptionsType optionsTypeFor(uint8 paramIndex) const;
	uint8 NRPNfor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	uint8 defaultValueFor(uint8 paramIndex) const;
	uint16 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> ctrlCenterPointFor(uint8 paramIndex) const;
	int ctrlWidthFor(uint8 paramIndex) const;
	int ctrlHeightFor(uint8 paramIndex) const;
	uint8 lsByteLocationFor(uint8 paramIndex) const;
	uint8 msByteLocationFor(uint8 paramIndex) const;
	~InfoForUnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForUnexposedParameters)
};

