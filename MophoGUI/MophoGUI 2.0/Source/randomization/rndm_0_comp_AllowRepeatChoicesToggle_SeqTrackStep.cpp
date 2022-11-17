#include "rndm_0_comp_AllowRepeatChoicesToggle_SeqTrackStep.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace MophoConstants;

AllowRepeatChoicesToggle_SeqTrackStep::AllowRepeatChoicesToggle_SeqTrackStep(
	Track track, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	track{ track },
	step{ randomization->targetStepForSeqTrack(track) },
	randomization{ randomization }
{
	repeatsMustBeAllowedForStepAsValue = randomization->getRepeatsMustBeAllowedForSeqTrackStepAsValue(track, step);
	repeatsMustBeAllowedForStepAsValue.addListener(this);

	setInterceptsMouseClicks(true, false);

	toggle_AllowRepeatChoices.setComponentID(ID::comp_RedToggle.toString());
	toggle_AllowRepeatChoices.onClick = [this, randomization, track] {
		auto shouldBeAllowed{ toggle_AllowRepeatChoices.getToggleState() };
		randomization->setRepeatChoicesAreAllowedForSeqTrackStep(shouldBeAllowed ? true : false, track, step);
	};
	toggle_AllowRepeatChoices.addShortcut(KeyPress{ 'r', ModifierKeys::ctrlModifier, 0 });
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. Obviously, if\n";
		tip += "there is only one allowed setting then the\n";
		tip += "same setting is always going to be produced.\n";
		tip += "Shortcut key: CTRL+R";
		toggle_AllowRepeatChoices.setTooltip(tip);
	}
	toggle_AllowRepeatChoices.setBounds(0, 0, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_AllowRepeatChoices);

	valueChanged(repeatsMustBeAllowedForStepAsValue);

	setSize(GUI::allowRepeatChoicesToggleComponent_w, GUI::allowRepeatChoicesToggleComponent_h);
}

void AllowRepeatChoicesToggle_SeqTrackStep::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesToggle_png, BinaryData::bkgrnd_RepeatChoicesToggle_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesToggle_SeqTrackStep::mouseDown(const MouseEvent& /*event*/) {
	toggle_AllowRepeatChoices.triggerClick();
}

void AllowRepeatChoicesToggle_SeqTrackStep::valueChanged(Value& /*value*/) {
	if ((bool)repeatsMustBeAllowedForStepAsValue.getValue() == true) {
		toggle_AllowRepeatChoices.setToggleState(true, dontSendNotification);
		setEnabled(false);
	}
	else {
		toggle_AllowRepeatChoices.setToggleState(randomization->repeatChoicesAreAllowedForSeqTrackStep(track, step), dontSendNotification);
		setEnabled(true);
	}
}

AllowRepeatChoicesToggle_SeqTrackStep::~AllowRepeatChoicesToggle_SeqTrackStep() {
	repeatsMustBeAllowedForStepAsValue.removeListener(this);
}
