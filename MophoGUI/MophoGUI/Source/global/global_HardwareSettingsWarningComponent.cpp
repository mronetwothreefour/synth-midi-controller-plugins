#include "global_HardwareSettingsWarningComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_GlobalParametersDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



HardwareSettingsWarningComponent::HardwareSettingsWarningComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingComponent{ "" },
	button_ForSendingGlobalParametersDumpRequest{ "" }
{
	button_ForSendingGlobalParametersDumpRequest.onClick = [this] { sendRequestForGlobalParametersDump(); };
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	setSize(GUI::editor_w, GUI::editor_h);
}

void HardwareSettingsWarningComponent::addButtonsToComponent() {
	button_ForSendingGlobalParametersDumpRequest.setComponentID(ID::button_Retry.toString());
	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
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
