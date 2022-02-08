#include "master_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_MasterOptionsDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SysExIsOffWarningComponent::SysExIsOffWarningComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingComponent{ "" },
	button_ForSendingMasterOptionsDumpRequest{ "" }
{
	button_ForSendingMasterOptionsDumpRequest.setComponentID(ID::button_Retry.toString());
	button_ForSendingMasterOptionsDumpRequest.onClick = [this] { sendRequestForMasterOptionsDump(); };
	addAndMakeVisible(button_ForSendingMasterOptionsDumpRequest);

	button_ForClosingComponent.setComponentID(ID::button_X_Master.toString());
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	addAndMakeVisible(button_ForClosingComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void SysExIsOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::NoSysExWarningWindow_png, BinaryData::NoSysExWarningWindow_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::sysexIsOffWarningWindow_x, GUI::sysexIsOffWarningWindow_y);
}

void SysExIsOffWarningComponent::resized() {
	button_ForClosingComponent.setBounds(GUI::bounds_SysexisOffWarningComponentCloseButton);
	button_ForSendingMasterOptionsDumpRequest.setBounds(GUI::bounds_SysexisOffWarningComponentRetryButton);
}

void SysExIsOffWarningComponent::sendRequestForMasterOptionsDump() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	MasterOptionsDataMessage::addRequestForMasterOptionsDataToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(200, [this] { checkHardwareSettings(); });
}

void SysExIsOffWarningComponent::checkHardwareSettings() {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	if (masterOptions->sysExEnabled())
		hideThisComponent();
}

void SysExIsOffWarningComponent::hideThisComponent() {
	setVisible(false);
}

void SysExIsOffWarningComponent::timerCallback()
{
}
