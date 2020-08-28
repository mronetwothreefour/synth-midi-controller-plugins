#include "params_UnexposedParamsInfo_Singleton.h"

#include "params_Identifiers.h"
#include "params_IntToContextualStringConverters.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"



InfoForUnexposedParameters::InfoForUnexposedParameters() {
	fillAllInfoContainers();
}

void InfoForUnexposedParameters::fillAllInfoContainers() {
	static const auto knob_diameter{ 40 };
	static const auto toggle_diameter{ 14 };

	String descriptionString;

	identifiers.add(ID::global_Transpose); // 0
	controlTypes.add(ControlType::knobWithValueStringDisplay);
	NRPNs.add((uint16)384);
}
