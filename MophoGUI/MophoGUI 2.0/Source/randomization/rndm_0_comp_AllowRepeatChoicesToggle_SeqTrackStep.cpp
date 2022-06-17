#include "rndm_0_comp_AllowRepeatChoicesToggle_SeqTrackStep.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



AllowRepeatChoicesToggle_SeqTrackStep::AllowRepeatChoicesToggle_SeqTrackStep(int trackNum, int stepNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	stepNum{ stepNum },
	randomizationOptions{ unexposedParams->getRandomizationOptions() }
{
	jassert(trackNum > 0 && trackNum < 5);
	jassert(stepNum > 0 && stepNum < 17);
	randomizationOptions->addListenerToSeqTrackTree(this, trackNum);
	toggle_AllowRepeatChoices.setComponentID(ID::component_RedToggle_AllowRepeatChoices.toString());
	toggle_AllowRepeatChoices.onClick = [this, trackNum, stepNum] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomizationOptions->setRepeatChoicesAreAllowedForSeqTrackStep(shouldBeAllowed ? true : false, trackNum, stepNum);
	};
	toggle_AllowRepeatChoices.setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether the current setting is allowed\n";
		toggleTooltip += "when a new setting is randomly generated. If it\n";
		toggleTooltip += "is not, consecutive randomization operations\n";
		toggleTooltip += "can never produce the same setting. Obviously, if\n";
		toggleTooltip += "there is only one allowed setting then the\n";
		toggleTooltip += "same setting is always going to be produced.";
		toggle_AllowRepeatChoices.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(toggle_AllowRepeatChoices);

	ValueTree placeholderTree{ ID::rndm_SeqTrack_.toString() + (String)trackNum};
	Identifier propertyID{ ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + (String)stepNum };
	valueTreePropertyChanged(placeholderTree, propertyID);

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle_SeqTrackStep::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle_SeqTrackStep::resized() {
	toggle_AllowRepeatChoices.setTopLeftPosition(0, 0);
}

void AllowRepeatChoicesToggle_SeqTrackStep::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + (String)stepNum) {
		if (randomizationOptions->repeatsMustBeAllowedForSeqTrackStep(trackNum, stepNum)) {
			toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(false);
		}
		else {
			auto repeatsAreAllowed{ randomizationOptions->repeatChoicesAreAllowedForSeqTrackStep(trackNum, stepNum) };
			toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(true);
		}
	}
}

AllowRepeatChoicesToggle_SeqTrackStep::~AllowRepeatChoicesToggle_SeqTrackStep() {
	randomizationOptions->removeListenerFromSeqTrackTree(this, trackNum);
}
