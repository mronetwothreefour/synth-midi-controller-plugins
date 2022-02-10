#include "voices_VoicesBanksComponent.h"

#include "voices_BankTransmissionComponent.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoicesBanksComponent::VoicesBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingVoicesBanks{ "" },
	comboBox_ForSelectingBank{ unexposedParams },
	label_txTime{ "transmitTime", "" }
{
	tabbedComponent.addListenerToPullBankButtonInAllCustomTabs(this);
	tabbedComponent.addListenerToPushBankButtonInAllTabs(this);

	setSize(GUI::editor_w, GUI::editor_h);

	button_ForClosingVoicesBanks.setComponentID(ID::button_X_VoicesBanks.toString());
	addAndMakeVisible(button_ForClosingVoicesBanks);
	button_ForClosingVoicesBanks.setBounds(GUI::bounds_VoicesBanksXbutton);
	button_ForClosingVoicesBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingVoicesBanks.setAlwaysOnTop(true);

	comboBox_ForSelectingBank.setComponentID(ID::comboBox_VoicesBankSelector.toString());
	addAndMakeVisible(comboBox_ForSelectingBank);
	comboBox_ForSelectingBank.addListener(this);
	comboBox_ForSelectingBank.setBounds(GUI::bounds_VoicesBanksSelectorComboBox);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single patch between the plugin and the Matrix-6R hardware. Increase this\n";
		label_txTimeTooltip += "value if patches are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}

	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);
	label_txTime.setBounds(GUI::bounds_VoicesBanksTransmitTimeLabel);

	addAndMakeVisible(tabbedComponent);
	tabbedComponent.setBounds(GUI::bounds_TabbedComponentForVoicesBanks);
}

void VoicesBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::button_blue);
	auto componentBounds{ GUI::bounds_VoicesBanksWindow };
	auto componentOutlineBounds{ componentBounds.expanded(GUI::windowBorderThickness) };
	g.fillRect(componentOutlineBounds);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesHeader_png, BinaryData::PatchesHeader_pngSize, false };
	auto headerImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(headerImage, componentBounds.getX(), componentBounds.getY());
}

void VoicesBanksComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(params::maxTransmitTimeDigits, "0123456789");
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		editor.setFont(FontsMenu::fontFor_LabelEditors);
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
			if (newValue >= params::minTransmitTimeValue && newValue <= params::maxTransmitTimeValue)
				voiceTransmissionOptions->setVoiceTransmitTime(newValue);
		}
		label->setText((String)voiceTransmissionOptions->voiceTransmitTime(), dontSendNotification);
	}
}

void VoicesBanksComponent::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::button_PullCustomBankA.toString())
		showPullEntireBankComponentForBank(VoicesBank::customA);
	if (button->getComponentID() == ID::button_PullCustomBankB.toString())
		showPullEntireBankComponentForBank(VoicesBank::customB);
	if (button->getComponentID() == ID::button_PushAnalogSynthsBankA.toString())
		showPushEntireBankComponentForBank(VoicesBank::analogSynthsA);
	if (button->getComponentID() == ID::button_PushAnalogSynthsBankB.toString())
		showPushEntireBankComponentForBank(VoicesBank::analogSynthsB);
	if (button->getComponentID() == ID::button_PushBassesBank.toString())
		showPushEntireBankComponentForBank(VoicesBank::basses);
	if (button->getComponentID() == ID::button_PushBrassAndWoodwindsBank.toString())
		showPushEntireBankComponentForBank(VoicesBank::brassAndWoodwinds);
	if (button->getComponentID() == ID::button_PushCustomBankA.toString())
		showPushEntireBankComponentForBank(VoicesBank::customA);
	if (button->getComponentID() == ID::button_PushCustomBankB.toString())
		showPushEntireBankComponentForBank(VoicesBank::customB);
	if (button->getComponentID() == ID::button_PushFXandndPercussionBank.toString())
		showPushEntireBankComponentForBank(VoicesBank::fxAndPercussion);
	if (button->getComponentID() == ID::button_PushKeyboardsBankA.toString())
		showPushEntireBankComponentForBank(VoicesBank::keyboardsA);
	if (button->getComponentID() == ID::button_PushKeyboardsBankB.toString())
		showPushEntireBankComponentForBank(VoicesBank::keyboardsB);
	if (button->getComponentID() == ID::button_PushLeadsBank.toString())
		showPushEntireBankComponentForBank(VoicesBank::leads);
	if (button->getComponentID() == ID::button_PushMiscellaneousBankA.toString())
		showPushEntireBankComponentForBank(VoicesBank::miscellaneousA);
	if (button->getComponentID() == ID::button_PushMiscellaneousBankB.toString())
		showPushEntireBankComponentForBank(VoicesBank::miscellaneousB);
	if (button->getComponentID() == ID::button_PushStringsBank.toString())
		showPushEntireBankComponentForBank(VoicesBank::strings);
}

void VoicesBanksComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox->getComponentID() == ID::comboBox_VoicesBankSelector.toString()) {
		auto selectedBank{ comboBox->getSelectedItemIndex() };
		tabbedComponent.setCurrentTabIndex(selectedBank);
	}
}

void VoicesBanksComponent::showPushEntireBankComponentForBank(VoicesBank bank) {
	pushEntireBankComponent.reset(new VoicesBankTransmissionComponent(bank, VoicesBankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
	}
}

void VoicesBanksComponent::showPullEntireBankComponentForBank(VoicesBank bank) {
	pullEntireBankComponent.reset(new VoicesBankTransmissionComponent(bank, VoicesBankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
	}
}

void VoicesBanksComponent::hideThisComponent() {
	setVisible(false);
}

VoicesBanksComponent::~VoicesBanksComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
	tabbedComponent.removeListenerFromPullEntireBankButtonInAllCustomTabs(this);
	tabbedComponent.removeListenerFromPushEntireBankButtonInAllTabs(this);
}