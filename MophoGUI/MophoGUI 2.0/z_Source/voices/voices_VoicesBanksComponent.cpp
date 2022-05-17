#include "voices_VoicesBanksComponent.h"

#include "voices_BankTransmissionComponent.h"
#include "voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../imptExpt/imptExpt_ExportVoiceDataComponent.h"
#include "../imptExpt/imptExpt_ExportVoicesBankComponent.h"
#include "../imptExpt/imptExpt_ImportVoiceDataComponent.h"
#include "../imptExpt/imptExpt_ImportVoicesBankComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoicesBanksComponent::VoicesBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingVoicesBanksComponent{ "" }
{
	tabbedComponent.addListenerToButtonsInAllTabs(this);

	setSize(GUI::editor_w, GUI::editor_h);

	addAndMakeVisible(tabbedComponent);
	tabbedComponent.setBounds(GUI::bounds_VoicesBanksTabbedComponent);

	button_ForClosingVoicesBanksComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingVoicesBanksComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	addAndMakeVisible(button_ForClosingVoicesBanksComponent);
	button_ForClosingVoicesBanksComponent.setBounds(GUI::bounds_VoicesBanksCloseButton);
	button_ForClosingVoicesBanksComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingVoicesBanksComponent.setAlwaysOnTop(true);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescriptions()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		label_txTimeTooltip += "this value if programs are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}

	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setComponentID(ID::component_EditLabel.toString());
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);
	label_txTime.setBounds(GUI::bounds_VoicesBanksTransmitTimeLabel);
}

void VoicesBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	Rectangle<int> componentOutlineBounds{ GUI::bounds_VoicesBanksTabbedComponent.expanded(GUI::windowOutlineThickness) };
	g.fillRect(componentOutlineBounds);
}

void VoicesBanksComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(4, "0123456789");
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		editor.setFont(FontsMenu::fontFor_Labels);
		editor.setText((String)voiceTransmissionOptions->voiceTransmitTime());
		editor.selectAll();
	}
}

void VoicesBanksComponent::labelTextChanged(Label* label) {
	if (label == &label_txTime) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				voiceTransmissionOptions->setVoiceTransmitTime(newValue);
		}
		label->setText((String)voiceTransmissionOptions->voiceTransmitTime() + " ms", dontSendNotification);
	}
}

void VoicesBanksComponent::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::button_ExportCustomBank1.toString())
		showExportVoicesBankComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_ExportCustomBank2.toString())
		showExportVoicesBankComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_ExportCustomBank3.toString())
		showExportVoicesBankComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_ExportVoiceFromCustomBank1.toString())
		showExportSelectedVoiceComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_ExportVoiceFromCustomBank2.toString())
		showExportSelectedVoiceComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_ExportVoiceFromCustomBank3.toString())
		showExportSelectedVoiceComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_ImportBankIntoCustomBank1.toString())
		showImportVoicesBankComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_ImportBankIntoCustomBank2.toString())
		showImportVoicesBankComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_ImportBankIntoCustomBank3.toString())
		showImportVoicesBankComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_ImportVoiceIntoCustomBank1.toString())
		showImportVoiceComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_ImportVoiceIntoCustomBank2.toString())
		showImportVoiceComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_ImportVoiceIntoCustomBank3.toString())
		showImportVoiceComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_PullCustomBank1.toString())
		showPullEntireBankComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_PullCustomBank2.toString())
		showPullEntireBankComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_PullCustomBank3.toString())
		showPullEntireBankComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_PushCustomBank1.toString())
		showPushEntireBankComponentForBank(VoicesBank::custom1);
	if (button->getComponentID() == ID::button_PushCustomBank2.toString())
		showPushEntireBankComponentForBank(VoicesBank::custom2);
	if (button->getComponentID() == ID::button_PushCustomBank3.toString())
		showPushEntireBankComponentForBank(VoicesBank::custom3);

	if (button->getComponentID() == ID::button_PushFactoryBank1.toString())
		showPushEntireBankComponentForBank(VoicesBank::factory1);
	if (button->getComponentID() == ID::button_PushFactoryBank2.toString())
		showPushEntireBankComponentForBank(VoicesBank::factory2);
	if (button->getComponentID() == ID::button_PushFactoryBank3.toString())
		showPushEntireBankComponentForBank(VoicesBank::factory3);
}

