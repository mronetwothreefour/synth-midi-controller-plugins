#include "params_InfoForExposedParameters_Singleton.h"

InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	const uint8 knob_diameter{ 40 };
	const uint8 toggle_diameter{ 14 };
	const uint8 comboBox_h{ 16 };
	const auto oscControlsRow1_y{ 50 };
	const auto oscControlsRow2_y{ 110 };
	const auto lpfControlsRow1_y{ 161 };
	const auto lpfControlsRow2_y{ 215 };
	const auto lpfControlsRow3_y{ 267 };
	const auto vcaControlsRow1_y{ 373 };
	const auto vcaControlsRow2_y{ 425 };
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

	identifiers.add("osc1Pitch"); // 0
	exposedNames.add("Oscillator 1 Pitch");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)0); 
	converters.add(IntToOscPitchString::get()); 
	maxValues.add((uint8)120); 
	defaultValues.add((uint8)24);
	descriptions.add("Sets oscillator 1's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.");
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
	descriptions.add("Fine tunes oscillator 1's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).");
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
	descriptions.add("Selects oscillator 1's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.");
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
	descriptions.add("Sets oscillator 1's glide (portamento) rate.\nRange: 0 (instantaneous) to 127 (very slow)");
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
	descriptions.add("Turns keyboard tracking for oscillator 1\non or off. When turned off, oscillator 1\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.");
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
	descriptions.add("Sets the level of sub-oscillator 1,\nwhich generates a square wave pitched\none octave lower than oscillator 1.\nRange: 0 to 127.");
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
	descriptions.add("Sets oscillator 2's base pitch in semitone steps.\nRange: C 0 (8 Hz) to C 10 (8 KHz). Middle C is C 5.");
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
	descriptions.add("Fine tunes oscillator 2's base pitch.\nRange: -50 cents to +50 cents.\n0 = no detuning (centered).");
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
	descriptions.add("Selects oscillator 2's wave shape.\nAvailable options: Off; Sawtooth; Triangle;\nSawtooth/Triangle Mix; Pulse (Width 0 to 99).\nA Pulse with width 50 is a square wave.");
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
	descriptions.add("Sets oscillator 2's glide (portamento) rate.\nRange: 0 (instantaneous) to 127 (very slow)");
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
	descriptions.add("Turns keyboard tracking for oscillator 2\non or off. When turned off, oscillator 1\nalways produces its base pitch, unaffected\nby the pitch of incoming MIDI notes.");
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
	descriptions.add("Sets the level of sub-oscillator 2,\nwhich generates a square wave pitched\none octave lower than oscillator 2.\nRange: 0 to 127.");
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
	descriptions.add("Turns hard oscillator sync on or off. When\nturned on, every time oscillator 2 resets,\nit forces oscillator 1 to reset as well.");
	ctrlWidths.add(toggle_diameter);
	ctrlHeights.add(toggle_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol6_x, 22));

	identifiers.add("glideMode"); // 13
	exposedNames.add("Glide Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint16)11);
	converters.add(IntToGlideModeString::get());
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptions.add("Fixed Rate: The actual glide time depends on the size of the note interval.\nFixed Time: The glide time is constant, regardless of the interval size.\nThe Auto modes only apply glide when a note is played legato\n(the new note is played before the previous note is released).");
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(500, 78));

	identifiers.add("oscSlop"); // 14
	exposedNames.add("Oscillator Slop");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)12);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)2);
	descriptions.add("Introduces a subtle amount of random oscillator\npitch drift for a \"vintage analog\" sound.\nRange: 0 to 5.");
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
	descriptions.add("Sets the maximum amount (in semitones) by which pitch wheel\nmessages can raise or lower the pitches of the oscillators.\nRange: 0 (no bend) to +/-12 semitones.");
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
	descriptions.add("Selects which note is given priority when multiple\nnotes are played, and whether the envelopes are\nre-triggered when a note is played legato (before\nthe previous note has been released).");
	ctrlWidths.add(124);
	ctrlHeights.add(comboBox_h);
	ctrlCenterPoints.add(Point<int>(500, 38));

	identifiers.add("oscMix"); // 17
	exposedNames.add("Oscillator 1 & 2 Mix");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)13);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptions.add("Controls the level balance between oscillators 1 & 2.\nRange: 0 to 127. At 0, only oscillator 1 is heard.\nAt 127, only oscillator 2 is heard. At 64, an equal\nmix of the two oscillators is heard.");
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
	descriptions.add("Sets the level of white noise\nsent into the low-pass filter.\nRange: 0 to 127.");
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
	descriptions.add("Sets the level of external audio\ninput sent into the low-pass filter.\nWhen nothing is connected to audio in,\nthis controls the level of feedback\nfrom the left audio output.\nRange: 0 to 127.");
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
	descriptions.add("Sets the base cutoff frequency for the\nlow-pass filter (in semitone steps).\nRange: 0 (C 0) to 164 (G# 13).");
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
	descriptions.add("Sets the resonance level of the low-pass\nfilter. When in 4-pole mode, high settings\nwill cause the filter to self-oscillate.\nRange: 0 to 127.");
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
	descriptions.add("Sets the amount by which keyboard (MIDI) notes\nwill shift the low-pass filter's cutoff frequency.\nRange: 0 to 127. At 64, cutoff is shifted by one\nsemitone for each note. At 32, cutoff is shifted\nby one half-semitone for each note.");
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
	descriptions.add("Sets the degree to which oscillator 1 modulates\nthe low-pass filter's cutoff frequency. This is\nuseful for generating bell-like sounds.\nRange: 0 to 127.");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol3_x, lpfControlsRow3_y));

	identifiers.add("lpfType"); // 24
	exposedNames.add("LPF Type");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint16)19);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)1);
	descriptions.add("Switches the low-pass filter type between 2-Pole and 4-Pole.\nWhen set to 4-pole, the filter has a steeper cutoff frequency\nslope and more pronounced resonance.");
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
	descriptions.add("Sets the degree to which the LPF envelope\nmodulates the filter's cutoff frequency.\nNegative values invert the envelope.\nRange: -127 to +127.");
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
	descriptions.add("Sets the degree to which MIDI note velocity modulates\nthe amplitude of the low-pass filter's envelope.\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the LPF envelope's delay segment\n(the amount of time that passes after the envelope\nis triggered before its attack segment begins).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the LPF envelope's attack segment\n(the amount of time it takes for the envelope's\nlevel to rise from minimum to maximum).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the LPF envelope's decay segment\n(the amount of time it takes for the envelope's\nlevel to fall from maximum to the sustain level).\nRange: 0 to 127.");
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
	descriptions.add("Sets the LPF envelope's sustain level (once the\ndecay segment completes, the envelope stays\nat this level until it is gated off).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the LPF envelope's release segment\n(the amount of time it takes to fall from the sustain\nlevel down to minimum once the envelope is gated off).\nRange: 0 to 127.");
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
	descriptions.add("Sets the voltage-controlled amplifier's baseline level. Turn this\nup for droning sounds or when processing external audio input.\nWhen this level is set to 127, the VCA envelope has no effect.\nRange: 0 to 127.");
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
	descriptions.add("Sets the degree to which the VCA envelope\nmodulates the voltage-controlled ampifier's level.\nRange: 0 to 127.");
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
	descriptions.add("Sets the degree to which MIDI note velocity modulates\nthe amplitude of the voltage-controlled ampifier's envelope.\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the VCA envelope's delay segment\n(the amount of time that passes after the envelope\nis triggered before its attack segment begins).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the VCA envelope's attack segment\n(the amount of time it takes for the envelope's\nlevel to rise from minimum to maximum).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the VCA envelope's decay segment\n(the amount of time it takes for the envelope's\nlevel to fall from maximum to the sustain level).\nRange: 0 to 127.");
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
	descriptions.add("Sets the VCA envelope's sustain level (once the\ndecay segment completes, the envelope stays\nat this level until it is gated off).\nRange: 0 to 127.");
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
	descriptions.add("Sets the length of the VCA envelope's release segment\n(the amount of time it takes to fall from the sustain\nlevel down to minimum once the envelope is gated off).\nRange: 0 to 127.");
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
	descriptions.add("Sets the overall gain of the current program.\nRange: 0 to 127.");
	ctrlWidths.add(knob_diameter);
	ctrlHeights.add(knob_diameter);
	ctrlCenterPoints.add(Point<int>(controlsCol2_x, vcaControlsRow2_y));
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




