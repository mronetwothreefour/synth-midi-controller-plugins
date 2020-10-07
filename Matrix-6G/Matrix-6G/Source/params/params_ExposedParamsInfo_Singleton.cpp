#include "params_ExposedParamsInfo_Singleton.h"

#include "params_IntToContextualStringConverters.h"
#include "params_RangeTypes.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	static const auto controlsVerticalGap{ 28 };
	static const auto controlsRow1_y{ 69 };
	static const auto controlsRow2_y{ controlsRow1_y + controlsVerticalGap };
	static const auto controlsRow3_y{ controlsRow2_y + controlsVerticalGap };
	static const auto controlsRow4_y{ controlsRow3_y + controlsVerticalGap };
	static const auto controlsRow5_y{ controlsRow4_y + controlsVerticalGap };
	static const auto controlsRow6_y{ controlsRow5_y + controlsVerticalGap };
	static const auto controlsRow7_y{ controlsRow6_y + controlsVerticalGap };
	static const auto controlsRow8_y{ controlsRow7_y + controlsVerticalGap };
	static const auto controlsRow9_y{ controlsRow8_y + controlsVerticalGap };
	static const auto controlsRow10_y{ controlsRow9_y + controlsVerticalGap };
	static const auto controlsRow11_y{ controlsRow10_y + controlsVerticalGap };
	static const auto oscControlsCol1_x{ 130 };
	static const auto oscControlsCol2_x{ 196 };
	static const auto oscControls_w{ 60 };
	static const auto controlsHorizontalGap{ 6 };
	static const auto oscBalanceControl_w{ 2 * oscControls_w + controlsHorizontalGap };

	String descriptionString;

	//======================================================

	identifiers.add("osc1Pitch");
	exposedNames.add("Oscillator 1 Pitch");
	paramNumbers.add((uint8)0);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToOscPitchString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)24);
	descriptionString =  "Sets oscillator 1's base\n";
	descriptionString += "pitch in semitone steps.\n";
	descriptionString += "Range: C 0 to D#5.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow1_y));
	lsbByteLocations.add((uint16)23);

	identifiers.add("osc1_LFO1_FM");
	exposedNames.add("Oscillator 1 LFO 1 FM Amount");
	paramNumbers.add((uint8)1);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed6bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which LFO 1 modulates oscillator 1's pitch.\n";
	descriptionString += "Range: -63* to +63. (*Negative control values cannot be sent with\n";
	descriptionString += "Quick Patch Edit. This requires sending a full patch dump for\n";
	descriptionString += "every change in value, and will therefore be noticeably slower.)";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow2_y));
	lsbByteLocations.add((uint16)177);
}

InfoForExposedParameters& InfoForExposedParameters::get() noexcept {
	static InfoForExposedParameters exposedParamsInfo;
	return exposedParamsInfo;
}

int InfoForExposedParameters::paramOutOfRange() const noexcept {
	return identifiers.size();
}

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) const {
	return identifiers[paramIndex];
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	return exposedNames[paramIndex];
}

uint8 InfoForExposedParameters::paramNumberFor(uint8 paramIndex) const {
	return paramNumbers[paramIndex];
}

bool InfoForExposedParameters::isQuickEditable(uint8 paramIndex) const {
	return isQuickEditEnabled[paramIndex];
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	return controlTypes[paramIndex];
}

IntToContextualStringConverter* InfoForExposedParameters::converterFor(uint8 paramIndex) const {
	return converters[paramIndex];
}

RangeType InfoForExposedParameters::rangeTypeFor(uint8 paramIndex) const {
	return rangeTypes[paramIndex];
}

uint8 InfoForExposedParameters::maxValueFor(uint8 paramIndex) const {
	return maxValues[paramIndex];
}

uint8 InfoForExposedParameters::defaultValueFor(uint8 paramIndex) const {
	return defaultValues[paramIndex];
}

uint8 InfoForExposedParameters::numberOfStepsFor(uint8 paramIndex) const {
	return maxValues[paramIndex] + 1;
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) const {
	return descriptions[paramIndex];
}

Point<int> InfoForExposedParameters::controlCenterPointFor(uint8 paramIndex) const {
	return controlCenterPoints[paramIndex];
}

int InfoForExposedParameters::controlWidthFor(uint8 paramIndex) const {
	return controlWidths[paramIndex];
}

uint8 InfoForExposedParameters::indexForParamID(const String& parameterID) const {
	return (uint8)identifiers.indexOf(Identifier(parameterID));
}

uint16 InfoForExposedParameters::lsbByteLocationFor(uint8 paramIndex) const {
	return lsbByteLocations[paramIndex];
}

uint16 InfoForExposedParameters::msbByteLocationFor(uint8 paramIndex) const {
	return lsbByteLocations[paramIndex] + 1;
}