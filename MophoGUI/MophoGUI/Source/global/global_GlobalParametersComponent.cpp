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
	nrpnType_ParameterReceiveType{ 389 },
	nrpnType_SysExOn{ 395 },
	button_ForClosingGlobalParameters{ "CLOSE" },
	knob_ForGlobalTranspose{ unexposedParams },
	valueDisplay_ForGlobalTranspose{&knob_ForGlobalTranspose, IntToGlobalTransposeString::get() },
	knob_ForGlobalFineTune{ unexposedParams },
	valueDisplay_ForGlobalFineTune{&knob_ForGlobalFineTune, IntToFineTuneString::get() },
	knob_ForGlobalMidiChannel{ unexposedParams },
	valueDisplay_ForGlobalMidiChannel{&knob_ForGlobalMidiChannel, IntToGlobalMidiChannelString::get() },
	comboBox_ForMidiClock{ unexposedParams },
	comboBox_ForParameterSend{ unexposedParams },
	comboBox_ForParameterReceive{ unexposedParams },
	toggle_ForSysEx{ unexposedParams }
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

	comboBox_ForParameterSend.addListener(this);
	addAndMakeVisible(comboBox_ForParameterSend);

	comboBox_ForParameterReceive.addListener(this);
	addAndMakeVisible(comboBox_ForParameterReceive);

	toggle_ForSysEx.addListener(this);
	addAndMakeVisible(toggle_ForSysEx);

	setSize(1273, 626);
}

void GlobalParametersComponent::hideThisComponent() {
	setVisible(false);
}

void GlobalParametersComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	g.setColour(Color::black);
	auto componentOutline_w{ 245 };
	auto componentOutline_h{ 422 };
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
	Rectangle<int> componentLabelArea{ 525, 108, 165, 21 };
	g.drawText("GLOBAL PARAMETERS", componentLabelArea, Justification::left, false);

	Font controlLabelFont{ FontsDB::family_Global, FontsDB::style_ForControlLabels, FontsDB::size_ForControlLabels };
	g.setFont(controlLabelFont);
	auto knobLabel_w{ 70 };
	auto knobLabel_h{ 14 };
	auto comboBoxLabel_w{ 100 };
	auto toggleLabel_w{ 148 };
	auto comboBoxAndToggleLabel_h{ 16 };
	auto knobLabelRow1_y{ 174 };
	auto knobLabelRow2_y{ 183 };
	auto horizSpaceBetweenKnobs{ 75 };
	auto knobLabelCol1_x{ 528 };
	auto knobLabelCol2_x{ knobLabelCol1_x + horizSpaceBetweenKnobs };
	auto knobLabelCol3_x{ knobLabelCol2_x + horizSpaceBetweenKnobs };
	auto comboBoxAndToggleLabels_x{ 524 };
	auto vertSpaceBetweenComboBoxesAndToggles{ 20 };
	auto comboBoxLabel1_y{ 213 };
	auto comboBoxLabel2_y{ comboBoxLabel1_y + vertSpaceBetweenComboBoxesAndToggles };
	auto comboBoxLabel3_y{ comboBoxLabel2_y + vertSpaceBetweenComboBoxesAndToggles };
	auto comboBoxLabel4_y{ comboBoxLabel3_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleLabel1_y{ comboBoxLabel4_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleLabel2_y{ toggleLabel1_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleLabel3_y{ toggleLabel2_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleLabel4_y{ toggleLabel3_y + vertSpaceBetweenComboBoxesAndToggles };
	g.drawFittedText("MASTER", knobLabelCol1_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("TRANSPOSE", knobLabelCol1_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MASTER", knobLabelCol2_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("FINE TUNE", knobLabelCol2_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MIDI", knobLabelCol3_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("CHANNEL", knobLabelCol3_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MIDI CLOCK", comboBoxAndToggleLabels_x, comboBoxLabel1_y, comboBoxLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PARAM. SEND", comboBoxAndToggleLabels_x, comboBoxLabel2_y, comboBoxLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PARAM. RECEIVE", comboBoxAndToggleLabels_x, comboBoxLabel3_y, comboBoxLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PEDAL MODE", comboBoxAndToggleLabels_x, comboBoxLabel4_y, comboBoxLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("MIDI SYSTEM EXCLUSIVE", comboBoxAndToggleLabels_x, toggleLabel1_y, toggleLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("MIDI CONTROLLERS", comboBoxAndToggleLabels_x, toggleLabel2_y, toggleLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("STEREO OUTPUT", comboBoxAndToggleLabels_x, toggleLabel3_y, toggleLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
	g.drawFittedText("PROGRAM CHANGE", comboBoxAndToggleLabels_x, toggleLabel4_y, toggleLabel_w, comboBoxAndToggleLabel_h, Justification::centredRight, 1, 1.0f);
}

void GlobalParametersComponent::resized() {
	button_ForClosingGlobalParameters.setBounds(703, 108, 50, 21);
	auto knobDiameter{ 40 };
	auto comboBox_w{ 115 };
	auto comboBox_h{ 16 };
	auto togglesDiameter{ 14 };
	auto horizSpaceBetweenKnobs{ 75 };
	auto knobCol1_x{ 543 };
	auto knobCol2_x{ knobCol1_x + horizSpaceBetweenKnobs };
	auto knobCol3_x{ knobCol2_x + horizSpaceBetweenKnobs };
	auto knobRow_y{ 138 };
	auto vertSpaceBetweenComboBoxesAndToggles{ 20 };
	auto comboBoxRow1_y{ 213 };
	auto comboBoxRow2_y{ comboBoxRow1_y + vertSpaceBetweenComboBoxesAndToggles };
	auto comboBoxRow3_y{ comboBoxRow2_y + vertSpaceBetweenComboBoxesAndToggles };
	auto comboBoxRow4_y{ comboBoxRow3_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleRow1_y{ 294 };
	auto toggleRow2_y{ toggleRow1_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleRow3_y{ toggleRow2_y + vertSpaceBetweenComboBoxesAndToggles };
	auto toggleRow4_y{ toggleRow3_y + vertSpaceBetweenComboBoxesAndToggles };
	auto comboBoxes_x{ 629 };
	auto toggles_x{ 679 };
	knob_ForGlobalTranspose.setBounds(knobCol1_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalTranspose.setBounds(knobCol1_x, knobRow_y, knobDiameter, knobDiameter);
	knob_ForGlobalFineTune.setBounds(knobCol2_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalFineTune.setBounds(knobCol2_x, knobRow_y, knobDiameter, knobDiameter);
	knob_ForGlobalMidiChannel.setBounds(knobCol3_x, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalMidiChannel.setBounds(knobCol3_x, knobRow_y, knobDiameter, knobDiameter);
	comboBox_ForMidiClock.setBounds(comboBoxes_x, comboBoxRow1_y, comboBox_w, comboBox_h);
	comboBox_ForParameterSend.setBounds(comboBoxes_x, comboBoxRow2_y, comboBox_w, comboBox_h);
	comboBox_ForParameterReceive.setBounds(comboBoxes_x, comboBoxRow3_y, comboBox_w, comboBox_h);
	toggle_ForSysEx.setBounds(toggles_x, toggleRow1_y, togglesDiameter, togglesDiameter);
}

void GlobalParametersComponent::buttonClicked(Button* button) {
	if (button == &toggle_ForSysEx) {
		auto stateIsOn{ button->getToggleState() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (stateIsOn)
			midiOptions->setSysExOn();
		else
			midiOptions->setSysExOff();
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(stateIsOn ? 1 : 0, nrpnType_SysExOn);
	}
}

void GlobalParametersComponent::comboBoxChanged(ComboBox* comboBox) {
	if (comboBox == &comboBox_ForMidiClock) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setClockType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_MidiClock);
	}
	if (comboBox == &comboBox_ForParameterSend) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterSendType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_ParameterSendType);
	}
	if (comboBox == &comboBox_ForParameterReceive) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterReceiveType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, nrpnType_ParameterReceiveType);
	}
}

void GlobalParametersComponent::editorShown(Label* label, TextEditor& editor) {
}

void GlobalParametersComponent::labelTextChanged(Label* label) {
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

void GlobalParametersComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
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
	toggle_ForSysEx.removeListener(this);
	comboBox_ForParameterReceive.removeListener(this);
	comboBox_ForParameterSend.removeListener(this);
	comboBox_ForMidiClock.removeListener(this);
	knob_ForGlobalMidiChannel.removeListener(this);
	knob_ForGlobalFineTune.removeListener(this);
	knob_ForGlobalTranspose.removeListener(this);
}
