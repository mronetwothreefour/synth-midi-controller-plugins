#include "global_FailedLinkComponent.h"

#include "../midi/midi_GlobalParametersDump.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



FailedLinkComponent::FailedLinkComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingFailedLinkComponent{ "CLOSE" },
	button_ForSendingGlobalParametersDumpRequest{ "RETRY" }
{
	addAndMakeVisible(button_ForSendingGlobalParametersDumpRequest);
	button_ForSendingGlobalParametersDumpRequest.onClick = [this] { sendRequestForGlobalParametersDump(); };
	addAndMakeVisible(button_ForClosingFailedLinkComponent);
	button_ForClosingFailedLinkComponent.onClick = [this] { hideThisComponent(); };
	setSize(1273, 626);
}

void FailedLinkComponent::sendRequestForGlobalParametersDump() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	GlobalParametersDump::addRequestForDumpToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(200, [this] { checkSysExLink(); });
}

void FailedLinkComponent::checkSysExLink() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->sysExIsOn())
		hideThisComponent();
}

void FailedLinkComponent::hideThisComponent() {
	setVisible(false);
}

void FailedLinkComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
}

void FailedLinkComponent::resized() {
	button_ForClosingFailedLinkComponent.setBounds(700, 126, 50, 21);
	button_ForSendingGlobalParametersDumpRequest.setBounds(600, 450, 50, 21);
}

void FailedLinkComponent::timerCallback() {
}

FailedLinkComponent::~FailedLinkComponent() {
}
