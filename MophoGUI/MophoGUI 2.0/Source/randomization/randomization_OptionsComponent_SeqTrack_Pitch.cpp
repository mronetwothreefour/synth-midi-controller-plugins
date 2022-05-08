#include "randomization_OptionsComponent_SeqTrack_Pitch.h"

#include "randomization_RepeatValuesToggleComponent.h"
#include "randomization_RepeatValuesToggleComponentForAllStepsInSeqTrack.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_SeqTrack_Pitch::RandomizationOptionsComponent_SeqTrack_Pitch(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	editMode{ trackNum, unexposedParams },
	probabilites{ trackNum, unexposedParams },
	allowedNotes{ trackNum, unexposedParams },
	allowedOctaves{ trackNum, unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);

	addAndMakeVisible(editMode);
	addAndMakeVisible(probabilites);
	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	button_ForClosingSeqTrackOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingSeqTrackOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingSeqTrackOptionsComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingSeqTrackOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingSeqTrackOptionsComponent);

	setSize(GUI::editor_w, GUI::editor_h);

	resetAndRepaintAppropriateRepeatValuesToggle();
}

void RandomizationOptionsComponent_SeqTrack_Pitch::resetAndRepaintAppropriateRepeatValuesToggle() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum)) {
		repeatValues = nullptr;
		repeatValuesForAllSteps.reset(new RepeatValuesToggleComponentForAllStepsInSeqTrack(trackNum, unexposedParams));
		if (repeatValuesForAllSteps != nullptr) {
			addAndMakeVisible(repeatValuesForAllSteps.get());
			repeatValuesForAllSteps->setBounds(GUI::bounds_RandomizationSeqTrackOptionsPitchRepeatValuesToggle);
		}
	}
	else {
		repeatValuesForAllSteps = nullptr;
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
		auto& info{ InfoForExposedParameters::get() };
		auto paramIndex{ info.indexForParamID("seqTrack" + (String)trackNum + "Step" + (String)selectedStep) };
		repeatValues.reset(new RepeatValuesToggleComponent(paramIndex, unexposedParams));
		if (repeatValues != nullptr) {
			addAndMakeVisible(repeatValues.get());
			repeatValues->setBounds(GUI::bounds_RandomizationSeqTrackOptionsPitchRepeatValuesToggle);
		}
	}
}

void RandomizationOptionsComponent_SeqTrack_Pitch::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::switchOn);
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum)) {
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
		auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
		auto paramIndex{ info.indexForParamID(paramID) };
		auto controlCenter{ info.controlCenterPointFor(paramIndex) };
		g.drawRect((controlCenter.x - GUI::seqSteps_w / 2 - 2), (controlCenter.y - GUI::seqSteps_h / 2 - 2), GUI::seqSteps_w + 4, GUI::seqSteps_h + 4, 2);
	}
	else
		g.drawRect(GUI::sequencerStep1_x - 2, GUI::sequencerTrack1Steps_y + (trackNum - 1) * GUI::sequencerTracksVerticalSpacer - 2, GUI::sequencerTracksStepsGroup_w + 4, GUI::seqSteps_h + 4, 2);
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationOptionsSeqStepsPitchBackground_png, BinaryData::RandomizationOptionsSeqStepsPitchBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, GUI::randomizationSeqTrackOptionsPitchBackground_x, GUI::randomizationSeqTrackOptionsPitchBackground_y);
}

void RandomizationOptionsComponent_SeqTrack_Pitch::resized() {
	editMode.setBounds(GUI::bounds_RandomizationEditModeForSeqTrack);
	probabilites.setBounds(trackNum == 1 ? GUI::bounds_RandomizationProbabilitiesForSeqTrack1_Pitch : GUI::bounds_RandomizationProbabilitiesForSeqTrack2_3_4_Pitch);
	allowedNotes.setBounds(GUI::bounds_RandomizationAllowedNotesForSeqTrack);
	allowedOctaves.setBounds(GUI::bounds_RandomizationAllowedOctavesForSeqTrack);
	button_ForClosingSeqTrackOptionsComponent.setBounds(GUI::bounds_RandomizationSeqTrackOptionsCloseButton);
}

void RandomizationOptionsComponent_SeqTrack_Pitch::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto propertyIDstring{ propertyID.toString() };
	if (propertyIDstring == "editModeIsSelectedStepForSeqTrack" + (String)trackNum ||
		propertyIDstring == "stepSelectedForEditingInSeqTrack" + (String)trackNum)
		resetAndRepaintAppropriateRepeatValuesToggle();
}

void RandomizationOptionsComponent_SeqTrack_Pitch::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_SeqTrack_Pitch::~RandomizationOptionsComponent_SeqTrack_Pitch() {
	repeatValues = nullptr;
	repeatValuesForAllSteps = nullptr;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
}
