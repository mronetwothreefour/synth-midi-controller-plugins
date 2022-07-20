#include "rndm_2_gui_layer_AllowedChoices_SeqTrack.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_AllowedChoices_SeqTrack::GUI_Layer_AllowedChoices_SeqTrack(
	Track track, bool destIsPitched, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	track{ track },
	destIsPitched{ destIsPitched },
	unexposedParams{ unexposedParams },
	randomization{ exposedParams->randomization.get() },
	trackTree{ exposedParams->randomization->getChildTreeForSeqTrack(track) },
	button_Close{ unexposedParams },
	targetStepSelector{ track, randomization, unexposedParams },
	button_Randomize{ track, exposedParams->randomize.get(), unexposedParams}
{
	trackTree.addListener(this);

	auto targetStep_x{ 0 };
	auto button_Randomize_center_y{ 0 };
	if (destIsPitched) {
		background_x = track == Track::one ? 468 : 522;
		background_y = 29;
		background_w = track == Track::one ? 334 : 280;
		background_h = 572;
		center_x = track == Track::one ? 635 : 662;
		targetStep_x = background_x + GUI::allowedChoices_Inset;
		button_Randomize_center_y = 573;
	}
	else {
		background_x = 430;
		background_y = 141;
		background_w = 372;
		background_h = 348;
		center_x = 616;
		targetStep_x = track == Track::one ? 463 : 485;
		button_Randomize_center_y = 461;
	}
	auto allowAllAndCloseButtons_y{ background_y + GUI::allowedChoices_Inset };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this, track] {
		auto targetStep{ randomization->targetStepForSeqTrack(track) };
		randomization->allowAllChoicesForSeqTrackStep(track, targetStep);
		if (allowChoiceToggles != nullptr)
			allowChoiceToggles->restoreToggles();
	};
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the choices\n";
		tip += "when generating a random setting\n";
		tip += "for the target step in track " + String((int)track) + ".";
		button_AllowAll.setTooltip(tip);
	}
	button_AllowAll.setSize(GUI::button_AllowAll_w, GUI::redButton_h);
	button_AllowAll.setTopLeftPosition(background_x + GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(button_AllowAll);

	button_Close.setTopRightPosition(background_x + background_w - GUI::allowedChoices_Inset, allowAllAndCloseButtons_y);
	addAndMakeVisible(button_Close);

	targetStepSelector.setTopLeftPosition(targetStep_x, background_y + 51);
	addAndMakeVisible(targetStepSelector);

	button_Randomize.setCentrePosition(center_x, button_Randomize_center_y);
	addAndMakeVisible(button_Randomize);

	resetKnobsAndToggles();

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_SeqTrack::resetKnobsAndToggles() {
	repeatChoices.reset(new AllowRepeatChoicesToggle_SeqTrackStep{ track, randomization, unexposedParams });
	if (repeatChoices != nullptr) {
		repeatChoices->setCentrePosition(center_x, destIsPitched ? 57 : 169);
		addAndMakeVisible(repeatChoices.get());
	}

	probabilities.reset(new SeqTrackProbabilities{ track, randomization, unexposedParams });
	if (probabilities != nullptr) {
		auto probabilities_x{ track == Track::one ? 601 : 625 };
		if (destIsPitched)
			probabilities_x = background_x + (track == Track::one ? 149 : 141);
		probabilities->setTopLeftPosition(probabilities_x, background_y + 51);
		addAndMakeVisible(probabilities.get());
	}

	allowChoiceToggles.reset(new AllowChoiceToggles_SeqTrackStep{ track, destIsPitched, randomization, unexposedParams });
	if (allowChoiceToggles != nullptr) {
		allowChoiceToggles->setCentrePosition(center_x, 360);
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
		g.drawRect(targetStep_1_Border_x, targetStepBorder_y, 450, targetStepBorder_h);
	else {
		auto targetStepBorder_x{ targetStep_1_Border_x + (28 * ((int)targetStep - 1)) };
		g.drawRect(targetStepBorder_x, targetStepBorder_y, GUI::seqSteps_w + 4, targetStepBorder_h, 2);
	}
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
	g.setColour(GUI::color_Black);
	float divider_x;
	if (destIsPitched)
		divider_x = background_x + (track == Track::one ? 129.0f : 122.0f);
	else 
		divider_x = background_x + (track == Track::one ? 150.0f : 171.0f);
	g.drawLine(divider_x, background_y + 49.0f, divider_x, background_y + 129.0f, 1.0f);
}

void GUI_Layer_AllowedChoices_SeqTrack::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::rndm_SeqTrackTargetStep)
		resetKnobsAndToggles();
}

GUI_Layer_AllowedChoices_SeqTrack::~GUI_Layer_AllowedChoices_SeqTrack() {
	trackTree.removeListener(this);
	repeatChoices = nullptr;
	probabilities = nullptr;
	allowChoiceToggles = nullptr;
}
