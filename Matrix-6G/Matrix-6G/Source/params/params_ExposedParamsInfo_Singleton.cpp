#include "params_ExposedParamsInfo_Singleton.h"

#include "params_IntToContextualStringConverters.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"



InfoForExposedParameters::InfoForExposedParameters() {
	fillAllInfoContainers();
}

void InfoForExposedParameters::fillAllInfoContainers() {
	static const auto controls_h{ 20 };
	static const auto controlsVerticalGap{ 8 };
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
	identifiers.add("osc1Pitch"); // 0
	exposedNames.add("Oscillator 1 Pitch");
	controlTypes.add(ControlType::slider);
	converters.add(IntToOscPitchString::get());
	minValues.add((int8)0);
	maxValues.add((int8)63);
	defaultValues.add((int8)24);
	descriptionString =  "Sets oscillator 1's base pitch in semitone steps.\n";
	descriptionString += "Range: C 0 to D#5.";
}
