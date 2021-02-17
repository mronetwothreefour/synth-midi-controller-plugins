#include "patches_PatchBanksComponent.h"

#include "patches_BankTransmissionComponent.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchBanksComponent::PatchBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingPatchBanks{ "" },
	comboBox_ForSelectingBank{ unexposedParams },
	label_txTime{ "transmitTime", "" }
{
	tabbedComponent.addListenerToPullBankButtonInAllCustomTabs(this);
	tabbedComponent.addListenerToPushBankButtonInAllTabs(this);

	setSize(GUI::editor_w, GUI::editor_h);

	button_ForClosingPatchBanks.setComponentID(ID::button_X.toString());
	addAndMakeVisible(button_ForClosingPatchBanks);
	button_ForClosingPatchBanks.setBounds(GUI::bounds_PatchBanksXbutton);
	button_ForClosingPatchBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingPatchBanks.setAlwaysOnTop(true);

	comboBox_ForSelectingBank.setComponentID(ID::comboBox_PatchBankSelector.toString());
	addAndMakeVisible(comboBox_ForSelectingBank);
	comboBox_ForSelectingBank.addListener(this);
	comboBox_ForSelectingBank.setBounds(GUI::bounds_PatchBanksSelectorComboBox);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single patch between the plugin and the Mopho hardware. Increase this\n";
		label_txTimeTooltip += "value if patches are getting 'lost' during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}

	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);
	label_txTime.setBounds(GUI::bounds_PatchBanksTransmitTimeLabel);

	addAndMakeVisible(tabbedComponent);
	tabbedComponent.setBounds(GUI::bounds_TabbedComponentForPatchBanks);
}

void PatchBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::button_blue);
	auto componentBounds{ GUI::bounds_PatchBanksWindow };
	auto componentOutlineBounds{ componentBounds.expanded(GUI::windowBorderThickness) };
	g.fillRect(componentOutlineBounds);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesHeader_png, BinaryData::PatchesHeader_pngSize, false };
	auto headerImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(headerImage, componentBounds.getX(), componentBounds.getY());
}

void PatchBanksComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(matrixParams::maxTransmitTimeDigits, "0123456789");
		auto midiOptions{ unexposedParams->midiOptions_get() };
		editor.setFont(FontsMenu::fontFor_LabelEditors);
		editor.setText((String)midiOptions->patchTransmitTime());
		editor.selectAll();
	}
}

void PatchBanksComponent::labelTextChanged(Label* label) {
	if (label == &label_txTime) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue >= matrixParams::minTransmitTimeValue && newValue <= matrixParams::maxTransmitTimeValue)
				midiOptions->setPatchTransmitTime(newValue);
		}
		label->setText((String)midiOptions->patchTransmitTime(), dontSendNotification);
	}
}

void PatchBanksComponent::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::button_PullCustomBankA.toString())
		showPullEntireBankComponentForBank(PatchBank::customA);
	if (button->getComponentID() == ID::button_PullCustomBankB.toString())
		showPullEntireBankComponentForBank(PatchBank::customB);
	if (button->getComponentID() == ID::button_PushAnalogSynthsBankA.toString())
		showPushEntireBankComponentForBank(PatchBank::analogSynthsA);
	if (button->getComponentID() == ID::button_PushAnalogSynthsBankB.toString())
		showPushEntireBankComponentForBank(PatchBank::analogSynthsB);
	if (button->getComponentID() == ID::button_PushBassesBank.toString())
		showPushEntireBankComponentForBank(PatchBank::basses);
	if (button->getComponentID() == ID::button_PushBrassAndWoodwindsBank.toString())
		showPushEntireBankComponentForBank(PatchBank::brassAndWoodwinds);
	if (button->getComponentID() == ID::button_PushCustomBankA.toString())
		showPushEntireBankComponentForBank(PatchBank::customA);
	if (button->getComponentID() == ID::button_PushCustomBankB.toString())
		showPushEntireBankComponentForBank(PatchBank::customB);
	if (button->getComponentID() == ID::button_PushFXandndPercussionBank.toString())
		showPushEntireBankComponentForBank(PatchBank::fxAndPercussion);
	if (button->getComponentID() == ID::button_PushKeyboardsBankA.toString())
		showPushEntireBankComponentForBank(PatchBank::keyboardsA);
	if (button->getComponentID() == ID::button_PushKeyboardsBankB.toString())
		showPushEntireBankComponentForBank(PatchBank::keyboardsB);
	if (button->getComponentID() == ID::button_PushLeadsBank.toString())
		showPushEntireBankComponentForBank(PatchBank::leads);
	if (button->getComponentID() == ID::button_PushMiscellaneousBankA.toString())
		showPushEntireBankComponentForBank(PatchBank::miscellaneousA);
	if (button->getComponentID() == ID::button_PushMiscellaneousBankB.toString())
		showPushEntireBankComponentForBank(PatchBank::miscellaneousB);
	if (button->getComponentID() == ID::button_PushStringsBank.toString())
		showPushEntireBankComponentForBank(PatchBank::strings);
}

void PatchBanksComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox->getComponentID() == ID::comboBox_PatchBankSelector.toString()) {
		auto selectedBank{ comboBox->getSelectedItemIndex() };
		tabbedComponent.setCurrentTabIndex(selectedBank);
	}
}

void PatchBanksComponent::showPushEntireBankComponentForBank(PatchBank bank) {
	pushEntireBankComponent.reset(new PatchBankTransmissionComponent(bank, PatchBankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
	}
}

void PatchBanksComponent::showPullEntireBankComponentForBank(PatchBank bank) {
	pullEntireBankComponent.reset(new PatchBankTransmissionComponent(bank, PatchBankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
	}
}

void PatchBanksComponent::hideThisComponent() {
	setVisible(false);
}

PatchBanksComponent::~PatchBanksComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
	tabbedComponent.removeListenerFromPullEntireBankButtonInAllCustomTabs(this);
	tabbedComponent.removeListenerFromPushEntireBankButtonInAllTabs(this);
}