#include "rndm_0_comp_SeqTrackEditMode.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



SeqTrackEditMode::SeqTrackEditMode(Track track, UnexposedParameters* unexposedParams) :
	track{ track },
	randomizationOptions{ unexposedParams->getRandomizationOptions() }
{
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };

	toggle_AllStepsMode.setComponentID(ID::component_RedToggle_AllStepsMode.toString());
	toggle_AllStepsMode.addListener(this);
	toggle_AllStepsMode.setToggleState(randomizationOptions->editModeIsAllStepsForSeqTrack(track), dontSendNotification);
	toggle_AllStepsMode.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "In this mode, changes to the allowed value settings\n";
		tip += "are applied to all steps in sequencer track " + String((int)track) + ".";
		toggle_AllStepsMode.setTooltip(tip);
	}
	toggle_AllStepsMode.setBounds(0, 23, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_AllStepsMode);

	toggle_SelectedStepMode.setComponentID(ID::component_RedToggle_SelectedStepMode.toString());
	toggle_SelectedStepMode.addListener(this);
	toggle_SelectedStepMode.setToggleState(randomizationOptions->editModeIsSelectedStepForSeqTrack(track), dontSendNotification);
	toggle_SelectedStepMode.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "In this mode, changes to the allowed value settings are\n";
		tip += "applied only to the selected step in sequencer track " + String((int)track) + ".";
		toggle_SelectedStepMode.setTooltip(tip);
	}
	toggle_SelectedStepMode.setBounds(0, 48, GUI::toggle_diameter, GUI::toggle_diameter);
	addAndMakeVisible(toggle_SelectedStepMode);

	stepSelector.setComponentID(ID::component_SeqTrackStepSelector.toString());
	stepSelector.addListener(this);
	StringArray stepList;
	for (auto step = 1; step != 17; ++step)
		stepList.add((String)step);
	stepSelector.addItemList(stepList, 1);
	stepSelector.setSelectedId((int)randomizationOptions->selectedStepForSeqTrack(track), dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Selects which step in sequencer\n";
		tip += "track " + String((int)track) + " is targeted for editing.";
		stepSelector.setTooltip(tip);
	}
	stepSelector.setBounds(52, 47, 38, GUI::comboBox_h);
	addAndMakeVisible(stepSelector);

	setSize(90, 63);
}

void SeqTrackEditMode::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_SeqTrackEditMode_png, BinaryData::bkgrnd_SeqTrackEditMode_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void SeqTrackEditMode::buttonClicked(Button* /*button*/) {
	auto editModeIsAllSteps{ toggle_AllStepsMode.getToggleState() == true };
	randomizationOptions->setEditModeIsAllStepsForSeqTrack(editModeIsAllSteps ? true : false, track);
	getParentComponent()->repaint();
}

void SeqTrackEditMode::comboBoxChanged(ComboBox* comboBox) {
	auto selectedStep{ comboBox->getSelectedId() };
	randomizationOptions->setSelectedStepForSeqTrack(Step{ selectedStep }, track);
	getParentComponent()->repaint();
}

SeqTrackEditMode::~SeqTrackEditMode() {
	toggle_AllStepsMode.removeListener(this);
	toggle_SelectedStepMode.removeListener(this);
	stepSelector.removeListener(this);
}
