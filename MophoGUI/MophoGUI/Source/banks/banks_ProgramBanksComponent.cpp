#include "banks_ProgramBanksComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_BankTransmission/widget_BankTransmissionComponent.h"

using namespace constants;



ProgramBanksComponent::ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingProgramBanks{ "" }
{
	tabbedComponent.addListenerToPushEntireBankButtonInAllTabs(this);
	tabbedComponent.addListenerToPullEntireBankButtonInAllCustomTabs(this);

	setSize(GUI::editor_w, GUI::editor_h);

	addAndMakeVisible(tabbedComponent);
	tabbedComponent.setBounds(GUI::bounds_ProgramBanksTabbedComponent);

	button_ForClosingProgramBanks.setComponentID(ID::button_Close.toString());
	addAndMakeVisible(button_ForClosingProgramBanks);
	button_ForClosingProgramBanks.setBounds(GUI::bounds_ProgramBanksCloseButton);
	button_ForClosingProgramBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingProgramBanks.setAlwaysOnTop(true);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		label_txTimeTooltip += "this value if programs are getting 'lost' during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}

	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setComponentID(ID::component_EditLabel.toString());
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);
	label_txTime.setBounds(GUI::bounds_ProgramBanksTransmitTimeLabel);
}

void ProgramBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	Rectangle<int> componentOutlineBounds{ GUI::bounds_ProgramBanksTabbedComponent.expanded(GUI::windowOutlineThickness) };
	g.fillRect(componentOutlineBounds);
}

void ProgramBanksComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_txTime) {
		editor.setInputRestrictions(4, "0123456789");
		auto midiOptions{ unexposedParams->midiOptions_get() };
		editor.setFont(FontsMenu::fontFor_Labels);
		editor.setText((String)midiOptions->programTransmitTime());
		editor.selectAll();
	}
}

void ProgramBanksComponent::labelTextChanged(Label* label) {
	if (label == &label_txTime) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue > 49 && newValue < 5001)
				midiOptions->setProgramTransmitTime(newValue);
		}
		label->setText((String)midiOptions->programTransmitTime() + " ms", dontSendNotification);
	}
}

void ProgramBanksComponent::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::button_PullCustomBank1.toString())
		showPullEntireBankComponentForBank(ProgramBank::custom1);
	if (button->getComponentID() == ID::button_PullCustomBank2.toString())
		showPullEntireBankComponentForBank(ProgramBank::custom2);
	if (button->getComponentID() == ID::button_PullCustomBank3.toString())
		showPullEntireBankComponentForBank(ProgramBank::custom3);
	if (button->getComponentID() == ID::button_PushCustomBank1.toString())
		showPushEntireBankComponentForBank(ProgramBank::custom1);
	if (button->getComponentID() == ID::button_PushCustomBank2.toString())
		showPushEntireBankComponentForBank(ProgramBank::custom2);
	if (button->getComponentID() == ID::button_PushCustomBank3.toString())
		showPushEntireBankComponentForBank(ProgramBank::custom3);
	if (button->getComponentID() == ID::button_PushFactoryBank1.toString())
		showPushEntireBankComponentForBank(ProgramBank::factory1);
	if (button->getComponentID() == ID::button_PushFactoryBank2.toString())
		showPushEntireBankComponentForBank(ProgramBank::factory2);
	if (button->getComponentID() == ID::button_PushFactoryBank3.toString())
		showPushEntireBankComponentForBank(ProgramBank::factory3);
}

void ProgramBanksComponent::showPushEntireBankComponentForBank(ProgramBank bank) {
	pushEntireBankComponent.reset(new BankTransmissionComponent(bank, BankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
	}
}

void ProgramBanksComponent::showPullEntireBankComponentForBank(ProgramBank bank) {
	pullEntireBankComponent.reset(new BankTransmissionComponent(bank, BankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
	}
}

void ProgramBanksComponent::hideThisComponent() {
	setVisible(false);
}

ProgramBanksComponent::~ProgramBanksComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
	tabbedComponent.removeListenerFromPullEntireBankButtonInAllCustomTabs(this);
	tabbedComponent.removeListenerFromPushEntireBankButtonInAllTabs(this);
}
