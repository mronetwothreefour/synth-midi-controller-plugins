#include "banks_ProgramBanksComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_BankTransmission/widget_BankTransmissionComponent.h"



ProgramBanksComponent::ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingProgramBanks{ "" },
	button_ForPushingEntireBankToHardware{ unexposedParams },
	button_ForPullingEntireBankFromHardware{ unexposedParams }
{
	setSize(1273, 626);

	addAndMakeVisible(tabbedComponent);
	auto tabbedComponent_w{ 1095 };
	auto tabbedComponent_h{ 400 };
	auto tabbedComponent_x{ (getWidth() - tabbedComponent_w) / 2 };
	auto tabbedComponent_y{ (getHeight() - tabbedComponent_h) / 2 };
	tabbedComponent.setBounds(tabbedComponent_x, tabbedComponent_y, tabbedComponent_w, tabbedComponent_h);

	button_ForClosingProgramBanks.setComponentID(ID::button_Close.toString());
	addAndMakeVisible(button_ForClosingProgramBanks);
	auto controls_y{ 477 };
	auto controls_w{ 50 };
	auto controls_h{ 22 };
	button_ForClosingProgramBanks.setBounds(1130, 117, controls_w, controls_h);
	button_ForClosingProgramBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingProgramBanks.setAlwaysOnTop(true);

	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);
	button_ForPushingEntireBankToHardware.onClick = [this] { showPushEntireBankComponent(); };
	button_ForPullingEntireBankFromHardware.onClick = [this] { showPullEntireBankComponent(); };
	button_ForPushingEntireBankToHardware.setBounds(757, controls_y, controls_w, controls_h);
	button_ForPullingEntireBankFromHardware.setBounds(812, controls_y, controls_w, controls_h);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String label_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescription()) {
		label_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		label_txTimeTooltip += "of a single program between the plugin and the Mopho hardware. Increase\n";
		label_txTimeTooltip += "this value if programs are getting 'lost' during pushes or pulls.\n";
		label_txTimeTooltip += "Minimum time: 50 ms. Maximum time 5000 ms.";
	}

	label_txTime.setTooltip(label_txTimeTooltip);
	label_txTime.addListener(this);
	label_txTime.setComponentID(ID::component_EditLabel.toString());
	label_txTime.setEditable(true);
	labelTextChanged(&label_txTime);
	addAndMakeVisible(label_txTime);
	label_txTime.setBounds(1119, controls_y, controls_w, controls_h);
}

void ProgramBanksComponent::hideThisComponent() {
	setVisible(false);
}

void ProgramBanksComponent::showPushEntireBankComponent() {
	//pushEntireBankComponent.reset(new BankTransmissionComponent(tabbedComponent, BankTransmissionComponent::TransmissionType::push, unexposedParams));
	//if (pushEntireBankComponent != nullptr) {
	//	addAndMakeVisible(pushEntireBankComponent.get());
	//	pushEntireBankComponent->setBounds(getLocalBounds());
	//	pushEntireBankComponent->setAlwaysOnTop(true);
	//}
}

void ProgramBanksComponent::showPullEntireBankComponent() {
	//pullEntireBankComponent.reset(new BankTransmissionComponent(tabbedComponent, BankTransmissionComponent::TransmissionType::pull, unexposedParams));
	//if (pullEntireBankComponent != nullptr) {
	//	addAndMakeVisible(pullEntireBankComponent.get());
	//	pullEntireBankComponent->setBounds(getLocalBounds());
	//	pullEntireBankComponent->setAlwaysOnTop(true);
	//}
}

void ProgramBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 1099 };
	auto componentOutline_h{ 404 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
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

ProgramBanksComponent::~ProgramBanksComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
}
