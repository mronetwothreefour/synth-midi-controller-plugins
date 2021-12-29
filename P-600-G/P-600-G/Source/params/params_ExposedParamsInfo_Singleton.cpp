#include "params_ExposedParamsInfo_Singleton.h"

#include "../gui/gui_Constants.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	String descriptionString;

	for (int i = 0; i!= 2; ++i) {
		String oscLetter{ i == 0 ? "A" : "B" };
		identifiers.add("osc" + oscLetter + "_Frequency"); // Parameters 0 & 6
		exposedNames.add("Oscillator " + oscLetter + " Frequency");
		controlTypes.add(ControlType::knob);
		descriptionString = "Sets oscillator " + oscLetter + GUI::apostrophe + "s base pitch in semitone steps.\n";
		descriptionString += "Range: 0 (C 0) to 48 (C 4). Hold down the\n";
		descriptionString += "SHIFT key when using the mouse wheel to incre-\n";
		descriptionString += "ment the pitch by one octave (12 semitones).";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::knobsOscFrequency_x, i == 0 ? GUI::knobRow2_y : GUI::knobRow3_y));
		maxValues.add((uint8)48);
		defaultValues.add((uint8)12);
		firstNybbleIndices.add(i == 0 ? (uint8)8 : (uint8)6);
		firstBitIndices.add(i == 0 ? (uint8)1 : (uint8)3);

		if (i == 0) {
			identifiers.add("oscA_Sync"); // Parameter 1 
			exposedNames.add("Oscillator A Sync");
			controlTypes.add(ControlType::twoPoleSwitch);
			descriptionString = "When on, oscillator A is forced to follow\n";
			descriptionString += "oscillator B in " + GUI::openQuote + "hard" + GUI::closeQuote + "synchronization.";
			descriptions.add(descriptionString);
			controlCenterPoints.add(Point<int>(GUI::switchOscA_Sync_x, GUI::switchRow2_y));
			maxValues.add((uint8)1);
			defaultValues.add((uint8)1);
			firstNybbleIndices.add((uint8)30);
			firstBitIndices.add((uint8)2);
		}

		if (i == 1) {
			identifiers.add("oscB_Fine"); // Parameter 7 
			exposedNames.add("Oscillator B Fine");
			controlTypes.add(ControlType::knob);
			descriptionString = "Raises the pitch of oscillator B by\n";
			descriptionString += "up to one semitone. Range: 0 to 127";
			descriptions.add(descriptionString);
			controlCenterPoints.add(Point<int>(GUI::knobOscB_Fine_x, GUI::knobRow3_y));
			maxValues.add((uint8)127);
			defaultValues.add((uint8)0);
			firstNybbleIndices.add((uint8)9);
			firstBitIndices.add((uint8)3);
		}

		identifiers.add("osc" + oscLetter + "_Saw"); // Parameters 2 & 8 
		exposedNames.add("Oscillator " + oscLetter + " Shape: Sawtooth");
		controlTypes.add(ControlType::twoPoleSwitch);
		descriptionString = "When on, oscillator " + oscLetter + " outputs a sawtooth wave.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::switchesOscSaw_x, i == 0 ? GUI::switchRow2_y : GUI::switchRow3_y));
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		firstNybbleIndices.add((uint8)30);
		firstBitIndices.add(i == 0 ? (uint8)0 : (uint8)3);

		identifiers.add("osc" + oscLetter + "_Tri"); // Parameters 3 & 9 
		exposedNames.add("Oscillator " + oscLetter + " Shape: Triangle");
		controlTypes.add(ControlType::twoPoleSwitch);
		descriptionString = "When on, oscillator " + oscLetter + " outputs a triangle wave.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::switchesOscTri_x, i == 0 ? GUI::switchRow2_y : GUI::switchRow3_y));
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		firstNybbleIndices.add(i == 0 ? (uint8)30 : 31);
		firstBitIndices.add(i == 0 ? (uint8)1 : (uint8)0);

		identifiers.add("osc" + oscLetter + "_Pulse"); // Parameters 4 & 10 
		exposedNames.add("Oscillator " + oscLetter + " Shape: Pulse");
		controlTypes.add(ControlType::twoPoleSwitch);
		descriptionString = "When on, oscillator " + oscLetter + " outputs a pulse wave.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::switchesOscPulse_x, i == 0 ? GUI::switchRow2_y : GUI::switchRow3_y));
		maxValues.add((uint8)1);
		defaultValues.add((uint8)1);
		firstNybbleIndices.add((uint8)28);
		firstBitIndices.add(i == 0 ? (uint8)0 : (uint8)1);

		identifiers.add("osc" + oscLetter + "_PulseWidth"); // Parameters 5 & 11
		exposedNames.add("Oscillator " + oscLetter + " Pulse Width");
		controlTypes.add(ControlType::knob);
		descriptionString = "Sets the width of the pulse wave generated by oscillator " + oscLetter + GUI::apostrophe + ".\n";
		descriptionString += "This has no effect if the oscillator's Wave Shape: Pulse switch\n";
		descriptionString += "is turned off. Range: 0 (narrowest) to 127 (widest). A value of\n";
		descriptionString += "64 will produce an approximately square wave. At the extremes of\n";
		descriptionString += "the range, the pulse will thin out so much as to be inaudible.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::knobsOscPulseWidth_x, i == 0 ? GUI::knobRow2_y : GUI::knobRow3_y));
		maxValues.add((uint8)127);
		defaultValues.add((uint8)64);
		firstNybbleIndices.add(i == 0 ? (uint8)0 : (uint8)26);
		firstBitIndices.add(i == 0 ? (uint8)0 : (uint8)1);
	}

	identifiers.add("mixer"); // Parameter 12
	exposedNames.add("Mixer");
	controlTypes.add(ControlType::knob);
	descriptionString = "Adjusts the ratio of the two oscillators' output to the filter.\n";
	descriptionString += "Range: 0 (only oscillator A is output) to 63 (only oscillator B).\n";
	descriptionString += "At a setting of 32, an equal mix of the two oscillators is output.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsMixerAndGlide_x, GUI::knobRow2_y));
	maxValues.add((uint8)63);
	defaultValues.add((uint8)32);
	firstNybbleIndices.add((uint8)11);
	firstBitIndices.add((uint8)2);

	identifiers.add("glide"); // Parameter 13
	exposedNames.add("Glide");
	controlTypes.add(ControlType::knob);
	descriptionString = GUI::openQuote + "Glide" + GUI::closeQuote + " is a smooth pitch transition between two consecutive notes.\n";
	descriptionString += "This knob adjusts the amount of time for the transition to complete.\n";
	descriptionString += "The actual time is dependent upon the distance between the two notes.\n";
	descriptionString += "Range: 0 (instantaneous, i.e. no glide) to 15 (longest glide time).";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsMixerAndGlide_x, GUI::knobRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)25);
	firstBitIndices.add((uint8)1);

	identifiers.add("filterCutoff"); // Parameter 14
	exposedNames.add("Filter Cutoff Frequency");
	controlTypes.add(ControlType::knob);
	descriptionString = "Adjusts the cutoff frequency of the 4-pole low-pass filter.\n";
	descriptionString += "Increasing the cutoff lets through higher and higher fre-\n";
	descriptionString += "quencies and makes the sound 'brighter.' Range: 0 to 127.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsCutoffAndAttack_x, GUI::knobRow1_y));
	maxValues.add((uint8)127);
	defaultValues.add((uint8)66);
	firstNybbleIndices.add((uint8)13);
	firstBitIndices.add((uint8)0);

	identifiers.add("filterReso"); // Parameter 15
	exposedNames.add("Filter Resonance");
	controlTypes.add(ControlType::knob);
	descriptionString = "Increasing filter resonance boosts frequencies near the\n";
	descriptionString += "cutoff frequency. At high resonance settings, the filter\n";
	descriptionString += "will self-oscillate, producing a sine wave with a pitch\n";
	descriptionString += "determined by the cutoff frequency. Range: 0 to 63.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsResoAndDecay_x, GUI::knobRow1_y));
	maxValues.add((uint8)63);
	defaultValues.add((uint8)32);
	firstNybbleIndices.add((uint8)14);
	firstBitIndices.add((uint8)3);

	identifiers.add("filterEnvAmt"); // Parameter 16
	exposedNames.add("Filter Envelope Amount");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the depth of the envelope which modulates the filter\n";
	descriptionString += "cutoff frequency. Range: 0 (no modulation) to 15 (maximum depth).";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsEnvAmtAndSustain_x, GUI::knobRow1_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)16);
	firstBitIndices.add((uint8)1);

	identifiers.add("filterKeyTrack"); // Parameter 17
	exposedNames.add("Filter Keyboard Tracking");
	controlTypes.add(ControlType::threePoleSwitch);
	descriptionString = "When set to FULL, the filter cutoff frequency " + GUI::openQuote + "tracks" + GUI::closeQuote + " the notes\n";
	descriptionString += "played on the keyboard, rising and falling so that all pitches have\n";
	descriptionString += "consistent brightness and loudness. When set to OFF, the cutoff\n";
	descriptionString += "frequency does not change. As you go higher up the keyboard past\n";
	descriptionString += "the cutoff frequency, the pitches are progressively duller and\n";
	descriptionString += "quieter. 1/2 selects the midrange between these two effects.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchKeyFollow_x, GUI::switchRow1_y));
	maxValues.add((uint8)2);
	defaultValues.add((uint8)2);
	firstNybbleIndices.add((uint8)28);
	firstBitIndices.add((uint8)2);

	identifiers.add("filterAttack"); // Parameter 18
	exposedNames.add("Filter Envelope Attack");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the filter\n";
	descriptionString += "envelope to rise from zero to maximum level.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsCutoffAndAttack_x, GUI::knobRow2_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)20);
	firstBitIndices.add((uint8)1);

	identifiers.add("filterDecay"); // Parameter 19
	exposedNames.add("Filter Envelope Decay");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the filter envelope\n";
	descriptionString += "to fall from maximum level down to the sustain level.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsResoAndDecay_x, GUI::knobRow2_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)19);
	firstBitIndices.add((uint8)1);

	identifiers.add("filterSustain"); // Parameter 20
	exposedNames.add("Filter Envelope Sustain");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the sustain level for the filter envelope.\n";
	descriptionString += "The envelope decays to this level and stays\n";
	descriptionString += "there until the note is released.\n";
	descriptionString += "Range: 0 to 15 (maximum level)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsEnvAmtAndSustain_x, GUI::knobRow2_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)18);
	firstBitIndices.add((uint8)1);

	identifiers.add("filterRelease"); // Parameter 21
	exposedNames.add("Filter Envelope Release.");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the filter\n";
	descriptionString += "envelope to fall to zero once the note is released.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsRelease_x, GUI::knobRow2_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)17);
	firstBitIndices.add((uint8)1);

	identifiers.add("amplifierAttack"); // Parameter 22
	exposedNames.add("Amplifier Envelope Attack");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the amplifier\n";
	descriptionString += "envelope to rise from zero to maximum level.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsCutoffAndAttack_x, GUI::knobRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)24);
	firstBitIndices.add((uint8)1);

	identifiers.add("amplifierDecay"); // Parameter 23
	exposedNames.add("Amplifier Envelope Decay");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the amplifier envelope\n";
	descriptionString += "to fall from maximum level down to the sustain level.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsResoAndDecay_x, GUI::knobRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)23);
	firstBitIndices.add((uint8)1);

	identifiers.add("amplifierSustain"); // Parameter 24
	exposedNames.add("Amplifier Envelope Sustain");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the sustain level for the amplifier envelope.\n";
	descriptionString += "The envelope decays to this level and stays\n";
	descriptionString += "there until the note is released.\n";
	descriptionString += "Range: 0 to 15 (maximum level)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsEnvAmtAndSustain_x, GUI::knobRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)15);
	firstNybbleIndices.add((uint8)22);
	firstBitIndices.add((uint8)1);

	identifiers.add("amplifierRelease"); // Parameter 25
	exposedNames.add("Amplifier Envelope Release");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the amount of time it takes for the amplifier\n";
	descriptionString += "envelope to fall to zero once the note is released.\n";
	descriptionString += "Range: 0 (instantaneous) to 15 (longest time)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsRelease_x, GUI::knobRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)21);
	firstBitIndices.add((uint8)1);

	identifiers.add("polyModAmt_FilterEnv"); // Parameter 26
	exposedNames.add("Poly-Mod Filter Envelope Amount");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the degree to which the filter envelope\n";
	descriptionString += "modulates the enabled poly-mod destination(s).\n";
	descriptionString += "Range: 0 (no modulation) to 15 (maximum modulation)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsPmodFilterEnvAndLFOfreq_x, GUI::knobRow2_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)1);
	firstBitIndices.add((uint8)3);

	identifiers.add("polyModAmt_OscB"); // Parameter 27
	exposedNames.add("Poly-Mod Oscillator B Amount");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the degree to which oscillator B" + GUI::apostrophe + "s frequency\n";
	descriptionString += "modulates the enabled poly-mod destination(s).\n";
	descriptionString += "Range: 0 (no modulation) to 127 (maximum modulation)";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobPmodOscB_x, GUI::knobRow2_y));
	maxValues.add((uint8)127);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)3);
	firstBitIndices.add((uint8)3);

	identifiers.add("polyModDest_OscAfreq"); // Parameter 28 
	exposedNames.add("Poly-Mod Destination: Oscillator A Frequency");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables modulation of oscillator A" + GUI::apostrophe + "s\n";
	descriptionString = "frequency by the two poly-mod sources.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchesPmodDestOscAandLFOdestFreq_x, GUI::switchRow2_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)31);
	firstBitIndices.add((uint8)1);

	identifiers.add("polyModDest_Filter"); // Parameter 29 
	exposedNames.add("Poly-Mod Destination: Filter Cutoff Frequency");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables modulation of the filter" + GUI::apostrophe + "s cutoff\n";
	descriptionString = "frequency by the two poly-mod sources.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchPmodFilter_x, GUI::switchRow2_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)31);
	firstBitIndices.add((uint8)2);

	identifiers.add("unisonTrack"); // Parameter 30 
	exposedNames.add("Unison Tracking");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables one of the three unison keyboard tracking modes:\n";
	descriptionString = "Normal: Switch unison on while no keys are pressed. All 6 voices play\n";
	descriptionString = "at once at a single pitch (the lowest triggered note has priority).\n";
	descriptionString = "Chord Track: Switch unison on while holding down multiple notes.\n";
	descriptionString = "When new notes are triggered, the same note intervals are played,\n";
	descriptionString = "but with the lowest triggered new note as the root.\n";
	descriptionString = "Single Voice: Switch unison on while holding down a single note.\n";
	descriptionString = "Similar to normal unison, but only one voice plays at a time.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchUnison_x, GUI::switchRow2_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)31);
	firstBitIndices.add((uint8)3);

	identifiers.add("lfoFreq"); // Parameter 31
	exposedNames.add("LFO Frequency");
	controlTypes.add(ControlType::knob);
	descriptionString = "Adjusts the frequency of the low-frequency oscillator.\n";
	descriptionString = "Range: 0 (~0.25 Hz) to 16 (~20 Hz)\n";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobsPmodFilterEnvAndLFOfreq_x, GUI::switchRow3_y));
	maxValues.add((uint8)15);
	defaultValues.add((uint8)9);
	firstNybbleIndices.add((uint8)2);
	firstBitIndices.add((uint8)3);

	identifiers.add("lfoShape"); // Parameter 32 
	exposedNames.add("LFO Wave Shape");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Sets the low-frequency oscillator" + GUI::apostrophe + "s\n";
	descriptionString = "wave shape (square or triangle).";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchesPmodDestOscAandLFOdestFreq_x, GUI::switchRow3_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)1);
	firstNybbleIndices.add((uint8)29);
	firstBitIndices.add((uint8)0);

	identifiers.add("lfoInitAmount"); // Parameter 33
	exposedNames.add("LFO Initial Amount");
	controlTypes.add(ControlType::knob);
	descriptionString = "Sets the baseline amount of modulation produced by the low-\n";
	descriptionString = "frequency oscillator when the modulation wheel is at zero.\n";
	descriptionString = "Range: 0 (no modulation) to 31 (maximum modulation)\n";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::knobLFOamount_x, GUI::switchRow3_y));
	maxValues.add((uint8)31);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)5);
	firstBitIndices.add((uint8)2);

	identifiers.add("lfoDest_Freq"); // Parameter 34 
	exposedNames.add("LFO Destination: Oscillator Frequency");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables modulation of the frequencies of both\n";
	descriptionString = "oscillators by the low-frequency oscillator.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchesPmodDestOscAandLFOdestFreq_x, GUI::switchRow3_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)29);
	firstBitIndices.add((uint8)1);

	identifiers.add("lfoDest_PW"); // Parameter 35 
	exposedNames.add("LFO Destination: Oscillator Pulse Width");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables modulation of the pulse widths of both\n";
	descriptionString = "oscillators by the low-frequency oscillator.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchesPmodDestFilterandLFOdestPW_x, GUI::switchRow3_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)1);
	firstNybbleIndices.add((uint8)29);
	firstBitIndices.add((uint8)2);

	identifiers.add("lfoDest_Filter"); // Parameter 36
	exposedNames.add("LFO Destination: Filter Cutoff");
	controlTypes.add(ControlType::twoPoleSwitch);
	descriptionString = "Enables modulation of the filter's cutoff\n";
	descriptionString = "frequency by the low-frequency oscillator.";
	descriptions.add(descriptionString);
	controlCenterPoints.add(Point<int>(GUI::switchLFOdestFilter_x, GUI::switchRow3_y));
	maxValues.add((uint8)1);
	defaultValues.add((uint8)0);
	firstNybbleIndices.add((uint8)29);
	firstBitIndices.add((uint8)3);
}
