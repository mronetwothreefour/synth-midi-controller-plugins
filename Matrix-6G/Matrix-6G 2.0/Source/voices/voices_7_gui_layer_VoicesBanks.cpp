#include "voices_7_gui_layer_VoicesBanks.h"

#include "voices_6_gui_layer_BankTransmit.h"
#include "../voicesImportExport/imEx_3_gui_layer_Export_Voice.h"
#include "../voicesImportExport/imEx_3_gui_layer_Export_VoicesBank.h"
#include "../voicesImportExport/imEx_3_gui_layer_Import_Voice.h"
#include "../voicesImportExport/imEx_3_gui_layer_Import_VoicesBank.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_VoicesBanks::GUI_Layer_VoicesBanks(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	voicesBanksTabs{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	btn_Close{ BorderColor::blue, unexposedParams->getTooltipsOptions() }
{
	btn_Close.setTopRightPosition(borderBounds.getRight(), borderBounds.getY());
	btn_Close.setAlwaysOnTop(true);
	addAndMakeVisible(btn_Close);
	
	auto topRow_y{ 77 };

	bankSelector.addItemList(voicesBanksTabs.getTabNames(), 1);
	bankSelector.onChange = [this] {
		auto selectedBank{ bankSelector.getSelectedItemIndex() };
		voicesBanksTabs.setCurrentTabIndex(selectedBank);
	};
	bankSelector.setSelectedItemIndex(0, dontSendNotification);
	bankSelector.setBounds(484, topRow_y, 188, GUI::buttons_small_h);
	addAndMakeVisible(bankSelector);

	auto tooltips{ unexposedParams->getTooltipsOptions() };
	
	auto voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() };
	lbl_txTimeEditor.setComponentID(ID::lbl_EditLabel.toString());
	lbl_txTimeEditor.setEditable(true);
	lbl_txTimeEditor.onEditorShow = [this, tooltips, voiceTransmit] {
		auto editor{ lbl_txTimeEditor.getCurrentTextEditor() };
		editor->setInputRestrictions(4, "0123456789");
		editor->setText((String)voiceTransmit->voiceTransmitTime());
		editor->selectAll();
		if (tooltips->shouldShowDescription())
			editor->setTooltip("Type a new transmit\ntime in milliseconds.\n(Range: 50 to 5000)");
	};
	lbl_txTimeEditor.onTextChange = [this, voiceTransmit] {
		if (lbl_txTimeEditor.getText().isNotEmpty()) {
			auto newValue{ lbl_txTimeEditor.getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				voiceTransmit->setVoiceTransmitTime(newValue);
		}
		lbl_txTimeEditor.setText((String)voiceTransmit->voiceTransmitTime(), dontSendNotification);
	};
	lbl_txTimeEditor.setBounds(771, topRow_y, 54, GUI::buttons_small_h);
	addAndMakeVisible(lbl_txTimeEditor);
	lbl_txTimeEditor.onTextChange();

	voicesBanksTabs.addListenerToButtonsInAllTabs(this);

	voicesBanksTabs.setTopLeftPosition(componentBounds.getX(), 102);
	addAndMakeVisible(voicesBanksTabs);

	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Selects which bank of stored patches to work with.\n";
		tip += "Only patches in the Custom A & B banks can be overwritten.";
		bankSelector.setTooltip(tip);
		tip = "";
		tip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		tip += "of a single patch between the plugin and the Matrix-6R hardware. Increase this\n";
		tip += "value if patches are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		tip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
		lbl_txTimeEditor.setTooltip(tip);
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_VoicesBanks::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	g.setColour(GUI::color_ButtonBlue);
	g.fillRect(borderBounds);
	g.setColour(GUI::color_Device);
	g.fillRect(componentBounds);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_VoicesBanksHeader_png, BinaryData::bkgrnd_VoicesBanksHeader_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, componentBounds.getX(), componentBounds.getY());
}

void GUI_Layer_VoicesBanks::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto bankNum{ buttonID.fromLastOccurrenceOf("_", false, false).getIntValue() };

	if (buttonID.startsWith(ID::btn_Expt_VoicesBank_.toString()))
		showExportBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::btn_Expt_VoiceFromBank_.toString()))
		showExportVoiceLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::btn_Impt_AllVoicesIntoBank_.toString()))
		showImportBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::btn_Impt_VoiceIntoBank_.toString()))
		showImportVoiceLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::btn_Pull_VoicesBank_.toString()))
		showPullBankLayerForBank(VoicesBank{ bankNum });

	if (buttonID.startsWith(ID::btn_Push_VoicesBank_.toString()))
		showPushBankLayerForBank(VoicesBank{ bankNum });
}

void GUI_Layer_VoicesBanks::showExportVoiceLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsComponentForBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		exportVoiceLayer.reset(new GUI_Layer_Export_Voice{ bank, slotsComponent, unexposedParams });
		if (exportVoiceLayer != nullptr) {
			addAndMakeVisible(exportVoiceLayer.get());
			exportVoiceLayer->setBounds(getLocalBounds());
			exportVoiceLayer->setAlwaysOnTop(true);
			exportVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBanks::showImportVoiceLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsComponentForBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < VCS::numberOfSlotsInVoicesBank) {
		importVoiceLayer.reset(new GUI_Layer_Import_Voice{ bank, slotsComponent, unexposedParams });
		if (importVoiceLayer != nullptr) {
			addAndMakeVisible(importVoiceLayer.get());
			importVoiceLayer->setBounds(getLocalBounds());
			importVoiceLayer->setAlwaysOnTop(true);
			importVoiceLayer->grabKeyboardFocus();
		}
	}
}

void GUI_Layer_VoicesBanks::showPushBankLayerForBank(VoicesBank bank) {
	pushBankLayer.reset(new GUI_Layer_VoicesBankTransmit{ bank, BankTransmitType::push, unexposedParams });
	if (pushBankLayer != nullptr) {
		addAndMakeVisible(pushBankLayer.get());
		pushBankLayer->setBounds(getLocalBounds());
		pushBankLayer->setAlwaysOnTop(true);
		pushBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showPullBankLayerForBank(VoicesBank bank) {
	pullBankLayer.reset(new GUI_Layer_VoicesBankTransmit{ bank, BankTransmitType::pull, unexposedParams });
	if (pullBankLayer != nullptr) {
		addAndMakeVisible(pullBankLayer.get());
		pullBankLayer->setBounds(getLocalBounds());
		pullBankLayer->setAlwaysOnTop(true);
		pullBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showExportBankLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsComponentForBank(bank) };
	exportBankLayer.reset(new GUI_Layer_Export_VoicesBank{ bank, slotsComponent, unexposedParams });
	if (exportBankLayer != nullptr) {
		addAndMakeVisible(exportBankLayer.get());
		exportBankLayer->setBounds(getLocalBounds());
		exportBankLayer->setAlwaysOnTop(true);
		exportBankLayer->grabKeyboardFocus();
	}
}

void GUI_Layer_VoicesBanks::showImportBankLayerForBank(VoicesBank bank) {
	auto slotsComponent{ voicesBanksTabs.getVoiceSlotsComponentForBank(bank) };
	importBankLayer.reset(new GUI_Layer_Import_VoicesBank{ bank, slotsComponent, unexposedParams });
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
