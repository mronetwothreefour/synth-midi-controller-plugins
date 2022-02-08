#include "params_ExposedParamsInfo_Singleton.h"

#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"
#include "../gui/gui_Constants.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	String descriptionString;

	//======================================================

	for (uint8 i = 1; i != 3; ++i) {
		identifiers.add("osc" + (String)i + "Pitch"); // 0 & 6
		exposedNames.add("Oscillator " + (String)i + " Pitch");
		controlTypes.add(ControlType::knobForPitchWithValueStringDisplay);
		NRPNs.add(i == 1 ? (uint8)0 : (uint8)5);
		converters.add(IntToOscPitchString::get());
		maxValues.add((uint8)120);
		defaultValues.add((uint8)24);
		descriptionString =  "Sets oscillator " + (String)i + GUI::apostrophe + "s base pitch in semitone steps.\n";
		descriptionString += "Range: C 0 (8 Hz) to C 10 (8.2 KHz). Middle C is C 5.\n";
		descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
		descriptionString += "increment the pitch by one octave (12 semitones).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol1_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));

		identifiers.add("osc" + (String)i + "Fine"); // 1 & 7
		exposedNames.add("Oscillator " + (String)i + " Fine Tune");
		controlTypes.add(ControlType::knobForPitchWithValueStringDisplay);
		NRPNs.add(i == 1 ? (uint8)1 : (uint8)6);
		converters.add(IntToFineTuneString::get());
		maxValues.add((uint8)100); 
		defaultValues.add(i == 1 ? (uint8)49 : (uint8)51);
		descriptionString =  "Fine tunes oscillator " + (String)i + GUI::apostrophe + "s base pitch.\n";
		descriptionString += "Range: -50 cents to +50 cents.\n";
		descriptionString += "0 = no detuning (centered).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));

		identifiers.add("osc" + (String)i + "Shape"); // 2 & 8
		exposedNames.add("Oscillator " + (String)i + " Wave Shape");
		controlTypes.add(ControlType::knobWithWaveShapeDisplay);
		NRPNs.add(i == 1 ? (uint8)2 : (uint8)7);
		converters.add(IntToOscWaveShapeString::get());
		maxValues.add((uint8)103); 
		defaultValues.add((uint8)1);
		descriptionString =  "Selects oscillator " + (String)i + GUI::apostrophe + "s wave shape.\n";
		descriptionString += "Hold down a number on the keyboard and click\n";
		descriptionString += "the knob to jump directly to a wave shape:\n";
		descriptionString += "0 = Off;  1 = Sawtooth;  2 = Triangle;\n";
		descriptionString += "3 = Sawtooth / Triangle Mixture;\n";
		descriptionString += "4 = Square (a Pulse with width 50).";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol3_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));

		identifiers.add("osc" + (String)i + "Glide"); // 3 & 9
		exposedNames.add("Oscillator " + (String)i + " Glide Rate");
		controlTypes.add(ControlType::knobWithValueStringDisplay);
		NRPNs.add(i == 1 ? (uint8)3 : (uint8)8);
		converters.add(IntToPlainValueString::get());
		maxValues.add((uint8)127); 
		defaultValues.add((uint8)0);
		descriptionString =  "Sets oscillator " + (String)i + GUI::apostrophe + "s glide (portamento) rate.\n";
		descriptionString += "Range: 0 (instantaneous) to 127 (very slow)";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol4_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));

		identifiers.add("osc" + (String)i + "KeyTrack"); // 4 & 10
		exposedNames.add("Oscillator " + (String)i + " Keyboard Track On/Off");
		controlTypes.add(ControlType::toggleButton);
		NRPNs.add(i == 1 ? (uint8)4 : (uint8)9);
		converters.add(IntToOffOnString::get());
		maxValues.add((uint8)1); 
		defaultValues.add((uint8)1);
		descriptionString =  "Turns keyboard tracking for oscillator " + (String)i + "\n";
		descriptionString += "on or off. When turned off, oscillator " + (String)i + "\n";
		descriptionString += "always produces its base pitch, unaffected\n";
		descriptionString += "by the pitch of incoming MIDI notes.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::toggle_diameter);
		controlHeights.add(GUI::toggle_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol6_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));

		identifiers.add("osc" + (String)i + "SubLevel"); // 5 & 11
		exposedNames.add("Sub-Oscillator " + (String)i + " Level");
		controlTypes.add(ControlType::knobWithValueStringDisplay);
		NRPNs.add(i == 1 ? (uint8)114 : (uint8)115);
		converters.add(IntToPlainValueString::get());
		maxValues.add((uint8)127); 
		defaultValues.add((uint8)0);
		descriptionString =  "Sets the level of sub-oscillator " + (String)i + ",\n";
		descriptionString += "which generates a square wave pitched\n";
		descriptionString += "one octave lower than oscillator " + (String)i + ".\n";
		descriptionString += "Range: 0 to 127.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::controlsCol5_x, i == 1 ? GUI::oscControlsRow1_y : GUI::oscControlsRow2_y));
	}

	identifiers.add("oscSync"); // 12
	exposedNames.add("Hard Oscillator Sync On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint8)10);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns hard oscillator sync on or off. When\n";
	descriptionString += "turned on, every time oscillator 2 resets,\n";
	descriptionString += "it forces oscillator 1 to reset as well.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::toggle_diameter);
	controlHeights.add(GUI::toggle_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol6_x, 22));

	//======================================================

	identifiers.add("glideMode"); // 13
	exposedNames.add("Glide Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)11);
	converters.add(IntToGlideModeString::get());
	maxValues.add((uint8)3);
	defaultValues.add((uint8)0);
	descriptionString =  "Fixed Rate: The actual glide time depends on the size of the note interval.\n";
	descriptionString += "Fixed Time: The glide time is constant, regardless of the interval size.\n";
	descriptionString += "The Auto modes only apply glide when a note is played legato\n";
	descriptionString += "(the new note is triggered before the previous note is released).";
	descriptions.add(descriptionString);
	controlWidths.add(124);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::controlsCol10_x, 78));

	identifiers.add("oscSlop"); // 14
	exposedNames.add("Oscillator Slop");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)12);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)2);
	descriptionString =  "Introduces a subtle amount of random oscillator\n";
	descriptionString += "pitch drift for a " + GUI::openQuote + "vintage analog" + GUI::closeQuote + " sound.\n";
	descriptionString += "Range: 0 to 5.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol7_x, GUI::oscControlsRow1_y));

	identifiers.add("bendRange"); // 15
	exposedNames.add("Pitch Bend Range");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)93);
	converters.add(IntToBendRangeString::get());
	maxValues.add((uint8)12);
	defaultValues.add((uint8)4);
	descriptionString =  "Sets the maximum amount (in semitones) by which pitch wheel\n";
	descriptionString += "messages can raise or lower the pitches of the oscillators.\n";
	descriptionString += "Range: 0 (no pitch bend) to +/-12 semitones.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol9_x, GUI::oscControlsRow1_y));

	identifiers.add("notePriority"); // 16
	exposedNames.add("Note Priority (Key Assign)");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)96);
	converters.add(IntToNotePriorityString::get());
	maxValues.add((uint8)5);
	defaultValues.add((uint8)0);
	descriptionString =  "Selects which note is given priority when multiple\n";
	descriptionString += "notes are played, and whether the envelopes are\n";
	descriptionString += "re-triggered when a note is played legato (before\n";
	descriptionString += "the previous note has been released).";
	descriptions.add(descriptionString);
	controlWidths.add(124);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::controlsCol10_x, 38));

	identifiers.add("oscMix"); // 17
	exposedNames.add("Oscillator 1 & 2 Mix");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)13);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Controls the level balance between oscillators 1 & 2.\n";
	descriptionString += "Range: 0 to 127. At 0, only oscillator 1 is heard.\n";
	descriptionString += "At 127, only oscillator 2 is heard. At 64, an equal\n";
	descriptionString += "mix of the two oscillators is heard.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol8_x, GUI::oscControlsRow1_y));

	identifiers.add("noiseLevel"); // 18
	exposedNames.add("Noise Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)14);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the level of white noise\n";
	descriptionString += "sent into the low-pass filter.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol7_x, GUI::oscControlsRow2_y));

	identifiers.add("extInLevel"); // 19
	exposedNames.add("External Audio Input Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)116);
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
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol8_x, GUI::oscControlsRow2_y));

	//======================================================

	identifiers.add("lpfFreq"); // 20
	exposedNames.add("LPF Cutoff Frequency");
	controlTypes.add(ControlType::knobForPitchWithValueStringDisplay);
	NRPNs.add((uint8)15);
	converters.add(IntToLPFfreqString::get());
	maxValues.add((uint8)164);
	defaultValues.add((uint8)148);
	descriptionString =  "Sets the base cutoff frequency for the low-pass filter\n";
	descriptionString += "(in semitone steps). Range: 0 (C 0) to 164 (G# 13).\n";
	descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
	descriptionString += "increment the frequency by one octave (12 semitones).";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol1_x, GUI::lpfControlsRow2_y));

	identifiers.add("lpfReso"); // 21
	exposedNames.add("LPF Resonance");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)16);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the resonance level of the low-pass\n";
	descriptionString += "filter. When in 4-pole mode, high settings\n";
	descriptionString += "will cause the filter to self-oscillate.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::lpfControlsRow2_y));

	identifiers.add("lpfKeyAmount"); // 22
	exposedNames.add("LPF Keyboard Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)17);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the amount by which keyboard (MIDI) notes\n";
	descriptionString += "will shift the low-pass filter" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Range: 0 to 127. At 64, cutoff is shifted by one\n";
	descriptionString += "semitone for each note. At 32, cutoff is shifted\n";
	descriptionString += "by one half-semitone for each note.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol3_x, GUI::lpfControlsRow2_y));

	identifiers.add("lpfFMamount"); // 23
	exposedNames.add("LPF FM (By Oscillator 1)");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)18);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which oscillator 1 modulates\n";
	descriptionString += "the low-pass filter" + GUI::apostrophe + "s cutoff frequency. This is\n";
	descriptionString += "useful for generating bell-like sounds.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol3_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfType"); // 24
	exposedNames.add("LPF Type");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint8)19);
	converters.add(IntToLPFtypeString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)1);
	descriptionString =  "Switches the low-pass filter type between 2-Pole and 4-Pole.\n";
	descriptionString += "When set to 4-pole, the filter has a steeper cutoff frequency\n";
	descriptionString += "slope and more pronounced resonance.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::toggle_diameter);
	controlHeights.add(GUI::toggle_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::lpfControlsRow1_y));

	identifiers.add("lpfEnvAmount"); // 25
	exposedNames.add("LPF Envelope Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)20);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which the LPF envelope\n";
	descriptionString += "modulates the filter" + GUI::apostrophe + "s cutoff frequency.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol1_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfVelAmount"); // 26
	exposedNames.add("LPF Envelope Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)21);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the low-pass filter" + GUI::apostrophe + "s envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfDelay"); // 27
	exposedNames.add("LPF Envelope Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)22);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol4_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfAttack"); // 28
	exposedNames.add("LPF Envelope Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)23);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol5_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfDecay"); // 29
	exposedNames.add("LPF Envelope Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)24);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol6_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfSustain"); // 30
	exposedNames.add("LPF Envelope Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)25);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the LPF envelope" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol7_x, GUI::lpfControlsRow3_y));

	identifiers.add("lpfRelease"); // 31
	exposedNames.add("LPF Envelope Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)26);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the LPF envelope" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol8_x, GUI::lpfControlsRow3_y));

	//======================================================

	identifiers.add("vcaLevel"); // 32
	exposedNames.add("VCA Baseline Level");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)27);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the voltage-controlled amplifier" + GUI::apostrophe + "s baseline level. Turn this\n";
	descriptionString += "up for droning sounds or when processing external audio input.\n";
	descriptionString += "When this level is set to 127, the VCA envelope has no effect.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol1_x, GUI::vcaControlsRow1_y));

	identifiers.add("vcaEnvAmount"); // 33
	exposedNames.add("VCA Envelope Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)30);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which the VCA envelope\n";
	descriptionString += "modulates the voltage-controlled ampifier" + GUI::apostrophe + "s level.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::vcaControlsRow1_y));

	identifiers.add("vcaVelAmount"); // 34
	exposedNames.add("VCA Envelope Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)31);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity modulates\n";
	descriptionString += "the amplitude of the voltage-controlled ampifier" + GUI::apostrophe + "s envelope.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol3_x, GUI::vcaControlsRow1_y));

	identifiers.add("vcaDelay"); // 35
	exposedNames.add("VCA Envelope Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)32);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol4_x, GUI::vcaControlsRow2_y));

	identifiers.add("vcaAttack"); // 36
	exposedNames.add("VCA Envelope Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)33);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol5_x, GUI::vcaControlsRow2_y));

	identifiers.add("vcaDecay"); // 37
	exposedNames.add("VCA Envelope Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)34);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol6_x, GUI::vcaControlsRow2_y));

	identifiers.add("vcaSustain"); // 38
	exposedNames.add("VCA Envelope Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)35);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Sets the VCA envelope" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol7_x, GUI::vcaControlsRow2_y));

	identifiers.add("vcaRelease"); // 39
	exposedNames.add("VCA Envelope Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)36);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)64);
	descriptionString =  "Sets the length of the VCA envelope" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol8_x, GUI::vcaControlsRow2_y));

	identifiers.add("pgmVolume"); // 40
	exposedNames.add("Program Volume");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)29);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)120);
	descriptionString =  "Sets the overall gain of the current program.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::vcaControlsRow2_y));

	//======================================================

	for (uint8 i = 0; i != 4; ++i) {
		identifiers.add("lfo" + String(i + 1) + "Freq"); // 41, 46, 51, 56
		exposedNames.add("LFO " + String(i + 1) + " Frequency");
		controlTypes.add(ControlType::knobWithValueStringDisplay);
		NRPNs.add((uint8)(37 + i * 5));
		converters.add(IntToLFOfreqString::get());
		maxValues.add((uint8)166);
		defaultValues.add((uint8)80);
		descriptionString =  "Sets LFO " + String(i + 1) + GUI::apostrophe + "s cycle speed. Range: 0 to 166.\n";
		descriptionString += "At 0, 1 cycle lasts 30 sec. At 89, the frequency is 8 Hz.\n";
		descriptionString += "From 90 to 150, LFO " + String(i + 1) + " has a pitched frequency, increasing\n";
		descriptionString += "in semitones steps from C 0 (8.2 Hz) up to C 5 (261.6 Hz).\n";
		descriptionString += "Above 150, LFO " + String(i + 1) + " is synced with the step sequencer,\n";
		descriptionString += "displayed as [number of cycles] : [length in steps].";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(416 + i * GUI::lfoControlsHorizontalSpacing, GUI::lfoControlsRow1_y));

		identifiers.add("lfo" + String(i + 1) + "Shape"); // 42, 47, 52, 57
		exposedNames.add("LFO " + String(i + 1) + " Wave Shape");
		controlTypes.add(ControlType::comboBox);
		NRPNs.add((uint8)(38 + i * 5));
		converters.add(IntToLFOshapeString::get());
		maxValues.add((uint8)4);
		defaultValues.add((uint8)1);
		descriptions.add("Selects LFO " + String(i + 1) + GUI::apostrophe + "s wave shape.");
		controlWidths.add(134);
		controlHeights.add(GUI::comboBox_h);
		controlCenterPoints.add(Point<int>(463 + i * GUI::lfoControlsHorizontalSpacing, GUI::lfoControlsRow2_y));

		identifiers.add("lfo" + String(i + 1) + "Amount"); // 43, 48, 53, 58
		exposedNames.add("LFO " + String(i + 1) + " Amount");
		controlTypes.add(ControlType::knobWithValueStringDisplay);
		NRPNs.add((uint8)(39 + i * 5));
		converters.add(IntToPlainValueString::get());
		maxValues.add((uint8)127);
		defaultValues.add((uint8)0);
		descriptionString =  "Sets the degree to which LFO " + String(i + 1) + "\n";
		descriptionString += "modulates the destination parameter.\n";
		descriptionString += "Range: 0 to 127.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(461 + i * GUI::lfoControlsHorizontalSpacing, GUI::lfoControlsRow1_y));

		identifiers.add("lfo" + String(i + 1) + "Destination"); // 44, 49, 54, 59
		exposedNames.add("LFO " + String(i + 1) + " Modulation Destination");
		controlTypes.add(ControlType::comboBox);
		NRPNs.add((uint8)(40 + i * 5));
		converters.add(IntToModDestinationString::get());
		maxValues.add((uint8)46);
		defaultValues.add((uint8)0);
		descriptions.add("Selects the target parameter for modulation by LFO " + String(i + 1) + ".");
		controlWidths.add(134);
		controlHeights.add(GUI::comboBox_h);
		controlCenterPoints.add(Point<int>(463 + i * GUI::lfoControlsHorizontalSpacing, GUI::lfoControlsRow3_y));

		identifiers.add("lfo" + String(i + 1) + "KeySync"); // 45, 50, 55, 60
		exposedNames.add("LFO " + String(i + 1) + " Key Sync On/Off");
		controlTypes.add(ControlType::toggleButton);
		NRPNs.add((uint8)(41 + i * 5));
		converters.add(IntToOffOnString::get());
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		descriptionString =  "When on, LFO " + String(i + 1) + GUI::apostrophe + "s cycle will reset\n";
		descriptionString += "each time a new note is played.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::toggle_diameter);
		controlHeights.add(GUI::toggle_diameter);
		controlCenterPoints.add(Point<int>(507 + i * GUI::lfoControlsHorizontalSpacing, GUI::lfoControlsRow1_y));
	}

	//======================================================

	identifiers.add("env3Destination"); // 61
	exposedNames.add("Envelope 3 Modulation Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)57);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add("Selects the target parameter for modulation by envelope 3");
	controlWidths.add(126);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Amount"); // 62
	exposedNames.add("Envelope 3 Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)58);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which envelope 3\n";
	descriptionString += "modulates the destination parameter.\n";
	descriptionString += "Negative values invert the envelope.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol2_x, GUI::env3ControlsRow1_y));

	identifiers.add("env3VelAmount"); // 63
	exposedNames.add("Envelope 3 Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)59);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "modulates the amplitude of envelope 3.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol3_x, GUI::env3ControlsRow1_y));

	identifiers.add("env3Delay"); // 64
	exposedNames.add("Envelope 3 Delay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)60);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s delay segment\n";
	descriptionString += "(the amount of time that passes after the envelope\n";
	descriptionString += "is triggered before its attack segment begins).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol4_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Attack"); // 65
	exposedNames.add("Envelope 3 Attack");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)61);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s attack segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to rise from minimum to maximum).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol5_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Decay"); // 66
	exposedNames.add("Envelope 3 Decay");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)62);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of the envelope 3" + GUI::apostrophe + "s decay segment\n";
	descriptionString += "(the amount of time it takes for the envelope" + GUI::apostrophe + "s\n";
	descriptionString += "level to fall from maximum to the sustain level).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol6_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Sustain"); // 67
	exposedNames.add("Envelope 3 Sustain");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)63);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets envelope 3" + GUI::apostrophe + "s sustain level (once the\n";
	descriptionString += "decay segment completes, the envelope stays\n";
	descriptionString += "at this level until it is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol7_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Release"); // 68
	exposedNames.add("Envelope 3 Release");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)64);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the length of envelope 3" + GUI::apostrophe + "s release segment\n";
	descriptionString += "(the amount of time it takes to fall from the sustain\n";
	descriptionString += "level down to minimum once the envelope is gated off).\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol8_x, GUI::env3ControlsRow2_y));

	identifiers.add("env3Repeat"); // 69
	exposedNames.add("Envelope 3 Repeat On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint8)98);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "When repeat is on, envelope 3 loops through\n";
	descriptionString += "its delay, attack, decay, and sustain segments\n";
	descriptionString += "for as long as the envelope is gated on.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::toggle_diameter);
	controlHeights.add(GUI::toggle_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol1_x, GUI::env3ControlsRow1_y));

	//======================================================

	String modSourceDescription{ "Selects the modulation source." };
	String modAmountDescription = "Sets the degree to which the selected source\n";
	modAmountDescription += "modulates the selected destination parameter.\n";
	modAmountDescription += "Negative values invert the modulation.\nRange: -127 to +127.";
	String modDestinationDescription{ "Selects the target parameter for modulation." };

	for (uint8 i = 0; i != 4; ++i) {
		identifiers.add("mod" + (String)(i + 1) + "Source"); // 70, 73, 76, 79
		exposedNames.add("Modulator " + (String)(i + 1) + " Source");
		controlTypes.add(ControlType::comboBox);
		NRPNs.add((uint8)65 + (uint8)3 * i);
		converters.add(IntToModSourceString::get());
		maxValues.add((uint8)22);
		defaultValues.add((uint8)0);
		descriptions.add(modSourceDescription);
		controlWidths.add(GUI::modulatorComboBox_w);
		controlHeights.add(GUI::comboBox_h);
		controlCenterPoints.add(Point<int>(GUI::modulatorControlsCol1_x, 184 + i * GUI::modulatorControlsVerticalSpacing));

		identifiers.add("mod" + (String)(i + 1) + "Amount"); // 71, 74, 77, 80
		exposedNames.add("Modulator " + (String)(i + 1) + " Amount");
		controlTypes.add(ControlType::knobWithValueStringDisplay);
		NRPNs.add((uint8)66 + (uint8)3 * i);
		converters.add(IntToPlusMinus127String::get());
		maxValues.add((uint8)254);
		defaultValues.add((uint8)127);
		descriptions.add(modAmountDescription);
		controlWidths.add(GUI::knob_diameter);
		controlHeights.add(GUI::knob_diameter);
		controlCenterPoints.add(Point<int>(GUI::modulatorControlsCol2_x, 201 + i * GUI::modulatorControlsVerticalSpacing));

		identifiers.add("mod" + (String)(i + 1) + "Destination"); // 72, 75, 78, 81
		exposedNames.add("Modulator " + (String)(i + 1) + " Destination");
		controlTypes.add(ControlType::comboBox);
		NRPNs.add((uint8)67 + (uint8)3 * i);
		converters.add(IntToModDestinationString::get());
		maxValues.add((uint8)46);
		defaultValues.add((uint8)0);
		descriptions.add(modDestinationDescription);
		controlWidths.add(GUI::modulatorComboBox_w);
		controlHeights.add(GUI::comboBox_h);
		controlCenterPoints.add(Point<int>(GUI::modulatorControlsCol1_x, 218 + i * GUI::modulatorControlsVerticalSpacing));
	}

	//======================================================

	identifiers.add("modWheelAmount"); // 82
	exposedNames.add("Modulation Wheel Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)81);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI modulation wheel controller\n";
	descriptionString += "messages (CC#1) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol2_x, 191));

	identifiers.add("modWheelDest"); // 83
	exposedNames.add("Modulation Wheel Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)82);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	controlWidths.add(GUI::midiControllerComboBox_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol1_x, 191));

	identifiers.add("pressureAmount"); // 84
	exposedNames.add("Pressure (Aftertouch) Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)83);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI channel pressure\n";
	descriptionString += "(aftertouch) messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol2_x, 253));

	identifiers.add("pressureDest"); // 85
	exposedNames.add("Pressure (Aftertouch) Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)84);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	controlWidths.add(GUI::midiControllerComboBox_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol1_x, 253));

	identifiers.add("breathAmount"); // 86
	exposedNames.add("Breath Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)85);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI breath controller\n";
	descriptionString += "messages (CC#2) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol2_x, 315));

	identifiers.add("breathDest"); // 87
	exposedNames.add("Breath Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)86);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	controlWidths.add(GUI::midiControllerComboBox_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol1_x, 315));

	identifiers.add("velocityAmount"); // 88
	exposedNames.add("Note Velocity Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)87);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI note velocity\n";
	descriptionString += "messages modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol2_x, 377));

	identifiers.add("velocityDest"); // 89
	exposedNames.add("Note Velocity Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)88);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	controlWidths.add(GUI::midiControllerComboBox_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol1_x, 377));

	identifiers.add("footPedalAmount"); // 90
	exposedNames.add("Foot Pedal Amount");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)89);
	converters.add(IntToPlusMinus127String::get());
	maxValues.add((uint8)254);
	defaultValues.add((uint8)127);
	descriptionString =  "Sets the degree to which MIDI foot pedal controller\n";
	descriptionString += "messages (CC#4) modulate the destination parameter.\n";
	descriptionString += "Negative values invert the modulation.\n";
	descriptionString += "Range: -127 to +127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol2_x, 439));

	identifiers.add("footPedalDest"); // 91
	exposedNames.add("Foot Pedal Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)90);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)0);
	descriptions.add(modDestinationDescription);
	controlWidths.add(GUI::midiControllerComboBox_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::midiControllersCol1_x, 439));

	//======================================================

	identifiers.add("pushItPitch"); // 92
	exposedNames.add("Push It! Switch Pitch");
	controlTypes.add(ControlType::knobForPitchWithValueStringDisplay);
	NRPNs.add((uint8)111);
	converters.add(IntToOscPitchString::get());
	maxValues.add((uint8)120);
	defaultValues.add((uint8)60);
	descriptionString =  "Sets the note that plays when the Push It! switch is pressed.\n";
	descriptionString += "Range: C 0 (8.2 Hz) to C 10 (8.4 KHz). Middle C is C 5.\n";
	descriptionString += "Hold down the SHIFT key when using the mouse wheel to\n";
	descriptionString += "increment the pitch by one octave (12 semitones).";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(1191, 528));

	identifiers.add("pushItVelocity"); // 93
	exposedNames.add("Push It! Switch Velocity");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)112);
	converters.add(IntToPlainValueString::get());
	maxValues.add((uint8)127);
	defaultValues.add((uint8)100);
	descriptionString =  "Sets the velocity of the note that plays\n";
	descriptionString += "when the Push It! switch is pressed.\n";
	descriptionString += "Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(1239, 528));

	identifiers.add("pushItMode"); // 94
	exposedNames.add("Push It! Switch Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)113);
	converters.add(IntToPushItModeString::get());
	maxValues.add((uint8)2);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the operating mode for the Mopho" + GUI::apostrophe + "s Push It! switch.\n";
	descriptionString += "Normal: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and gated off when the switch is released.\n";
	descriptionString += "Toggle: The selected note is gated on when the switch is\n";
	descriptionString += "pressed and remains on until the switch is pressed again.\n";
	descriptionString += "Audio In: The selected note is gated on for as long as the\n";
	descriptionString += "external audio input level is above a certain threshold.";
	descriptions.add(descriptionString);
	controlWidths.add(88);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(1215, 577));

	//======================================================

	identifiers.add("clockTempo"); // 95
	exposedNames.add("Clock Tempo");
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint8)91);
	converters.add(IntToClockTempoString::get());
	maxValues.add((uint8)220);
	defaultValues.add((uint8)90);
	descriptionString =  "Sets the tempo (in beats per minute)\n";
	descriptionString += "for the sequencer and the arpeggiator.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knob_diameter);
	controlHeights.add(GUI::knob_diameter);
	controlCenterPoints.add(Point<int>(1236, 126));

	identifiers.add("clockDivision"); // 96
	exposedNames.add("Clock Division");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)92);
	converters.add(IntToClockDivString::get());
	maxValues.add((uint8)12);
	defaultValues.add((uint8)2);
	descriptionString =  "Sets the rate at which the sequencer and\n";
	descriptionString += "arpeggiator advance, relative to the tempo.";
	descriptions.add(descriptionString);
	controlWidths.add(124);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(1139, 126));

	//======================================================

	identifiers.add("arpegMode"); // 97
	exposedNames.add("Arpeggiator Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)97);
	converters.add(IntToArpegModeString::get());
	maxValues.add((uint8)14);
	defaultValues.add((uint8)0);
	descriptionString =  "Sets the order in which the arpeggiator plays notes.\n";
	descriptionString += "Assign mode: notes play in the order in which they were struck.";
	descriptions.add(descriptionString);
	controlWidths.add(124);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::controlsCol10_x, 118));

	identifiers.add("arpegOnOff"); // 98
	exposedNames.add("Arpeggiator On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint8)100);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns the Mopho" + GUI::apostrophe + "s arpeggiator on and off.\n";
	descriptionString += "Turning this on will turn off the sequencer.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::toggle_diameter);
	controlHeights.add(GUI::toggle_diameter);
	controlCenterPoints.add(Point<int>(GUI::controlsCol9_x, GUI::oscControlsRow2_y));

	identifiers.add("sequencerTrigMode"); // 99
	exposedNames.add("Sequencer Trigger Mode");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)94);
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
	controlWidths.add(114);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(998, 126));

	identifiers.add("sequencerOnOff"); // 100
	exposedNames.add("Sequencer On/Off");
	controlTypes.add(ControlType::toggleButton);
	NRPNs.add((uint8)101);
	converters.add(IntToOffOnString::get());
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	descriptionString =  "Turns the Mopho" + GUI::apostrophe + "s internal sequencer on and off.\n";
	descriptionString += "Turning this on will turn off the arpeggiator.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::toggle_diameter);
	controlHeights.add(GUI::toggle_diameter);
	controlCenterPoints.add(Point<int>(819, 126));

	identifiers.add(ID::param_SeqTrack1Dest); // 101
	exposedNames.add("Sequencer Track 1 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)77);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)1);
	descriptionString =  "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 1.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::seqTrackDestComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::seqTrackDestComboBoxes_x, 169));

	identifiers.add(ID::param_SeqTrack2Dest); // 102
	exposedNames.add("Sequencer Track 2 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)78);
	converters.add(IntToSeqTrack2DestinationString::get());
	maxValues.add((uint8)47);
	defaultValues.add((uint8)2);
	descriptionString =  "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 2.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::seqTrackDestComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::seqTrackDestComboBoxes_x, 252));

	identifiers.add(ID::param_SeqTrack3Dest); // 103
	exposedNames.add("Sequencer Track 3 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)79);
	converters.add(IntToModDestinationString::get());
	maxValues.add((uint8)46);
	defaultValues.add((uint8)9);
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 3.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::seqTrackDestComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::seqTrackDestComboBoxes_x, 335));

	identifiers.add(ID::param_SeqTrack4Dest); // 104
	exposedNames.add("Sequencer Track 4 Destination");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)80);
	converters.add(IntToSeqTrack4DestinationString::get());
	maxValues.add((uint8)47);
	defaultValues.add((uint8)0);
	descriptionString = "Selects the target parameter for\n";
	descriptionString += "modulation by sequencer track 4.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::seqTrackDestComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::seqTrackDestComboBoxes_x, 418));

	//======================================================

	identifiers.add("assignKnob1"); // 105
	exposedNames.add("Assign Parameter to Knob 1");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)105);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)5);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 1.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knobAssignComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::knobAssignComboBoxes_x, 521));

	identifiers.add("assignKnob2"); // 106
	exposedNames.add("Assign Parameter to Knob 2");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)106);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)11);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 2.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knobAssignComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::knobAssignComboBoxes_x, 549));

	identifiers.add("assignKnob3"); // 107
	exposedNames.add("Assign Parameter to Knob 3");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)107);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)43);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 3.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knobAssignComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::knobAssignComboBoxes_x, 577));

	identifiers.add("assignKnob4"); // 108
	exposedNames.add("Assign Parameter to Knob 4");
	controlTypes.add(ControlType::comboBox);
	NRPNs.add((uint8)108);
	converters.add(IntToParamNameString::get());
	maxValues.add((uint8)168);
	defaultValues.add((uint8)23);
	descriptionString =  "Selects a target parameter for\n";
	descriptionString += "assignable hardware knob 4.";
	descriptions.add(descriptionString);
	controlWidths.add(GUI::knobAssignComboBoxes_w);
	controlHeights.add(GUI::comboBox_h);
	controlCenterPoints.add(Point<int>(GUI::knobAssignComboBoxes_x, 605));

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
			NRPNs.add((uint8)(120 + (16 * track) + step));
			converters.add(IntToSeqStepValueString::get());
			maxValues.add(track == 0 ? (uint8)127 : (uint8)126);
			defaultValues.add((uint8)0);
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
			controlWidths.add(GUI::seqSteps_w);
			controlHeights.add(GUI::seqSteps_h);
			controlCenterPoints.add(Point<int>(GUI::sequencerStep1_x + step * GUI::sequencerStepsHorizontalSpacer, GUI::sequencerTrack1Steps_y + track * GUI::sequencerTracksVerticalSpacer));
		}
	}

	//======================================================

	// 184..199
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		identifiers.add("nameChar" + charNumString);
		exposedNames.add("Program Name Character " + charNumString);
		controlTypes.add(ControlType::pgmNameChar);
		NRPNs.add((uint8)(184 + charNum));
		converters.add(IntToPgmNameCharString::get());
		maxValues.add((uint8)127);
		descriptionString =  "To change character " + charNumString + " of the program" + GUI::apostrophe + "s name,\n";
		descriptionString += "click-and-drag the character or hover over\n";
		descriptionString += "it and turn the mouse wheel. Click the edit\n";
		descriptionString += "button above to type in the entire name.";
		descriptions.add(descriptionString);
		controlWidths.add(GUI::pgmNameCharacters_w);
		controlHeights.add(GUI::pgmNameCharacters_h);
		controlCenterPoints.add(Point<int>(GUI::pgmNameCharacter1_x + (charNum * GUI::pgmNameCharactersHorizontalSpacer), GUI::pgmNameCharacters_y));
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

	for (uint16 param = 0; param != 189; ++param) {
		fillDataByteLocationsFor(param);
	}
}

void InfoForExposedParameters::fillDataByteLocationsFor(uint16 param) {
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

uint8 InfoForExposedParameters::NRPNfor(uint8 paramIndex) const {
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

Point<int> InfoForExposedParameters::controlCenterPointFor(uint8 paramIndex) const {
	return controlCenterPoints[paramIndex];
}

int InfoForExposedParameters::controlWidthFor(uint8 paramIndex) const {
	return controlWidths[paramIndex];
}

int InfoForExposedParameters::controlHeightFor(uint8 paramIndex) const {
	return controlHeights[paramIndex];
}

uint8 InfoForExposedParameters::indexForParamID(const String& parameterID) const {
	return (uint8)identifiers.indexOf(Identifier(parameterID));
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

uint8 InfoForExposedParameters::indexForNRPN(const uint8 nrpn) const {
	auto index{ NRPNs.indexOf(nrpn) };
	if (index > -1)
		return (uint8)NRPNs.indexOf(nrpn);
	else
		return (uint8)255;
}

