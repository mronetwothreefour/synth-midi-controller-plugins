#include "banks_ProgramBanksComponent.h"

#include "banks_ProgramBanksButtons.h"
#include "../helpers/helper_CustomColors.h"



void ProgramBanksComponent::hideThisComponent() {
	setVisible(false);
}

ProgramBanksComponent::ProgramBanksComponent(AudioProcessorValueTreeState* exposedParams) :
	tabbedComponent{ exposedParams },
	button_ForClosingProgramBanks{ "CLOSE" }
{
	addAndMakeVisible(tabbedComponent);
	addAndMakeVisible(button_ForClosingProgramBanks);
	button_ForClosingProgramBanks.onClick = [this] { hideThisComponent(); };
	button_ForClosingProgramBanks.setAlwaysOnTop(true);
	setSize(1273, 626);
	auto tabbedComponent_w{ 1065 };
	auto tabbedComponent_h{ 400 };
	auto tabbedComponent_x{ (getWidth() - tabbedComponent_w) / 2 };
	auto tabbedComponent_y{ (getHeight() - tabbedComponent_h) / 2 };
	tabbedComponent.setBounds(tabbedComponent_x, tabbedComponent_y, tabbedComponent_w, tabbedComponent_h);
	button_ForClosingProgramBanks.setBounds(1115, 118, 50, 21);
}

ProgramBanksComponent::~ProgramBanksComponent() {
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
