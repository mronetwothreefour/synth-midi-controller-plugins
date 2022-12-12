#include "rndm_0_comp_AllowRepeatChoicesSwitch.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace P_600_G_Constants;

AllowRepeatChoicesSwitch::AllowRepeatChoicesSwitch(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	switch_AllowRepeatChoices{ &exposedParams->undoManager }
{
	auto controlType{ info->controlTypeFor(paramIndex) };
	if (controlType != ControlType::twoPoleSwitch) {
		onlyOneChoiceIsAllowedForParamAsValue = randomization->getOnlyOneChoiceIsAllowedForParamAsValue(paramIndex);
		onlyOneChoiceIsAllowedForParamAsValue.addListener(this);
	}

	switch_AllowRepeatChoices.setRange(0.0, 1.0, 1.0);
	switch_AllowRepeatChoices.onValueChange = [this, paramIndex] {
		auto shouldBeAllowed{ switch_AllowRepeatChoices.getValue() == 1.0 };
		randomization->setRepeatChoicesAreAllowedForParam(shouldBeAllowed, paramIndex);
	};
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. ";
		if (controlType != ControlType::twoPoleSwitch) {
			tip += "Obviously,\n";
			tip += "if there is only one allowed setting then the\n";
			tip += "same setting is always going to be produced.";
		}
		else {
			tip += "This means\n";
			tip += "that the switch will simply alternate between\n";
			tip += "states with every randomization.";
		}
		switch_AllowRepeatChoices.setTooltip(tip);
	}
	setSize(GUI::switch_w, GUI::switch_2_Pole_h);
	switch_AllowRepeatChoices.setBounds(getLocalBounds());
	addAndMakeVisible(switch_AllowRepeatChoices);

	if (controlType == ControlType::twoPoleSwitch) {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		switch_AllowRepeatChoices.setValue(repeatsAreAllowed ? 1.0 : 0.0, dontSendNotification);
	}
	else
		valueChanged(onlyOneChoiceIsAllowedForParamAsValue);
}

void AllowRepeatChoicesSwitch::valueChanged(Value& /*value*/) {
	if ((bool)onlyOneChoiceIsAllowedForParamAsValue.getValue() == true) {
		switch_AllowRepeatChoices.setValue(1.0, dontSendNotification);
		setEnabled(false);
	}
	else {
		auto areAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		switch_AllowRepeatChoices.setValue(areAllowed ? 1.0 : 0.0, dontSendNotification);
		setEnabled(true);
	}
}

AllowRepeatChoicesSwitch::~AllowRepeatChoicesSwitch() {
	auto controlType{ info->controlTypeFor(paramIndex) };
	if (controlType != ControlType::twoPoleSwitch)
		onlyOneChoiceIsAllowedForParamAsValue.removeListener(this);
}
