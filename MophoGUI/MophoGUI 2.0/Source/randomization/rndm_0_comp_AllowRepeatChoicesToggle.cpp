#include "rndm_0_comp_AllowRepeatChoicesToggle.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;

AllowRepeatChoicesToggle::AllowRepeatChoicesToggle(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() }
{
	auto allowedChoicesType{ info->allowedChoicesTypeFor(paramIndex) };
	jassert(allowedChoicesType != AllowedChoicesType::seqTrackStep);
	if (allowedChoicesType != AllowedChoicesType::binary) {
		onlyOneChoiceIsAllowedForParamAsValue = randomization->getOnlyOneChoiceIsAllowedForParamAsValue(paramIndex);
		onlyOneChoiceIsAllowedForParamAsValue.addListener(this);
	}

	setInterceptsMouseClicks(true, false);

	toggle_AllowRepeatChoices.setComponentID(ID::comp_RedToggle.toString());
	toggle_AllowRepeatChoices.onClick = [this, paramIndex] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomization->setRepeatChoicesAreAllowedForParam(shouldBeAllowed ? true : false, paramIndex);
	};
	toggle_AllowRepeatChoices.addShortcut(KeyPress{ 'r', ModifierKeys::ctrlModifier, 0 });
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. ";
		if (allowedChoicesType != AllowedChoicesType::binary) {
			tip += "Obviously,\n";
			tip += "if there is only one allowed setting then the\n";
			tip += "same setting is always going to be produced.";
		}
		else {
			tip += "This means\n";
			tip += "that the toggle will simply alternate between\n";
			tip += "states with every randomization.\n";
			tip += "Shortcut key: CTRL+R";
		}
		toggle_AllowRepeatChoices.setTooltip(tip);
	}
	toggle_AllowRepeatChoices.setBounds(0, 0, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_AllowRepeatChoices);

	if (allowedChoicesType == AllowedChoicesType::binary) {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
	}
	else
		valueChanged(onlyOneChoiceIsAllowedForParamAsValue);

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle::mouseDown(const MouseEvent& /*event*/) {
	toggle_AllowRepeatChoices.triggerClick();
}

void AllowRepeatChoicesToggle::valueChanged(Value& /*value*/) {
	if ((bool)onlyOneChoiceIsAllowedForParamAsValue.getValue() == true) {
		toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
		setEnabled(false);
	}
	else {
		toggle_AllowRepeatChoices.setToggleState(randomization->repeatChoicesAreAllowedForParam(paramIndex), dontSendNotification);
		setEnabled(true);
	}
}

AllowRepeatChoicesToggle::~AllowRepeatChoicesToggle() {
	if (info->allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary)
		onlyOneChoiceIsAllowedForParamAsValue.removeListener(this);
}
