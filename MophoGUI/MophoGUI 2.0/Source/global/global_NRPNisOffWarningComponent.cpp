#include "global_NRPNisOffWarningComponent.h"

#include "global_ParameterReceiveType.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



NRPNisOffWarningComponent::NRPNisOffWarningComponent(UnexposedParameters* unexposedParams) :
	HardwareSettingsWarningComponent{ unexposedParams }
{
	addButtonsToComponent();
	resized();
}

void NRPNisOffWarningComponent::checkHardwareSettings() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->hardwareIsSetToReceiveNRPNcontrollers())
		hideThisComponent();
}

void NRPNisOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::NoNRPNWarningBackground_png, BinaryData::NoNRPNWarningBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::nrpnIsOffWarningWindow_x, GUI::nrpnIsOffWarningWindow_y);
}

void NRPNisOffWarningComponent::resized() {
	button_ForClosingComponent.setBounds(GUI::bounds_NRPNisOffWarningComponentCloseButton);
	button_ForSendingGlobalParametersDumpRequest.setBounds(GUI::bounds_NRPNisOffWarningComponentRetryButton);
}
