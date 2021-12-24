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
			defaultValues.add((uint8)0);
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
		defaultValues.add((uint8)1);
		firstNybbleIndices.add((uint8)30);
		firstBitIndices.add(i == 0 ? (uint8)0 : (uint8)3);

		identifiers.add("osc" + oscLetter + "_Tri"); // Parameters 3 & 9 
		exposedNames.add("Oscillator " + oscLetter + " Shape: Triangle");
		controlTypes.add(ControlType::twoPoleSwitch);
		descriptionString = "When on, oscillator " + oscLetter + " outputs a triangle wave.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::switchesOscTri_x, i == 0 ? GUI::switchRow2_y : GUI::switchRow3_y));
		maxValues.add((uint8)1);
		defaultValues.add((uint8)1);
		firstNybbleIndices.add(i == 0 ? (uint8)30 : 31);
		firstBitIndices.add(i == 0 ? (uint8)1 : (uint8)0);

		identifiers.add("osc" + oscLetter + "_Pulse"); // Parameters 4 & 10 
		exposedNames.add("Oscillator " + oscLetter + " Shape: Pulse");
		controlTypes.add(ControlType::twoPoleSwitch);
		descriptionString = "When on, oscillator " + oscLetter + " outputs a pulse wave.";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::switchesOscPulse_x, i == 0 ? GUI::switchRow2_y : GUI::switchRow3_y));
		maxValues.add((uint8)1);
		defaultValues.add((uint8)0);
		firstNybbleIndices.add((uint8)28);
		firstBitIndices.add(i == 0 ? (uint8)0 : (uint8)1);
	}
}
