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
using ComboBoxType = GlobalParamComboBoxType;
using KnobType = GlobalParamKnobType;
using LabelType = GlobalParamDisplayLabelType;
using ToggleType = GlobalParamToggleType;


GUI_Layer_GlobalParameters::GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_Close{ unexposedParams },
	knob_GlobalTranspose{ KnobType::globalTranspose, unexposedParams },
	knob_GlobalFineTune{ KnobType::globalFineTune, unexposedParams },
	knob_HardwareReceiveChannel{ KnobType::hardwareReceiveChannel, unexposedParams },
	comboBox_MIDI_ClockSource{ ComboBoxType::midiClockSource, unexposedParams },
	comboBox_PedalMode{ ComboBoxType::pedalMode, unexposedParams },
	comboBox_VoiceChange{ ComboBoxType::voiceChange, unexposedParams },
	comboBox_ParamChangeSendType{ ComboBoxType::paramChangeSendType, unexposedParams },
	toggle_CurrentValueTooltip{ ToggleType::currentValueTooltip, unexposedParams },
	toggle_DescriptionTooltip{ ToggleType::descriptionTooltip, unexposedParams },
	label_ParamChangeReceiveType{ LabelType::paramChangeReceiveType, unexposedParams },
	label_MIDI_ControllersStatus{ LabelType::midiControllersStatus, unexposedParams },
	label_SysExStatus{ LabelType::sysExStatus, unexposedParams },
	label_AudioOutput{ LabelType::audioOutput, unexposedParams },
	label_HardwareOutputBalance{ LabelType::hardwareOutputBalance, unexposedParams },
	editorForTooltipDelay{ unexposedParams }
{
	addAndMakeVisible(button_Close);

	addAndMakeVisible(knob_GlobalTranspose);
	addAndMakeVisible(knob_GlobalFineTune);
	addAndMakeVisible(knob_HardwareReceiveChannel);

	addAndMakeVisible(comboBox_MIDI_ClockSource);
	addAndMakeVisible(comboBox_PedalMode);
	addAndMakeVisible(comboBox_VoiceChange);
	addAndMakeVisible(comboBox_ParamChangeSendType);

	addAndMakeVisible(label_ParamChangeReceiveType);
	addAndMakeVisible(label_MIDI_ControllersStatus);
	addAndMakeVisible(label_SysExStatus);
	addAndMakeVisible(label_AudioOutput);
	addAndMakeVisible(label_HardwareOutputBalance);

	addAndMakeVisible(toggle_CurrentValueTooltip);
	addAndMakeVisible(toggle_DescriptionTooltip);
	addAndMakeVisible(editorForTooltipDelay);

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
	const int displayLabels_h{ label_ParamChangeReceiveType.getHeight() };
	const int displayLabels_w{ label_ParamChangeReceiveType.getWidth() };
	const int displayLabels_x{ 514 };
	label_ParamChangeReceiveType.setBounds(displayLabels_x, 311, displayLabels_w, displayLabels_h);
	label_MIDI_ControllersStatus.setBounds(displayLabels_x, 331, displayLabels_w, displayLabels_h);
	label_SysExStatus.setBounds(displayLabels_x, 351, displayLabels_w, displayLabels_h);
	label_AudioOutput.setBounds(displayLabels_x, 371, displayLabels_w, displayLabels_h);
	label_HardwareOutputBalance.setBounds(displayLabels_x, 391, displayLabels_w, displayLabels_h);
	const int tooltipControls_x{ 678 };
	toggle_CurrentValueTooltip.setBounds(tooltipControls_x, 441, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_DescriptionTooltip.setBounds(tooltipControls_x, 461, GUI::toggle_diameter, GUI::toggle_diameter);
	editorForTooltipDelay.setBounds(tooltipControls_x, 481, editorForTooltipDelay.getWidth(), GUI::comboBox_h);
}

void GUI_Layer_GlobalParameters::timerCallback() {
}

