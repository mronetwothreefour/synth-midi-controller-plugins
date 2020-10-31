#include "global_NRPNisOffWarningComponent.h"

#include "global_ParameterReceiveType.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



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
	g.drawImageAt(backgroundImage, 396, 205);
}

void NRPNisOffWarningComponent::resized() {
	auto button_h{ 22 };
	button_ForClosingComponent.setBounds(820, 212, 50, button_h);
	button_ForSendingGlobalParametersDumpRequest.setBounds(611, 387, 51, button_h);
}

NRPNisOffWarningComponent::~NRPNisOffWarningComponent() {
}
