#include "splits_SplitsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SplitsComponent::SplitsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingSplitsComponent{ "" },
	splitNameEditor{ "splitNameEditor", "" },
	comboBox_ForSelectingZoneVoiceAssignments{ unexposedParams },
	splitSlots{ unexposedParams },
	button_ForLoadingSelectedSplit{ splitSlots, unexposedParams },
	button_ForPullingSelectedSplitFromHardware{ splitSlots, unexposedParams }
{
	button_ForClosingSplitsComponent.setComponentID(ID::button_X_Splits.toString());
	addAndMakeVisible(button_ForClosingSplitsComponent);
	button_ForClosingSplitsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingSplitsComponent.setAlwaysOnTop(true);

	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->addListener(this);

	splitNameEditor.setComponentID(ID::label_SplitNameEditor.toString());
	splitNameEditor.addListener(this);
	splitNameEditor.setText(splitOptions->splitName(), dontSendNotification);
	splitNameEditor.setTooltip(generateSplitNameTooltipString());
	addAndMakeVisible(splitNameEditor);

	comboBox_ForSelectingZoneVoiceAssignments.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingZoneVoiceAssignments);

	addAndMakeVisible(splitSlots);
	addAndMakeVisible(button_ForLoadingSelectedSplit);
	addAndMakeVisible(button_ForPullingSelectedSplitFromHardware);

	setSize(GUI::editor_w, GUI::editor_h);
}

void SplitsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::SplitsWindow_png, BinaryData::SplitsWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::splitsWindow_x, GUI::splitsWindow_y);
}

void SplitsComponent::resized() {
	button_ForClosingSplitsComponent.setBounds(GUI::bounds_SplitsComponentXbutton);
	splitNameEditor.setBounds(GUI::bounds_SplitNameEditor);
	comboBox_ForSelectingZoneVoiceAssignments.setBounds(GUI::bounds_SplitsComboBoxForZoneVoiceAssignment);
	splitSlots.setBounds(GUI::bounds_SplitSlotsComponent);
	button_ForLoadingSelectedSplit.setBounds(GUI::bounds_SplitsComponentLoadButton);
	button_ForPullingSelectedSplitFromHardware.setBounds(GUI::bounds_SplitsComponentPullSelectedSplitButton);
}

void SplitsComponent::buttonClicked(Button* /*button*/) {
}

void SplitsComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox == &comboBox_ForSelectingZoneVoiceAssignments) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto splitOptions{ unexposedParams->splitOptions_get() };
		splitOptions->setZoneVoiceAssignment(currentSelection);
	}
}

void SplitsComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &splitNameEditor)
	 editor.setInputRestrictions(matrixParams::maxSplitNameLength, "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[");
}

void SplitsComponent::labelTextChanged(Label* label) {
	if (label == &splitNameEditor) {
		String labelText{ label->getText() };
		String newName(labelText.toUpperCase());
		padNameLessThan6CharactersLongWithSpaces(newName);
		splitNameEditor.setText(newName, dontSendNotification);
		auto splitOptions{ unexposedParams->splitOptions_get() };
		splitOptions->setSplitName(newName);
		repaint();
	}
}

void SplitsComponent::padNameLessThan6CharactersLongWithSpaces(String& name) {
	for (auto i = name.length(); i != matrixParams::maxSplitNameLength; ++i)
		name += " ";
}

String SplitsComponent::generateSplitNameTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Click to edit the name of the split (6 characters max.)\n";
		tooltipText += "The name will not be updated until you select one of\n";
		tooltipText += "the storage slots below and click the SAVE button.";
	}
	return tooltipText;
}

void SplitsComponent::sliderValueChanged(Slider* slider) {
}

void SplitsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::split_Name) {
		auto splitOptions{ unexposedParams->splitOptions_get() };
		splitNameEditor.setText(splitOptions->splitName(), dontSendNotification);
		repaint();
	}
}

void SplitsComponent::hideThisComponent() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	auto activateQuickPatchEditingMessage{ RawSysExDataVector::createActivateQuickPatchEditingMessage() };
	outgoingMidiBuffers->addDataMessage(activateQuickPatchEditingMessage);
	setVisible(false);
}

SplitsComponent::~SplitsComponent() {
	comboBox_ForSelectingZoneVoiceAssignments.removeListener(this);
	splitNameEditor.removeListener(this);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
