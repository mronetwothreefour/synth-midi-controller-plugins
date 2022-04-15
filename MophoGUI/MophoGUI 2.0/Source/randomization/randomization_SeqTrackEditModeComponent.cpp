#include "randomization_SeqTrackEditModeComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SeqTrackEditModeComponent::SeqTrackEditModeComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	editAllStepsModeToggle.setComponentID(ID::component_ToggleButton_EditAllStepsModeForTrack.toString() + (String)trackNum);
	editAllStepsModeToggle.addListener(this);
	editAllStepsModeToggle.setToggleState(randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum), dontSendNotification);
	editAllStepsModeToggle.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "In this mode, changes to the allowed value settings\n";
		toggleTooltip += "are applied to all steps in sequencer track" + (String)trackNum + ".";
		editAllStepsModeToggle.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(editAllStepsModeToggle);

	editSelectedStepModeToggle.setComponentID(ID::component_ToggleButton_EditSelectedStepModeForTrack.toString() + (String)trackNum);
	editSelectedStepModeToggle.addListener(this);
	editSelectedStepModeToggle.setToggleState(randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum), dontSendNotification);
	editSelectedStepModeToggle.setRadioGroupId(1, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "In this mode, changes to the allowed value settings are\n";
		toggleTooltip += "applied only to the selected step in sequencer track" + (String)trackNum + ".";
		editSelectedStepModeToggle.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(editSelectedStepModeToggle);

	stepSelector.setComponentID(ID::component_StepSelectorForTrack.toString() + (String)trackNum);
	stepSelector.addListener(this);
	for (auto step = 0; step != 16; ++step)
		stepSelector.addItem((String)step, step);
	stepSelector.setSelectedItemIndex(randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum), dontSendNotification);
	if (shouldShowDescriptions) {
		String menuTooltip{ "" };
		menuTooltip += "Selects which step in sequencer track" + (String)trackNum + "\n";
		menuTooltip += "is targeted for editing.";
		stepSelector.setTooltip(menuTooltip);
	}
	addAndMakeVisible(stepSelector);

	setSize(GUI::randomizationEditModeForSeqTrackComponent_w, GUI::randomizationEditModeForSeqTrackComponent_h);
}

void SeqTrackEditModeComponent::resized() {
	editAllStepsModeToggle.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
	editSelectedStepModeToggle.setBounds(0, 25, GUI::toggle_diameter, GUI::toggle_diameter);
	stepSelector.setBounds(52, 24, 38, GUI::comboBox_h);
}

void SeqTrackEditModeComponent::buttonClicked(Button* button) {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (button->getComponentID() == ID::component_ToggleButton_EditAllStepsModeForTrack.toString() + (String)trackNum) {
		if(button->getToggleState())
			randomizationOptions->setEditModeForSeqTrackToAllSteps(trackNum);
	}
	if (button->getComponentID() == ID::component_ToggleButton_EditSelectedStepModeForTrack.toString() + (String)trackNum) {
		if(button->getToggleState())
			randomizationOptions->setEditModeForSeqTrackToSelectedStep(trackNum);
	}
}

void SeqTrackEditModeComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox->getComponentID() == ID::component_StepSelectorForTrack.toString() + (String)trackNum) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto selectedStep{ comboBox->getSelectedItemIndex() };
		randomizationOptions->setStepSelectedForEditingInSeqTrack(selectedStep, trackNum);
	}
}

SeqTrackEditModeComponent::~SeqTrackEditModeComponent() {
	stepSelector.removeListener(this);
	editSelectedStepModeToggle.removeListener(this);
	editAllStepsModeToggle.removeListener(this);
}
