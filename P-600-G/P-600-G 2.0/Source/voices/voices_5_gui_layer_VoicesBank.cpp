#include "voices_5_gui_layer_VoicesBank.h"

#include "voices_4_gui_layer_BankTransmit.h"
#include "voices_4_gui_layer_RestoreFactoryVoicesDialog.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voicesImportExport/imEx_3_gui_layer_Export_Voice.h"
#include "../voicesImportExport/imEx_3_gui_layer_Export_VoicesBank.h"
#include "../voicesImportExport/imEx_3_gui_layer_Import_Voice.h"
#include "../voicesImportExport/imEx_3_gui_layer_Import_VoicesBank.h"

GUI_Layer_VoicesBank::GUI_Layer_VoicesBank(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	voicesBank{ unexposedParams->getVoicesBank() },
	voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() },
	voiceSlots{ exposedParams, unexposedParams },
	btn_LoadSelected{ &voiceSlots, unexposedParams },
	btn_SaveIntoSelected{ &voiceSlots, unexposedParams },
	btn_PullSelected{ &voiceSlots, unexposedParams },
	btn_ExportSelected{ unexposedParams },
	btn_ImportSelected{ unexposedParams },
	btn_EditName{ &voiceSlots, unexposedParams },
	btn_PushBank{ unexposedParams },
	btn_PullBank{ unexposedParams },
	btn_ExportBank{ unexposedParams },
	btn_ImportBank{ unexposedParams },
	btn_Exit{ unexposedParams->getTooltipsOptions() },
	btn_RestoreFactoryVoices{ unexposedParams }
{
	auto buttons_x_spacing{ 50 };
	auto buttons_y{ 84 };

	btn_LoadSelected.setTopLeftPosition(360, buttons_y);
	addAndMakeVisible(btn_LoadSelected);
	btn_SaveIntoSelected.setTopLeftPosition(btn_LoadSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_SaveIntoSelected);
	btn_PullSelected.setTopLeftPosition(btn_SaveIntoSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_PullSelected);
	btn_ExportSelected.addListener(this);
	btn_ExportSelected.setTopLeftPosition(btn_PullSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_ExportSelected);
	btn_ImportSelected.addListener(this);
	btn_ImportSelected.setTopLeftPosition(btn_ExportSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_ImportSelected);
	btn_EditName.setTopLeftPosition(btn_ImportSelected.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_EditName);

	btn_PushBank.addListener(this);
	btn_PushBank.setTopLeftPosition(780, buttons_y);
	addAndMakeVisible(btn_PushBank);
	btn_PullBank.addListener(this);
	btn_PullBank.setTopLeftPosition(btn_PushBank.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_PullBank);
	btn_ExportBank.addListener(this);
	btn_ExportBank.setTopLeftPosition(btn_PullBank.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_ExportBank);
	btn_ImportBank.addListener(this);
	btn_ImportBank.setTopLeftPosition(btn_ExportBank.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_ImportBank);
	btn_RestoreFactoryVoices.addListener(this);
	btn_RestoreFactoryVoices.setTopLeftPosition(btn_ImportBank.getX() + buttons_x_spacing, buttons_y);
	addAndMakeVisible(btn_RestoreFactoryVoices);

	auto tooltips{ unexposedParams->getTooltipsOptions() };

	lbl_txTimeEditor.setComponentID(ID::comp_TextEditorForTransmitTime.toString());
	lbl_txTimeEditor.setEditable(true);
	lbl_txTimeEditor.onEditorShow = [this, tooltips] {
		auto editor{ lbl_txTimeEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(4, "0123456789");
		editor->setText((String)voiceTransmit->voiceTransmitTime());
		editor->selectAll();
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type a new transmit\ntime in milliseconds.\n(Range: 50 to 5000)");
	};
	lbl_txTimeEditor.onTextChange = [this] {
		if (lbl_txTimeEditor.getText().isNotEmpty()) {
			auto newValue{ lbl_txTimeEditor.getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				voiceTransmit->setVoiceTransmitTime(newValue);
		}
		lbl_txTimeEditor.setText(String(voiceTransmit->voiceTransmitTime()).paddedLeft('0', 4), dontSendNotification);
	};
	lbl_txTimeEditor.setBounds(1155, 76, 112, 50);
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		tip += "of a single program between the plugin and the Prophet-600 hardware.\n";
		tip += "Increase this value if programs are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		tip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
		lbl_txTimeEditor.setTooltip(tip);
	}
	addAndMakeVisible(lbl_txTimeEditor);
	lbl_txTimeEditor.onTextChange();

	btn_Exit.setTopLeftPosition(1336, buttons_y);
	addAndMakeVisible(btn_Exit);

	voiceSlots.setTopLeftPosition(26, 156);
	addAndMakeVisible(voiceSlots);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_VoicesBank::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_VoicesBank_png, BinaryData::bkgrnd_VoicesBank_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 11, 61);
}

