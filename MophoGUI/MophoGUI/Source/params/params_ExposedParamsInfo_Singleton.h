#pragma once

#include <JuceHeader.h>



enum class ControlType;
struct IntToContextualStringConverter;

class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> exposedNames;
	Array<ControlType> controlTypes;
	Array<uint8> NRPNs;
	Array<IntToContextualStringConverter*> converters;
	Array<uint8> maxValues;
	Array<uint8> defaultValues;
	Array<String> descriptions;
	Array<Point<int>> ctrlCenterPoints;
	Array<int> ctrlWidths;
	Array<int> ctrlHeights;
	Array<uint16> msBitPackedByteLocations;
	Array<uint16> lsByteLocations;
	Array<uint8> msBitMasks;

	InfoForExposedParameters();
	void fillAllInfoContainers();
	void fillDataByteLocationsFor(uint16 param);
	uint16 offsetParamToAccountForUnassignedParams109to119(uint16 param);

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int paramOutOfRange() const noexcept;
	Identifier IDfor(uint8 paramIndex) const;
	String exposedNameFor(uint8 paramIndex) const;
	ControlType controlTypeFor(uint8 paramIndex) const;
	uint8 NRPNfor(uint8 paramIndex) const;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
	uint8 maxValueFor(uint8 paramIndex) const;
	uint8 defaultValueFor(uint8 paramIndex) const;
	uint16 numberOfStepsFor(uint8 paramIndex) const;
	String descriptionFor(uint8 paramIndex) const;
	Point<int> ctrlCenterPointFor(uint8 paramIndex) const;
	int ctrlWidthFor(uint8 paramIndex) const;
	int ctrlHeightFor(uint8 paramIndex) const;
	uint8 indexForParamID(const String& parameterID) const;
	uint16 msBitPackedByteLocationFor(uint8 paramIndex) const;
	uint16 lsByteLocationFor(uint8 paramIndex) const;
	uint8 msBitMaskFor(uint8 paramIndex) const;

	// Returns 255 if NRPN is not found
	uint8 indexForNRPN(const uint8 nrpn) const;

	~InfoForExposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};