#include "rndm_0_comp_AllowRepeatChoicesToggle.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



AllowRepeatChoicesToggle::AllowRepeatChoicesToggle(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	if (info.allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary)
		randomizationOptions->addListenerToChildTreeForParam(this, paramIndex);
	toggle_AllowRepeatChoices.setComponentID(ID::component_RedToggle_AllowRepeatChoices.toString());
	toggle_AllowRepeatChoices.onClick = [this, randomizationOptions, paramIndex] {
		auto allowed{ toggle_AllowRepeatChoices.getToggleState() };
		if (allowed)
			randomizationOptions->allowRepeatChoicesForParam(paramIndex);
		else
			randomizationOptions->forbidRepeatChoicesForParam(paramIndex);
	};
	toggle_AllowRepeatChoices.setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto numberOfChoices{ info.numberOfChoicesFor(paramIndex) };
		String knobTooltip{ "" };
		knobTooltip += "Toggles whether the current setting is allowed\n";
		knobTooltip += "when a new setting is randomly generated. If it\n";
		knobTooltip += "is not, consecutive randomization operations\n";
		knobTooltip += "can never produce the same setting. ";
		if (numberOfChoices > 2) {
			knobTooltip += "Obviously, if\n";
			knobTooltip += "there is only one allowed setting then the\n";
			knobTooltip += "same setting is always going to be produced.";
		}
		else {
			knobTooltip += "This means that\n";
			knobTooltip += "the toggle will simply alternate between\n";
			knobTooltip += "states with every randomization.";
		}
		toggle_AllowRepeatChoices.setTooltip(knobTooltip);
	}
	addAndMakeVisible(toggle_AllowRepeatChoices);

	if (info.allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::binary) {
		auto repeatsAllowed{ randomizationOptions->repeatChoicesAreAllowedForParam(paramIndex) };
		toggle_AllowRepeatChoices.setToggleState(repeatsAllowed ? true : false, dontSendNotification);
	}
	else {
		ValueTree placeholderTree{ info.IDfor(paramIndex) };
		valueTreePropertyChanged(placeholderTree, ID::rndm_OnlyOneChoiceIsAllowed);
	}

	setSize(70, 14);
}

void AllowRepeatChoicesToggle::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle::resized() {
	toggle_AllowRepeatChoices.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
}

void AllowRepeatChoicesToggle::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	if (tree.getType() == paramID) {
		if (propertyID == ID::rndm_OnlyOneChoiceIsAllowed) {
			auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
			if (randomizationOptions->onlyOneChoiceIsAllowedForParam(paramIndex)) {
				toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
				toggle_AllowRepeatChoices.setEnabled(false);
			}
			else {
				auto repeatsAllowed{ randomizationOptions->repeatChoicesAreAllowedForParam(paramIndex) };
				toggle_AllowRepeatChoices.setToggleState(repeatsAllowed ? true : false, dontSendNotification);
				toggle_AllowRepeatChoices.setEnabled(true);
			}
		}
	}
}

AllowRepeatChoicesToggle::~AllowRepeatChoicesToggle() {
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	if (info.allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary)
		randomizationOptions->removeListenerFromChildTreeForParam(this, paramIndex);
}
