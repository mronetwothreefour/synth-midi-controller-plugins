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

	identifiers.add("osc1_Pitch");
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
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which LFO 1\n";
	descriptionString += "modulates the pitch of oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the LFO waveform.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow2_y));
	lsbByteLocations.add((uint16)177);

	identifiers.add("osc1_Sync");
	exposedNames.add("Oscillator 1 Sync");
	paramNumbers.add((uint8)2);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOsc1SyncString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects whether and to what degree oscillator 1's\n";
	descriptionString += "waveform is synchronized with that of oscillator 2.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow3_y));
	lsbByteLocations.add((uint16)55);

	identifiers.add("osc1_PulseWidth");
	exposedNames.add("Oscillator 1 Pulse Width");
	paramNumbers.add((uint8)3);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Sets the width of oscillator 1's\n";
	descriptionString += "wave when its type is set to PULSE.\n";
	descriptionString += "Range: 0 (very wide) to 63 (very narrow).\n";
	descriptionString += "A value of 31 produces a square wave.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow5_y));
	lsbByteLocations.add((uint16)27);

	identifiers.add("osc1_PWMbyLFO2");
	exposedNames.add("Oscillator 1 Pulse Width Mod. by LFO 2");
	paramNumbers.add((uint8)4);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which LFO 2 modulates\n";
	descriptionString += "the pulse width of oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the LFO waveform.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow7_y));
	lsbByteLocations.add((uint16)179);

	identifiers.add("osc1_SawTri");
	exposedNames.add("Oscillator 1 Saw / Triangle Wave");
	paramNumbers.add((uint8)5);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Sets the shape of oscillator 1\n";
	descriptionString += "when its type is set to WAVE.\n";
	descriptionString += "Range: 0 (sawtooth) to 63 (triangle).\n";
	descriptionString += "Intermediate values produce various\n";
	descriptionString += "mixtures of the two shapes.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow6_y));
	lsbByteLocations.add((uint16)25);

	identifiers.add("osc1_Type");
	exposedNames.add("Oscillator 1 Type");
	paramNumbers.add((uint8)6);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOscWaveShapeString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects oscillator 1's type.\n";
	descriptionString += "Off: The oscillator produces no sound.\n";
	descriptionString += "Pulse: Set the width of the pulse below.\n";
	descriptionString += "Wave: Set the shape of the wave below.\n";
	descriptionString += "Both: A blend of pulse and wave.";
	descriptions.add(descriptionString);
	controlWidths.add(oscControls_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow4_y));
	lsbByteLocations.add((uint16)31);
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