void VoicesBanksComponent::showExportSelectedVoiceComponentForBank(VoicesBank bank) {
	auto slotsComponent{ tabbedComponent.getVoiceSlotsComponentForCustomBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		exportSelectedVoiceComponent.reset(new ExportVoiceDataComponent(bank, slotsComponent, unexposedParams));
		if (exportSelectedVoiceComponent != nullptr) {
			addAndMakeVisible(exportSelectedVoiceComponent.get());
			exportSelectedVoiceComponent->setBounds(getLocalBounds());
			exportSelectedVoiceComponent->setAlwaysOnTop(true);
			exportSelectedVoiceComponent->grabKeyboardFocus();
		}
	}
}

void VoicesBanksComponent::showImportVoiceComponentForBank(VoicesBank bank) {
	auto slotsComponent{ tabbedComponent.getVoiceSlotsComponentForCustomBank(bank) };
	auto slot{ slotsComponent->selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		importVoiceComponent.reset(new ImportVoiceDataComponent(bank, slotsComponent, unexposedParams));
		if (importVoiceComponent != nullptr) {
			addAndMakeVisible(importVoiceComponent.get());
			importVoiceComponent->setBounds(getLocalBounds());
			importVoiceComponent->setAlwaysOnTop(true);
			importVoiceComponent->grabKeyboardFocus();
		}
	}
}

void VoicesBanksComponent::showPushEntireBankComponentForBank(VoicesBank bank) {
	pushEntireBankComponent.reset(new BankTransmissionComponent(bank, BankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
		pushEntireBankComponent->grabKeyboardFocus();
	}
}

void VoicesBanksComponent::showPullEntireBankComponentForBank(VoicesBank bank) {
	pullEntireBankComponent.reset(new BankTransmissionComponent(bank, BankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
		pullEntireBankComponent->grabKeyboardFocus();
	}
}

void VoicesBanksComponent::showExportVoicesBankComponentForBank(VoicesBank bank) {
	auto slotsComponent{ tabbedComponent.getVoiceSlotsComponentForCustomBank(bank) };
	exportVoicesBankComponent.reset(new ExportVoicesBankComponent(bank,slotsComponent, unexposedParams));
	if (exportVoicesBankComponent != nullptr) {
		addAndMakeVisible(exportVoicesBankComponent.get());
		exportVoicesBankComponent->setBounds(getLocalBounds());
		exportVoicesBankComponent->setAlwaysOnTop(true);
		exportVoicesBankComponent->grabKeyboardFocus();
	}
}

void VoicesBanksComponent::showImportVoicesBankComponentForBank(VoicesBank bank) {
	auto slotsComponent{ tabbedComponent.getVoiceSlotsComponentForCustomBank(bank) };
	importVoicesBankComponent.reset(new ImportVoicesBankComponent(bank, slotsComponent, unexposedParams));
	if (importVoicesBankComponent != nullptr) {
		addAndMakeVisible(importVoicesBankComponent.get());
		importVoicesBankComponent->setBounds(getLocalBounds());
		importVoicesBankComponent->setAlwaysOnTop(true);
		importVoicesBankComponent->grabKeyboardFocus();
	}
}

void VoicesBanksComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

VoicesBanksComponent::~VoicesBanksComponent() {
	exportSelectedVoiceComponent = nullptr;
	exportVoicesBankComponent = nullptr;
	importVoiceComponent = nullptr;
	importVoicesBankComponent = nullptr;
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
	tabbedComponent.removeListenerFromButtonsInAllTabs(this);
}
