#include "global_2_gui_layer_GlobalParams.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GlobalParameters.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/midi_0_NRPNbufferWithLeadingMSBs.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using ChoiceName = GlobalParamChoiceName;
using ComboBoxType = GlobalParamComboBoxType;
using KnobType = GlobalParamKnobType;
using LabelType = GlobalParamDisplayLabelType;
using ToggleType = GlobalParamToggleType;


GUI_Layer_GlobalParameters::GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	button_Close{ unexposedParams },
	knob_GlobalTranspose{ KnobType::globalTranspose, unexposedParams, undoManager },
	knob_GlobalFineTune{ KnobType::globalFineTune, unexposedParams, undoManager },
	knob_HardwareReceiveChannel{ KnobType::hardwareReceiveChannel, unexposedParams, undoManager },
	comboBox_MIDI_ClockSource{ ComboBoxType::midiClockSource, unexposedParams },
	comboBox_PedalMode{ ComboBoxType::pedalMode, unexposedParams },
	comboBox_VoiceChange{ ComboBoxType::voiceChanges, unexposedParams },
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
	button_Close.setTopLeftPosition(703, 121);
	addAndMakeVisible(button_Close);

	const int knobRow_y{ 153 };
	knob_GlobalTranspose.setTopLeftPosition(542, knobRow_y);
	addAndMakeVisible(knob_GlobalTranspose);
	knob_GlobalFineTune.setTopLeftPosition(617, knobRow_y);
	addAndMakeVisible(knob_GlobalFineTune);
	knob_HardwareReceiveChannel.setTopLeftPosition(692, knobRow_y);
	addAndMakeVisible(knob_HardwareReceiveChannel);

	const int comboBoxes_x{ 630 };
	comboBox_MIDI_ClockSource.setTopLeftPosition(comboBoxes_x, 226);
	addAndMakeVisible(comboBox_MIDI_ClockSource);
	comboBox_PedalMode.setTopLeftPosition(comboBoxes_x, 246);
	addAndMakeVisible(comboBox_PedalMode);
	comboBox_VoiceChange.setTopLeftPosition(comboBoxes_x, 266);
	addAndMakeVisible(comboBox_VoiceChange);
	comboBox_ParamChangeSendType.setTopLeftPosition(comboBoxes_x, 286);
	addAndMakeVisible(comboBox_ParamChangeSendType);

	const int displayLabels_x{ 514 };
	label_ParamChangeReceiveType.setTopLeftPosition(displayLabels_x, 311);
	addAndMakeVisible(label_ParamChangeReceiveType);
	label_MIDI_ControllersStatus.setTopLeftPosition(displayLabels_x, 331);
	addAndMakeVisible(label_MIDI_ControllersStatus);
	label_SysExStatus.setTopLeftPosition(displayLabels_x, 351);
	addAndMakeVisible(label_SysExStatus);
	label_AudioOutput.setTopLeftPosition(displayLabels_x, 371);
	addAndMakeVisible(label_AudioOutput);
	label_HardwareOutputBalance.setTopLeftPosition(displayLabels_x, 391);
	addAndMakeVisible(label_HardwareOutputBalance);

	const int tooltipControls_x{ 678 };
	toggle_CurrentValueTooltip.setTopLeftPosition(tooltipControls_x, 441);
	addAndMakeVisible(toggle_CurrentValueTooltip);
	toggle_DescriptionTooltip.setTopLeftPosition(tooltipControls_x, 461);
	addAndMakeVisible(toggle_DescriptionTooltip);
	editorForTooltipDelay.setTopLeftPosition(tooltipControls_x, 481);
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

