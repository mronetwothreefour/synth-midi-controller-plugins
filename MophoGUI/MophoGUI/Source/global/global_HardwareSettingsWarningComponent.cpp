#include "global_HardwareSettingsWarningComponent.h"

#include "../midi/midi_GlobalParametersDump.h"
#include "../params/params_UnexposedParameters_Facade.h"



HardwareSettingsWarningComponent::HardwareSettingsWarningComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingComponent{ "CLOSE" },
	button_ForSendingGlobalParametersDumpRequest{ "RETRY" }
{
	button_ForSendingGlobalParametersDumpRequest.onClick = [this] { sendRequestForGlobalParametersDump(); };
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	setSize(1273, 626);
}

void HardwareSettingsWarningComponent::addButtonsToComponent() {
	addAndMakeVisible(button_ForSendingGlobalParametersDumpRequest);
	addAndMakeVisible(button_ForClosingComponent);
}

void HardwareSettingsWarningComponent::sendRequestForGlobalParametersDump() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	GlobalParametersDump::addRequestForDumpToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(200, [this] { checkHardwareSettings(); });
}

void HardwareSettingsWarningComponent::hideThisComponent() {
	setVisible(false);
}

void HardwareSettingsWarningComponent::timerCallback() {
}

HardwareSettingsWarningComponent::~HardwareSettingsWarningComponent() {
}
