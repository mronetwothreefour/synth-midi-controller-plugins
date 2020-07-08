#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_ControlTypes.h"
#include "../helpers/helper_Identifiers.h"
#include "../helpers/helper_IntToContextualStringConverters.h"



class InfoForExposedParameters
{
	Array<Identifier> identifiers;
	Array<String> publicNames;
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
	~InfoForExposedParameters();

	void fillAllInfoContainers();

public:
	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;

	static InfoForExposedParameters& get() noexcept;
	int numberOfExposedParameters() noexcept;
	Identifier IDfor(uint8 paramIndex) noexcept;
	String publicNameFor(uint8 paramIndex) noexcept;
	ControlType controlTypeFor(uint8 paramIndex) noexcept;
	uint16 NRPNfor(uint8 paramIndex) noexcept;
	IntToContextualStringConverter* converterFor(uint8 paramIndex) noexcept;
	uint8 maxValueFor(uint8 paramIndex) noexcept;
	uint8 defaultValueFor(uint8 paramIndex) noexcept;
	uint16 numberOfStepsFor(uint8 paramIndex) noexcept;
	String descriptionFor(uint8 paramIndex) noexcept;
	Point<int> ctrlCenterPointFor(uint8 paramIndex) noexcept;
	int ctrlWidthFor(uint8 paramIndex) noexcept;
	int ctrlHeightFor(uint8 paramIndex) noexcept;
	uint8 getIndexFor(const String& parameterID) noexcept;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
};