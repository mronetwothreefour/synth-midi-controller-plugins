#include "params_ExposedParamsInfo_Singleton.h"

#include "../gui/gui_Constants.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	String descriptionString;

	for (int i = 1; i!= 3; ++i) {
		String oscLetter{ i == 1 ? "A" : "B" };
		identifiers.add("osc" + oscLetter + "_Frequency"); // 0 & 6
		exposedNames.add("Oscillator " + oscLetter + " Frequency");
		controlTypes.add(ControlType::knob);
		descriptionString = "Sets oscillator " + oscLetter + GUI::apostrophe + "s base pitch in semitone steps.\n";
		descriptionString += "Range: 0 (C 0) to 48 (C 4). Hold down the\n";
		descriptionString += "SHIFT key when using the mouse wheel to incre-\n";
		descriptionString += "ment the pitch by one octave (12 semitones).";
		descriptions.add(descriptionString);
		controlCenterPoints.add(Point<int>(GUI::knobsOscFrequency_x, i == 1 ? GUI::knobRow2_y : GUI::knobRow3_y));
		maxValues.add((uint8)48);
		defaultValues.add((uint8)12);
		firstNybbleIndices.add(i == 1 ? (uint8)8 : (uint8)6);
		firstBitIndices.add(i == 1 ? (uint8)1 : (uint8)3);

		if (i == 1) {
			identifiers.add("oscA_Sync"); // 1 
			exposedNames.add("Oscillator A Sync");
			controlTypes.add(ControlType::twoPoleSwitch);
			descriptionString = "When on, oscillator A is forced to follow\n";
			descriptionString += "oscillator B in " + GUI::openQuote + "hard" + GUI::closeQuote + "synchronization.";
			descriptions.add(descriptionString);
			controlCenterPoints.add(Point<int>(GUI::switchOscASync_x, GUI::switchRow2_y));
			maxValues.add((uint8)1);
			defaultValues.add((uint8)0);
			firstNybbleIndices.add((uint8)30);
			firstBitIndices.add((uint8)2);
		}
	}
}
