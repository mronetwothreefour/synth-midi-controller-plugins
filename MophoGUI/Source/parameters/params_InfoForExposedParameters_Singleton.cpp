#include "params_InfoForExposedParameters_Singleton.h"

InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	const auto knob_diameter{ 40 };
	const auto toggle_diameter{ 14 };
	const auto modulatorComboBox_w{ 126 };
	const auto midiControllerComboBox_w{ 136 };
	const auto seqTrackDestComboBoxes_w{ 126 };
	const auto seqSteps_w{ 26 };
	const auto seqSteps_h{ 26 };
	const auto knobAssignComboBoxes_w{ 134 };
	const auto comboBox_h{ 16 };
	const auto horizGapBtwnControls{ 5 };
	const auto controlsCol1_x{ 48 };
	const auto controlsCol2_x{ controlsCol1_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol3_x{ controlsCol2_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol4_x{ controlsCol3_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol5_x{ controlsCol4_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol6_x{ controlsCol5_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol7_x{ controlsCol6_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol8_x{ controlsCol7_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol9_x{ controlsCol8_x + knob_diameter + horizGapBtwnControls };
	const auto controlsCol10_x{ 500 };
	const auto modulatorControlsCol1_x{ 486 };
	const auto modulatorControlsCol2_x{ 575 };
	const auto midiControllerssCol1_x{ 680 };
	const auto midiControllerssCol2_x{ 776 };
	const auto oscControlsRow1_y{ 50 };
	const auto oscControlsRow2_y{ 110 };
	const auto lpfControlsRow1_y{ 161 };
	const auto lpfControlsRow2_y{ 215 };
	const auto lpfControlsRow3_y{ 267 };
	const auto vcaControlsRow1_y{ 373 };
	const auto vcaControlsRow2_y{ 425 };
	const auto lfoControlsRow1_y{ 515 };
	const auto lfoControlsRow2_y{ 560 };
	const auto lfoControlsRow3_y{ 594 };
	const auto env3ControlsRow1_y{ 531 };
	const auto env3ControlsRow2_y{ 583 };
	const auto seqTrackDestComboBoxes_x{ 1055 };
	const auto knobAssignComboBoxes_x{ 1089 };
	const auto sequencerStep1_x{ 825 };
	const auto sequencerStepsHorizontalSpacer{ 28 };
	const auto sequencerTrack1Steps_y{ 196 };
	const auto sequencerTracksVerticalSpacer{ 83 };
	const auto pgmNameCharacter1_x{ 596 };
	const auto pgmNameCharactersHorizontalSpacer{ 14 };
	const auto pgmNameCharacters_w{ 12 };
	const auto pgmNameCharacters_h{ 17 };
	const auto pgmNameCharacters_y{ 52 };

	String descriptionString;

	//======================================================

	identifiers.add("osc1Pitch"); // 0
	exposedNames.add("Oscillator 1 Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)0); 
	converters.add(IntToOscPitchString::get()); 
	maxValues.add((uint8)120); 
	defaultValues.add((uint8)24);
	descriptionString =  "Sets oscillator 1's base pitch in semitone steps.\n";
	descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, oscControlsRow1_y));

	identifiers.add("osc1Fine"); // 1
	exposedNames.add("Oscillator 1 Fine Tune");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)1); 
	converters.add(IntToFineTuneString::get());
	maxValues.add((uint8)100); 
	defaultValues.add((uint8)49);
	descriptionString =  "Fine tunes oscillator 1's base pitch.\n";
	descriptionString += "Range: -50 cents to +50 cents.\n";
	descriptionString += "0 = no detuning (centered).";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, oscControlsRow1_y));

	identifiers.add("osc1Shape"); // 2
	exposedNames.add("Oscillator 1 Wave Shape");
	controlTypes.add(ControlType::knobWithWaveShapeDisplay);
	NRPNs.add((uint16)2); 
	converters.add(IntToOscWaveShapeString::get());
	maxValues.add((uint8)103); 
	defaultValues.add((uint8)1);
	descriptionString =  "Selects oscillator 1's wave shape.\n";
	descriptionString += "Available options: Off; Sawtooth; Triangle;\n";
	descriptionString += "Sawtooth/Triangle Mix; Pulse (Width 0 to 99).\n";
	descriptionString += "A Pulse with width 50 is a square wave.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, oscControlsRow1_y));

	identifiers.add("osc1Glide"); // 3
	exposedNames.add("Oscillator 1 Glide Rate");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)3); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptionString =  "Sets oscillator 1's glide (portamento) rate.\n";
	descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol4_x, oscControlsRow1_y));

	identifiers.add("osc1KeyTrack"); // 4
	exposedNames.add("Oscillator 1 Keyboard Track On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)4); 
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1); 
	defaultValues.add((uint8)1);
	descriptionString =  "Turns keyboard tracking for oscillator 1\n";
	descriptionString += "on or off. When turned off, oscillator 1\n";
	descriptionString += "always produces its base pitch, unaffected\n";
	descriptionString += "by the pitch of incoming MIDI notes.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, oscControlsRow1_y));

	identifiers.add("osc1SubLevel"); // 5
	exposedNames.add("Sub-Oscillator 1 Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)114); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the level of sub-oscillator 1,\n";
	descriptionString += "which generates a square wave pitched\n";
	descriptionString += "one octave lower than oscillator 1.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol5_x, 50));

	identifiers.add("osc2Pitch"); // 6
	exposedNames.add("Oscillator 2 Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)5); 
	converters.add(IntToOscPitchString::get()); 
	maxValues.add((uint8)120); 
	defaultValues.add((uint8)24);
	descriptionString =  "Sets oscillator 2's base pitch in semitone steps.\n";
	descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, oscControlsRow2_y));

	identifiers.add("osc2Fine"); // 7
	exposedNames.add("Oscillator 2 Fine Tune");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)6); 
	converters.add(IntToFineTuneString::get());
	maxValues.add((uint8)100); 
	defaultValues.add((uint8)51);
	descriptionString =  "Fine tunes oscillator 2's base pitch.\n";
	descriptionString += "Range: -50 cents to +50 cents.\n";
	descriptionString += "0 = no detuning (centered).";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, oscControlsRow2_y));

	identifiers.add("osc2Shape"); // 8
	exposedNames.add("Oscillator 2 Wave Shape");
	controlTypes.add(ControlType::knobWithWaveShapeDisplay);
	NRPNs.add((uint16)7); 
	converters.add(IntToOscWaveShapeString::get());
	maxValues.add((uint8)103); 
	defaultValues.add((uint8)1);
	descriptionString =  "Selects oscillator 2's wave shape.\n";
	descriptionString += "Available options: Off; Sawtooth; Triangle;\n";
	descriptionString += "Sawtooth/Triangle Mix; Pulse (Width 0 to 99).\n";
	descriptionString += "A Pulse with width 50 is a square wave.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, oscControlsRow2_y));

	identifiers.add("osc2Glide"); // 9
	exposedNames.add("Oscillator 2 Glide Rate");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)8); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptionString =  "Sets oscillator 2's glide (portamento) rate.\n";
	descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol4_x, oscControlsRow2_y));

	identifiers.add("osc2KeyTrack"); // 10
	exposedNames.add("Oscillator 2 Keyboard Track On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)9); 
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1); 
	defaultValues.add((uint8)1);
	descriptionString =  "Turns keyboard tracking for oscillator 2\n";
	descriptionString += "on or off. When turned off, oscillator 2\n";
	descriptionString += "always produces its base pitch, unaffected\n";
	descriptionString += "by the pitch of incoming MIDI notes.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, oscControlsRow2_y));

	identifiers.add("osc2SubLevel"); // 11
	exposedNames.add("Sub-Oscillator 2 Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)115); 
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127); 
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the level of sub-oscillator 2,\n";
	descriptionString += "which generates a square wave pitched\n";
	descriptionString += "one octave lower than oscillator 2.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol5_x, oscControlsRow2_y));

	identifiers.add("oscSync"); // 12
	exposedNames.add("Hard Oscillator Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)10);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns hard oscillator sync on or off. When\n";
	descriptionString += "turned on, every time oscillator 2 resets,\n";
	descriptionString += "it forces oscillator 1 to reset as well.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, 22));

	//======================================================

	identifiers.add("glideMode"); // 13
	exposedNames.add("Glide Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)11);
	converters.add(IntToGlideModeString::get());
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
	descriptionString += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
	descriptionString += "The Auto modes only apply glide when a note is played legato\n";
	descriptionString += "(the new note is triggered before the previous note is released).";
	descriptions.add(descriptionString);
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(controlsCol10_x, 78));

	identifiers.add("oscSlop"); // 14
	exposedNames.add("Oscillator Slop");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)12);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)2);
	descriptionString =  "Introduces a subtle amount of random oscillator\n";
	descriptionString += "pitch drift for a \"vintage analog\" sound.\n";
	descriptionString += "Range: 0 to 5.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol7_x, oscControlsRow1_y));

	identifiers.add("bendRange"); // 15
	exposedNames.add("Pitch Bend Range");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)93);
	converters.add(IntToBendRangeString::get());
	maxValues.add((uint8)12);
	defaultValues.add((uint8)4);
	descriptionString =  "Sets the maximum amount (in semitones) by which pitch wheel\n";
	descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
	descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol9_x, oscControlsRow1_y));

	identifiers.add("notePriority"); // 16
	exposedNames.add("Note Priority (Key Assign)");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)96);
	converters.add(IntToNotePriorityString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects which note is given priority when multiple\n";
	descriptionString += "notes are played, and whether the envelopes are\n";
	descriptionString += "re-triggered when a note is played legato (before\n";
	descriptionString += "the previous note has been released).";
	descriptions.add(descriptionString);
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(controlsCol10_x, 38));

	identifiers.add("oscMix"); // 17
	exposedNames.add("Oscillator 1 & 2 Mix");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)13);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Controls the level balance between oscillators 1 & 2.\n";
	descriptionString += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
	descriptionString += "At 127, only oscillator 2 is heard. At 64, an equal\n";
	descriptionString += "mix of the two oscillators is heard.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol8_x, oscControlsRow1_y));

	identifiers.add("noiseLevel"); // 18
	exposedNames.add("Noise Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)14);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the level of white noise\n";
	descriptionString += "sent into the low-pass filter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol7_x, oscControlsRow2_y));

	identifiers.add("extInLevel"); // 19
	exposedNames.add("External Audio Input Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)116);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the level of external audio\n";
	descriptionString += "input sent into the low-pass filter.\n";
	descriptionString += "When nothing is connected to audio in,\n";
	descriptionString += "this controls the level of feedback\n";
	descriptionString += "from the left audio output.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol8_x, oscControlsRow2_y));

	//======================================================

	identifiers.add("lpfFreq"); // 20
	exposedNames.add("LPF Cutoff Frequency");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)15);
	converters.add(IntToLPFfreqString::get());
	maxValues.add((uint8)164);
	defaultValues.add((uint8)148);
	descriptionString =  "Sets the base cutoff frequency for the\n";
	descriptionString += "low-pass filter (in semitone steps).\n";
	descriptionString += "Range: 0 (C 0) to 164 (G# 13).";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, lpfControlsRow2_y));

	identifiers.add("lpfReso"); // 21
	exposedNames.add("LPF Resonance");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)16);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the resonance level of the low-pass\n";
	descriptionString += "filter. When in 4-pole mode, high settings\n";
	descriptionString += "will cause the filter to self-oscillate.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, lpfControlsRow2_y));

	identifiers.add("lpfKeyAmount"); // 22
	exposedNames.add("LPF Keyboard Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)17);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the amount by which keyboard (MIDI) notes\n";
	descriptionString += "will shift the low-pass filter's cutoff frequency.\n";
	descriptionString += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
	descriptionString += "semitone for each note. At 32, cutoff is shifted\n";
	descriptionString += "by one half-semitone for each note.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, lpfControlsRow2_y));

	identifiers.add("lpfFMamount"); // 23
	exposedNames.add("LPF FM (By Oscillator 1)");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)18);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which oscillator 1 modulates\n";
	descriptionString += "the low-pass filter's cutoff frequency. This is\n";
	descriptionString += "useful for generating bell-like sounds.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, lpfControlsRow3_y));

	identifiers.add("lpfType"); // 24
	exposedNames.add("LPF Type");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)19);
	converters.add(IntToLPFtypeString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)1);
	descriptionString =  "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
	descriptionString += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
	descriptionString += "slope and more pronounced resonance.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, lpfControlsRow1_y));

	identifiers.add("lpfEnvAmount"); // 25
	exposedNames.add("LPF Envelope Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)20);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which the LPF envelope\n";
	descriptionString += "modulates the filter's cutoff frequency.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, lpfControlsRow3_y));

	identifiers.add("lpfVelAmount"); // 26
	exposedNames.add("LPF Envelope Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)21);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the low-pass filter's envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, lpfControlsRow3_y));

	identifiers.add("lpfDelay"); // 27
	exposedNames.add("LPF Envelope Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)22);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope's delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol4_x, lpfControlsRow3_y));

	identifiers.add("lpfAttack"); // 28
	exposedNames.add("LPF Envelope Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)23);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope's attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol5_x, lpfControlsRow3_y));

	identifiers.add("lpfDecay"); // 29
	exposedNames.add("LPF Envelope Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)24);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope's decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, lpfControlsRow3_y));

	identifiers.add("lpfSustain"); // 30
	exposedNames.add("LPF Envelope Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)25);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the LPF envelope's sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol7_x, lpfControlsRow3_y));

	identifiers.add("lpfRelease"); // 31
	exposedNames.add("LPF Envelope Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)26);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope's release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol8_x, lpfControlsRow3_y));

	//======================================================

	identifiers.add("vcaLevel"); // 32
	exposedNames.add("VCA Baseline Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)27);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the voltage-controlled amplifier's baseline level. Turn this\n";
	descriptionString += "up for droning sounds or when processing external audio input.\n";
	descriptionString += "When this level is set to 127, the VCA envelope has no effect.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, vcaControlsRow1_y));

	identifiers.add("vcaEnvAmount"); // 33
	exposedNames.add("VCA Envelope Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)30);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which the VCA envelope\n";
	descriptionString += "modulates the voltage-controlled ampifier's level.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, vcaControlsRow1_y));

	identifiers.add("vcaVelAmount"); // 34
	exposedNames.add("VCA Envelope Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)31);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the voltage-controlled ampifier's envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, vcaControlsRow1_y));

	identifiers.add("vcaDelay"); // 35
	exposedNames.add("VCA Envelope Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)32);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope's delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol4_x, vcaControlsRow2_y));

	identifiers.add("vcaAttack"); // 36
	exposedNames.add("VCA Envelope Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)33);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope's attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol5_x, vcaControlsRow2_y));

	identifiers.add("vcaDecay"); // 37
	exposedNames.add("VCA Envelope Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)34);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope's decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, vcaControlsRow2_y));

	identifiers.add("vcaSustain"); // 38
	exposedNames.add("VCA Envelope Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)35);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Sets the VCA envelope's sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol7_x, vcaControlsRow2_y));

	identifiers.add("vcaRelease"); // 39
	exposedNames.add("VCA Envelope Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)36);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Sets the length of the VCA envelope's release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol8_x, vcaControlsRow2_y));

	identifiers.add("pgmVolume"); // 40
	exposedNames.add("Program Volume");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)29);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)120);
	descriptionString =  "Sets the overall gain of the current program.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, vcaControlsRow2_y));

	//======================================================

	identifiers.add("lfo1Freq"); // 41
	exposedNames.add("LFO 1 Frequency");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)37);
	converters.add(IntToLFOfreqString::get());
	maxValues.add((uint8)166);
	defaultValues.add((uint8)80);
	descriptionString =  "Sets LFO 1's cycle speed. Range: 0 to 166.\n";
	descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
	descriptionString += "From 90 to 150, LFO 1 has a pitched frequency, increasing\n";
	descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
	descriptionString += "Above 150, LFO 1 is synced with the step sequencer,\n";
	descriptionString += "displayed as [number of cycles] : [length in steps].";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(416, lfoControlsRow1_y));

	identifiers.add("lfo1Shape"); // 42
	exposedNames.add("LFO 1 Wave Shape");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)38);
	converters.add(IntToLFOshapeString::get());
	maxValues.add((uint8)4);
	defaultValues.add((uint8)1);
	descriptions.add("Selects LFO 1's wave shape.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(463, lfoControlsRow2_y));

	identifiers.add("lfo1Amount"); // 43
	exposedNames.add("LFO 1 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)39);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which LFO 1\n";
	descriptionString += "nmodulates the destination parameter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(461, lfoControlsRow1_y));

	identifiers.add("lfo1Destination"); // 44
	exposedNames.add("LFO 1 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)40);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by LFO 1.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(463, lfoControlsRow3_y));

	identifiers.add("lfo1KeySync"); // 45
	exposedNames.add("LFO 1 Key Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)41);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When on, LFO 1's cycle will reset\n";
	descriptionString += "each time a new note is played.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(507, lfoControlsRow1_y));

	//======================================================

	identifiers.add("lfo2Freq"); // 46
	exposedNames.add("LFO 2 Frequency");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)42);
	converters.add(IntToLFOfreqString::get());
	maxValues.add((uint8)166);
	defaultValues.add((uint8)80);
	descriptionString =  "Sets LFO 2's cycle speed. Range: 0 to 166.\n";
	descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
	descriptionString += "From 90 to 150, LFO 2 has a pitched frequency, increasing\n";
	descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
	descriptionString += "Above 150, LFO 2 is synced with the step sequencer,\n";
	descriptionString += "displayed as [number of cycles] : [length in steps].";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(571, lfoControlsRow1_y));

	identifiers.add("lfo2Shape"); // 47
	exposedNames.add("LFO 2 Wave Shape");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)43);
	converters.add(IntToLFOshapeString::get());
	maxValues.add((uint8)4);
	defaultValues.add((uint8)1);
	descriptions.add("Selects LFO 2's wave shape.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(618, lfoControlsRow2_y));

	identifiers.add("lfo2Amount"); // 48
	exposedNames.add("LFO 1 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)44);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which LFO 2\n";
	descriptionString += "nmodulates the destination parameter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(616, lfoControlsRow1_y));

	identifiers.add("lfo2Destination"); // 49
	exposedNames.add("LFO 2 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)45);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by LFO 2.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(618, lfoControlsRow3_y));

	identifiers.add("lfo2KeySync"); // 50
	exposedNames.add("LFO 2 Key Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)46);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When on, LFO 2's cycle will reset\n";
	descriptionString += "each time a new note is played.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(662, lfoControlsRow1_y));

	//======================================================

	identifiers.add("lfo3Freq"); // 51
	exposedNames.add("LFO 3 Frequency");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)47);
	converters.add(IntToLFOfreqString::get());
	maxValues.add((uint8)166);
	defaultValues.add((uint8)80);
	descriptionString =  "Sets LFO 3's cycle speed. Range: 0 to 166.\n";
	descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
	descriptionString += "From 90 to 150, LFO 3 has a pitched frequency, increasing\n";
	descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
	descriptionString += "Above 150, LFO 3 is synced with the step sequencer,\n";
	descriptionString += "displayed as [number of cycles] : [length in steps].";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(724, lfoControlsRow1_y));

	identifiers.add("lfo3Shape"); // 52
	exposedNames.add("LFO 3 Wave Shape");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)48);
	converters.add(IntToLFOshapeString::get());
	maxValues.add((uint8)4);
	defaultValues.add((uint8)1);
	descriptions.add("Selects LFO 3's wave shape.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(771, lfoControlsRow2_y));

	identifiers.add("lfo3Amount"); // 53
	exposedNames.add("LFO 3 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)49);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which LFO 3\n";
	descriptionString += "nmodulates the destination parameter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(769, lfoControlsRow1_y));

	identifiers.add("lfo3Destination"); // 54
	exposedNames.add("LFO 3 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)50);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by LFO 3.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(771, lfoControlsRow3_y));

	identifiers.add("lfo3KeySync"); // 55
	exposedNames.add("LFO 3 Key Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)51);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When on, LFO 3's cycle will reset\n";
	descriptionString += "each time a new note is played.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(815, lfoControlsRow1_y));

	//======================================================

	identifiers.add("lfo4Freq"); // 56
	exposedNames.add("LFO 4 Frequency");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)52);
	converters.add(IntToLFOfreqString::get());
	maxValues.add((uint8)166);
	defaultValues.add((uint8)80);
	descriptionString =  "Sets LFO 4's cycle speed. Range: 0 to 166.\n";
	descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
	descriptionString += "From 90 to 150, LFO 4 has a pitched frequency, increasing\n";
	descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
	descriptionString += "Above 150, LFO 4 is synced with the step sequencer,\n";
	descriptionString += "displayed as [number of cycles] : [length in steps].";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(877, lfoControlsRow1_y));

	identifiers.add("lfo4Shape"); // 57
	exposedNames.add("LFO 4 Wave Shape");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)53);
	converters.add(IntToLFOshapeString::get());
	maxValues.add((uint8)4);
	defaultValues.add((uint8)1);
	descriptions.add("Selects LFO 4's wave shape.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(924, lfoControlsRow2_y));

	identifiers.add("lfo4Amount"); // 58
	exposedNames.add("LFO 4 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)54);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which LFO 4\n";
	descriptionString += "nmodulates the destination parameter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(922, lfoControlsRow1_y));

	identifiers.add("lfo4Destination"); // 59
	exposedNames.add("LFO 4 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)55);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by LFO 4.");
	ctrlWidths.add(134);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(924, lfoControlsRow3_y));

	identifiers.add("lfo4KeySync"); // 60
	exposedNames.add("LFO 4 Key Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)56);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When on, LFO 4's cycle will reset\n";
	descriptionString += "each time a new note is played.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(968, lfoControlsRow1_y));

	//======================================================

	identifiers.add("env3Destination"); // 61
	exposedNames.add("Envelope 3 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)57);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by envelope 3");
	ctrlWidths.add(126);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, env3ControlsRow2_y));

	identifiers.add("env3Amount"); // 62
	exposedNames.add("Envelope 3 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)58);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which envelope 3\n";
	descriptionString += "modulates the destination parameter.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, env3ControlsRow1_y));

	identifiers.add("env3VelAmount"); // 63
	exposedNames.add("Envelope 3 Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)59);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "modulates the amplitude of envelope 3.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, env3ControlsRow1_y));

	identifiers.add("env3Delay"); // 64
	exposedNames.add("Envelope 3 Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)60);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3's delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol4_x, env3ControlsRow2_y));

	identifiers.add("env3Attack"); // 65
	exposedNames.add("Envelope 3 Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)61);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3's attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol5_x, env3ControlsRow2_y));

	identifiers.add("env3Decay"); // 66
	exposedNames.add("Envelope 3 Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)62);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the envelope 3's decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope's\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, env3ControlsRow2_y));

	identifiers.add("env3Sustain"); // 67
	exposedNames.add("Envelope 3 Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)63);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets envelope 3's sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol7_x, env3ControlsRow2_y));

	identifiers.add("env3Release"); // 68
	exposedNames.add("Envelope 3 Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)64);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3's release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol8_x, env3ControlsRow2_y));

	identifiers.add("env3Repeat"); // 69
	exposedNames.add("Envelope 3 Repeat On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)98);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When repeat is on, envelope 3 loops through\n";
	descriptionString += "its delay, attack, decay, and sustain segments\n";
	descriptionString += "for as long as the envelope is gated on.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol1_x, env3ControlsRow1_y));

	//======================================================

	String modSourceDescription{ "Selects the modulation source." };
	String modAmountDescription = "Sets the degree to which the selected source\n";
	modAmountDescription += "modulates the selected destination parameter.\n";
	modAmountDescription += "Negative values invert the modulation.\nRange: -127 to +127.";
	String modDestinationDescription{ "Selects the target parameter for modulation." };

	identifiers.add("mod1Source"); // 70
	exposedNames.add("Modulator 1 Source");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)65);
	converters.add(IntToModSourceString::get());
	maxValues.add((uint8)22);
	defaultValues.add((uint8)0);
	descriptions.add(modSourceDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 184));

	identifiers.add("mod1Amount"); // 71
	exposedNames.add("Modulator 1 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)66);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptions.add(modAmountDescription);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol2_x, 201));

	identifiers.add("mod1Destination"); // 72
	exposedNames.add("Modulator 1 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)67);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 218));

	identifiers.add("mod2Source"); // 73
	exposedNames.add("Modulator 2 Source");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)68);
	converters.add(IntToModSourceString::get());
	maxValues.add((uint8)22);
	defaultValues.add((uint8)0);
	descriptions.add(modSourceDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 262));

	identifiers.add("mod2Amount"); // 74
	exposedNames.add("Modulator 2 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)69);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptions.add(modAmountDescription);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol2_x, 279));

	identifiers.add("mod2Destination"); // 75
	exposedNames.add("Modulator 2 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)70);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 296));

	identifiers.add("mod3Source"); // 76
	exposedNames.add("Modulator 3 Source");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)71);
	converters.add(IntToModSourceString::get());
	maxValues.add((uint8)22);
	defaultValues.add((uint8)0);
	descriptions.add(modSourceDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 340));

	identifiers.add("mod3Amount"); // 77
	exposedNames.add("Modulator 3 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)72);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptions.add(modAmountDescription);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol2_x, 357));

	identifiers.add("mod3Destination"); // 78
	exposedNames.add("Modulator 3 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)73);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 374));

	identifiers.add("mod4Source"); // 79
	exposedNames.add("Modulator 4 Source");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)74);
	converters.add(IntToModSourceString::get());
	maxValues.add((uint8)22);
	defaultValues.add((uint8)0);
	descriptions.add(modSourceDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 418));

	identifiers.add("mod4Amount"); // 80
	exposedNames.add("Modulator 4 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)75);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptions.add(modAmountDescription);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol2_x, 435));

	identifiers.add("mod4Destination"); // 81
	exposedNames.add("Modulator 4 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)76);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(modulatorComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(modulatorControlsCol1_x, 452));

	//======================================================

	identifiers.add("modWheelAmount"); // 82
	exposedNames.add("Modulation Wheel Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)81);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI modulation wheel controller\n";
	descriptionString += "messages (CC#1) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol2_x, 191));

	identifiers.add("modWheelDest"); // 83
	exposedNames.add("Modulation Wheel Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)82);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(midiControllerComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol1_x, 191));

	identifiers.add("pressureAmount"); // 84
	exposedNames.add("Pressure (Aftertouch) Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)83);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI channel pressure\n";
	descriptionString += "(aftertouch) messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol2_x, 253));

	identifiers.add("pressureDest"); // 85
	exposedNames.add("Pressure (Aftertouch) Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)84);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(midiControllerComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol1_x, 253));

	identifiers.add("breathAmount"); // 86
	exposedNames.add("Breath Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)85);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI breath controller\n";
	descriptionString += "messages (CC#2) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol2_x, 315));

	identifiers.add("breathDest"); // 87
	exposedNames.add("Breath Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)86);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(midiControllerComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol1_x, 315));

	identifiers.add("velocityAmount"); // 88
	exposedNames.add("Note Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)87);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol2_x, 377));

	identifiers.add("velocityDest"); // 89
	exposedNames.add("Note Velocity Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)88);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(midiControllerComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol1_x, 377));

	identifiers.add("footPedalAmount"); // 90
	exposedNames.add("Foot Pedal Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)89);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI foot pedal controller\n";
	descriptionString += "messages (CC#4) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol2_x, 439));

	identifiers.add("footPedalDest"); // 91
	exposedNames.add("Foot Pedal Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)90);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	ctrlWidths.add(midiControllerComboBox_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(midiControllerssCol1_x, 439));

	//======================================================

	identifiers.add("pushItPitch"); // 92
	exposedNames.add("Push It! Switch Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)111);
	converters.add(IntToOscPitchString::get());
	maxValues.add((uint8)120);
	defaultValues.add((uint8)60);
	descriptionString =  "Sets the note that plays when\n";
	descriptionString += "the Push It! switch is pressed.\n";
	descriptionString += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz).\n";
	descriptionString += "Middle C is C 5.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(1191, 528));

	identifiers.add("pushItVelocity"); // 93
	exposedNames.add("Push It! Switch Velocity");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)112);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)100);
	descriptionString =  "Sets the velocity of the note that plays\n";
	descriptionString += "when the Push It! switch is pressed.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(1238, 528));

	identifiers.add("pushItMode"); // 94
	exposedNames.add("Push It! Switch Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)113);
	converters.add(IntToPushItModeString::get());
	maxValues.add((uint8)2);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the operating mode for the Mopho's Push It! switch.\n";
	descriptionString += "Normal: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and gated off when the switch is released.\n";
	descriptionString += "Toggle: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and remains on until the switch is pressed again.\n";
	descriptionString += "Audio In: The selected note is gated on for as long as the\n";
	descriptionString += "external audio input level is above a certain threshold.";
	descriptions.add(descriptionString);
	ctrlWidths.add(88);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(1215, 577));

	//======================================================

	identifiers.add("clockTempo"); // 95
	exposedNames.add("Clock Tempo");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)91);
	converters.add(IntToClockTempoString::get());
	maxValues.add((uint8)220);
	defaultValues.add((uint8)90);
	descriptionString =  "Sets the tempo (in beats per minute)\n";
	descriptionString += "for the sequencer and the arpeggiator.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(1236, 126));

	identifiers.add("clockDivision"); // 96
	exposedNames.add("Clock Division");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)92);
	converters.add(IntToClockDivString::get());
	maxValues.add((uint8)12);
	defaultValues.add((uint8)2);
	descriptionString =  "Sets the rate at which the sequencer and\n";
	descriptionString += "arpeggiator advance, relative to the tempo.";
	descriptions.add(descriptionString);
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(1139, 126));

	//======================================================

	identifiers.add("arpegMode"); // 97
	exposedNames.add("Arpeggiator Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)97);
	converters.add(IntToArpegModeString::get());
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the order in which the arpeggiator plays notes.\n";
	descriptionString += "Assign mode: notes play in the order in which they were struck.";
	descriptions.add(descriptionString);
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(controlsCol10_x, 118));

	identifiers.add("arpegOnOff"); // 98
	exposedNames.add("Arpeggiator On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)100);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns the Mopho's arpeggiator on and off.\n";
	descriptionString += "Turning this on will turn off the sequencer.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol9_x, oscControlsRow2_y));

	identifiers.add("sequencerTrigMode"); // 99
	exposedNames.add("Sequencer Trigger Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)94);
	converters.add(IntToSeqTrigModeString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)0);
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
	ctrlWidths.add(114);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(998, 126));

	identifiers.add("sequencerOnOff"); // 100
	exposedNames.add("Sequencer On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)101);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns the Mopho's internal sequencer on and off.\n";
	descriptionString += "Turning this on will turn off the arpeggiator.";
	descriptions.add(descriptionString);
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(819, 126));

	identifiers.add(ID::param_SeqTrack1Dest); // 101
	exposedNames.add("Sequencer Track 1 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)77);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)1);
	descriptionString =  "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 1.";
	descriptions.add(descriptionString);
	ctrlWidths.add(seqTrackDestComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(seqTrackDestComboBoxes_x, 169));

	identifiers.add(ID::param_SeqTrack2Dest); // 102
	exposedNames.add("Sequencer Track 2 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)78);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)2);
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 2.";
	descriptions.add(descriptionString);
	ctrlWidths.add(seqTrackDestComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(seqTrackDestComboBoxes_x, 252));

	identifiers.add(ID::param_SeqTrack3Dest); // 103
	exposedNames.add("Sequencer Track 3 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)79);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)9);
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 3.";
	descriptions.add(descriptionString);
	ctrlWidths.add(seqTrackDestComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(seqTrackDestComboBoxes_x, 335));

	identifiers.add(ID::param_SeqTrack4Dest); // 104
	exposedNames.add("Sequencer Track 4 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)80);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 4.";
	descriptions.add(descriptionString);
	ctrlWidths.add(seqTrackDestComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(seqTrackDestComboBoxes_x, 418));

	//======================================================

	identifiers.add("assignKnob1"); // 105
	exposedNames.add("Assign Parameter to Knob 1");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)105);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)5);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 1.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knobAssignComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(knobAssignComboBoxes_x, 521));

	identifiers.add("assignKnob2"); // 106
	exposedNames.add("Assign Parameter to Knob 2");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)106);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)11);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 2.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knobAssignComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(knobAssignComboBoxes_x, 549));

	identifiers.add("assignKnob3"); // 107
	exposedNames.add("Assign Parameter to Knob 3");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)107);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)43);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 3.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knobAssignComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(knobAssignComboBoxes_x, 577));

	identifiers.add("assignKnob4"); // 108
	exposedNames.add("Assign Parameter to Knob 4");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)108);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)23);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 4.";
	descriptions.add(descriptionString);
	ctrlWidths.add(knobAssignComboBoxes_w);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(knobAssignComboBoxes_x, 605));

	//======================================================

	// Parameters 109-119 are unused

	//======================================================

	// 120..183
	for (auto track = 0; track != 4; ++track) {
		for (auto step = 0; step != 16; ++step) {
			auto trackString{ (String)(track + 1) };
			auto stepString{ (String)(step + 1) };
			identifiers.add("track" + trackString + "Step" + stepString);
			exposedNames.add("Sequencer Track " + trackString + " Step " + stepString);
			controlTypes.add(ControlType::sequencerStep);
			NRPNs.add((uint16)(120 + (16 * track) + step));
			converters.add(IntToSeqStepValueString::get());
			maxValues.add(track == 0 ? (uint8)127 : (uint8)126);
			defaultValues.add((uint8)0);
			descriptionString =  "Sets the value that sequencer track " + trackString + "'s destination parameter has at step " + stepString + ",\n";
			descriptionString += "Range: 0 to 125. If the destination is an oscillator pitch, the range is C0 to D5+.\n";
			descriptionString += "A \"+\" indicates that the pitch is a quarter-tone higher than the displayed note.\n";
			descriptionString += "Reset (126): Restarts the track from step 1. CTRL-click a step to set it to reset.";
			if (track == 0) {
				descriptionString += "\nRest (127): The step produces no output. ALT-click a step to make it a rest\n";
				descriptionString += "(Rests are only available for the steps in sequencer track 1).";
			}
			descriptions.add(descriptionString);
			ctrlWidths.add(seqSteps_w);
			ctrlHeights.add(seqSteps_h);
			ctrlCenterPoints.add(Point<int>(sequencerStep1_x + step * sequencerStepsHorizontalSpacer, sequencerTrack1Steps_y + track * sequencerTracksVerticalSpacer));
		}
	}

	//======================================================

	// 184..199
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		identifiers.add("nameChar" + charNumString);
		exposedNames.add("Program Name Character " + charNumString);
		controlTypes.add(ControlType::pgmNameChar);
		NRPNs.add((uint16)(184 + charNum));
		converters.add(IntToPgmNameCharString::get());
		maxValues.add((uint8)127);
		descriptionString =  "To change character " + charNumString + " of the program's name,\n";
		descriptionString += "click-and-drag the character or hover over\n";
		descriptionString += "it and turn the mouse wheel. Click the edit\n";
		descriptionString += "button above to type in the entire name.";
		descriptions.add(descriptionString);
		ctrlWidths.add(pgmNameCharacters_w);
		ctrlHeights.add(pgmNameCharacters_h);
		ctrlCenterPoints.add(Point<int>(pgmNameCharacter1_x + (charNum * pgmNameCharactersHorizontalSpacer), pgmNameCharacters_y));
	}
	defaultValues.add((uint8)66);	// B
	defaultValues.add((uint8)97);	// a
	defaultValues.add((uint8)115);	// s
	defaultValues.add((uint8)105);	// i
	defaultValues.add((uint8)99);	// c
	defaultValues.add((uint8)32);	// space
	defaultValues.add((uint8)80);	// P
	defaultValues.add((uint8)97);	// a
	defaultValues.add((uint8)116);	// t
	defaultValues.add((uint8)99);	// c
	defaultValues.add((uint8)104);	// h
	defaultValues.add((uint8)32);	// space
	defaultValues.add((uint8)32);	// space
	defaultValues.add((uint8)32);	// space
	defaultValues.add((uint8)32);	// space
	defaultValues.add((uint8)32);	// space
}

