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
	auto paramReceiveType{ midiOptions->parameterReceiveType() };
	if (paramReceiveType == (uint8)ParameterReceiveType::all || paramReceiveType == (uint8)ParameterReceiveType::nrpnOnly)
		hideThisComponent();
}

void NRPNisOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
}

void NRPNisOffWarningComponent::resized() {
	button_ForClosingComponent.setBounds(800, 126, 50, 21);
	button_ForSendingGlobalParametersDumpRequest.setBounds(600, 600, 50, 21);
}

NRPNisOffWarningComponent::~NRPNisOffWarningComponent() {
}