void GUI_Layer_VoicesBank::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };

	if (buttonID == ID::btn_Expt_Voice.toString())
		showExportVoiceLayer();

	if (buttonID == ID::btn_Expt_VoicesBank.toString())
		showExportBankLayer();

	if (buttonID == ID::btn_Impt_Voice.toString())
		showImportVoiceLayer();

	if (buttonID == ID::btn_Impt_VoicesBank.toString())
		showImportBankLayer();

	if (buttonID == ID::btn_Pull_VoicesBank.toString())
		showPullBankLayer();

	if (buttonID == ID::btn_Push_VoicesBank.toString())
		showPushBankLayer();

	if (buttonID == ID::btn_RestoreFactoryVoices.toString())
		showRestoreFactoryVoicesDialogLayer();
}

ApplicationCommandTarget* GUI_Layer_VoicesBank::getNextCommandTarget() {
	return nullptr;
}

void GUI_Layer_VoicesBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice, pasteVoice };
	commands.addArray(IDs);
}

void GUI_Layer_VoicesBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteVoice:
		result.setInfo("Paste Program", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool GUI_Layer_VoicesBank::perform(const InvocationInfo& info) {
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
			auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(selectedSlot) };
			voiceCopyBuffer = voiceDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < VCS::numberOfSlotsInVoicesBank && voiceCopyBuffer != "") {
			voicesBank->storeVoiceDataHexStringInSlot(voiceCopyBuffer, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void GUI_Layer_VoicesBank::showExportVoiceLayer() {
	auto slot{ voiceSlots.selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		exportVoiceLayer.reset(new GUI_Layer_Export_Voice{ &voiceSlots, unexposedParams });
		if (exportVoiceLayer != nullptr) {
			addAndMakeVisible(exportVoiceLayer.get());
			exportVoiceLayer->setBounds(getLocalBounds());
			exportVoiceLayer->setAlwaysOnTop(true);
			exportVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBank::showImportVoiceLayer() {
	auto slot{ voiceSlots.selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		importVoiceLayer.reset(new GUI_Layer_Import_Voice{ &voiceSlots, unexposedParams });
		if (importVoiceLayer != nullptr) {
			addAndMakeVisible(importVoiceLayer.get());
			importVoiceLayer->setBounds(getLocalBounds());
			importVoiceLayer->setAlwaysOnTop(true);
			importVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBank::showPushBankLayer() {
	pushBankLayer.reset(new GUI_Layer_VoicesBankTransmit{ BankTransmitType::push, unexposedParams });
	if (pushBankLayer != nullptr) {
		addAndMakeVisible(pushBankLayer.get());
		pushBankLayer->setBounds(getLocalBounds());
		pushBankLayer->setAlwaysOnTop(true);
		pushBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBank::showPullBankLayer() {
	pullBankLayer.reset(new GUI_Layer_VoicesBankTransmit{ BankTransmitType::pull, unexposedParams });
	if (pullBankLayer != nullptr) {
		addAndMakeVisible(pullBankLayer.get());
		pullBankLayer->setBounds(getLocalBounds());
		pullBankLayer->setAlwaysOnTop(true);
		pullBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBank::showExportBankLayer() {
	exportBankLayer.reset(new GUI_Layer_Export_VoicesBank{ &voiceSlots, unexposedParams });
	if (exportBankLayer != nullptr) {
		addAndMakeVisible(exportBankLayer.get());
		exportBankLayer->setBounds(getLocalBounds());
		exportBankLayer->setAlwaysOnTop(true);
		exportBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBank::showImportBankLayer() {
	importBankLayer.reset(new GUI_Layer_Import_VoicesBank{ &voiceSlots, unexposedParams });
	if (importBankLayer != nullptr) {
		addAndMakeVisible(importBankLayer.get());
		importBankLayer->setBounds(getLocalBounds());
		importBankLayer->setAlwaysOnTop(true);
		importBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBank::showRestoreFactoryVoicesDialogLayer() {
	restoreFactoryVoicesDialogLayer.reset(new GUI_Layer_RestoreFactoryVoicesDialog{ unexposedParams });
	if (restoreFactoryVoicesDialogLayer != nullptr) {
		addAndMakeVisible(restoreFactoryVoicesDialogLayer.get());
		restoreFactoryVoicesDialogLayer->setBounds(getLocalBounds());
		restoreFactoryVoicesDialogLayer->setAlwaysOnTop(true);
		restoreFactoryVoicesDialogLayer->grabKeyboardFocus();
	}
}

GUI_Layer_VoicesBank::~GUI_Layer_VoicesBank() {
	btn_ImportSelected.removeListener(this);
	btn_ExportSelected.removeListener(this);
	btn_PushBank.removeListener(this);
	btn_PullBank.removeListener(this);
	btn_ImportBank.removeListener(this);
	btn_ExportBank.removeListener(this);
	exportVoiceLayer = nullptr;
	exportBankLayer = nullptr;
	importVoiceLayer = nullptr;
	importBankLayer = nullptr;
	pullBankLayer = nullptr;
	pushBankLayer = nullptr;
	restoreFactoryVoicesDialogLayer = nullptr;
}
