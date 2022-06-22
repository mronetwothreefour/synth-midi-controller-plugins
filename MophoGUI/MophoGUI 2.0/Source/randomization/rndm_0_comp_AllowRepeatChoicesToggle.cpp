#include "rndm_0_comp_AllowRepeatChoicesToggle.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Info = InfoForExposedParameters;



AllowRepeatChoicesToggle::AllowRepeatChoicesToggle(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	randomization{ unexposedParams->getRandomizationOptions() }
{
	auto allowedChoicesType{ Info::get().allowedChoicesTypeFor(paramIndex) };
	jassert(allowedChoicesType != AllowedChoicesType::seqTrackStep);
	if (allowedChoicesType != AllowedChoicesType::binary)
		randomization->addListenerToChildTreeForParam(this, paramIndex);
	toggle_AllowRepeatChoices.setComponentID(ID::component_RedToggle_AllowRepeatChoices.toString());
	toggle_AllowRepeatChoices.onClick = [this, paramIndex] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomization->setRepeatChoicesAreAllowedForParam(shouldBeAllowed ? true : false, paramIndex);
	};
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto numberOfChoices{ Info::get().numberOfChoicesFor(paramIndex) };
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. ";
		if (numberOfChoices > 2) {
			tip += "Obviously, if\n";
			tip += "there is only one allowed setting then the\n";
			tip += "same setting is always going to be produced.";
		}
		else {
			tip += "This means that\n";
			tip += "the toggle will simply alternate between\n";
			tip += "states with every randomization.";
		}
		toggle_AllowRepeatChoices.setTooltip(tip);
	}
	toggle_AllowRepeatChoices.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_AllowRepeatChoices);

	if (allowedChoicesType == AllowedChoicesType::binary) {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
	}
	else {
		ValueTree placeholderTree{ Info::get().IDfor(paramIndex) };
		valueTreePropertyChanged(placeholderTree, ID::rndm_OnlyOneChoiceIsAllowed);
	}

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID == ID::rndm_OnlyOneChoiceIsAllowed) {
		if (randomization->onlyOneChoiceIsAllowedForParam(paramIndex)) {
			toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(false);
		}
		else {
			auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
			toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(true);
		}
	}
}

AllowRepeatChoicesToggle::~AllowRepeatChoicesToggle() {
	if (Info::get().allowedChoicesTypeFor(paramIndex) != AllowedChoicesType::binary)
		randomization->removeListenerFromChildTreeForParam(this, paramIndex);
}
