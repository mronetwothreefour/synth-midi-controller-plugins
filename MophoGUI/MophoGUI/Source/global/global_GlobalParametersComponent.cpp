#include "global_GlobalParametersComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_NRPNbufferWithLeadingMSBs.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



GlobalParametersComponent::GlobalParametersComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	nrpnType_GlobalTranspose{ 384 },
	nrpnType_GlobalFineTune{ 385 },
	nrpnType_GlobalMidiChannel{ 386 },
	nrpnType_MidiClock{ 388 },
	nrpnType_ParameterSendType{ 390 },
	nrpnType_ProgramChange{ 392 },
	nrpnType_PedalMode{ 396 },
	button_ForClosingGlobalParameters{ "CLOSE" },
	knob_ForGlobalTranspose{ unexposedParams },
	valueDisplay_ForGlobalTranspose{&knob_ForGlobalTranspose, IntToGlobalTransposeString::get() },
	knob_ForGlobalFineTune{ unexposedParams },
	valueDisplay_ForGlobalFineTune{&knob_ForGlobalFineTune, IntToFineTuneString::get() },
	knob_ForGlobalMidiChannel{ unexposedParams },
	valueDisplay_ForGlobalMidiChannel{&knob_ForGlobalMidiChannel, IntToGlobalMidiChannelString::get() },
	comboBox_ForMidiClock{ unexposedParams },
	comboBox_ForPedalMode{ unexposedParams },
	comboBox_ForProgramChange{ unexposedParams },
	comboBox_ForParameterSend{ unexposedParams },
	displayLabel_ForParameterReceive{ unexposedParams },
	displayLabel_ForMidiControllers{ unexposedParams },
	displayLabel_ForForSysEx{ unexposedParams },
	displayLabel_ForAudioOutput{ unexposedParams },
	displayLabel_ForBalanceTweak{ unexposedParams },
	toggle_ForDescriptionTooltip{ unexposedParams },
	toggle_ForCurrentSettingTooltip{ unexposedParams },
	label_ForSettingTooltipDelay{ unexposedParams }
{
	addAndMakeVisible(button_ForClosingGlobalParameters);
	button_ForClosingGlobalParameters.onClick = [this] { hideThisComponent(); };

	knob_ForGlobalTranspose.addListener(this);
	knob_ForGlobalTranspose.setMouseDragSensitivity(90);
	knob_ForGlobalTranspose.setComponentID(ID::component_Knob.toString());
	addAndMakeVisible(knob_ForGlobalTranspose);
	addAndMakeVisible(valueDisplay_ForGlobalTranspose);
	valueDisplay_ForGlobalTranspose.setInterceptsMouseClicks(false, false);

	knob_ForGlobalFineTune.addListener(this);
	knob_ForGlobalFineTune.setMouseDragSensitivity(105);
	knob_ForGlobalFineTune.setComponentID(ID::component_Knob.toString());
	addAndMakeVisible(knob_ForGlobalFineTune);
	addAndMakeVisible(valueDisplay_ForGlobalFineTune);
	valueDisplay_ForGlobalFineTune.setInterceptsMouseClicks(false, false);

	knob_ForGlobalMidiChannel.addListener(this);
	knob_ForGlobalMidiChannel.setMouseDragSensitivity(90);
	knob_ForGlobalMidiChannel.setComponentID(ID::component_Knob.toString());
	addAndMakeVisible(knob_ForGlobalMidiChannel);
	addAndMakeVisible(valueDisplay_ForGlobalMidiChannel);
	valueDisplay_ForGlobalMidiChannel.setInterceptsMouseClicks(false, false);

	comboBox_ForMidiClock.addListener(this);
	addAndMakeVisible(comboBox_ForMidiClock);

	comboBox_ForPedalMode.addListener(this);
	addAndMakeVisible(comboBox_ForPedalMode);

	comboBox_ForProgramChange.addListener(this);
	addAndMakeVisible(comboBox_ForProgramChange);

	comboBox_ForParameterSend.addListener(this);
	addAndMakeVisible(comboBox_ForParameterSend);

	addAndMakeVisible(displayLabel_ForParameterReceive);
	addAndMakeVisible(displayLabel_ForMidiControllers);
	addAndMakeVisible(displayLabel_ForForSysEx);
	addAndMakeVisible(displayLabel_ForAudioOutput);
	addAndMakeVisible(displayLabel_ForBalanceTweak);

	toggle_ForDescriptionTooltip.addListener(this);
	addAndMakeVisible(toggle_ForDescriptionTooltip);

	toggle_ForCurrentSettingTooltip.addListener(this);
	addAndMakeVisible(toggle_ForCurrentSettingTooltip);

	label_ForSettingTooltipDelay.addListener(this);
	addAndMakeVisible(label_ForSettingTooltipDelay);

	setSize(1273, 626);
}

