#include "splits_4_gui_layer_Splits.h"

#include "splits_2_gui_layer_BankTransmit.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Splits.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_Splits::GUI_Layer_Splits(UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	unexposedParams{ unexposedParams },
	splitSlots{ unexposedParams },
	splitsBank{ unexposedParams->getSplitsBank() },
	btn_Close{ BorderColor::grey, unexposedParams->getTooltipsOptions() },
	comboBox_ZoneVoiceAssignment{ ComboBoxType::zoneVoiceAssignment, unexposedParams},
	slider_ZoneVolumeBalance{ unexposedParams, undoManager },
	slider_LowerZoneLimit{ SliderType::lowerZoneLimit, unexposedParams, undoManager },
	slider_LowerZoneVoiceNum{ SliderType::lowerZoneVoiceNum, unexposedParams, undoManager },
	slider_LowerZoneTranspose{ SliderType::lowerZoneTranspose, unexposedParams, undoManager },
	comboBox_LowerZone_MIDI_IsEnabled{ ComboBoxType::lowerZone_MIDI_IsEnabled, unexposedParams},
	slider_UpperZoneLimit{ SliderType::upperZoneLimit, unexposedParams, undoManager },
	slider_UpperZoneVoiceNum{ SliderType::upperZoneVoiceNum, unexposedParams, undoManager },
	slider_UpperZoneTranspose{ SliderType::upperZoneTranspose, unexposedParams, undoManager },
	comboBox_UpperZone_MIDI_IsEnabled{ ComboBoxType::upperZone_MIDI_IsEnabled, unexposedParams},
	btn_LoadSelected{ &splitSlots, unexposedParams },
	btn_SaveIntoSelected{ &splitSlots, unexposedParams },
	btn_PullSelected{ &splitSlots, unexposedParams },
	btn_PushBank{ unexposedParams },
	btn_PullBank{ unexposedParams }
{
	auto splitOptions{ unexposedParams->getSplitOptions() };
	splitNameAsValue = splitOptions->getSplitParamAsValue(ID::split_Name);
	splitNameAsValue.addListener(this);

	btn_Close.setTopLeftPosition(805, 36);
	btn_Close.setAlwaysOnTop(true);
	addAndMakeVisible(btn_Close);

	splitNameEditor.setFont(GUI::font_LabelEditors);
	splitNameEditor.setComponentID(ID::comp_SplitNameEditor.toString());
	splitNameEditor.setEditable(true);
	splitNameEditor.setText(splitOptions->splitName(), dontSendNotification);
	splitNameEditor.onEditorShow = [this] {
		auto editor{ splitNameEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(SPLT::numberOfCharsInSplitName, GUI::allowed_ASCII_Characters);
	};
	splitNameEditor.onTextChange = [this, splitOptions] {
		String labelText{ splitNameEditor.getText() };
		String newName(labelText.toUpperCase());
		newName = newName.paddedRight(' ', SPLT::numberOfCharsInSplitName);
		splitNameEditor.setText(newName, dontSendNotification);
		splitOptions->setSplitName(newName);
	};
	auto tooltps{ unexposedParams->getTooltipsOptions() };
	if (tooltps->shouldShowDescription()) {
		String tip{ "" };
		tip += "Click to edit the name of the split (6 characters max.)\n";
		tip += "NOTE: Changes made to split parameters are not\n";
		tip += "sent to the hardware until you SAVE the split in\n";
		tip += "one of the storage bank slots below.";
		splitNameEditor.setTooltip(tip);
	}
	splitNameEditor.setBounds(510, 99, 70, GUI::control_h);
	addAndMakeVisible(splitNameEditor);

	comboBox_ZoneVoiceAssignment.setTopLeftPosition(761, 197);
	addAndMakeVisible(comboBox_ZoneVoiceAssignment);

	slider_ZoneVolumeBalance.setTopLeftPosition(594, 127);
	addAndMakeVisible(slider_ZoneVolumeBalance);

	auto zoneLimit_x{ 485 };
	auto zoneVoiceNum_x{ 596 };
	auto zoneTranspose_x{ 678 };
	auto zoneMIDI_x{ 761 };
	auto lowerZone_y{ 197 };
	slider_LowerZoneLimit.setTopLeftPosition(zoneLimit_x, lowerZone_y);
	addAndMakeVisible(slider_LowerZoneLimit);
	slider_LowerZoneVoiceNum.setTopLeftPosition(zoneVoiceNum_x, lowerZone_y);
	addAndMakeVisible(slider_LowerZoneVoiceNum);
	slider_LowerZoneTranspose.setTopLeftPosition(zoneTranspose_x, lowerZone_y);
	addAndMakeVisible(slider_LowerZoneTranspose);
	comboBox_LowerZone_MIDI_IsEnabled.setTopLeftPosition(zoneMIDI_x, lowerZone_y);
	addAndMakeVisible(comboBox_LowerZone_MIDI_IsEnabled);

	auto upperZone_y{ 268 };
	slider_UpperZoneLimit.setTopLeftPosition(zoneLimit_x, upperZone_y);
	addAndMakeVisible(slider_UpperZoneLimit);
	slider_UpperZoneVoiceNum.setTopLeftPosition(zoneVoiceNum_x, upperZone_y);
	addAndMakeVisible(slider_UpperZoneVoiceNum);
	slider_UpperZoneTranspose.setTopLeftPosition(zoneTranspose_x, upperZone_y);
	addAndMakeVisible(slider_UpperZoneTranspose);
	comboBox_UpperZone_MIDI_IsEnabled.setTopLeftPosition(zoneMIDI_x, upperZone_y);
	addAndMakeVisible(comboBox_UpperZone_MIDI_IsEnabled);

	splitSlots.setTopLeftPosition(460, 334);
	addAndMakeVisible(splitSlots);

	auto buttons_y{ 511 };
	auto buttons_x_spacing{ 39 };
	btn_LoadSelected.setTopLeftPosition(525, buttons_y);
	addAndMakeVisible(btn_LoadSelected);
	btn_SaveIntoSelected.setTopLeftPosition(btn_LoadSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_SaveIntoSelected);
	btn_PullSelected.setTopLeftPosition(btn_SaveIntoSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_PullSelected);

	btn_PushBank.onClick = [this] { showPushBankLayer(); };
	btn_PushBank.setTopLeftPosition(724, buttons_y);
	addAndMakeVisible(btn_PushBank);
	btn_PullBank.onClick = [this] { showPullBankLayer(); };
	btn_PullBank.setTopLeftPosition(btn_PushBank.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_PullBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_Splits::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_SplitsWindow_png, BinaryData::bkgrnd_SplitsWindow_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 435, 36);
}

ApplicationCommandTarget* GUI_Layer_Splits::getNextCommandTarget() {
	return nullptr;
}

void GUI_Layer_Splits::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice, pasteVoice };
	commands.addArray(IDs);
}