InfoForExposedParameters::~InfoForExposedParameters() {
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

ControlType InfoForExposedParameters::controlTypeFor(uint8 paramIndex) const {
	return controlTypes[paramIndex];
}

uint16 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
	return NRPNs[paramIndex];
}

IntToContextualStringConverter* InfoForExposedParameters::converterFor(uint8 paramIndex) const {
	return converters[paramIndex];
}

uint8 InfoForExposedParameters::maxValueFor(uint8 paramIndex) const {
	return maxValues[paramIndex];
}

uint8 InfoForExposedParameters::defaultValueFor(uint8 paramIndex) const {
	return defaultValues[paramIndex];
}

uint16 InfoForExposedParameters::numberOfStepsFor(uint8 paramIndex) const {
	return maxValues[paramIndex] + 1;
}

String InfoForExposedParameters::descriptionFor(uint8 paramIndex) const {
	return descriptions[paramIndex];
}

Point<int> InfoForExposedParameters::ctrlCenterPointFor(uint8 paramIndex) const {
	return ctrlCenterPoints[paramIndex];
}

int InfoForExposedParameters::ctrlWidthFor(uint8 paramIndex) const {
	return ctrlWidths[paramIndex];
}

int InfoForExposedParameters::ctrlHeightFor(uint8 paramIndex) const {
	return ctrlHeights[paramIndex];
}

uint8 InfoForExposedParameters::indexFor(const String& parameterID) const noexcept {
	return (uint8)identifiers.indexOf(Identifier(parameterID));
}




