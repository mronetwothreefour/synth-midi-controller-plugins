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
	static const auto vcfCol_x{ 382 };
	static const auto vcfFMcontrols_x{ 550 };
	static const auto defaultControl_w{ 60 };
	static const auto controlsHorizontalGap{ 6 };
	static const auto oscBalanceControl_x{ 163 };
	static const auto oscBalanceControl_w{ 126 };
	static const auto trackPointControls_y{ 279 };
	static const auto trackPointControls_w{ 26 };
	static const auto trackPointControlsHorizontalGap{ 5 };
	static const auto trackPoint1Control_x{ 853 };
	static const auto trackPoint2Control_x{ trackPoint1Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
	static const auto trackPoint3Control_x{ trackPoint2Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
	static const auto trackPoint4Control_x{ trackPoint3Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
	static const auto trackPoint5Control_x{ trackPoint4Control_x + trackPointControls_w + trackPointControlsHorizontalGap };
	static const auto rampControlsCol1_x{ 894 };
	static const auto rampControlsCol2_x{ 960 };

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
	controlWidths.add(defaultControl_w);
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
	controlWidths.add(defaultControl_w);
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
	controlWidths.add(defaultControl_w);
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
	controlWidths.add(defaultControl_w);
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
	controlWidths.add(defaultControl_w);
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
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow6_y));
	lsbByteLocations.add((uint16)25);

	identifiers.add("osc1_Type");
	exposedNames.add("Oscillator 1 Type");
	paramNumbers.add((uint8)6);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOscTypeString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects oscillator 1's wave type.\n";
	descriptionString += "OFF: The oscillator produces no sound.\n";
	descriptionString += "PULSE: Set the width of the pulse below.\n";
	descriptionString += "WAVE: Set the shape of the wave below.\n";
	descriptionString += "BOTH: A blend of pulse and wave.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow4_y));
	lsbByteLocations.add((uint16)31);

	identifiers.add("osc1_LeverControl");
	exposedNames.add("Oscillator 1 Lever Control");
	paramNumbers.add((uint8)7);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToLeverControlString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)3);
	descriptionString =  "Selects which of the performance \"levers\"\n";
	descriptionString += "(wheel-type controllers) will modulate oscillator 1.\n";
	descriptionString += "OFF: Oscillator 1 is not controlled by either lever.\n";
	descriptionString += "BEND: Pitch bend is controlled by lever 1 (pitch wheel).\n";
	descriptionString += "VIB: Vibrato amount is controlled by lever 2 (mod wheel).\n";
	descriptionString += "BOTH: Oscillator 1 is controlled by both levers.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow10_y));
	lsbByteLocations.add((uint16)29);

	identifiers.add("osc1_KeyTrack");
	exposedNames.add("Oscillator 1 Key Tracking");
	paramNumbers.add((uint8)8);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOsc1KeyTrackString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects how oscillator 1 responds to incoming pitch\n";
	descriptionString += "change messages (e.g. notes played on a keyboard controller).\n";
	descriptionString += "KEYBD: Oscillater 1's pitch tracks note key changes normally.\n";
	descriptionString += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
	descriptionString += "according to the settings in the portamento (aka \"glide\") section.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow9_y));
	lsbByteLocations.add((uint16)47);

	identifiers.add("osc1_KeyClick");
	exposedNames.add("Oscillator 1 Key Click");
	paramNumbers.add((uint8)9);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOffOnString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Adds percussive punch to\n";
	descriptionString += "the start of the sound.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol1_x, controlsRow8_y));
	lsbByteLocations.add((uint16)49);

	//======================================================

	identifiers.add("osc2_Pitch");
	exposedNames.add("Oscillator 2 Pitch");
	paramNumbers.add((uint8)10);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToOscPitchString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)36);
	descriptionString =  "Sets oscillator 2's base\n";
	descriptionString += "pitch in semitone steps.\n";
	descriptionString += "Range: C 0 to D#5.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow1_y));
	lsbByteLocations.add((uint16)33);

	identifiers.add("osc2_LFO1_FM");
	exposedNames.add("Oscillator 2 LFO 1 FM Amount");
	paramNumbers.add((uint8)11);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which LFO 1\n";
	descriptionString += "modulates the pitch of oscillator 2.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the LFO waveform.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow2_y));
	lsbByteLocations.add((uint16)181);

	identifiers.add("osc2_Detune");
	exposedNames.add("Oscillator 2 Detune");
	paramNumbers.add((uint8)12);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned6bitValueString::get());
	rangeTypes.add(RangeType::signed6bitValue);
	maxValues.add((uint8)62);
	defaultValues.add((uint8)31);
	descriptionString =  "Slightly lowers or raises Oscillator 2's pitch.\n";
	descriptionString += "Range -31 to +31 (-/+ ~25 cents). 0 is no detune.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow3_y));
	lsbByteLocations.add((uint16)43);

	identifiers.add("osc2_PulseWidth");
	exposedNames.add("Oscillator 2 Pulse Width");
	paramNumbers.add((uint8)13);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)24);
	descriptionString =  "Sets the width of oscillator 2's\n";
	descriptionString += "wave when its type is set to PULSE.\n";
	descriptionString += "Range: 0 (very wide) to 63 (very narrow).\n";
	descriptionString += "A value of 31 produces a square wave.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow5_y));
	lsbByteLocations.add((uint16)37);

	identifiers.add("osc2_PWMbyLFO2");
	exposedNames.add("Oscillator 2 Pulse Width Mod. by LFO 2");
	paramNumbers.add((uint8)14);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which LFO 2 modulates\n";
	descriptionString += "the pulse width of oscillator 2.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the LFO waveform.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow7_y));
	lsbByteLocations.add((uint16)183);

	identifiers.add("osc2_SawTri");
	exposedNames.add("Oscillator 2 Saw / Triangle Wave");
	paramNumbers.add((uint8)15);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Sets the shape of oscillator 2\n";
	descriptionString += "when its type is set to WAVE.\n";
	descriptionString += "Range: 0 (sawtooth) to 63 (triangle).\n";
	descriptionString += "Intermediate values produce various\n";
	descriptionString += "mixtures of the two shapes.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow6_y));
	lsbByteLocations.add((uint16)35);

	identifiers.add("osc2_Type");
	exposedNames.add("Oscillator 2 Type");
	paramNumbers.add((uint8)16);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOscTypeString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)4);
	defaultValues.add((uint8)1);
	descriptionString =  "Selects oscillator 2's wave type.\n";
	descriptionString += "OFF: The oscillator produces no sound.\n";
	descriptionString += "PULSE: Set the width of the pulse below.\n";
	descriptionString += "WAVE: Set the shape of the wave below.\n";
	descriptionString += "BOTH: A blend of pulse and wave.\n";
	descriptionString += "NOISE: White noise (oscillator 2 only).";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow4_y));
	lsbByteLocations.add((uint16)41);

	identifiers.add("osc2_LeverControl");
	exposedNames.add("Oscillator 2 Lever Control");
	paramNumbers.add((uint8)17);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToLeverControlString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)3);
	descriptionString =  "Selects which of the performance \"levers\"\n";
	descriptionString += "(wheel-type controllers) will modulate oscillator 2.\n";
	descriptionString += "OFF: Oscillator 2 is not controlled by either lever.\n";
	descriptionString += "BEND: Pitch bend is controlled by lever 1 (pitch wheel).\n";
	descriptionString += "VIB: Vibrato amount is controlled by lever 2 (mod wheel).\n";
	descriptionString += "BOTH: Oscillator 2 is controlled by both levers.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow10_y));
	lsbByteLocations.add((uint16)39);

	identifiers.add("osc2_KeyTrack");
	exposedNames.add("Oscillator 2 Key Tracking");
	paramNumbers.add((uint8)18);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOsc2AndVCFKeyTrackString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)2);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects how oscillator 2 responds to incoming pitch\n";
	descriptionString += "change messages (e.g. notes played on a keyboard controller).\n";
	descriptionString += "OFF: Oscillater 2's pitch will not change as notes are played.\n";
	descriptionString += "PORTA: Tracking is active, but transitions between pitches are smoothed\n";
	descriptionString += "according to the settings in the portamento (aka \"glide\") section.\n";
	descriptionString += "KEYBD: Oscillator 2's pitch tracks note key changes normally.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow9_y));
	lsbByteLocations.add((uint16)51);

	identifiers.add("osc2_KeyClick");
	exposedNames.add("Oscillator 2 Key Click");
	paramNumbers.add((uint8)19);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOffOnString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Adds percussive punch to\n";
	descriptionString += "the start of the sound.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(oscControlsCol2_x, controlsRow8_y));
	lsbByteLocations.add((uint16)53);

	identifiers.add("osc_Balance");
	exposedNames.add("Oscillator Balance");
	paramNumbers.add((uint8)20);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::linearSlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Sets the relative levels of the two oscillators.\n";
	descriptionString += "Range: 0 to 63. At 63, only oscillator 1 is heard.\n";
	descriptionString += "At 0, only oscillator 2 is heard. 31 is an equal mix.";
	descriptions.add(descriptionString);
	controlWidths.add(oscBalanceControl_w);
	controlCenterPoints.add(Point<int>(oscBalanceControl_x, controlsRow11_y));
	lsbByteLocations.add((uint16)45);

	//======================================================

	identifiers.add("vcf_Freq");
	exposedNames.add("VCF Frequency");
	paramNumbers.add((uint8)21);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)127);
	defaultValues.add((uint8)55);
	descriptionString =  "Sets the cutoff frequency of\n";
	descriptionString += "the voltage-controlled filter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow1_y));
	lsbByteLocations.add((uint16)57);

	identifiers.add("vcf_Env1Amt");
	exposedNames.add("VCF Envelope 1 Amount");
	paramNumbers.add((uint8)22);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)105);
	descriptionString =  "Sets the degree to which the VCF's\n";
	descriptionString += "frequency is modulated by envelope 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow3_y));
	lsbByteLocations.add((uint16)185);

	identifiers.add("vcf_PressureAmt");
	exposedNames.add("VCF Pressure Amount");
	paramNumbers.add((uint8)23);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which the VCF's frequency\n";
	descriptionString += "is modulated by keyboard pressure (aftertouch).\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the pressure.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow4_y));
	lsbByteLocations.add((uint16)187);

	identifiers.add("vcf_Reso");
	exposedNames.add("VCF Resonance");
	paramNumbers.add((uint8)24);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the resonance level of\n";
	descriptionString += "the voltage-controlled filter.\n";
	descriptionString += "Range: 0 to 63. At 63, the/n";
	descriptionString += "filter will self-oscillate.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow2_y));
	lsbByteLocations.add((uint16)59);

	identifiers.add("vcf_LeverControl");
	exposedNames.add("VCF Lever Control");
	paramNumbers.add((uint8)25);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToLeverControlString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects which of the performance \"levers\"\n";
	descriptionString += "(wheel-type controllers) modulate the VCF frequency.\n";
	descriptionString += "OFF: VCF frequency is not controlled by either lever.\n";
	descriptionString += "BEND: VCF frequency is controlled by lever 1 (pitch wheel).\n";
	descriptionString += "VIB: VCF frequency vibrato is controlled by lever 2 (mod wheel).\n";
	descriptionString += "BOTH: VCF frequency is controlled by both levers.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow5_y));
	lsbByteLocations.add((uint16)61);

	identifiers.add("vcf_KeyTrack");
	exposedNames.add("VCF Key Tracking");
	paramNumbers.add((uint8)26);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToOsc2AndVCFKeyTrackString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)2);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects how the VCF's cutoff frequency responds to incoming pitch\n";
	descriptionString += "change messages (e.g. notes played on a keyboard controller).\n";
	descriptionString += "OFF: Note key changes have no effect on the VCF's cutoff frequency.\n";
	descriptionString += "PORTA: Tracking is active, but transitions between cutoff frequencies are\n";
	descriptionString += "smoothed according to the settings in the portamento (aka \"glide\") section.\n";
	descriptionString += "KEYBD: The VCF's cutoff frequency tracks note key changes, rising as\n";
	descriptionString += "higher notes are played and dropping as lower notes are played.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow6_y));
	lsbByteLocations.add((uint16)63);

	//======================================================

	identifiers.add("vca1_Volume");
	exposedNames.add("VCA 1 Volume");
	paramNumbers.add((uint8)27);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the initial output level of the\n";
	descriptionString += "first-stage voltage-controlled amplifier.\n";
	descriptionString += "Range: 0 (silence) to 63 (maximum).";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow9_y));
	lsbByteLocations.add((uint16)67);

	identifiers.add("vca1_VeloAmt");
	exposedNames.add("VCA 1 Velocity Amount");
	paramNumbers.add((uint8)28);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which note velocity\n";
	descriptionString += "modulates the output level of VCA 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the note velocity.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow10_y));
	lsbByteLocations.add((uint16)189);

	identifiers.add("vca2_Env2Amt");
	exposedNames.add("VCA 2 Envelope 2 Amount");
	paramNumbers.add((uint8)29);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)126);
	descriptionString =  "Sets the degree to which envelope 2\n";
	descriptionString += "modulates the output level of the second-\n";
	descriptionString += "stage voltage-controlled amplifier.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfCol_x, controlsRow11_y));
	lsbByteLocations.add((uint16)191);

	//======================================================

	identifiers.add("vcfFM_Osc1Amt");
	exposedNames.add("VCF FM By Oscillator 1 Amount");
	paramNumbers.add((uint8)30);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which the VCF's cutoff\n";
	descriptionString += "frequency is modulated by oscillator 1.\n";
	descriptionString += "Range: 0 (no modulation) to 63 (maximum).";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfFMcontrols_x, controlsRow1_y));
	lsbByteLocations.add((uint16)65);

	identifiers.add("vcfFM_Env3Amt");
	exposedNames.add("VCF FM Envelope 3 Amount");
	paramNumbers.add((uint8)31);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which envelope 3 modulates\n";
	descriptionString += "the amount of VCF FM by oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the envelope.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfFMcontrols_x, controlsRow2_y));
	lsbByteLocations.add((uint16)205);

	identifiers.add("vcfFM_PressureAmt");
	exposedNames.add("VCF FM Pressure Amount");
	paramNumbers.add((uint8)32);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToSigned7bitValueString::get());
	rangeTypes.add(RangeType::signed7bitValue);
	maxValues.add((uint8)126);
	defaultValues.add((uint8)63);
	descriptionString =  "Sets the degree to which keyboard\n";
	descriptionString += "pressure (aftertouch) modulates the\n";
	descriptionString += "amount of VCF FM by oscillator 1.\n";
	descriptionString += "Range: -63 to +63. 0 is no modulation.\n";
	descriptionString += "Negative values invert the pressure.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(vcfFMcontrols_x, controlsRow3_y));
	lsbByteLocations.add((uint16)207);

	//======================================================

	identifiers.add("track_Input");
	exposedNames.add("Tracking Generator Input");
	paramNumbers.add((uint8)33);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToModSourceString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)20);
	defaultValues.add((uint8)9);
	descriptionString =  "Selects the modulation source which\n";
	descriptionString += "will be shaped by the tracking generator.";
	descriptions.add(descriptionString);
	controlWidths.add(94);
	controlCenterPoints.add(Point<int>(943, 165));
	lsbByteLocations.add((uint16)157);

	identifiers.add("track_Point1");
	exposedNames.add("Track Point 1");
	paramNumbers.add((uint8)34);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Track Point 1\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 0.";
	descriptions.add(descriptionString);
	controlWidths.add(trackPointControls_w);
	controlCenterPoints.add(Point<int>(trackPoint1Control_x, trackPointControls_y));
	lsbByteLocations.add((uint16)159);

	identifiers.add("track_Point2");
	exposedNames.add("Track Point 2");
	paramNumbers.add((uint8)35);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)15);
	descriptionString =  "Track Point 2\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 15.";
	descriptions.add(descriptionString);
	controlWidths.add(trackPointControls_w);
	controlCenterPoints.add(Point<int>(trackPoint2Control_x, trackPointControls_y));
	lsbByteLocations.add((uint16)161);

	identifiers.add("track_Point3");
	exposedNames.add("Track Point 3");
	paramNumbers.add((uint8)36);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)31);
	descriptionString =  "Track Point 3\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 31.";
	descriptions.add(descriptionString);
	controlWidths.add(trackPointControls_w);
	controlCenterPoints.add(Point<int>(trackPoint3Control_x, trackPointControls_y));
	lsbByteLocations.add((uint16)163);

	identifiers.add("track_Point4");
	exposedNames.add("Track Point 4");
	paramNumbers.add((uint8)37);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)47);
	descriptionString =  "Track Point 4\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 47.";
	descriptions.add(descriptionString);
	controlWidths.add(trackPointControls_w);
	controlCenterPoints.add(Point<int>(trackPoint4Control_x, trackPointControls_y));
	lsbByteLocations.add((uint16)165);

	identifiers.add("track_Point5");
	exposedNames.add("Track Point 5");
	paramNumbers.add((uint8)38);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)63);
	descriptionString =  "Track Point 5\n";
	descriptionString += "Range: 0 to 63.\n";
	descriptionString += "Linear output value: 63.";
	descriptions.add(descriptionString);
	controlWidths.add(trackPointControls_w);
	controlCenterPoints.add(Point<int>(trackPoint5Control_x, trackPointControls_y));
	lsbByteLocations.add((uint16)167);

	//======================================================

	identifiers.add("ramp1_Rate");
	exposedNames.add("Ramp 1 Rate");
	paramNumbers.add((uint8)40);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the amount of time it takes for\n";
	descriptionString += "Ramp 1 to complete its control cycle.\n";
	descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(rampControlsCol1_x, controlsRow1_y));
	lsbByteLocations.add((uint16)169);

	identifiers.add("ramp1_Trig");
	exposedNames.add("Ramp 1 Trigger");
	paramNumbers.add((uint8)41);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToRampTrigString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects the type of trigger that will start ramp 1's control cycle.\n";
	descriptionString += "STRIG: Single - A new note triggers the ramp only when no other\n";
	descriptionString += "notes are currently held down (only active in unison mode).\n";
	descriptionString += "MTRIG: Multiple - the ramp is triggered with every new note played.\n";
	descriptionString += "XTRIG: External - an external signal (e.g. a footswitch) triggers the ramp.\n";
	descriptionString += "GATEX: Gated External - an external signal triggers the ramp only when\n";
	descriptionString += "there are one or more notes being played.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(rampControlsCol1_x, controlsRow2_y));
	lsbByteLocations.add((uint16)171);

	identifiers.add("ramp2_Rate");
	exposedNames.add("Ramp 2 Rate");
	paramNumbers.add((uint8)42);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::rotarySlider);
	converters.add(IntToUnsignedValueString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)63);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the amount of time it takes for\n";
	descriptionString += "Ramp 2 to complete its control cycle.\n";
	descriptionString += "Range: 0 (instantaneous) to 63 (longest).";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(rampControlsCol2_x, controlsRow1_y));
	lsbByteLocations.add((uint16)173);

	identifiers.add("ramp2_Trig");
	exposedNames.add("Ramp 2 Trigger");
	paramNumbers.add((uint8)43);
	isQuickEditEnabled.add((bool)true);
	controlTypes.add(ControlType::comboBox);
	converters.add(IntToRampTrigString::get());
	rangeTypes.add(RangeType::unsignedValue);
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects the type of trigger that will start ramp 2's control cycle.\n";
	descriptionString += "STRIG: Single - A new note triggers the ramp only when no other\n";
	descriptionString += "notes are currently held down (only active in unison mode).\n";
	descriptionString += "MTRIG: Multiple - the ramp is triggered with every new note played.\n";
	descriptionString += "XTRIG: External - an external signal (e.g. a footswitch) triggers the ramp.\n";
	descriptionString += "GATEX: Gated External - an external signal triggers the ramp only when\n";
	descriptionString += "there are one or more notes being played.";
	descriptions.add(descriptionString);
	controlWidths.add(defaultControl_w);
	controlCenterPoints.add(Point<int>(rampControlsCol2_x, controlsRow2_y));
	lsbByteLocations.add((uint16)175);
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