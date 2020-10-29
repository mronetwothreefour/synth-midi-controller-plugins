#include "global_SysExIsOffWarningComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



SysExIsOffWarningComponent::SysExIsOffWarningComponent(UnexposedParameters* unexposedParams) :
	HardwareSettingsWarningComponent{ unexposedParams }
{
	addButtonsToComponent();
	resized();
}

void SysExIsOffWarningComponent::checkHardwareSettings() {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	if (midiOptions->sysExIsOn())
		hideThisComponent();
}

void SysExIsOffWarningComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 501 };
	auto componentOutline_h{ 340 };
	auto componentOutline_x{ (getWidth() - componentOutline_w) / 2 };
	auto componentOutline_y{ (getHeight() - componentOutline_h) / 2 };
	Rectangle<int> componentOutline{ componentOutline_x, componentOutline_y, componentOutline_w, componentOutline_h };
	g.fillRect(componentOutline);
	g.setColour(Color::device);
	auto componentBackground{ componentOutline.reduced(2, 2) };
	g.fillRect(componentBackground);

	g.setColour(Color::black);
	Font componentLabelFont{ FontsMenu::family_Global, FontsMenu::style_ForComponentTitle, FontsMenu::size_ForComponentTitle };
	g.setFont(componentLabelFont);
	Rectangle<int> componentLabelArea{ componentOutline_x, 159, componentOutline_w, 21 };
	g.drawText("COMMUNICATION ERROR!", componentLabelArea, Justification::centredTop, false);

	String msg{ "" };
	msg += "This plugin attempted to request a Global Parameters data dump from the\n";
	msg += "hardware via MIDI system exclusive messages, but a reply was not received.\n";
	msg += "System exclusive communication is needed for this plugin to function correctly.\n";
	msg += "\n";
	msg += "Here are some possible fixes:\n";
	Font boldMessageFont{ FontsMenu::family_Global, FontsMenu::style_ForBoldHardwareSettingsWarningMessage, FontsMenu::size_ForBoldHardwareSettingsWarningMessage };
	g.setFont(boldMessageFont);
	g.drawMultiLineText(msg, componentOutline_x, 194, componentOutline_w, Justification::centred, 2.0f);

	msg =  "1) Check the hardware connections: the Mopho's MIDI out port should connect to a MIDI\n";
	msg += "in port on your computer, and the Mopho's MIDI in port should be connected to a MIDI out\n";
	msg += "port on your computer. In the Mopho hardware's Global Parameters menus, confirm that\n";
	msg += "MIDI SysEx is set to \"On\" and that MIDI OutSel is set to \"Out.\"\n";
	msg += "\n";
	msg += "2) Check the input/output routing for the track this plugin is installed on. Ensure that the\n";
	msg += "MIDI in port which is receiving messages from the Mopho hardware is routed to the plugin's\n";
	msg += "input, and that the plugin's output is routed to the MIDI out port sending messages to the\n";
	msg += "Mopho. Make sure that input monitoring is enabled for the track and that MIDI output isn't\n";
	msg += "muted or disabled. Make sure that the host is not filtering out system exclusive messages.";
	Font messageFont{ FontsMenu::family_Global, FontsMenu::style_ForHardwareSettingsWarningMessage, FontsMenu::size_ForHardwareSettingsWarningMessage };
	g.setFont(messageFont);
	g.drawMultiLineText(msg, 421, 270, 438, Justification::left, 2.0f);

	msg =  "Click the Retry button to send a new data dump request to the hardware.\n";
	msg += "If a  valid reply is received, this warning window will close automatically.";
	g.setFont(boldMessageFont);
	g.drawMultiLineText(msg, componentOutline_x, 424, componentOutline_w, Justification::centred, 2.0f);
}

void SysExIsOffWarningComponent::resized() {
	auto button_w{ 50 };
	auto button_h{ 21 };
	button_ForClosingComponent.setBounds(830, 150, button_w, button_h);
	button_ForSendingGlobalParametersDumpRequest.setBounds(612, 449, button_w, button_h);
}

SysExIsOffWarningComponent::~SysExIsOffWarningComponent() {
}
