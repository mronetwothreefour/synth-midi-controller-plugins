#include "rndm_0_comp_AllowRepeatChoicesToggle_AllSeqTrackSteps.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



AllowRepeatChoicesToggle_AllSeqTrackSteps::AllowRepeatChoicesToggle_AllSeqTrackSteps(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	randomizationOptions{ unexposedParams->getRandomizationOptions() }
{
	jassert(trackNum > 0 && trackNum < 5);
	randomizationOptions->addListenerToSeqTrackTree(this, trackNum);
	toggle_AllowRepeatChoices.setComponentID(ID::component_RedToggle_AllowRepeatChoices.toString());
	toggle_AllowRepeatChoices.onClick = [this, trackNum] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomizationOptions->setRepeatChoicesAreAllowedForAllStepsInSeqTrack(shouldBeAllowed ? true : false, trackNum);
	};
	toggle_AllowRepeatChoices.setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether the current step setting is allowed\n";
		toggleTooltip += "when a new setting is randomly generated for all the\n";
		toggleTooltip += "steps in the track. If it is not, consecutive randomiz-\n";
		toggleTooltip += "ation operations can never produce the same setting.\n";
		toggleTooltip += "Obviously, if there is only one allowed setting then\n";
		toggleTooltip += "the same setting is always going to be produced.";
		toggle_AllowRepeatChoices.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(toggle_AllowRepeatChoices);

	ValueTree placeholderTree{ ID::rndm_SeqTrack_.toString() + (String)trackNum };
	valueTreePropertyChanged(placeholderTree, ID::rndm_RepeatChoicesMustBeAllowedForAllSteps);

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle_AllSeqTrackSteps::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle_AllSeqTrackSteps::resized() {
	toggle_AllowRepeatChoices.setTopLeftPosition(0, 0);
}

void AllowRepeatChoicesToggle_AllSeqTrackSteps::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID == ID::rndm_RepeatChoicesMustBeAllowedForAllSteps) {
		if (randomizationOptions->repeatsMustBeAllowedForAllStepsInSeqTrack(trackNum)) {
			toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(false);
		}
		else {
			auto repeatsAreAllowed{ randomizationOptions->repeatChoicesAreAllowedForAllStepsInSeqTrack(trackNum) };
			toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(true);
		}
	}
}

AllowRepeatChoicesToggle_AllSeqTrackSteps::~AllowRepeatChoicesToggle_AllSeqTrackSteps() {
	randomizationOptions->removeListenerFromSeqTrackTree(this, trackNum);
}
