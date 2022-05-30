#include "2_global_gui_layer_GlobalParams.h"

#include "0_global_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/0_midi_NRPNbufferWithLeadingMSBs.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;



GUI_Layer_GlobalParameters::GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_Close{ unexposedParams },
	knob_GlobalTranspose{ GlobalParamKnobType::globalTranspose, unexposedParams },
	knob_GlobalFineTune{ GlobalParamKnobType::globalFineTune, unexposedParams },
	knob_HardwareReceiveChannel{ GlobalParamKnobType::hardwareReceiveChannel, unexposedParams },
	comboBox_MIDI_ClockSource{ GlobalParamComboBoxType::midiClockSource, unexposedParams },
	comboBox_PedalMode{ GlobalParamComboBoxType::pedalMode, unexposedParams },
	comboBox_VoiceChange{ GlobalParamComboBoxType::voiceChange, unexposedParams },
	comboBox_ParamChangeSendType{ GlobalParamComboBoxType::paramChangeSendType, unexposedParams },
	toggle_CurrentValueTooltip{ GlobalParamToggleType::currentValueTooltip, unexposedParams },
	toggle_DescriptionTooltip{ GlobalParamToggleType::descriptionTooltip, unexposedParams }
{
	addAndMakeVisible(button_Close);

	knob_GlobalTranspose.addListener(this);
	addAndMakeVisible(knob_GlobalTranspose);

	knob_GlobalFineTune.addListener(this);
	addAndMakeVisible(knob_GlobalFineTune);

	knob_HardwareReceiveChannel.addListener(this);
	addAndMakeVisible(knob_HardwareReceiveChannel);

	comboBox_MIDI_ClockSource.addListener(this);
	addAndMakeVisible(comboBox_MIDI_ClockSource);

	comboBox_PedalMode.addListener(this);
	addAndMakeVisible(comboBox_PedalMode);

	comboBox_VoiceChange.addListener(this);
	addAndMakeVisible(comboBox_VoiceChange);

	comboBox_ParamChangeSendType.addListener(this);
	addAndMakeVisible(comboBox_ParamChangeSendType);

	toggle_CurrentValueTooltip.addListener(this);
	addAndMakeVisible(toggle_CurrentValueTooltip);

	toggle_DescriptionTooltip.addListener(this);
	addAndMakeVisible(toggle_DescriptionTooltip);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_GlobalParameters::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_GlobalParams_png, (size_t)BinaryData::bkgrnd_GlobalParams_png, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 514, 115);

	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.setColour(GUI::color_White);
	auto concise{ (bool)false };
	auto currentChoice{ 0 };
	String choiceName{ "" };

	currentChoice = roundToInt(knob_GlobalTranspose.getValue());
	choiceName = ChoiceName::buildFor_GlobalTranspose(currentChoice, concise);
	g.drawText(choiceName, knob_GlobalTranspose.getBounds(), Justification::centred);

	currentChoice = roundToInt(knob_GlobalFineTune.getValue());
	choiceName = ChoiceName::buildFor_GlobalFineTune(currentChoice, concise);
	g.drawText(choiceName, knob_GlobalFineTune.getBounds(), Justification::centred);

	currentChoice = roundToInt(knob_HardwareReceiveChannel.getValue());
	choiceName = ChoiceName::buildFor_HardwareReceiveChannel(currentChoice, concise);
	g.drawText(choiceName, knob_HardwareReceiveChannel.getBounds(), Justification::centred);
}

void GUI_Layer_GlobalParameters::resized() {
	button_Close.setBounds(703, 121, button_Close.getWidth(), button_Close.getWidth());
	const int knobRow_y{ 153 };
	knob_GlobalTranspose.setBounds(542, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
	knob_GlobalFineTune.setBounds(617, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
	knob_HardwareReceiveChannel.setBounds(692, knobRow_y, GUI::knob_diameter, GUI::knob_diameter);
	const int comboBoxes_x{ 630 };
	const auto comboBoxes_w{ comboBox_MIDI_ClockSource.getWidth() };
	comboBox_MIDI_ClockSource.setBounds(comboBoxes_x, 226, comboBoxes_w, GUI::comboBox_h);
	comboBox_PedalMode.setBounds(comboBoxes_x, 246, comboBoxes_w, GUI::comboBox_h);
	comboBox_VoiceChange.setBounds(comboBoxes_x, 266, comboBoxes_w, GUI::comboBox_h);
	comboBox_ParamChangeSendType.setBounds(comboBoxes_x, 286, comboBoxes_w, GUI::comboBox_h);
	const int tooltipControls_x{ 678 };
	toggle_CurrentValueTooltip.setBounds(tooltipControls_x, 441, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_DescriptionTooltip.setBounds(tooltipControls_x, 461, GUI::toggle_diameter, GUI::toggle_diameter);
}

void GUI_Layer_GlobalParameters::buttonClicked(Button* button) {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShow{ button->getToggleState() };
	if (button == &toggle_CurrentValueTooltip) {
		if (shouldShow)
			tooltipOptions->setShouldShowCurrentValue();
		else
			tooltipOptions->setShouldNotShowCurrentValue();
	}
	if (button == &toggle_DescriptionTooltip) {
		if (shouldShow)
			tooltipOptions->setShouldShowDescription();
		else
			tooltipOptions->setShouldNotShowDescription();
	}
}

void GUI_Layer_GlobalParameters::comboBoxChanged(ComboBox* comboBox) {
	auto globalOptions{ unexposedParams->getGlobalOptions() };
	auto currentChoice{ comboBox->getSelectedItemIndex() };
	if (comboBox == &comboBox_MIDI_ClockSource) {
		globalOptions->setMIDI_ClockSource(MIDI_ClockSource{ currentChoice });
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers((uint8)currentChoice, GP::nrpnType_MIDI_ClockSource);
	}
	if (comboBox == &comboBox_PedalMode) {
		if (currentChoice == 0)
			globalOptions->setPedalModeToNormal();
		else
			globalOptions->setPedalModeToArpLatch();
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers((uint8)currentChoice, GP::nrpnType_PedalMode);
	}
	if (comboBox == &comboBox_VoiceChange) {
		if (currentChoice == 0)
			globalOptions->setVoiceChangeDisabled();
		else
			globalOptions->setVoiceChangeEnabled();
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers((uint8)currentChoice, GP::nrpnType_VoiceChange);
	}
	if (comboBox == &comboBox_ParamChangeSendType) {
		globalOptions->setParamChangeSendType(ParamChangeSendType{ currentChoice });
		sendNewValueForNRPN_TypeToOutgoingMidiBuffers((uint8)currentChoice, GP::nrpnType_ParamChangeSendType);
	}
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

GUI_Layer_GlobalParameters::~GUI_Layer_GlobalParameters() {
	knob_GlobalTranspose.removeListener(this);
	knob_GlobalFineTune.removeListener(this);
	knob_HardwareReceiveChannel.removeListener(this);
	comboBox_MIDI_ClockSource.removeListener(this);
	comboBox_PedalMode.removeListener(this);
	comboBox_VoiceChange.removeListener(this);
	comboBox_ParamChangeSendType.removeListener(this);
}
