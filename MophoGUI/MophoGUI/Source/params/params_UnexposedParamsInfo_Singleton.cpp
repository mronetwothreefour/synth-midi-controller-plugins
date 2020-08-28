#include "params_UnexposedParamsInfo_Singleton.h"

#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"



InfoForUnexposedParameters::InfoForUnexposedParameters() {
	fillAllInfoContainers();
}

void InfoForUnexposedParameters::fillAllInfoContainers() {
	static const auto knob_diameter{ 40 };
	static const auto toggle_diameter{ 14 };
	static const auto comboBox_w{ 110 };
	static const auto comboBox_w{ 110 };
	static const auto comboBox_x{ 689 };
	static const auto vertControlSpacing{ 20 };
	static const auto controlsRow1_y{ 158 };
	static const auto controlsRow2_y{ 221 };
	static const auto controlsRow3_y{ controlsRow2_y + vertControlSpacing };
	static const auto controlsRow4_y{ controlsRow3_y + vertControlSpacing };
	static const auto controlsRow5_y{ controlsRow4_y + vertControlSpacing };
	static const auto controlsRow6_y{ controlsRow5_y + vertControlSpacing };
	static const auto controlsRow7_y{ controlsRow6_y + vertControlSpacing };
	static const auto controlsRow8_y{ controlsRow7_y + vertControlSpacing };
	static const auto controlsRow9_y{ controlsRow8_y + vertControlSpacing };

	String descriptionString;

	identifiers.add(ID::global_Transpose); // 0
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)384);
	converters.add(IntToGlobalTransposeString::get());
	maxValues.add((uint8)24);
	defaultValues.add((uint8)12);
	descriptionString =  "All programs will be transposed up\n";
	descriptionString += "or down by this number of semitones.\n";
	descriptionString += "Range: -12 to +12.";
	descriptions.add(descriptionString);
	ctrlCenterPoints.add(Point<int>(563, controlsRow1_y));
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	lsByteLocations.add((uint8)4);
	msByteLocations.add((uint8)5);

	identifiers.add(ID::global_FineTune); // 1
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)385);
	converters.add(IntToFineTuneString::get());
	maxValues.add((uint8)100);
	defaultValues.add((uint8)50);
	descriptionString =  "All programs will be tuned up\n";
	descriptionString += "or down by this number of cents.\n";
	descriptionString += "Range: -50 to +50.";
	descriptions.add(descriptionString);
	ctrlCenterPoints.add(Point<int>(638, controlsRow1_y));
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	lsByteLocations.add((uint8)6);
	msByteLocations.add((uint8)7);
}

InfoForUnexposedParameters& InfoForUnexposedParameters::get() noexcept {
	static InfoForUnexposedParameters unexposedParamsInfo;
	return unexposedParamsInfo;
}

int InfoForUnexposedParameters::paramOutOfRange() const noexcept {
	return identifiers.size();
}

Identifier InfoForUnexposedParameters::IDfor(uint8 paramIndex) const {
	return identifiers[paramIndex];
}

ControlType InfoForUnexposedParameters::controlTypeFor(uint8 paramIndex) const {
	return controlTypes[paramIndex];
}

uint8 InfoForUnexposedParameters::NRPNfor(uint8 paramIndex) const {
	return NRPNs[paramIndex];
}

IntToContextualStringConverter* InfoForUnexposedParameters::converterFor(uint8 paramIndex) const {
	return converters[paramIndex];
}

uint8 InfoForUnexposedParameters::maxValueFor(uint8 paramIndex) const {
	return maxValues[paramIndex];
}

uint8 InfoForUnexposedParameters::defaultValueFor(uint8 paramIndex) const {
	return defaultValues[paramIndex];
}

uint16 InfoForUnexposedParameters::numberOfStepsFor(uint8 paramIndex) const {
	return maxValues[paramIndex] + 1;
}

String InfoForUnexposedParameters::descriptionFor(uint8 paramIndex) const {
	return descriptions[paramIndex];
}

Point<int> InfoForUnexposedParameters::ctrlCenterPointFor(uint8 paramIndex) const {
	return ctrlCenterPoints[paramIndex];
}

int InfoForUnexposedParameters::ctrlWidthFor(uint8 paramIndex) const {
	return ctrlWidths[paramIndex];
}

int InfoForUnexposedParameters::ctrlHeightFor(uint8 paramIndex) const {
	return ctrlHeights[paramIndex];
}

uint8 InfoForUnexposedParameters::lsByteLocationFor(uint8 paramIndex) const {
	return lsByteLocations[paramIndex];
}

uint8 InfoForUnexposedParameters::msByteLocationFor(uint8 paramIndex) const {
	return msByteLocations[paramIndex];
}

InfoForUnexposedParameters::~InfoForUnexposedParameters() {
}