void GlobalParametersComponent::hideThisComponent() {
	setVisible(false);
}

void GlobalParametersComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 245 };
	auto componentOutline_h{ 396 };
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
	Rectangle<int> componentLabelArea{ 525, 121, 165, 21 };
	g.drawText("GLOBAL PARAMETERS", componentLabelArea, Justification::left, false);

	Font controlLabelFont{ FontsDB::family_Global, FontsDB::style_ForControlLabels, FontsDB::size_ForControlLabels };
	g.setFont(controlLabelFont);
	auto knobLabels_w{ 70 };
	auto comboBoxLabels_w{ 111 };
	auto tooltipLabels_w{ 158 };
	auto labels_h{ 16 };
	auto knobLabels_h{ 14 };
	auto knobLabelRow1_y{ 189 };
	auto knobLabelRow2_y{ knobLabelRow1_y + 9 };
	auto horizSpaceBetweenKnobs{ 75 };
	auto knobLabelCol1_x{ 527 };
	auto knobLabelCol2_x{ knobLabelCol1_x + horizSpaceBetweenKnobs };
	auto knobLabelCol3_x{ knobLabelCol2_x + horizSpaceBetweenKnobs };
	auto comboBoxAndToggleLabels_x{ componentOutline_x };
	auto vertSpaceBetweenLabels{ 20 };
	auto labelRow1_y{ 226 };
	auto labelRow2_y{ labelRow1_y + vertSpaceBetweenLabels };
	auto labelRow3_y{ labelRow2_y + vertSpaceBetweenLabels };
	auto labelRow4_y{ labelRow3_y + vertSpaceBetweenLabels };
	auto labelRow5_y{ 421 };
	auto labelRow6_y{ labelRow5_y + vertSpaceBetweenLabels };
	auto labelRow7_y{ labelRow6_y + vertSpaceBetweenLabels };
	auto labelRow8_y{ labelRow7_y + vertSpaceBetweenLabels };
	g.drawFittedText("MASTER", knobLabelCol1_x, knobLabelRow1_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("TRANSPOSE", knobLabelCol1_x, knobLabelRow2_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MASTER", knobLabelCol2_x, knobLabelRow1_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("FINE TUNE", knobLabelCol2_x, knobLabelRow2_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MIDI", knobLabelCol3_x, knobLabelRow1_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("CHANNEL", knobLabelCol3_x, knobLabelRow2_y, knobLabels_w, knobLabels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MIDI CLOCK", comboBoxAndToggleLabels_x, labelRow1_y, comboBoxLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PEDAL MODE", comboBoxAndToggleLabels_x, labelRow2_y, comboBoxLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PROGRAM CHANGE", comboBoxAndToggleLabels_x, labelRow3_y, comboBoxLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PARAMETER SEND", comboBoxAndToggleLabels_x, labelRow4_y, comboBoxLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("TOOLTIPS FOR GUI CONTROLS:", comboBoxAndToggleLabels_x, labelRow5_y, componentOutline_w, labels_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("SHOW DESCRIPTION", comboBoxAndToggleLabels_x, labelRow6_y, tooltipLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("SHOW CURRENT SETTING", comboBoxAndToggleLabels_x, labelRow7_y, tooltipLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("DELAY BEFORE SHOWING", comboBoxAndToggleLabels_x, labelRow8_y, tooltipLabels_w, labels_h, Justification::centredRight, 1, 1.0f);
}

void GlobalParametersComponent::resized() {
	button_ForClosingGlobalParameters.setBounds(703, 121, 50, 21);
	auto knobDiameter{ 40 };
	auto comboBox_w{ 117 };
	auto displayLabel_w{ 245 };
	auto comboBoxAndDisplayLabel_h{ 16 };
	auto togglesDiameter{ 16 };
	auto horizSpaceBetweenKnobs{ 75 };
	auto knobCol1_x{ 542 };
	auto knobCol2_x{ knobCol1_x + horizSpaceBetweenKnobs };
	auto knobCol3_x{ knobCol2_x + horizSpaceBetweenKnobs };
	auto knobRow_y{ 153 };
	auto vertSpaceBetweenControls{ 20 };
	auto controlRow1_y{ 226 };
	auto controlRow2_y{ controlRow1_y + vertSpaceBetweenControls };
	auto controlRow3_y{ controlRow2_y + vertSpaceBetweenControls };
	auto controlRow4_y{ controlRow3_y + vertSpaceBetweenControls };
	auto controlRow5_y{ 311 };
	auto controlRow6_y{ controlRow5_y + vertSpaceBetweenControls };
	auto controlRow7_y{ controlRow6_y + vertSpaceBetweenControls };
	auto controlRow8_y{ controlRow7_y + vertSpaceBetweenControls };
	auto controlRow9_y{ controlRow8_y + vertSpaceBetweenControls };
	auto controlRow10_y{ 441 };
	auto controlRow11_y{ controlRow10_y + vertSpaceBetweenControls };
	auto controlRow12_y{ controlRow11_y + vertSpaceBetweenControls };
	auto comboBoxes_x{ 630 };
	auto displayLabels_x{ 514 };
	auto tooltipControls_x{ 678 };
	knob_ForGlobalTranspose.setBounds(knobCol1_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalTranspose.setBounds(knobCol1_x, knobRow_y, knobDiameter, knobDiameter);
	knob_ForGlobalFineTune.setBounds(knobCol2_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalFineTune.setBounds(knobCol2_x, knobRow_y, knobDiameter, knobDiameter);
	knob_ForGlobalMidiChannel.setBounds(knobCol3_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalMidiChannel.setBounds(knobCol3_x, knobRow_y, knobDiameter, knobDiameter);
	comboBox_ForMidiClock.setBounds(comboBoxes_x, controlRow1_y, comboBox_w, comboBoxAndDisplayLabel_h);
	comboBox_ForPedalMode.setBounds(comboBoxes_x, controlRow2_y, comboBox_w, comboBoxAndDisplayLabel_h);
	comboBox_ForProgramChange.setBounds(comboBoxes_x, controlRow3_y, comboBox_w, comboBoxAndDisplayLabel_h);
	comboBox_ForParameterSend.setBounds(comboBoxes_x, controlRow4_y, comboBox_w, comboBoxAndDisplayLabel_h);
	displayLabel_ForParameterReceive.setBounds(displayLabels_x, controlRow5_y, displayLabel_w, comboBoxAndDisplayLabel_h);
	displayLabel_ForMidiControllers.setBounds(displayLabels_x, controlRow6_y, displayLabel_w, comboBoxAndDisplayLabel_h);
	displayLabel_ForForSysEx.setBounds(displayLabels_x, controlRow7_y, displayLabel_w, comboBoxAndDisplayLabel_h);
	displayLabel_ForAudioOutput.setBounds(displayLabels_x, controlRow8_y, displayLabel_w, comboBoxAndDisplayLabel_h);
	displayLabel_ForBalanceTweak.setBounds(displayLabels_x, controlRow9_y, displayLabel_w, comboBoxAndDisplayLabel_h);
	toggle_ForDescriptionTooltip.setBounds(tooltipControls_x, controlRow10_y, togglesDiameter, togglesDiameter);
	toggle_ForCurrentSettingTooltip.setBounds(tooltipControls_x, controlRow11_y, togglesDiameter, togglesDiameter);
	label_ForSettingTooltipDelay.setBounds(tooltipControls_x, controlRow12_y, 50, 16);
}

void GlobalParametersComponent::buttonClicked(Button* button) {
	if (button == &toggle_ForDescriptionTooltip) {
		auto stateIsOn{ button->getToggleState() };
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (stateIsOn)
			tooltipOptions->setShouldShowDescription();
		else
			tooltipOptions->setShouldNotShowDescription();
	}
	if (button == &toggle_ForCurrentSettingTooltip) {
		auto stateIsOn{ button->getToggleState() };
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (stateIsOn)
			tooltipOptions->setShouldShowCurrentValue();
		else
			tooltipOptions->setShouldNotShowCurrentValue();
	}
}

void GlobalParametersComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox == &comboBox_ForMidiClock) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setClockType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_MidiClock);
	}
	if (comboBox == &comboBox_ForPedalMode) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterReceiveType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_PedalMode);
	}
	if (comboBox == &comboBox_ForProgramChange) {
		auto isOn{ (bool)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (isOn)
			midiOptions->setProgramChangeOn();
		else
			midiOptions->setProgramChangeOff();
		sendNewValueForNRPNtypeToOutgoingMidiBuffers((uint8)isOn, nrpnType_ProgramChange);
	}
	if (comboBox == &comboBox_ForParameterSend) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterSendType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_ParameterSendType);
	}
}

void GlobalParametersComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_ForSettingTooltipDelay) {
		editor.setInputRestrictions(4, "0123456789");
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		Font labelFont{ FontsDB::family_Global, FontsDB::style_ForLabelText, FontsDB::size_ForLabelText };
		editor.setFont(labelFont);
		editor.setText((String)tooltipOptions->delayInMilliseconds());
		editor.selectAll();
	}
}

