#include "rndm_2_gui_layer_AllowedChoices_SeqTrack.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_SeqTrack::GUI_Layer_AllowedChoices_SeqTrack(
	Track track, bool destIsPitched, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	track{ track },
	destIsPitched{ destIsPitched },
	unexposedParams{ unexposedParams },
	randomization{ exposedParams->randomization.get() },
	btn_Close{ unexposedParams },
	targetStepSelector{ track, randomization, unexposedParams },
	btn_Randomize{ track, exposedParams, unexposedParams}
{
	targetStepForSeqTrackValue = { randomization->getTargetStepForSeqTrackValue(track) };
	targetStepForSeqTrackValue.addListener(this);

	auto targetStep_x{ 0 };
	auto btn_Randomize_center_y{ 0 };
	if (destIsPitched) {
		background_x = track == Track::one ? 510 : 540;
		background_y = 41;
		background_w = track == Track::one ? 292 : 262;
		background_h = 548;
		center_x = track == Track::one ? 656 : 671;
		targetStep_x = track == Track::one ? 527 : 584;
		btn_Randomize_center_y = 561;
	}
	else {
		background_x = 430;
		background_y = 152;
		background_w = 372;
		background_h = 326;
		center_x = 616;
		targetStep_x = track == Track::one ? 487 : 529;
		btn_Randomize_center_y = 450;
	}
	auto allowAllAndCloseButtons_y{ background_y + GUI::allowedChoices_Inset };

	btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
	btn_AllowAll.onClick = [this, track] {
		auto targetStep{ randomization->targetStepForSeqTrack(track) };
		if (targetStep == Step::all)
			randomization->allowAllChoicesForAllSeqTrackSteps(track);
		else
			randomization->allowAllChoicesForSeqTrackStep(track, targetStep);
		if (allowChoiceToggles != nullptr)
			allowChoiceToggles->restoreToggles();
	};
	btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices\n";
		tip += "when generating a random setting\n";
		tip += "for the target step in track " + String((int)track) + ".\n";
		tip += "Shortcut key: CTRL+A";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setSize(GUI::btn_AllowAll_w, GUI::redButton_h);
	btn_AllowAll.setTopLeftPosition(background_x + GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(btn_AllowAll);

	btn_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(btn_Close);

	targetStepSelector.setTopLeftPosition(targetStep_x, background_y + 58);
	addAndMakeVisible(targetStepSelector);

	btn_Randomize.setCentrePosition(center_x, btn_Randomize_center_y);
	addAndMakeVisible(btn_Randomize);

	resetKnobsAndToggles();

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_SeqTrack::resetKnobsAndToggles() {
	repeatChoices.reset(new AllowRepeatChoicesToggle_SeqTrackStep{ track, randomization, unexposedParams });
	if (repeatChoices != nullptr) {
		repeatChoices->setCentrePosition(destIsPitched ? center_x + 10 : center_x, destIsPitched ? 69 : 180);
		addAndMakeVisible(repeatChoices.get());
	}

	probabilities.reset(new SeqTrackProbabilities{ track, randomization, unexposedParams });
	if (probabilities != nullptr) {
		auto probabilities_x{ track == Track::one ? 597 : 639 };
		if (destIsPitched)
			probabilities_x = track == Track::one ? 637 : 694;
		probabilities->setTopLeftPosition(probabilities_x, background_y + 47);
		addAndMakeVisible(probabilities.get());
	}

	allowChoiceToggles.reset(new AllowChoiceToggles_SeqTrackStep{ track, destIsPitched, randomization, unexposedParams });
	if (allowChoiceToggles != nullptr) {
		allowChoiceToggles->setCentrePosition(center_x, 349);
		addAndMakeVisible(allowChoiceToggles.get());
	}

	repaint();
}

void GUI_Layer_AllowedChoices_SeqTrack::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	g.setColour(GUI::color_ToggleOn);
	auto targetStep_1_Border_x{ 810 };
	auto targetStepBorder_y{ 181 + (GUI::seqTrackControlsGroup_h * ((int)track - 1)) };
	auto targetStepBorder_h{ GUI::seqSteps_h + 4 };
	auto targetStep{ randomization->targetStepForSeqTrack(track) };
	if (targetStep == Step::all)
		g.drawRect(targetStep_1_Border_x, targetStepBorder_y, 450, targetStepBorder_h, 2);
	else {
		auto targetStepBorder_x{ targetStep_1_Border_x + (28 * ((int)targetStep - 1)) };
		g.drawRect(targetStepBorder_x, targetStepBorder_y, GUI::seqSteps_w + 4, targetStepBorder_h, 2);
	}
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void GUI_Layer_AllowedChoices_SeqTrack::valueChanged(Value& /*value*/) {
		resetKnobsAndToggles();
}

GUI_Layer_AllowedChoices_SeqTrack::~GUI_Layer_AllowedChoices_SeqTrack() {
	targetStepForSeqTrackValue.removeListener(this);
	repeatChoices = nullptr;
	probabilities = nullptr;
	allowChoiceToggles = nullptr;
}
