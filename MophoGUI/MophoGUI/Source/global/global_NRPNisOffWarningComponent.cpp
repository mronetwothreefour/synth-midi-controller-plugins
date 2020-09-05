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
	g.setColour(Color::black);
	auto componentOutline_w{ 481 };
	auto componentOutline_h{ 216 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
	g.setColour(Color::device);
	auto componentBackground{ componentOutline.reduced(2, 2) };
	g.fillRect(componentBackground);

	g.setColour(Color::black);
	Font componentLabelFont{ FontsDB::family_Global, FontsDB::style_ForComponentTitle, FontsDB::size_ForComponentTitle };
	g.setFont(componentLabelFont);
	Rectangle<int> componentLabelArea{ componentOutline_x, 220, componentOutline_w, 21 };
	g.drawText("COMMUNICATION ERROR!", componentLabelArea, Justification::centredTop, false);

	String msg{ "" };
	msg += "This plugin has detected that the hardware is not set to receive MIDI\n";
	msg += "NRPN controller messages. These are used to send parameter changes\n";
	msg += "to the hardware and are critical for this plugin to function correctly.\n";
	msg += "\n";
	msg += "To fix this issue, go to the hardware's Global Parameters menus and make sure\n";
	msg += "that M Param Rec is set to \"All\" or \"NRPN,\" and that MIDI Control is set to \"On.\"\n";
	msg += "\n";
	msg += "Click the Retry button to check these parameters again. If they\n";
	msg += "are properly set, this warning window will close automatically.";
	Font boldMessageFont{ FontsDB::family_Global, FontsDB::style_ForBoldHardwareSettingsWarningMessage, FontsDB::size_ForBoldHardwareSettingsWarningMessage };
	g.setFont(boldMessageFont);
	g.drawMultiLineText(msg, componentOutline_x, 260, componentOutline_w, Justification::centred, 2.0f);
}

void NRPNisOffWarningComponent::resized() {
	auto button_w{ 50 };
	auto button_h{ 21 };
	button_ForClosingComponent.setBounds(820, 212, button_w, button_h);
	button_ForSendingGlobalParametersDumpRequest.setBounds(612, 387, button_w, button_h);
}

NRPNisOffWarningComponent::~NRPNisOffWarningComponent() {
}
