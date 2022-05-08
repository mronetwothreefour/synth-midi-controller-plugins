#include "randomization_OptionsComponent_SeqTrack_Value.h"

#include "randomization_RepeatValuesToggleComponent.h"
#include "randomization_RepeatValuesToggleComponentForAllStepsInSeqTrack.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_SeqTrack_Value::RandomizationOptionsComponent_SeqTrack_Value(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	editMode{ trackNum, unexposedParams },
	probabilites{ trackNum, unexposedParams },
	valueRange{ trackNum, unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);

	addAndMakeVisible(editMode);
	addAndMakeVisible(probabilites);
	addAndMakeVisible(valueRange);

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	button_ForClosingSeqTrackOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingSeqTrackOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingSeqTrackOptionsComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingSeqTrackOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingSeqTrackOptionsComponent);

	background_y = GUI::sequencerTrack1Steps_y + ((trackNum - 1) * GUI::sequencerTracksVerticalSpacer);

	setSize(GUI::editor_w, GUI::editor_h);

	resetAndRepaintAppropriateRepeatValuesToggle();
}

void RandomizationOptionsComponent_SeqTrack_Value::resetAndRepaintAppropriateRepeatValuesToggle() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum)) {
		repeatValues = nullptr;
		repeatValuesForAllSteps.reset(new RepeatValuesToggleComponentForAllStepsInSeqTrack(trackNum, unexposedParams));
		if (repeatValuesForAllSteps != nullptr) {
			addAndMakeVisible(repeatValuesForAllSteps.get());
			repeatValuesForAllSteps->setBounds(GUI::randomizationSeqTrackValueRepeatValuesToggle_x, background_y + GUI::randomizationSeqTrackValueRepeatValuesToggle_inset_y, GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
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
			repeatValues->setBounds(GUI::randomizationSeqTrackValueRepeatValuesToggle_x, background_y + GUI::randomizationSeqTrackValueRepeatValuesToggle_inset_y, GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
		}
	}
}

void RandomizationOptionsComponent_SeqTrack_Value::paint(Graphics& g) {
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
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationOptionsSeqStepsValueBackground_png, BinaryData::RandomizationOptionsSeqStepsValueBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, GUI::randomizationSeqTrackOptionsPitchBackground_x, background_y);
}

void RandomizationOptionsComponent_SeqTrack_Value::resized() {
	editMode.setBounds(GUI::randomizationEditModeForSeqTrackComponent_x, background_y + GUI::randomizationSeqTrackOptionsValueComponentsRow1_inset_y, GUI::randomizationEditModeForSeqTrackComponent_w, GUI::randomizationEditModeForSeqTrackComponent_h);
	if (trackNum == 1)
		probabilites.setBounds(GUI::randomizationProbabilitiesForSeqTrack1PitchComponent_x, background_y + GUI::randomizationSeqTrackOptionsValueComponentsRow1_inset_y, GUI::randomizationProbabilitiesForSeqTrack1Component_w, GUI::randomizationProbabilitiesForSeqTrackComponent_h);
	else
		probabilites.setBounds(GUI::randomizationProbabilitiesForSeqTracks2_3_4PitchComponent_x, background_y + GUI::randomizationSeqTrackOptionsValueComponentsRow1_inset_y, GUI::randomizationProbabilitiesForSeqTracks2_3_4Component_w, GUI::randomizationProbabilitiesForSeqTrackComponent_h);
	valueRange.setBounds(GUI::randomizationValueRangeComponentForSeqTrack_x, background_y + GUI::randomizationSeqTrackOptionsValueComponentsRow1_inset_y, GUI::randomizationValueRangeComponentForSeqTrack_w, GUI::randomizationValueRangeComponentForSeqTrack_h);
	button_ForClosingSeqTrackOptionsComponent.setBounds(GUI::randomizationSeqTrackOptionsPitchCloseButton_x, background_y + GUI::randomizationSeqTrackOptionsValueCloseButton_inset_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_SeqTrack_Value::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto propertyIDstring{ propertyID.toString() };
	if (propertyIDstring == "editModeIsSelectedStepForSeqTrack" + (String)trackNum ||
		propertyIDstring == "stepSelectedForEditingInSeqTrack" + (String)trackNum)
		resetAndRepaintAppropriateRepeatValuesToggle();
}

void RandomizationOptionsComponent_SeqTrack_Value::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_SeqTrack_Value::~RandomizationOptionsComponent_SeqTrack_Value() {
	repeatValues = nullptr;
	repeatValuesForAllSteps = nullptr;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
}