void GUI_Layer_Splits::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Split", "Copy the split in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteVoice:
		result.setInfo("Paste Split", "Replace the split in the selected storage slot with the split in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool GUI_Layer_Splits::perform(const InvocationInfo& info) {
	auto selectedSlot{ splitSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < SPLT::numberOfSlotsInSplitsBank) {
			auto splitDataHexString{ splitsBank->getSplitDataHexStringFromSlot(selectedSlot) };
			splitCopyBuffer = splitDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < SPLT::numberOfSlotsInSplitsBank && splitCopyBuffer != "") {
			splitsBank->storeSplitDataHexStringInSlot(splitCopyBuffer, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void GUI_Layer_Splits::valueChanged(Value& value) {
	splitNameEditor.setText(splitNameAsValue.getValue().toString(), dontSendNotification);
}

void GUI_Layer_Splits::showPushBankLayer() {
	pushBankLayer.reset(new GUI_Layer_SplitsBankTransmit{ BankTransmitType::push, unexposedParams });
	if (pushBankLayer != nullptr) {
		addAndMakeVisible(pushBankLayer.get());
		pushBankLayer->setBounds(getLocalBounds());
		pushBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_Splits::showPullBankLayer() {
	pullBankLayer.reset(new GUI_Layer_SplitsBankTransmit{ BankTransmitType::pull, unexposedParams });
	if (pullBankLayer != nullptr) {
		addAndMakeVisible(pullBankLayer.get());
		pullBankLayer->setBounds(getLocalBounds());
		pullBankLayer->grabKeyboardFocus();
	}
}

GUI_Layer_Splits::~GUI_Layer_Splits() {
	pullBankLayer = nullptr;
	pushBankLayer = nullptr;
	splitNameAsValue.removeListener(this);
}
