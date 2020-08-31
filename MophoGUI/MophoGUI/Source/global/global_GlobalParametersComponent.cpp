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
	nrpnType_SysExOn{ 395 },
	button_ForClosingGlobalParameters{ "CLOSE" },
	knob_ForGlobalTranspose{ unexposedParams },
	valueDisplay_ForGlobalTranspose{&knob_ForGlobalTranspose, IntToGlobalTransposeString::get() },
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
	auto knobLabelRow1_y{ 174 };
	auto knobLabelRow2_y{ 183 };
	auto spaceBetweenKnobs{ 75 };
	auto knobLabelCol1_x{ 528 };
	auto knobLabelCol2_x{ knobLabelCol1_x + spaceBetweenKnobs };
	auto knobLabelCol3_x{ knobLabelCol2_x + spaceBetweenKnobs };
	g.drawFittedText("MASTER", knobLabelCol1_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("TRANSPOSE", knobLabelCol1_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MASTER", knobLabelCol2_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("FINE TUNE", knobLabelCol2_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("MIDI", knobLabelCol3_x, knobLabelRow1_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
	g.drawFittedText("CHANNEL", knobLabelCol3_x, knobLabelRow2_y, knobLabel_w, knobLabel_h, Justification::centred, 1, 1.0f);
}

void GlobalParametersComponent::resized() {
	button_ForClosingGlobalParameters.setBounds(703, 108, 50, 21);
	const int knobDiameter{ 40 };
	const int knobRow_y{ 138 };
	knob_ForGlobalTranspose.setBounds(543, knobRow_y, knobDiameter, knobDiameter);
	valueDisplay_ForGlobalTranspose.setBounds(543, knobRow_y, knobDiameter, knobDiameter);
	const int togglesDiameter{ 14 };
	const int toggles_x{ 679 };
	toggle_ForSysEx.setBounds(toggles_x, 295, togglesDiameter, togglesDiameter);
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
}

void GlobalParametersComponent::editorShown(Label* label, TextEditor& editor) {
}

void GlobalParametersComponent::labelTextChanged(Label* label) {
}

void GlobalParametersComponent::sliderValueChanged(Slider* slider) {
	if (slider == &knob_ForGlobalTranspose) {
		auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		globalAudioOptions->setGlobalTranspose(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, nrpnType_GlobalTranspose);
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
	knob_ForGlobalTranspose.removeListener(this);
	toggle_ForSysEx.removeListener(this);
}
