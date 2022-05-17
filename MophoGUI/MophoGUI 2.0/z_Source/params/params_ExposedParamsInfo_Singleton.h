//#pragma once
//
//#include <JuceHeader.h>
//
//
//
//enum class ControlType;
//enum class RandomizationOptionsType;
//struct IntToContextualStringConverter;
//
//class InfoForExposedParameters
//{
//public:
//	static const int numberOfExposedParameters{ 189 };
//
//private:
//	ValueTree exposedParamsInfoTree;
//
//	Array<IntToContextualStringConverter*> converters;
//	Array<String> descriptions;
//	Array<RandomizationOptionsType> randomizationOptionsTypes;
//	Array<uint16> msBitPackedByteLocations;
//	Array<uint16> lsByteLocations;
//	Array<uint8> msBitMasks;
//	Array<int> allowedValuesColumnCounts;
//	Array<int> allowedValuesColumnWidths;
//	Array<int> allowedValuesRowsCounts;
//	Array<int> allowedValuesFirstRows;
//	Array<Point<int>> randomizationOptionsTopLeftCoordinates;
//
//
//	InfoForExposedParameters();
//	void fillAllInfoContainers();
//	void fillDataByteLocationsFor(uint8 param);
//	uint16 offsetParamToAccountForUnassignedParams109to119(uint16 param);
//
//public:
//	InfoForExposedParameters(InfoForExposedParameters&&) = delete;
//	InfoForExposedParameters& operator=(InfoForExposedParameters&&) = delete;
//
//	static InfoForExposedParameters& get() noexcept;
//	Identifier IDfor(uint8 paramIndex) const;
//	String exposedNameFor(uint8 paramIndex) const;
//	ControlType controlTypeFor(uint8 paramIndex) const;
//	uint8 NRPNfor(uint8 paramIndex) const;
//	IntToContextualStringConverter* converterFor(uint8 paramIndex) const;
//	uint8 maxValueFor(uint8 paramIndex) const;
//	uint8 defaultValueFor(uint8 paramIndex) const;
//	uint8 numberOfStepsFor(uint8 paramIndex) const;
//	String descriptionFor(uint8 paramIndex) const;
//	Point<int> controlCenterPointFor(uint8 paramIndex) const;
//	int controlWidthFor(uint8 paramIndex) const;
//	int controlHeightFor(uint8 paramIndex) const;
//	uint8 indexForParamID(const String& parameterID) const;
//	uint16 msBitPackedByteLocationFor(uint8 paramIndex) const;
//	uint16 lsByteLocationFor(uint8 paramIndex) const;
//	uint8 msBitMaskFor(uint8 paramIndex) const;
//	RandomizationOptionsType randomizationOptionsTypeFor(uint8 paramIndex) const; // todo: delete
//	int numberOfAllowedValuesColumnsFor(uint8 paramIndex) const;
//	int widthOfAllowedValuesColumnFor(uint8 paramIndex) const;
//	int numberOfAllowedValuesRowsFor(uint8 paramIndex) const;
//	int firstAllowedValuesRowFor(uint8 paramIndex) const;
//	int randomizationOptions_x_For(uint8 paramIndex) const;
//	int randomizationOptions_y_For(uint8 paramIndex) const;
//	uint8 paramIndexForNRPN(const uint8 NRPN) const;
//
//private:
//	//==============================================================================
//	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InfoForExposedParameters)
//};