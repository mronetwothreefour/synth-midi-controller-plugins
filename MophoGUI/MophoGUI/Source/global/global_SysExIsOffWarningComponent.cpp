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
	auto componentOutline_h{ 306 };
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
	Rectangle<int> componentLabelArea{ componentOutline_x, 174, componentOutline_w, 21 };
	g.drawText("COMMUNICATION ERROR!", componentLabelArea, Justification::centred, false);

	String msg{ "" };
	msg += "This plugin attempted to request a Global Parameters data dump from the\n";
	msg += "hardware via MIDI system exclusive messages, but a reply was not received.\n";
	msg += "System exclusive communication is needed for this plugin to function correctly.\n";
	msg += "\n";
	msg += "Here are some possible fixes:\n";
	Font boldMessageFont{ FontsDB::family_Global, FontsDB::style_ForBoldHardwareSettingsWarningMessage, FontsDB::size_ForBoldHardwareSettingsWarningMessage };
	g.setFont(boldMessageFont);
	g.drawMultiLineText(msg, componentOutline_x, 215, componentOutline_w, Justification::centred, 2.0f);

	msg =  "1) Check the hardware connections and the input/output routing for the track this plugin\n";
	msg += "is installed on. Ensure that the track is sending MIDI to the hardware's MIDI input and\n";
	msg += "receiving MIDI from the hardware's MIDI output. Also, make sure that input monitoring\n";
	msg += "is enabled for the track and that MIDI output isn't muted or disabled.\n";
	msg += "\n";
	msg += "2) In the hardware's Global Parameters menus, make sure that MIDI SysEx is set to \"On\"\n";
	msg += "and that MIDI OutSel is set to \"Out.\"";
	Font messageFont{ FontsDB::family_Global, FontsDB::style_ForHardwareSettingsWarningMessage, FontsDB::size_ForHardwareSettingsWarningMessage };
	g.setFont(messageFont);
	g.drawMultiLineText(msg, 421, 292, 438, Justification::left, 2.0f);

	msg =  "Click the Retry button to send a new data dump request to the hardware.\n";
	msg += "If a  valid reply is received, this warning window will automatically close.";
	g.setFont(boldMessageFont);
	g.drawMultiLineText(msg, componentOutline_x, 403, componentOutline_w, Justification::centred, 2.0f);
}

void SysExIsOffWarningComponent::resized() {
	auto button_w{ 50 };
	auto button_h{ 21 };
	button_ForClosingComponent.setBounds(830, 167, button_w, button_h);
	button_ForSendingGlobalParametersDumpRequest.setBounds(612, 430, button_w, button_h);
}

SysExIsOffWarningComponent::~SysExIsOffWarningComponent() {
}