void GlobalParametersComponent::labelTextChanged(Label* label) {
	if (label == &label_ForSettingTooltipDelay) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue < 5001)
				tooltipOptions->setDelayInMilliseconds(newValue);
		}
		label->setText((String)tooltipOptions->delayInMilliseconds() + " ms", dontSendNotification);
	}
}

void GlobalParametersComponent::sliderValueChanged(Slider* slider) {
	if (slider == &knob_ForGlobalTranspose) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
		globalAudioOptions->setGlobalTranspose(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, nrpnType_GlobalTranspose);
	}
	if (slider == &knob_ForGlobalFineTune) {
		auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		globalAudioOptions->setGlobalFineTune(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, nrpnType_GlobalFineTune);
	}
	if (slider == &knob_ForGlobalMidiChannel) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		midiOptions->setHardwareReceiveChannel(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, nrpnType_GlobalMidiChannel);
		if (currentKnobValue == 0)
			midiOptions->setTransmitChannel(currentKnobValue);
		else
			midiOptions->setTransmitChannel(currentKnobValue - 1);
	}
}

void GlobalParametersComponent::sendNewValueForNRPNtypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType) {
	auto midiOptions{ unexposedParams->midiOptions_get() };
	auto channel{ midiOptions->transmitChannel() };
	auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(channel, nrpnType, newValue) };
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	outgoingMidiBuffers->aggregateOutgoingMidiBuffers(nrpnBuffer);
}

void GlobalParametersComponent::timerCallback() {
}

GlobalParametersComponent::~GlobalParametersComponent() {
	label_ForSettingTooltipDelay.removeListener(this);
	toggle_ForCurrentSettingTooltip.removeListener(this);
	toggle_ForDescriptionTooltip.removeListener(this);
	comboBox_ForParameterSend.removeListener(this);
	comboBox_ForProgramChange.removeListener(this);
	comboBox_ForPedalMode.removeListener(this);
	comboBox_ForMidiClock.removeListener(this);
	knob_ForGlobalMidiChannel.removeListener(this);
	knob_ForGlobalFineTune.removeListener(this);
	knob_ForGlobalTranspose.removeListener(this);
}
