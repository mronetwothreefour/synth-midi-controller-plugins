#include "splits_SplitsComponent.h"

#include "splits_BankTransmissionComponent.h"
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
	slider_ForSettingZoneVolumeBalance{ unexposedParams },
	slider_ForSettingLowerZoneLimit{ unexposedParams, ID::split_LowerZoneLimit },
	slider_ForSettingLowerZonePatchNumber{ unexposedParams, ID::split_LowerZonePatchNumber },
	slider_ForSettingLowerZoneTranspose{ unexposedParams, ID::split_LowerZoneTranspose },
	comboBox_ForSelectingLowerZoneMIDIout{ unexposedParams, ID::split_LowerZoneMidiOut },
	slider_ForSettingUpperZoneLimit{ unexposedParams, ID::split_UpperZoneLimit },
	slider_ForSettingUpperZonePatchNumber{ unexposedParams, ID::split_UpperZonePatchNumber },
	slider_ForSettingUpperZoneTranspose{ unexposedParams, ID::split_UpperZoneTranspose },
	comboBox_ForSelectingUpperZoneMIDIout{ unexposedParams, ID::split_UpperZoneMidiOut },
	splitSlots{ unexposedParams },
	button_ForLoadingSelectedSplit{ splitSlots, unexposedParams },
	button_ForPullingSelectedSplitFromHardware{ splitSlots, unexposedParams },
	button_ForSavingCurrentSplitSettingsInSelectedSlot{ splitSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ unexposedParams },
	button_ForPullingEntireBankFromHardware{ unexposedParams }
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

	slider_ForSettingZoneVolumeBalance.addListener(this);
	addAndMakeVisible(slider_ForSettingZoneVolumeBalance);

	slider_ForSettingLowerZoneLimit.addListener(this);
	addAndMakeVisible(slider_ForSettingLowerZoneLimit);

	slider_ForSettingLowerZonePatchNumber.addListener(this);
	addAndMakeVisible(slider_ForSettingLowerZonePatchNumber);

	slider_ForSettingLowerZoneTranspose.addListener(this);
	addAndMakeVisible(slider_ForSettingLowerZoneTranspose);

	comboBox_ForSelectingLowerZoneMIDIout.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingLowerZoneMIDIout);

	slider_ForSettingUpperZoneLimit.addListener(this);
	addAndMakeVisible(slider_ForSettingUpperZoneLimit);

	slider_ForSettingUpperZonePatchNumber.addListener(this);
	addAndMakeVisible(slider_ForSettingUpperZonePatchNumber);

	slider_ForSettingUpperZoneTranspose.addListener(this);
	addAndMakeVisible(slider_ForSettingUpperZoneTranspose);

	comboBox_ForSelectingUpperZoneMIDIout.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingUpperZoneMIDIout);

	addAndMakeVisible(splitSlots);

	addAndMakeVisible(button_ForLoadingSelectedSplit);
	addAndMakeVisible(button_ForSavingCurrentSplitSettingsInSelectedSlot);
	addAndMakeVisible(button_ForPullingSelectedSplitFromHardware);

	button_ForPushingEntireBankToHardware.addListener(this);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	button_ForPullingEntireBankFromHardware.addListener(this);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);

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
	slider_ForSettingZoneVolumeBalance.setBounds(GUI::bounds_SplitZoneVolumeBalance);
	slider_ForSettingLowerZoneLimit.setBounds(GUI::bounds_SplitLowerZoneLimit);
	slider_ForSettingLowerZonePatchNumber.setBounds(GUI::bounds_SplitLowerZonePatchNumber);
	slider_ForSettingLowerZoneTranspose.setBounds(GUI::bounds_SplitLowerZoneTranspose);
	comboBox_ForSelectingLowerZoneMIDIout.setBounds(GUI::bounds_SplitLowerZoneMIDIout);
	slider_ForSettingUpperZoneLimit.setBounds(GUI::bounds_SplitUpperZoneLimit);
	slider_ForSettingUpperZonePatchNumber.setBounds(GUI::bounds_SplitUpperZonePatchNumber);
	slider_ForSettingUpperZoneTranspose.setBounds(GUI::bounds_SplitUpperZoneTranspose);
	comboBox_ForSelectingUpperZoneMIDIout.setBounds(GUI::bounds_SplitUpperZoneMIDIout);
	splitSlots.setBounds(GUI::bounds_SplitSlotsComponent);
	button_ForLoadingSelectedSplit.setBounds(GUI::bounds_SplitsComponentLoadButton);
	button_ForSavingCurrentSplitSettingsInSelectedSlot.setBounds(GUI::bounds_SplitsComponentSaveCurrentSplitButton);
	button_ForPullingSelectedSplitFromHardware.setBounds(GUI::bounds_SplitsComponentPullSelectedSplitButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_SplitsComponentPushEntireBankButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_SplitsComponentPullEntireBankButton);
}

