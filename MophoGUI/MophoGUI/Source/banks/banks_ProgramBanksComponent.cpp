#include "banks_ProgramBanksComponent.h"

#include "../gui/gui_Colors.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_BankTransmission/widget_BankTransmissionComponent.h"



ProgramBanksComponent::ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	tabbedComponent{ exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	button_ForClosingProgramBanks{ "CLOSE" },
	button_ForPushingEntireBankToHardware{ unexposedParams },
	button_ForPullingEntireBankFromHardware{ unexposedParams }
{
	setSize(1273, 626);

	addAndMakeVisible(tabbedComponent);
	auto tabbedComponent_w{ 1065 };
	auto tabbedComponent_h{ 400 };
	auto tabbedComponent_x{ (getWidth() - tabbedComponent_w) / 2 };
	auto tabbedComponent_y{ (getHeight() - tabbedComponent_h) / 2 };
	tabbedComponent.setBounds(tabbedComponent_x, tabbedComponent_y, tabbedComponent_w, tabbedComponent_h);

	addAndMakeVisible(button_ForClosingProgramBanks);
	auto buttons_w{ 50 };
	auto buttons_h{ 21 };
	button_ForClosingProgramBanks.setBounds(1115, 118, buttons_w, buttons_h);
	button_ForClosingProgramBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingProgramBanks.setAlwaysOnTop(true);

	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);
	button_ForPushingEntireBankToHardware.onClick = [this] { showPushEntireBankComponent(); };
	button_ForPullingEntireBankFromHardware.onClick = [this] { showPullEntireBankComponent(); };
	auto buttons_y{ 477 };
	button_ForPushingEntireBankToHardware.setBounds(664, buttons_y, buttons_w, buttons_h);
	button_ForPullingEntireBankFromHardware.setBounds(724, buttons_y, buttons_w, buttons_h);

}

void ProgramBanksComponent::hideThisComponent() {
	setVisible(false);
}

void ProgramBanksComponent::showPushEntireBankComponent() {
	pushEntireBankComponent.reset(new BankTransmissionComponent(tabbedComponent, BankTransmissionComponent::TransmissionType::push, unexposedParams));
	if (pushEntireBankComponent != nullptr) {
		addAndMakeVisible(pushEntireBankComponent.get());
		pushEntireBankComponent->setBounds(getLocalBounds());
		pushEntireBankComponent->setAlwaysOnTop(true);
	}
}

void ProgramBanksComponent::showPullEntireBankComponent() {
	pullEntireBankComponent.reset(new BankTransmissionComponent(tabbedComponent, BankTransmissionComponent::TransmissionType::pull, unexposedParams));
	if (pullEntireBankComponent != nullptr) {
		addAndMakeVisible(pullEntireBankComponent.get());
		pullEntireBankComponent->setBounds(getLocalBounds());
		pullEntireBankComponent->setAlwaysOnTop(true);
	}
}

void ProgramBanksComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 1069 };
	auto componentOutline_h{ 404 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
}

ProgramBanksComponent::~ProgramBanksComponent() {
	pullEntireBankComponent = nullptr;
	pushEntireBankComponent = nullptr;
}
