#include "global_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_GlobalOptionsDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SysExIsOffWarningComponent::SysExIsOffWarningComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingComponent{ "" },
	button_ForSendingGlobalOptionsDataRequest{ "" }
{
	button_ForSendingGlobalOptionsDataRequest.setComponentID(ID::button_Retry.toString());
	button_ForSendingGlobalOptionsDataRequest.onClick = [this] { sendRequestForGlobalOptionsData(); };
	addAndMakeVisible(button_ForSendingGlobalOptionsDataRequest);

	button_ForClosingComponent.setComponentID(ID::button_X_Global.toString());
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
	button_ForSendingGlobalOptionsDataRequest.setBounds(GUI::bounds_SysexisOffWarningComponentRetryButton);
}

void SysExIsOffWarningComponent::sendRequestForGlobalOptionsData() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	GlobalOptionsDataMessage::addRequestForGlobalOptionsDataToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(200, [this] { checkHardwareSettings(); });
}

void SysExIsOffWarningComponent::checkHardwareSettings() {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	if (globalOptions->sysExEnabled())
		hideThisComponent();
}

void SysExIsOffWarningComponent::hideThisComponent() {
	setVisible(false);
}

void SysExIsOffWarningComponent::timerCallback()
{
}