void SplitsComponent::comboBoxChanged(ComboBox* comboBox) {
	auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
	auto splitOptions{ unexposedParams->splitOptions_get() };
	if (comboBox == &comboBox_ForSelectingZoneVoiceAssignments)
		splitOptions->setZoneVoiceAssignment(currentSelection);
	if (comboBox == &comboBox_ForSelectingLowerZoneMIDIout)
		splitOptions->setLowerZoneMidiOut(currentSelection);
	if (comboBox == &comboBox_ForSelectingUpperZoneMIDIout)
		splitOptions->setUpperZoneMidiOut(currentSelection);
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
		tooltipText += "NOTE: Changes made to split parameters are not\n";
		tooltipText += "sent to the hardware until you SAVE the split in\n";
		tooltipText += "one of the storage bank slots below.";
	}
	return tooltipText;
}

void SplitsComponent::sliderValueChanged(Slider* slider) {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingZoneVolumeBalance)
		splitOptions->setZoneVolumeBalance(currentValue);
	if (slider == &slider_ForSettingLowerZoneLimit)
		splitOptions->setLowerZoneLimit(currentValue);
	if (slider == &slider_ForSettingLowerZonePatchNumber)
		splitOptions->setLowerZonePatchNumber(currentValue);
	if (slider == &slider_ForSettingLowerZoneTranspose)
		splitOptions->setLowerZoneTranspose(currentValue);
	if (slider == &slider_ForSettingUpperZoneLimit)
		splitOptions->setUpperZoneLimit(currentValue);
	if (slider == &slider_ForSettingUpperZonePatchNumber)
		splitOptions->setUpperZonePatchNumber(currentValue);
	if (slider == &slider_ForSettingUpperZoneTranspose)
		splitOptions->setUpperZoneTranspose(currentValue);
}

void SplitsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto splitOptions{ unexposedParams->splitOptions_get() };
	if (property == ID::split_Name) {
		splitNameEditor.setText(splitOptions->splitName(), dontSendNotification);
		repaint();
	}
}

void SplitsComponent::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::button_PullSplitsBank.toString())
		showPullEntireBankComponent();
	if (button->getComponentID() == ID::button_PushSplitsBank.toString())
		showPushEntireBankComponent();
}

void SplitsComponent::showPushEntireBankComponent() {
	pushEntireBankComponent.reset(new SplitsBankTransmissionComponent(SplitsBankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
	}
}

void SplitsComponent::showPullEntireBankComponent() {
	pullEntireBankComponent.reset(new SplitsBankTransmissionComponent(SplitsBankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
	}
}

void SplitsComponent::hideThisComponent() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	auto activateQuickPatchEditingMessage{ RawSysExDataVector::createActivateQuickPatchEditingMessage() };
	outgoingMidiBuffers->addDataMessage(activateQuickPatchEditingMessage);
	setVisible(false);
}

SplitsComponent::~SplitsComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
	button_ForPullingEntireBankFromHardware.removeListener(this);
	button_ForPushingEntireBankToHardware.removeListener(this);
	comboBox_ForSelectingUpperZoneMIDIout.removeListener(this);
	slider_ForSettingUpperZoneTranspose.removeListener(this);
	slider_ForSettingUpperZonePatchNumber.removeListener(this);
	slider_ForSettingUpperZoneLimit.removeListener(this);
	comboBox_ForSelectingLowerZoneMIDIout.removeListener(this);
	slider_ForSettingLowerZoneTranspose.removeListener(this);
	slider_ForSettingLowerZonePatchNumber.removeListener(this);
	slider_ForSettingLowerZoneLimit.removeListener(this);
	slider_ForSettingZoneVolumeBalance.removeListener(this);
	comboBox_ForSelectingZoneVoiceAssignments.removeListener(this);
	splitNameEditor.removeListener(this);
	auto splitOptions{ unexposedParams->splitOptions_get() };
	splitOptions->removeListener(this);
}
