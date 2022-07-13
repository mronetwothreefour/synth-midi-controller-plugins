#include "rndm_0_comp_AllowRepeatChoicesToggle_SeqTrackStep.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



AllowRepeatChoicesToggle_SeqTrackStep::AllowRepeatChoicesToggle_SeqTrackStep(
	Track track, Step step, ExposedParamsRandomizationOptions* randomization, UnexposedParameters* unexposedParams) :
	track{ track },
	step{ step },
	randomization{ randomization },
	trackTree{ randomization->getChildTreeForSeqTrack(track) }
{
	trackTree.addListener(this);
	toggle_AllowRepeatChoices.setComponentID(ID::component_RedToggle_AllowRepeatChoices.toString());
	toggle_AllowRepeatChoices.onClick = [this, randomization, track, step] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomization->setRepeatChoicesAreAllowedForSeqTrackStep(shouldBeAllowed ? true : false, track, step);
	};
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescriptions()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. Obviously, if\n";
		tip += "there is only one allowed setting then the\n";
		tip += "same setting is always going to be produced.";
		toggle_AllowRepeatChoices.setTooltip(tip);
	}
	toggle_AllowRepeatChoices.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_AllowRepeatChoices);

	ValueTree placeholderTree{ ID::rndm_SeqTrack_.toString() + String((int)track)};
	Identifier propertyID{ ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + String((int)step) };
	valueTreePropertyChanged(placeholderTree, propertyID);

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle_SeqTrackStep::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle_SeqTrackStep::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == ID::rndm_RepeatChoicesMustBeAllowedForStep_.toString() + String((int)step)) {
		if (randomization->repeatChoicesMustBeAllowedForSeqTrackStep(track, step)) {
			toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(false);
		}
		else {
			auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForSeqTrackStep(track, step) };
			toggle_AllowRepeatChoices.setToggleState(repeatsAreAllowed ? true : false, dontSendNotification);
			toggle_AllowRepeatChoices.setEnabled(true);
		}
	}
}

AllowRepeatChoicesToggle_SeqTrackStep::~AllowRepeatChoicesToggle_SeqTrackStep() {
	trackTree.removeListener(this);
}
