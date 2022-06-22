#include "voices_7_gui_layer_VoicesBanks.h"

#include "voices_6_gui_layer_BankTransmit.h"
#include "importExport/imEx_3_gui_layer_Export_Voice.h"
#include "importExport/imEx_3_gui_layer_Export_VoicesBank.h"
#include "importExport/imEx_3_gui_layer_Import_Voice.h"
#include "importExport/imEx_3_gui_layer_Import_VoicesBank.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



GUI_Layer_VoicesBanks::GUI_Layer_VoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	voicesBanksTabs{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() },
	button_Close{ unexposedParams }
{
	voicesBanksTabs.addListenerToButtonsInAllTabs(this);

	addAndMakeVisible(voicesBanksTabs);
	voicesBanksTabs.setBounds(89, 113, voicesBanksTabs.getWidth(), voicesBanksTabs.getHeight());

	addAndMakeVisible(button_Close);
	button_Close.setBounds(1130, 117, button_Close.getWidth(), GUI::redButton_h);
	button_Close.setAlwaysOnTop(true);

	label_txTimeEditor.addListener(this);
	label_txTimeEditor.setComponentID(ID::label_EditLabel.toString());
	label_txTimeEditor.setEditable(true);
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	String tip{ "" };
	if (tooltips->shouldShowDescriptions()) {
		tip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		tip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		tip += "this value if programs are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		tip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}
	label_txTimeEditor.setTooltip(tip);
	addAndMakeVisible(label_txTimeEditor);
	label_txTimeEditor.setBounds(1119, 477, 50, GUI::redButton_h);
	labelTextChanged(&label_txTimeEditor);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_VoicesBanks::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	g.setOpacity(1.0f);
	Rectangle<int> bkgrndBounds{ voicesBanksTabs.getBounds().expanded(2) };
	g.fillRect(bkgrndBounds);
}

void GUI_Layer_VoicesBanks::editorShown(Label* /*label*/, TextEditor& editor) {
	editor.setInputRestrictions(4, "0123456789");
	editor.setFont(GUI::fontFor_Labels);
	editor.setText((String)voiceTransmit->voiceTransmitTime());
	editor.selectAll();
}

void GUI_Layer_VoicesBanks::labelTextChanged(Label* label) {
	if (label->getText().isNotEmpty()) {
		auto newValue{ label->getText().getIntValue() };
		if (newValue > 49 && newValue < 5001)
			voiceTransmit->setVoiceTransmitTime(newValue);
	}
	label->setText((String)voiceTransmit->voiceTransmitTime() + " ms", dontSendNotification);
}

void GUI_Layer_VoicesBanks::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto bankNum{ buttonID.fromLastOccurrenceOf("_", false, false).getIntValue() };

	if (buttonID.startsWith(ID::button_Export_VoicesBank_.toString()))
		showExportBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::button_Export_VoiceFromBank_.toString()))
		showExportVoiceLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::button_Import_AllVoicesIntoBank_.toString()))
		showImportBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::button_Import_VoiceIntoBank_.toString()))
		showImportVoiceLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::button_Pull_VoicesBank_.toString()))
		showPullBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::button_Push_VoicesBank_.toString()))
		showPushBankLayerForBank(VoicesBank{ bankNum });
}

void GUI_Layer_VoicesBanks::showExportVoiceLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsForBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		exportVoiceLayer.reset(new GUI_Layer_Export_Voice(bank, slotsComponent, unexposedParams));
		if (exportVoiceLayer != nullptr) {
			addAndMakeVisible(exportVoiceLayer.get());
			exportVoiceLayer->setBounds(getLocalBounds());
			exportVoiceLayer->setAlwaysOnTop(true);
			exportVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBanks::showImportVoiceLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsForBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		importVoiceLayer.reset(new GUI_Layer_Import_Voice(bank, slotsComponent, unexposedParams));
		if (importVoiceLayer != nullptr) {
			addAndMakeVisible(importVoiceLayer.get());
			importVoiceLayer->setBounds(getLocalBounds());
			importVoiceLayer->setAlwaysOnTop(true);
			importVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBanks::showPushBankLayerForBank(VoicesBank bank) {
	pushBankLayer.reset(new GUI_Layer_BankTransmit(bank, BankTransmitType::push, unexposedParams));
	if (pushBankLayer != nullptr) {
		addAndMakeVisible(pushBankLayer.get());
		pushBankLayer->setBounds(getLocalBounds());
		pushBankLayer->setAlwaysOnTop(true);
		pushBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showPullBankLayerForBank(VoicesBank bank) {
	pullBankLayer.reset(new GUI_Layer_BankTransmit(bank, BankTransmitType::pull, unexposedParams));
	if (pullBankLayer != nullptr) {
		addAndMakeVisible(pullBankLayer.get());
		pullBankLayer->setBounds(getLocalBounds());
		pullBankLayer->setAlwaysOnTop(true);
		pullBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showExportBankLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsForBank(bank) };
	exportBankLayer.reset(new GUI_Layer_Export_VoicesBank(bank, slotsComponent, unexposedParams));
	if (exportBankLayer != nullptr) {
		addAndMakeVisible(exportBankLayer.get());
		exportBankLayer->setBounds(getLocalBounds());
		exportBankLayer->setAlwaysOnTop(true);
		exportBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showImportBankLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsForBank(bank) };
	importBankLayer.reset(new GUI_Layer_Import_VoicesBank(bank, slotsComponent, unexposedParams));
	if (importBankLayer != nullptr) {
		addAndMakeVisible(importBankLayer.get());
		importBankLayer->setBounds(getLocalBounds());
		importBankLayer->setAlwaysOnTop(true);
		importBankLayer->grabKeyboardFocus();
	}
}

GUI_Layer_VoicesBanks::~GUI_Layer_VoicesBanks() {
	exportVoiceLayer = nullptr;
	exportBankLayer = nullptr;
	importVoiceLayer = nullptr;
	importBankLayer = nullptr;
	pullBankLayer = nullptr;
	pushBankLayer = nullptr;
	voicesBanksTabs.removeListenerFromButtonsInAllTabs(this);
}
