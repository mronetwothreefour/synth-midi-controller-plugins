#include "params_ExposedParamsInfo_Singleton.h"

#include "params_Constants.h"
#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"
#include "params_RandomizationOptions.h"
#include "../gui/gui_Constants.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



InfoForExposedParameters::InfoForExposedParameters() :
	exposedParamsInfoTree{ ID::exposedParamsInfo }
{
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	String descriptionString;

	//======================================================

	for (uint8 oscNum = 1; oscNum != 3; ++oscNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 0 : 6), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_Pitch : ID::osc2_Pitch), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Pitch" },
							{ "controlType", (int)ControlType::knobForPitchWithValueStringDisplay },
							{ "NRPN", oscNum == 1 ? 0 : 5 },
							{ "maxValue", 120 },
							{ "defaultValue", 24 },
							{ "controlCenter_x", GUI::controlsCol1_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToOscPitchString::get());
		descriptionString =  "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch in semitone steps.\n";
		descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
		descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
		descriptionString += "increment the pitch by one octave (12 semitones).";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
		allowedValuesColumnCounts.add(11);
		allowedValuesColumnWidths.add(38);
		allowedValuesRowsCounts.add(12);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol1_x + GUI::knob_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::knob_diameter / 2));

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 1 : 7), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_Fine : ID::osc2_Fine), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Fine Tune" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", oscNum == 1 ? 1 : 6 },
							{ "maxValue", 100 },
							{ "defaultValue", 1 ? 49 : 51 },
							{ "controlCenter_x", GUI::controlsCol2_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToFineTuneString::get());
		descriptionString =  "Fine tunes oscillator " + (String)oscNum + GUI::apostrophe + "s base pitch.\n";
		descriptionString += "Range: -50 cents to +50 cents.\n";
		descriptionString += "0 = no detuning (centered).";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
		allowedValuesColumnCounts.add(11);
		allowedValuesColumnWidths.add(28);
		allowedValuesRowsCounts.add(10);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol2_x + GUI::knob_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::knob_diameter / 2));

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 2 : 8), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_Shape : ID::osc2_Shape), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Wave Shape" },
							{ "controlType", (int)ControlType::knobWithWaveShapeDisplay },
							{ "NRPN", oscNum == 1 ? 2 : 7 },
							{ "maxValue", 103 },
							{ "defaultValue", 1 },
							{ "controlCenter_x", GUI::controlsCol3_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToOscWaveShapeString::get());
		descriptionString =  "Selects oscillator " + (String)oscNum + GUI::apostrophe + "s wave shape.\n";
		descriptionString += "Hold down a number on the keyboard and click\n";
		descriptionString += "the knob to jump directly to a wave shape:\n";
		descriptionString += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
		descriptionString += "3 = Sawtooth / Triangle Mixture;\n";
		descriptionString += "4 = Square (a Pulse with width 50).";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::oscShape);
		allowedValuesColumnCounts.add(0);
		allowedValuesColumnWidths.add(0);
		allowedValuesRowsCounts.add(0);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol3_x + GUI::knob_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::knob_diameter / 2));

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 3 : 9), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_Glide : ID::osc2_Glide), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Glide Rate" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", oscNum == 1 ? 3 : 8 },
							{ "maxValue", 127 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", GUI::controlsCol4_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToPlainValueString::get());
		descriptionString =  "Sets oscillator " + (String)oscNum + GUI::apostrophe + "s glide (portamento) rate.\n";
		descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
		allowedValuesColumnCounts.add(13);
		allowedValuesColumnWidths.add(26);
		allowedValuesRowsCounts.add(10);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol4_x + GUI::knob_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::knob_diameter / 2));

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 4 : 10), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_KeyTrack : ID::osc2_KeyTrack), {
							{ "exposedName", "Oscillator " + (String)oscNum + " Keyboard Track On/Off" },
							{ "controlType", (int)ControlType::toggleButton },
							{ "NRPN", oscNum == 1 ? 4 : 9 },
							{ "defaultValue", 1 },
							{ "controlCenter_x", GUI::controlsCol6_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::toggle_diameter },
							{ "controlHeight", GUI::toggle_diameter },
							{ "maxValue", 1 },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToOffOnString::get());
		descriptionString =  "Turns keyboard tracking for oscillator " + (String)oscNum + "\n";
		descriptionString += "on or off. When turned off, oscillator " + (String)oscNum + "\n";
		descriptionString += "always produces its base pitch, unaffected\n";
		descriptionString += "by the pitch of incoming MIDI notes.";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
		allowedValuesColumnCounts.add(0);
		allowedValuesColumnWidths.add(0);
		allowedValuesRowsCounts.add(0);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol6_x + GUI::toggle_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::toggleLockButton_diameter / 2));

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(oscNum == 1 ? 5 : 11), {}, { ValueTree{ (oscNum == 1 ? ID::osc1_SubLevel : ID::osc2_SubLevel), {
							{ "exposedName", "Sub-Oscillator " + (String)oscNum + " Level" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", oscNum == 1 ? 114 : 115 },
							{ "maxValue", 127 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", GUI::controlsCol5_x },
							{ "controlCenter_y", oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToPlainValueString::get());
		descriptionString =  "Sets the level of sub-oscillator " + (String)oscNum + ",\n";
		descriptionString += "which generates a square wave pitched\n";
		descriptionString += "one octave lower than oscillator " + (String)oscNum + ".\n";
		descriptionString += "Range: 0 to 127.";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
		allowedValuesColumnCounts.add(13);
		allowedValuesColumnWidths.add(26);
		allowedValuesRowsCounts.add(10);
		allowedValuesFirstRows.add(0);
		randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol5_x + GUI::knob_diameter, (oscNum == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y) - GUI::knob_diameter / 2));
	}

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_12", {}, { ValueTree{ ID::oscSync, {
						{ "exposedName", "Hard Oscillator Sync On/Off" },
						{ "controlType", (int)ControlType::toggleButton },
						{ "NRPN", 10 },
						{ "maxValue", 1 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol6_x },
						{ "controlCenter_y", 22 },
						{ "controlWidth", GUI::toggle_diameter },
						{ "controlHeight", GUI::toggle_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToOffOnString::get());
	descriptionString =  "Turns hard oscillator sync on or off. When\n";
	descriptionString += "turned on, every time oscillator 2 resets,\n";
	descriptionString += "it forces oscillator 1 to reset as well.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
	allowedValuesColumnCounts.add(0);
	allowedValuesColumnWidths.add(0);
	allowedValuesRowsCounts.add(0);
	allowedValuesFirstRows.add(0);
	randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol6_x + GUI::toggle_diameter, 11));

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_13", {}, { ValueTree{ ID::glideMode, {
						{ "exposedName", "Glide Mode" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 11 },
						{ "maxValue", 3 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol10_x },
						{ "controlCenter_y", 78 },
						{ "controlWidth", 124 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToGlideModeString::get());
	descriptionString =  "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
	descriptionString += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
	descriptionString += "The Auto modes only apply glide when a note is played legato\n";
	descriptionString += "(the new note is triggered before the previous note is released).";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(124);
	allowedValuesRowsCounts.add(3);
	allowedValuesFirstRows.add(0);
	randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol10_x + 72, 70));

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_14", {}, { ValueTree{ ID::oscSlop, {
						{ "exposedName", "Oscillator Slop" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 12 },
						{ "maxValue", 5 },
						{ "defaultValue", 2 },
						{ "controlCenter_x", GUI::controlsCol7_x },
						{ "controlCenter_y", GUI::oscControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Introduces a subtle amount of random oscillator\n";
	descriptionString += "pitch drift for a " + GUI::openQuote + "vintage analog" + GUI::closeQuote + " sound.\n";
	descriptionString += "Range: 0 to 5.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(14);
	allowedValuesRowsCounts.add(5);
	allowedValuesFirstRows.add(0);
	randomizationOptionsTopLeftCoordinates.add(Point(GUI::controlsCol7_x + GUI::knob_diameter, GUI::oscControlsRow1_y - GUI::knob_diameter / 2));

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_15", {}, { ValueTree{ ID::bendRange, {
						{ "exposedName", "Pitch Bend Range" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 93 },
						{ "maxValue", 12 },
						{ "defaultValue", 4 },
						{ "controlCenter_x", GUI::controlsCol9_x },
						{ "controlCenter_y", GUI::oscControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToBendRangeString::get());
	descriptionString =  "Sets the maximum amount (in semitones) by which pitch wheel\n";
	descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
	descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(2);
	allowedValuesColumnWidths.add(28);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_16", {}, { ValueTree{ ID::notePriority, {
						{ "exposedName", "Note Priority (Key Assign)" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 96 },
						{ "maxValue", 5 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol10_x },
						{ "controlCenter_y", 38 },
						{ "controlWidth", 124 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToNotePriorityString::get());
	descriptionString =  "Selects which note is given priority when multiple\n";
	descriptionString += "notes are played, and whether the envelopes are\n";
	descriptionString += "re-triggered when a note is played legato (before\n";
	descriptionString += "the previous note has been released).";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(124);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_17", {}, { ValueTree{ ID::oscMix, {
						{ "exposedName", "Oscillator 1 & 2 Mix" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 13 },
						{ "maxValue", 127 },
						{ "defaultValue", 64 },
						{ "controlCenter_x", GUI::controlsCol8_x },
						{ "controlCenter_y", GUI::oscControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Controls the level balance between oscillators 1 & 2.\n";
	descriptionString += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
	descriptionString += "At 127, only oscillator 2 is heard. At 64, an equal\n";
	descriptionString += "mix of the two oscillators is heard.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_18", {}, { ValueTree{ ID::noiseLevel, {
						{ "exposedName", "Noise Level" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 14 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol7_x },
						{ "controlCenter_y", GUI::oscControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the level of white noise\n";
	descriptionString += "sent into the low-pass filter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_19", {}, { ValueTree{ ID::extInLevel, {
						{ "exposedName", "External Audio Input Level" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 116 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol8_x },
						{ "controlCenter_y", GUI::oscControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the level of external audio\n";
	descriptionString += "input sent into the low-pass filter.\n";
	descriptionString += "When nothing is connected to audio in,\n";
	descriptionString += "this controls the level of feedback\n";
	descriptionString += "from the left audio output.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_20", {}, { ValueTree{ ID::lpfFreq, {
						{ "exposedName", "LPF Cutoff Frequency" },
						{ "controlType", (int)ControlType::knobForPitchWithValueStringDisplay },
						{ "NRPN", 15 },
						{ "maxValue", 164 },
						{ "defaultValue", 148 },
						{ "controlCenter_x", GUI::controlsCol1_x },
						{ "controlCenter_y", GUI::lpfControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToLPFfreqString::get());
	descriptionString =  "Sets the base cutoff frequency for the low-pass filter\n";
	descriptionString += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
	descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
	descriptionString += "increment the frequency by one octave (12 semitones).";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::lpfFreq);
	allowedValuesColumnCounts.add(14);
	allowedValuesColumnWidths.add(64);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_21", {}, { ValueTree{ ID::lpfReso, {
						{ "exposedName", "LPF Resonance" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 16 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::lpfControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the resonance level of the low-pass\n";
	descriptionString += "filter. When in 4-pole mode, high settings\n";
	descriptionString += "will cause the filter to self-oscillate.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_22", {}, { ValueTree{ ID::lpfKeyAmount, {
						{ "exposedName", "LPF Keyboard Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 17 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol3_x },
						{ "controlCenter_y", GUI::lpfControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the amount by which keyboard (MIDI) notes\n";
	descriptionString += "will shift the low-pass filter" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
	descriptionString += "semitone for each note. At 32, cutoff is shifted\n";
	descriptionString += "by one half-semitone for each note.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_23", {}, { ValueTree{ ID::lpfFMamount, {
						{ "exposedName", "LPF FM (By Oscillator 1)" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 18 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol3_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the degree to which oscillator 1 modulates\n";
	descriptionString += "the low-pass filter" + GUI::apostrophe + "s cutoff frequency. This is\n";
	descriptionString += "useful for generating bell-like sounds.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_24", {}, { ValueTree{ ID::lpfType, {
						{ "exposedName", "LPF Type" },
						{ "controlType", (int)ControlType::toggleButton },
						{ "NRPN", 19 },
						{ "maxValue", 1 },
						{ "defaultValue", 1 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::lpfControlsRow1_y },
						{ "controlWidth", GUI::toggle_diameter },
						{ "controlHeight", GUI::toggle_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToLPFtypeString::get());
	descriptionString =  "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
	descriptionString += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
	descriptionString += "slope and more pronounced resonance.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
	allowedValuesColumnCounts.add(0);
	allowedValuesColumnWidths.add(0);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_25", {}, { ValueTree{ ID::lpfEnvAmount, {
						{ "exposedName", "LPF Envelope Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 20 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::controlsCol1_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which the LPF envelope\n";
	descriptionString += "modulates the filter" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_26", {}, { ValueTree{ ID::lpfVelAmount, {
						{ "exposedName", "LPF Envelope Velocity Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 21 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the low-pass filter" + GUI::apostrophe + "s envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_27", {}, { ValueTree{ ID::lpfDelay, {
						{ "exposedName", "LPF Envelope Delay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 22 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol4_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_28", {}, { ValueTree{ ID::lpfAttack, {
						{ "exposedName", "LPF Envelope Attack" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 23 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol5_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_29", {}, { ValueTree{ ID::lpfDecay, {
						{ "exposedName", "LPF Envelope Decay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 24 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol6_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_30", {}, { ValueTree{ ID::lpfSustain, {
						{ "exposedName", "LPF Envelope Sustain" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 25 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol7_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the LPF envelope" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_31", {}, { ValueTree{ ID::lpfRelease, {
						{ "exposedName", "LPF Envelope Release" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 26 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol8_x },
						{ "controlCenter_y", GUI::lpfControlsRow3_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_32", {}, { ValueTree{ ID::vcaLevel, {
						{ "exposedName", "VCA Baseline Level" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 27 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol1_x },
						{ "controlCenter_y", GUI::vcaControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the voltage-controlled amplifier" + GUI::apostrophe + "s baseline level. Turn this\n";
	descriptionString += "up for droning sounds or when processing external audio input.\n";
	descriptionString += "When this level is set to 127, the VCA envelope has no effect.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_33", {}, { ValueTree{ ID::vcaEnvAmount, {
						{ "exposedName", "VCA Envelope Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 30 },
						{ "maxValue", 127 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::vcaControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the degree to which the VCA envelope\n";
	descriptionString += "modulates the voltage-controlled ampifier" + GUI::apostrophe + "s level.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_34", {}, { ValueTree{ ID::vcaVelAmount, {
						{ "exposedName", "VCA Envelope Velocity Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 31 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol3_x },
						{ "controlCenter_y", GUI::vcaControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the voltage-controlled ampifier" + GUI::apostrophe + "s envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_35", {}, { ValueTree{ ID::vcaDelay, {
						{ "exposedName", "VCA Envelope Delay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 32 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol4_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_36", {}, { ValueTree{ ID::vcaAttack, {
						{ "exposedName", "VCA Envelope Attack" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 33 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol5_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_37", {}, { ValueTree{ ID::vcaDecay, {
						{ "exposedName", "VCA Envelope Decay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 34 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol6_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_38", {}, { ValueTree{ ID::vcaSustain, {
						{ "exposedName", "VCA Envelope Sustain" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 35 },
						{ "maxValue", 127 },
						{ "defaultValue", 64 },
						{ "controlCenter_x", GUI::controlsCol7_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the VCA envelope" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_39", {}, { ValueTree{ ID::vcaRelease, {
						{ "exposedName", "VCA Envelope Release" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 36 },
						{ "maxValue", 127 },
						{ "defaultValue", 64 },
						{ "controlCenter_x", GUI::controlsCol8_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_40", {}, { ValueTree{ ID::voiceVolume, {
						{ "exposedName", "Program Volume" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 29 },
						{ "maxValue", 127 },
						{ "defaultValue", 120 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::vcaControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the overall gain of the current program.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	//======================================================

	for (uint8 lfoNum = 0; lfoNum != 4; ++lfoNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(41 + lfoNum * 5), {}, { ValueTree{ "lfo" + String(lfoNum + 1) + "Freq", {
							{ "exposedName", "LFO " + String(lfoNum + 1) + " Frequency" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", 37 + lfoNum * 5 },
							{ "maxValue", 166 },
							{ "defaultValue", 80 },
							{ "controlCenter_x", 416 + lfoNum * GUI::lfoControlsHorizontalSpacing },
							{ "controlCenter_y", GUI::lfoControlsRow1_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToLFOfreqString::get());
		descriptionString =  "Sets LFO " + String(lfoNum + 1) + GUI::apostrophe + "s cycle speed. Range: 0 to 166.\n";
		descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
		descriptionString += "From 90 to 150, LFO " + String(lfoNum + 1) + " has a pitched frequency, increasing\n";
		descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
		descriptionString += "Above 150, LFO " + String(lfoNum + 1) + " is synced with the step sequencer,\n";
		descriptionString += "displayed as [number of LFO cycles] : [length in steps].";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::allowedLFOfrequencies);
		allowedValuesColumnCounts.add(0);
		allowedValuesColumnWidths.add(0);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(42 + lfoNum * 5), {}, { ValueTree{ "lfo" + String(lfoNum + 1) + "Shape", {
							{ "exposedName", "LFO " + String(lfoNum + 1) + " Wave Shape" },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 38 + lfoNum * 5 },
							{ "maxValue", 4 },
							{ "defaultValue", 1 },
							{ "controlCenter_x", 463 + lfoNum * GUI::lfoControlsHorizontalSpacing },
							{ "controlCenter_y", GUI::lfoControlsRow2_y },
							{ "controlWidth", 134 },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToLFOshapeString::get());
		descriptions.add("Selects LFO " + String(lfoNum + 1) + GUI::apostrophe + "s wave shape.");
		randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
		allowedValuesColumnCounts.add(1);
		allowedValuesColumnWidths.add(134);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(43 + lfoNum * 5), {}, { ValueTree{ "lfo" + String(lfoNum + 1) + "Amount", {
							{ "exposedName", "LFO " + String(lfoNum + 1) + " Amount" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", 39 + lfoNum * 5 },
							{ "maxValue", 127 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", 461 + lfoNum * GUI::lfoControlsHorizontalSpacing },
							{ "controlCenter_y", GUI::lfoControlsRow1_y },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToPlainValueString::get());
		descriptionString =  "Sets the degree to which LFO " + String(lfoNum + 1) + "\n";
		descriptionString += "modulates the destination parameter.\n";
		descriptionString += "Range: 0 to 127.";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
		allowedValuesColumnCounts.add(13);
		allowedValuesColumnWidths.add(26);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(44 + lfoNum * 5), {}, { ValueTree{ "lfo" + String(lfoNum + 1) + "Destination", {
							{ "exposedName", "LFO " + String(lfoNum + 1) + " Modulation Destination" },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 40 + lfoNum * 5 },
							{ "maxValue", 46 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", 463 + lfoNum * GUI::lfoControlsHorizontalSpacing },
							{ "controlCenter_y", GUI::lfoControlsRow3_y },
							{ "controlWidth", 134 },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToModDestinationString::get());
		descriptions.add("Selects the target parameter for modulation by LFO " + String(lfoNum + 1) + ".");
		randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
		allowedValuesColumnCounts.add(5);
		allowedValuesColumnWidths.add(134);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(45 + lfoNum * 5), {}, { ValueTree{ "lfo" + String(lfoNum + 1) + "KeySync", {
							{ "exposedName", "LFO " + String(lfoNum + 1) + " Key Sync On/Off" },
							{ "controlType", (int)ControlType::toggleButton },
							{ "NRPN", 41 + lfoNum * 5 },
							{ "maxValue", 1 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", 507 + lfoNum * GUI::lfoControlsHorizontalSpacing },
							{ "controlCenter_y", GUI::lfoControlsRow1_y },
							{ "controlWidth", GUI::toggle_diameter },
							{ "controlHeight", GUI::toggle_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToOffOnString::get());
		descriptionString =  "When on, LFO " + String(lfoNum + 1) + GUI::apostrophe + "s cycle will reset\n";
		descriptionString += "each time a new note is played.";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
		allowedValuesColumnCounts.add(0);
		allowedValuesColumnWidths.add(0);
	}

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_61", {}, { ValueTree{ ID::env3Destination, {
						{ "exposedName", "Envelope 3 Modulation Destination" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 57 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", 126 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add("Selects the target parameter for modulation by envelope 3");
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_62", {}, { ValueTree{ ID::env3Amount, {
						{ "exposedName", "Envelope 3 Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 58 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::controlsCol2_x },
						{ "controlCenter_y", GUI::env3ControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which envelope 3\n";
	descriptionString += "modulates the destination parameter.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_63", {}, { ValueTree{ ID::env3VelAmount, {
						{ "exposedName", "Envelope 3 Velocity Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 59 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol3_x },
						{ "controlCenter_y", GUI::env3ControlsRow1_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "modulates the amplitude of envelope 3.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_64", {}, { ValueTree{ ID::env3Delay, {
						{ "exposedName", "Envelope 3 Delay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 60 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol4_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_65", {}, { ValueTree{ ID::env3Attack, {
						{ "exposedName", "Envelope 3 Attack" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 61 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol5_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_66", {}, { ValueTree{ ID::env3Decay, {
						{ "exposedName", "Envelope 3 Decay" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 62 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol6_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of the envelope 3" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_67", {}, { ValueTree{ ID::env3Sustain, {
						{ "exposedName", "Envelope 3 Sustain" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 63 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol7_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets envelope 3" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_68", {}, { ValueTree{ ID::env3Release, {
						{ "exposedName", "Envelope 3 Release" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 64 },
						{ "maxValue", 127 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol8_x },
						{ "controlCenter_y", GUI::env3ControlsRow2_y },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_69", {}, { ValueTree{ ID::env3Repeat, {
						{ "exposedName", "Envelope 3 Repeat" },
						{ "controlType", (int)ControlType::toggleButton },
						{ "NRPN", 98 },
						{ "maxValue", 1 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol1_x },
						{ "controlCenter_y", GUI::env3ControlsRow1_y },
						{ "controlWidth", GUI::toggle_diameter },
						{ "controlHeight", GUI::toggle_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToOffOnString::get());
	descriptionString =  "When repeat is on, envelope 3 loops through\n";
	descriptionString += "its delay, attack, decay, and sustain segments\n";
	descriptionString += "for as long as the envelope is gated on.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
	allowedValuesColumnCounts.add(0);
	allowedValuesColumnWidths.add(0);

	//======================================================

	String modSourceDescription{ "Selects the modulation source." };
	String modAmountDescription = "Sets the degree to which the selected source\n";
	modAmountDescription += "modulates the selected destination parameter.\n";
	modAmountDescription += "Negative values invert the modulation.\nRange: -127 to +127.";
	String modDestinationDescription{ "Selects the target parameter for modulation." };

	for (uint8 modNum = 0; modNum != 4; ++modNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(70 + modNum * 3), {}, { ValueTree{ "mod" + (String)(modNum + 1) + "Source", {
							{ "exposedName", "Modulator " + (String)(modNum + 1) + " Source" },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 65 + 3 * modNum },
							{ "maxValue", 22 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", GUI::modulatorControlsCol1_x },
							{ "controlCenter_y", 184 + modNum * GUI::modulatorControlsVerticalSpacing },
							{ "controlWidth", GUI::modulatorComboBox_w },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToModSourceString::get());
		descriptions.add(modSourceDescription);
		randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
		allowedValuesColumnCounts.add(2);
		allowedValuesColumnWidths.add(GUI::modulatorComboBox_w);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(71 + modNum * 3), {}, { ValueTree{ "mod" + (String)(modNum + 1) + "Amount", {
							{ "exposedName", "Modulator " + (String)(modNum + 1) + " Amount" },
							{ "controlType", (int)ControlType::knobWithValueStringDisplay },
							{ "NRPN", 66 + 3 * modNum },
							{ "maxValue", 254 },
							{ "defaultValue", 127 },
							{ "controlCenter_x", GUI::modulatorControlsCol2_x },
							{ "controlCenter_y", 201 + modNum * GUI::modulatorControlsVerticalSpacing },
							{ "controlWidth", GUI::knob_diameter },
							{ "controlHeight", GUI::knob_diameter },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToPlusMinus127String::get());
		descriptions.add(modAmountDescription);
		randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
		allowedValuesColumnCounts.add(26);
		allowedValuesColumnWidths.add(32);

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + (String)(72 + modNum * 3), {}, { ValueTree{ "mod" + (String)(modNum + 1) + "Destination", {
							{ "exposedName", "Modulator " + (String)(modNum + 1) + " Destination" },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 67 + 3 * modNum },
							{ "maxValue", 46 },
							{ "defaultValue", 0 },
							{ "controlCenter_x", GUI::modulatorControlsCol1_x },
							{ "controlCenter_y", 218 + modNum * GUI::modulatorControlsVerticalSpacing },
							{ "controlWidth", GUI::modulatorComboBox_w },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToModDestinationString::get());
		descriptions.add(modDestinationDescription);
		randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
		allowedValuesColumnCounts.add(5);
		allowedValuesColumnWidths.add(134);
	}

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_82", {}, { ValueTree{ ID::modWheelAmount, {
						{ "exposedName", "Modulation Wheel Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 81 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::midiControllersCol2_x },
						{ "controlCenter_y", 191 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which MIDI modulation wheel controller\n";
	descriptionString += "messages (CC#1) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_83", {}, { ValueTree{ ID::modWheelDest, {
						{ "exposedName", "Modulation Wheel Destination" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 82 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::midiControllersCol1_x },
						{ "controlCenter_y", 191 },
						{ "controlWidth", GUI::midiControllerComboBox_w },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add(modDestinationDescription);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_84", {}, { ValueTree{ ID::pressureAmount, {
						{ "exposedName", "Pressure (Aftertouch) Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "NRPN", 83 },
						{ "controlCenter_x", GUI::midiControllersCol2_x },
						{ "controlCenter_y", 253 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which MIDI channel pressure\n";
	descriptionString += "(aftertouch) messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_85", {}, { ValueTree{ ID::pressureDest, {
						{ "exposedName", "Pressure (Aftertouch) Destination" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 84 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::midiControllersCol1_x },
						{ "controlCenter_y", 253 },
						{ "controlWidth", GUI::midiControllerComboBox_w },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add(modDestinationDescription);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_86", {}, { ValueTree{ ID::breathAmount, {
						{ "exposedName", "Breath Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 85 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::midiControllersCol2_x },
						{ "controlCenter_y", 315 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which MIDI breath controller\n";
	descriptionString += "messages (CC#2) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_87", {}, { ValueTree{ ID::breathDest, {
						{ "exposedName", "Breath Destination" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 86 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::midiControllersCol1_x },
						{ "controlCenter_y", 315 },
						{ "controlWidth", GUI::midiControllerComboBox_w },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add(modDestinationDescription);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_88", {}, { ValueTree{ ID::velocityAmount, {
						{ "exposedName", "Note Velocity Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 87 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::midiControllersCol2_x },
						{ "controlCenter_y", 377 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_89", {}, { ValueTree{ ID::velocityDest, {
						{ "exposedName", "Note Velocity Destination" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 88 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::midiControllersCol1_x },
						{ "controlCenter_y", 377 },
						{ "controlWidth", GUI::midiControllerComboBox_w },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add(modDestinationDescription);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_90", {}, { ValueTree{ ID::footPedalAmount, {
						{ "exposedName", "Foot Pedal Amount" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 89 },
						{ "maxValue", 254 },
						{ "defaultValue", 127 },
						{ "controlCenter_x", GUI::midiControllersCol2_x },
						{ "controlCenter_y", 439 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlusMinus127String::get());
	descriptionString =  "Sets the degree to which MIDI foot pedal controller\n";
	descriptionString += "messages (CC#4) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(26);
	allowedValuesColumnWidths.add(32);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_91", {}, { ValueTree{ ID::footPedalDest, {
						{ "controlType", (int)ControlType::comboBox },
						{ "exposedName", "Foot Pedal Destination" },
						{ "NRPN", 90 },
						{ "maxValue", 46 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::midiControllersCol1_x },
						{ "controlCenter_y", 439 },
						{ "controlWidth", GUI::midiControllerComboBox_w },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToModDestinationString::get());
	descriptions.add(modDestinationDescription);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_92", {}, { ValueTree{ ID::pushItPitch, {
						{ "exposedName", "Push It! Switch Pitch" },
						{ "controlType", (int)ControlType::knobForPitchWithValueStringDisplay },
						{ "NRPN", 111 },
						{ "maxValue", 120 },
						{ "defaultValue", 60 },
						{ "controlCenter_x", 1191 },
						{ "controlCenter_y", 528 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToOscPitchString::get());
	descriptionString =  "Sets the note that plays when the Push It! switch is pressed.\n";
	descriptionString += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.\n";
	descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
	descriptionString += "increment the pitch by one octave (12 semitones).";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::allowedValues);
	allowedValuesColumnCounts.add(11);
	allowedValuesColumnWidths.add(40);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_93", {}, { ValueTree{ ID::pushItVelocity, {
						{ "exposedName", "Push It! Switch Velocity" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 112 },
						{ "maxValue", 127 },
						{ "defaultValue", 100 },
						{ "controlCenter_x", 1239 },
						{ "controlCenter_y", 528 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPlainValueString::get());
	descriptionString =  "Sets the velocity of the note that plays\n";
	descriptionString += "when the Push It! switch is pressed.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(13);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_94", {}, { ValueTree{ ID::pushItMode, {
						{ "exposedName", "Push It! Switch Mode" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 113 },
						{ "maxValue", 2 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", 1215 },
						{ "controlCenter_y", 577 },
						{ "controlWidth", 88 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToPushItModeString::get());
	descriptionString =  "Sets the operating mode for the Mopho" + GUI::apostrophe + "s Push It! switch.\n";
	descriptionString += "Normal: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and gated off when the switch is released.\n";
	descriptionString += "Toggle: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and remains on until the switch is pressed again.\n";
	descriptionString += "Audio In: The selected note is gated on for as long as the\n";
	descriptionString += "external audio input level is above a certain threshold.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(88);

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_95", {}, { ValueTree{ ID::clockTempo, {
						{ "exposedName", "Clock Tempo" },
						{ "controlType", (int)ControlType::knobWithValueStringDisplay },
						{ "NRPN", 91 },
						{ "maxValue", 220 },
						{ "defaultValue", 90 },
						{ "controlCenter_x", 1236 },
						{ "controlCenter_y", 126 },
						{ "controlWidth", GUI::knob_diameter },
						{ "controlHeight", GUI::knob_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToClockTempoString::get());
	descriptionString =  "Sets the tempo (in beats per minute)\n";
	descriptionString += "for the sequencer and the arpeggiator.\n";
	descriptionString += "Range: 30 to 250 BPM.\n";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::valueRange);
	allowedValuesColumnCounts.add(23);
	allowedValuesColumnWidths.add(26);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_96", {}, { ValueTree{ ID::clockDivision, {
						{ "exposedName", "Clock Division" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 92 },
						{ "maxValue", 12 },
						{ "defaultValue", 2 },
						{ "controlCenter_x", 1139 },
						{ "controlCenter_y", 126 },
						{ "controlWidth", 124 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToClockDivString::get());
	descriptionString =  "Sets the rate at which the sequencer and\n";
	descriptionString += "arpeggiator advance, relative to the tempo.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(124);

	//======================================================

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_97", {}, { ValueTree{ ID::arpegMode, {
						{ "exposedName", "Arpeggiator Mode" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 97 },
						{ "maxValue", 14 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol10_x },
						{ "controlCenter_y", 118 },
						{ "controlWidth", 124 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToArpegModeString::get());
	descriptionString =  "Sets the order in which the arpeggiator plays notes.\n";
	descriptionString += "Assign mode: notes play in the order in which they were struck.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(124);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_98", {}, { ValueTree{ ID::arpegOnOff, {
						{ "exposedName", "Arpeggiator On/Off" },
						{ "controlType", (int)ControlType::toggleButton },
						{ "NRPN", 100 },
						{ "maxValue", 1 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", GUI::controlsCol9_x },
						{ "controlCenter_y", GUI::oscControlsRow2_y },
						{ "controlWidth", GUI::toggle_diameter },
						{ "controlHeight", GUI::toggle_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToOffOnString::get());
	descriptionString =  "Turns the Mopho" + GUI::apostrophe + "s arpeggiator on and off.\n";
	descriptionString += "Turning this on will turn off the sequencer.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
	allowedValuesColumnCounts.add(0);
	allowedValuesColumnWidths.add(0);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_99", {}, { ValueTree{ ID::sequencerTrigMode, {
						{ "exposedName", "Sequencer Trigger Mode" },
						{ "controlType", (int)ControlType::comboBox },
						{ "NRPN", 94 },
						{ "maxValue", 5 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", 998 },
						{ "controlCenter_y", 126 },
						{ "controlWidth", 114 },
						{ "controlHeight", GUI::comboBox_h },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToSeqTrigModeString::get());
	descriptionString =  "Normal: New notes reset the sequencer to the first step.\n";
	descriptionString += "The envelopes are re-triggered with each step.\n";
	descriptionString += "Normal, No Reset: New notes do not reset the sequencer to the\n";
	descriptionString += "first step. The envelopes are re-triggered with each step.\n";
	descriptionString += "No Gate: New notes reset the sequencer to the first step. New\n";
	descriptionString += "notes re-trigger the envelopes, but sequencer steps do not.\n";
	descriptionString += "No Gate, No Reset: New notes do not reset the sequencer to the\n";
	descriptionString += "first step. Sequencer steps do not re-trigger the envelopes.\n";
	descriptionString += "Key Step: Each new note advances the sequencer one step.\n";
	descriptionString += "Audio Input: The sequencer advances one step every time the\n";
	descriptionString += "external audio input level surpasses a certain threshold.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(1);
	allowedValuesColumnWidths.add(114);

	exposedParamsInfoTree.addChild(
		ValueTree{ "exposedParam_100", {}, { ValueTree{ ID::sequencerOnOff, {
						{ "exposedName", "Sequencer On/Off" },
						{ "controlType", (int)ControlType::toggleButton },
						{ "NRPN", 101 },
						{ "maxValue", 1 },
						{ "defaultValue", 0 },
						{ "controlCenter_x", 819 },
						{ "controlCenter_y", 126 },
						{ "controlWidth", GUI::toggle_diameter },
						{ "controlHeight", GUI::toggle_diameter },
					}, {} } }
		},
		-1,
		nullptr
	);

	converters.add(IntToOffOnString::get());
	descriptionString =  "Turns the Mopho" + GUI::apostrophe + "s internal sequencer on and off.\n";
	descriptionString += "Turning this on will turn off the arpeggiator.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::toggles);
	allowedValuesColumnCounts.add(0);
	allowedValuesColumnWidths.add(0);

	for (uint8 trackNum = 0; trackNum != 4; ++trackNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_10" + String(trackNum + 1), {}, { ValueTree{ "seqTrack" + String(trackNum + 1) + "Dest", {
							{ "exposedName", "Sequencer Track " + String(trackNum + 1) + " Destination" },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 77 + trackNum },
							{ "maxValue", trackNum == 0 || trackNum == 2 ? 46 : 47 },
							{ "defaultValue", trackNum < 2 ? trackNum + 1 : trackNum == 2 ? 9 : 0 },
							{ "controlCenter_x", GUI::seqTrackDestComboBoxes_x },
							{ "controlCenter_y", 169 + trackNum * GUI::sequencerTracksVerticalSpacer },
							{ "controlWidth", GUI::seqTrackDestComboBoxes_w },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);
	}

	converters.add(IntToModDestinationString::get());
	descriptionString =  "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 1.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	converters.add(IntToSeqTrack2DestinationString::get());
	descriptionString =  "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 2.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	converters.add(IntToModDestinationString::get());
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 3.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	converters.add(IntToSeqTrack4DestinationString::get());
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 4.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(5);
	allowedValuesColumnWidths.add(134);

	//======================================================

	for (uint8 knobNum = 0; knobNum != 4; ++knobNum) {
		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_10" + String(knobNum + 5), {}, { ValueTree{ "assignKnob" + String(knobNum + 1), {
							{ "exposedName", "Assign Parameter to Knob " + String(knobNum + 1) },
							{ "controlType", (int)ControlType::comboBox },
							{ "NRPN", 105 + knobNum },
							{ "maxValue", 168 },
							{ "defaultValue", knobNum == 0 ? 5 : knobNum == 1 ? 11 : knobNum == 2 ? 43 : 23 },
							{ "controlCenter_x", GUI::knobAssignComboBoxes_x },
							{ "controlCenter_y", 521 + knobNum * GUI::knobAssignComboBoxesVerticalSpacer },
							{ "controlWidth", GUI::knobAssignComboBoxes_w },
							{ "controlHeight", GUI::comboBox_h },
						}, {} } }
			},
			-1,
			nullptr
		);
	}

	converters.add(IntToParamNameString::get());
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 1.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(9);
	allowedValuesColumnWidths.add(GUI::knobAssignComboBoxes_w);

	converters.add(IntToParamNameString::get());
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 2.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(9);
	allowedValuesColumnWidths.add(GUI::knobAssignComboBoxes_w);

	converters.add(IntToParamNameString::get());
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 3.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(9);
	allowedValuesColumnWidths.add(GUI::knobAssignComboBoxes_w);

	converters.add(IntToParamNameString::get());
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 4.";
	descriptions.add(descriptionString);
	randomizationOptionsTypes.add(RandomizationOptionsType::comboBoxes);
	allowedValuesColumnCounts.add(9);
	allowedValuesColumnWidths.add(GUI::knobAssignComboBoxes_w);

	//======================================================

	// Parameters 109-119 are unused

	//======================================================

	for (auto track = 0; track != 4; ++track) {
		for (auto step = 0; step != 16; ++step) {
			auto trackString{ (String)(track + 1) };
			auto stepString{ (String)(step + 1) };

			exposedParamsInfoTree.addChild(
				ValueTree{ "exposedParam_" + String(109 + (track * 16 + step)), {}, { ValueTree{ "seqTrack" + trackString + "Step" + stepString, {
								{ "exposedName", "Sequencer Track " + trackString + " Step " + stepString },
								{ "controlType", (int)ControlType::sequencerStep },
								{ "NRPN", params::paramNumForSeqTrack1Step1 + (16 * track) + step },
								{ "maxValue", track == 0 ? 127 : 126 },
								{ "defaultValue", 0 },
								{ "controlCenter_x", GUI::sequencerStep1_center_x + step * GUI::sequencerStepsHorizontalSpacer },
								{ "controlCenter_y", GUI::sequencerTrack1Steps_center_y + track * GUI::sequencerTracksVerticalSpacer },
								{ "controlWidth", GUI::seqSteps_w },
								{ "controlHeight", GUI::seqSteps_h },
							}, {} } }
				},
				-1,
				nullptr
			);

			converters.add(IntToSeqStepValueString::get());
			descriptionString =  "Sets the value that sequencer track " + trackString + GUI::apostrophe + "s destination parameter has at step " + stepString + ",\n";
			descriptionString += "Range: 0 to 125. If the target is an oscillator pitch, the range is C0 to D5+.\n";
			descriptionString += "A " + GUI::openQuote + "+" + GUI::closeQuote + " indicates that the pitch is a quarter-tone higher than the displayed note.\n";
			descriptionString += "Reset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";
			if (track == 0) {
				descriptionString += "\nRest (127): The step produces no output. ALT-click a step to make it a rest\n";
				descriptionString += "(Rests are only available for the steps in sequencer track 1).";
			}
			descriptionString += "\nHold down the SHIFT key while using the mouse wheel to increment the step\n";
			descriptionString += "value by 24 (equivalent to one octave, including the " + GUI::openQuote + "bent" + GUI::closeQuote + " pitch values).";
			descriptions.add(descriptionString);
			randomizationOptionsTypes.add(RandomizationOptionsType::allowedSeqTrackStepValues);
			allowedValuesColumnCounts.add(0);
			allowedValuesColumnWidths.add(0);
		}
	}

	//======================================================

	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };

		exposedParamsInfoTree.addChild(
			ValueTree{ "exposedParam_" + String(173 + charNum), {}, { ValueTree{ "nameChar" + charNumString, {
							{ "exposedName", "Program Name Character " + charNumString },
							{ "controlType", (int)ControlType::voiceNameChar },
							{ "NRPN", params::paramNumFor1stNameChar + charNum },
							{ "maxValue", 127 },
							{ "defaultValue", int(String("Basic Program   ")[charNum]) },
							{ "controlCenter_x", GUI::voiceNameCharacter1_x + (charNum * GUI::voiceNameCharactersHorizontalSpacer) },
							{ "controlCenter_y", GUI::voiceNameCharacters_y },
							{ "controlWidth", GUI::voiceNameCharacters_w },
							{ "controlHeight", GUI::voiceNameCharacters_h },
						}, {} } }
			},
			-1,
			nullptr
		);

		converters.add(IntToVoiceNameCharString::get());
		descriptionString =  "To change character " + charNumString + " of the program" + GUI::apostrophe + "s name,\n";
		descriptionString += "click-and-drag the character or hover over\n";
		descriptionString += "it and turn the mouse wheel. Click the edit\n";
		descriptionString += "button above to type in the entire name.";
		descriptions.add(descriptionString);
		randomizationOptionsTypes.add(RandomizationOptionsType::none);
		allowedValuesColumnCounts.add(9);
		allowedValuesColumnWidths.add(GUI::knobAssignComboBoxes_w);
		allowedValuesColumnCounts.add(13);
		allowedValuesColumnWidths.add(20);
	}

	for (uint8 param = 0; param != params::numberOfExposedParams; ++param) {
		if (param < 92)
			exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)param).getChild(0).setProperty("paramIndex", param, nullptr);
		fillDataByteLocationsFor(param);
	}
}

void InfoForExposedParameters::fillDataByteLocationsFor(uint8 param) {
	auto offsetParam{ offsetParamToAccountForUnassignedParams109to119(param) };
	uint16 msBitPackedByteLocation{ (uint16)((offsetParam / 7) * 8) };
	msBitPackedByteLocations.add(msBitPackedByteLocation);
	uint16 lsByteLocation{ (uint16)(msBitPackedByteLocation + offsetParam % 7 + 1) };
	lsByteLocations.add(lsByteLocation);
	uint8 msBitMask{ (uint8)(roundToInt(pow(2, offsetParam % 7))) };
	msBitMasks.add(msBitMask);
}

uint16 InfoForExposedParameters::offsetParamToAccountForUnassignedParams109to119(uint16 param) {
	return param < 109 ? param : param + 11;
}

InfoForExposedParameters& InfoForExposedParameters::get() noexcept {
	static InfoForExposedParameters exposedParamsInfo;
	return exposedParamsInfo;
}

Identifier InfoForExposedParameters::IDfor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	return paramTree.getChild(0).getType().toString();
}

String InfoForExposedParameters::exposedNameFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	return paramTree.getChild(0).getProperty("exposedName").toString();
}

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto controlType{ (int)paramTree.getChild(0).getProperty("controlType") };
	switch (controlType)
	{
	case (int)ControlType::knobWithValueStringDisplay:
		return ControlType::knobWithValueStringDisplay;
	case (int)ControlType::knobForPitchWithValueStringDisplay:
		return ControlType::knobForPitchWithValueStringDisplay;
	case (int)ControlType::knobWithWaveShapeDisplay:
		return ControlType::knobWithWaveShapeDisplay;
	case (int)ControlType::toggleButton:
		return ControlType::toggleButton;
	case (int)ControlType::comboBox:
		return ControlType::comboBox;
	case (int)ControlType::sequencerStep:
		return ControlType::sequencerStep;
	case (int)ControlType::voiceNameChar:
		return ControlType::voiceNameChar;
	default:
		return ControlType::nullControl;
	}
}

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto NRPN{ (int)paramTree.getChild(0).getProperty("NRPN") };
	return (uint8)NRPN;
}

IntToContextualStringConverter* InfoForExposedParameters::converterFor(uint8 paramIndex) const {
	return converters[paramIndex];
}

uint8 InfoForExposedParameters::maxValueFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto maxValue{ (int)paramTree.getChild(0).getProperty("maxValue") };
	return (uint8)maxValue;
}

uint8 InfoForExposedParameters::defaultValueFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto defaultValue{ (int)paramTree.getChild(0).getProperty("defaultValue") };
	return (uint8)defaultValue;
}

uint8 InfoForExposedParameters::numberOfStepsFor(uint8 paramIndex) const {
	return uint8(maxValueFor(paramIndex) + 1);
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) const {
	return descriptions[paramIndex];
}

Point<int> InfoForExposedParameters::controlCenterPointFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex).getChild(0) };
	auto controlCenter_x{ (int)paramTree.getProperty("controlCenter_x") };
	auto controlCenter_y{ (int)paramTree.getProperty("controlCenter_y") };
	return Point<int>(controlCenter_x, controlCenter_y);
}

int InfoForExposedParameters::controlWidthFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto controlWidth{ (int)paramTree.getChild(0).getProperty("controlWidth") };
	return controlWidth;
}

int InfoForExposedParameters::controlHeightFor(uint8 paramIndex) const {
	jassert(paramIndex < params::numberOfExposedParams);
	auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex) };
	auto controlHeight{ (int)paramTree.getChild(0).getProperty("controlHeight") };
	return controlHeight;
}

uint8 InfoForExposedParameters::indexForParamID(const String& parameterID) const {
	for (auto paramIndex = (uint8)0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		auto paramTree{ exposedParamsInfoTree.getChildWithName("exposedParam_" + (String)paramIndex).getChild(0) };
		if (paramTree.hasType(parameterID))
			return paramIndex;
	}
	return (uint8)255;
}

uint16 InfoForExposedParameters::msBitPackedByteLocationFor(uint8 paramIndex) const {
	return msBitPackedByteLocations[paramIndex];
}

uint16 InfoForExposedParameters::lsByteLocationFor(uint8 paramIndex) const {
	return lsByteLocations[paramIndex];
}

uint8 InfoForExposedParameters::msBitMaskFor(uint8 paramIndex) const {
	return msBitMasks[paramIndex];
}

RandomizationOptionsType InfoForExposedParameters::randomizationOptionsTypeFor(uint8 paramIndex) const {
	return randomizationOptionsTypes[paramIndex];
}

int InfoForExposedParameters::numberOfAllowedValuesColumnsFor(uint8 paramIndex) const {
	return allowedValuesColumnCounts[paramIndex];
}

int InfoForExposedParameters::widthOfAllowedValuesColumnFor(uint8 paramIndex) const {
	return allowedValuesColumnWidths[paramIndex];
}

int InfoForExposedParameters::numberOfAllowedValuesRowsFor(uint8 paramIndex) const {
	return allowedValuesRowsCounts[paramIndex];
}

int InfoForExposedParameters::firstAllowedValuesRowFor(uint8 paramIndex) const {
	return allowedValuesFirstRows[paramIndex];
}

int InfoForExposedParameters::randomizationOptions_x_For(uint8 paramIndex) const {
	return randomizationOptionsTopLeftCoordinates[paramIndex].getX();
}

int InfoForExposedParameters::randomizationOptions_y_For(uint8 paramIndex) const {
	return randomizationOptionsTopLeftCoordinates[paramIndex].getY();
}

uint8 InfoForExposedParameters::paramIndexForNRPN(const uint8 NRPN) const {
	for (auto paramIndex = (uint8)0; paramIndex != params::numberOfExposedParams; ++paramIndex) {
		if (NRPNfor(paramIndex) == NRPN)
			return paramIndex;
	}
	return (uint8)255;
}

