#include "2_global_gui_layer_GlobalParams.h"

#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/0_midi_NRPNbufferWithLeadingMSBs.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_GlobalParameters::GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	knob_GlobalTranspose{ GlobalParamKnobType::globalTranspose, unexposedParams },
	knob_GlobalFineTune{ GlobalParamKnobType::globalFineTune, unexposedParams },
	knob_HardwareReceiveChannel{ GlobalParamKnobType::hardwareReceiveChannel, unexposedParams }
{
	button_Close.setComponentID(ID::button_Close.toString());
	button_Close.onClick = [this] { hideThisLayer(); };
	button_Close.addShortcut(KeyPress(KeyPress::escapeKey));
	addAndMakeVisible(button_Close);

	knob_GlobalTranspose.addListener(this);
	addAndMakeVisible(knob_GlobalTranspose);

	knob_GlobalFineTune.addListener(this);
	addAndMakeVisible(knob_GlobalFineTune);

	knob_HardwareReceiveChannel.addListener(this);
	addAndMakeVisible(knob_HardwareReceiveChannel);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_GlobalParameters::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_GlobalParams_png, (size_t)BinaryData::bkgrnd_GlobalParams_png, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 514, 115);
}

void GUI_Layer_GlobalParameters::resized() {
	button_Close.setBounds(703, 121, GUI::button_Close_w, GUI::redButton_h);
	const int knobRow_y{ 153 };
	knob_GlobalTranspose.setBounds(542, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
	knob_GlobalFineTune.setBounds(617, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
	knob_HardwareReceiveChannel.setBounds(692, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
}

void GUI_Layer_GlobalParameters::buttonClicked(Button* button)
{
}

void GUI_Layer_GlobalParameters::comboBoxChanged(ComboBox* comboBox)
{
}

void GUI_Layer_GlobalParameters::editorShown(Label* label, TextEditor& editor)
{
}

void GUI_Layer_GlobalParameters::labelTextChanged(Label* label)
{
}

void GUI_Layer_GlobalParameters::sliderValueChanged(Slider* slider) {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto currentChoice{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &knob_GlobalTranspose) {
		globalOptions->setGlobalTranspose(currentChoice);
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers(currentChoice, GP::nrpnType_GlobalTranspose);
	}
	if (slider == &knob_GlobalFineTune) {
		globalOptions->setGlobalFineTune(currentChoice);
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers(currentChoice, GP::nrpnType_GlobalFineTune);
	}
	if (slider == &knob_HardwareReceiveChannel) {
		globalOptions->setHardwareReceiveChannel(currentChoice);
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers(currentChoice, GP::nrpnType_GlobalMidiChannel);
		if (currentChoice == 0)
			globalOptions->setTransmitChannel(currentChoice);
		else
			globalOptions->setTransmitChannel(currentChoice - 1);
	}
}

void GUI_Layer_GlobalParameters::sendNewValueForNRPN_TypeToOutgoingMidiBuffers(uint8 newValue, uint16 nrpnType) {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto channel{ globalOptions->transmitChannel() };
	auto nrpnBuffer{ NRPNbufferWithLeadingMSBs::from_Channel_NRPNtype_NewValue(channel, nrpnType, newValue) };
	auto outgoingMidiBuffers{ unexposedParams->getOutgoingMidiBuffers() };
	outgoingMidiBuffers->addMidiBuffer(nrpnBuffer);
}

void GUI_Layer_GlobalParameters::timerCallback() {
}

void GUI_Layer_GlobalParameters::hideThisLayer() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

GUI_Layer_GlobalParameters::~GUI_Layer_GlobalParameters() {
	knob_GlobalTranspose.removeListener(this);
	knob_GlobalFineTune.removeListener(this);
	knob_HardwareReceiveChannel.removeListener(this);
}
