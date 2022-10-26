#include "global_4_gui_layer_GlobalParams.h"

#include "global_0_build_ChoiceName.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;
using ChoiceName = GlobalParamChoiceName;
using ComboBoxType = GlobalParamComboBoxType;
using Description = GlobalParamDescription;
using SliderType = GlobalParamSliderType;

GUI_Layer_GlobalParameters::GUI_Layer_GlobalParameters(UnexposedParameters* unexposedParams, UndoManager* undoManager) :
	unexposedParams{ unexposedParams },
	tooltips{ unexposedParams->getTooltipsOptions() },
	undoManager{ undoManager },
	btn_Close{ BorderColor::orange, unexposedParams },
	slider_BasicChannel{ SliderType::basicChannel, unexposedParams },
	comboBox_OmniMode{ ComboBoxType::omniModeOffOn, unexposedParams },
	comboBox_Controllers{ ComboBoxType::controllersOffOn, unexposedParams },
	comboBox_VoiceChanges{ ComboBoxType::voiceChangesOffOn, unexposedParams },
	comboBox_SysEx{ ComboBoxType::sysExOffOn, unexposedParams },
	comboBox_Spillover{ ComboBoxType::spilloverOffOn, unexposedParams },
	comboBox_MIDI_Echo{ ComboBoxType::midiEchoOffOn, unexposedParams },
	comboBox_MIDI_Mono{ ComboBoxType::midiMonoOffOn, unexposedParams },
	comboBox_ActiveSensing{ ComboBoxType::activeSensingOffOn, unexposedParams },
	comboBox_LocalControl{ ComboBoxType::localControlOffOn, unexposedParams },
	slider_Pedal_1_ControllerNum{ SliderType::pedal_1_ControllerNum, unexposedParams },
	slider_Pedal_2_ControllerNum{ SliderType::pedal_2_ControllerNum, unexposedParams },
	slider_Lever_2_ControllerNum{ SliderType::lever_2_ControllerNum, unexposedParams },
	slider_Lever_3_ControllerNum{ SliderType::lever_3_ControllerNum, unexposedParams },
	slider_VibratoSpeed{ SliderType::vibratoSpeed, unexposedParams },
	comboBox_VibratoWaveType{ ComboBoxType::vibratoWaveType, unexposedParams },
	slider_VibratoAmplitude{ SliderType::vibratoAmplitude, unexposedParams },
	comboBox_VibratoSpeedModSource{ ComboBoxType::vibratoSpeedModSource, unexposedParams },
	slider_VibratoSpeedModAmount{ SliderType::vibratoSpeedModAmount, unexposedParams },
	comboBox_VibratoAmpModSource{ ComboBoxType::vibratoAmpModSource, unexposedParams },
	slider_VibratoAmpModAmount{ SliderType::vibratoAmpModAmount, unexposedParams },
	slider_GlobalTune{ SliderType::globalTune, unexposedParams },
	comboBox_SplitStereo{ ComboBoxType::splitStereoOffOn, unexposedParams },
	comboBox_VoiceMap{ ComboBoxType::voiceMapOffOn, unexposedParams },
	comboBox_VoiceMapEcho{ ComboBoxType::voiceMapEchoOffOn, unexposedParams },
	slider_DisplayBrightness{ SliderType::displayBrightness, unexposedParams },
	comboBox_SQUICK{ ComboBoxType::squickOffOn, unexposedParams },
	comboBox_DescriptionTooltip{ ComboBoxType::descriptionTipsOffOn, unexposedParams },
	comboBox_CurrentChoiceTooltip{ ComboBoxType::currentChoiceTipsOffOn, unexposedParams },
	editorForTooltipDelay{ unexposedParams }
{
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);

	btn_Close.setTopRightPosition(borderBounds.getRight(), borderBounds.getY());
	addAndMakeVisible(btn_Close);

	auto col_1_x{ 403 };
	auto col_2_x{ 568 };
	auto col_3_x{ 707 };
	auto col_4_x{ 880 };
	auto row_VertSpacing{ 28 };
	auto row_1_y{ 194 };
	auto row_2_y{ row_1_y + row_VertSpacing };
	auto row_3_y{ row_2_y + row_VertSpacing };
	auto row_4_y{ row_3_y + row_VertSpacing };
	auto row_5_y{ row_4_y + row_VertSpacing };
	auto row_6_y{ row_5_y + row_VertSpacing };
	auto row_7_y{ row_6_y + row_VertSpacing };
	auto row_8_y{ row_7_y + row_VertSpacing };
	auto row_9_y{ row_8_y + row_VertSpacing };
	slider_BasicChannel.setTopLeftPosition(col_1_x, row_1_y);
	addAndMakeVisible(slider_BasicChannel);
	comboBox_OmniMode.setTopLeftPosition(col_1_x, row_2_y);
	addAndMakeVisible(comboBox_OmniMode);
	comboBox_Controllers.setTopLeftPosition(col_1_x, row_3_y);
	addAndMakeVisible(comboBox_Controllers);
	comboBox_VoiceChanges.setTopLeftPosition(col_1_x, row_4_y);
	addAndMakeVisible(comboBox_VoiceChanges);
	comboBox_SysEx.setTopLeftPosition(col_1_x, row_5_y);
	addAndMakeVisible(comboBox_SysEx);
	comboBox_Spillover.setTopLeftPosition(col_1_x, row_6_y);
	addAndMakeVisible(comboBox_Spillover);
	comboBox_MIDI_Echo.setTopLeftPosition(col_1_x, row_7_y);
	addAndMakeVisible(comboBox_MIDI_Echo);

	comboBox_MIDI_Mono.setTopLeftPosition(col_2_x, row_1_y);
	addAndMakeVisible(comboBox_MIDI_Mono);
	comboBox_ActiveSensing.setTopLeftPosition(col_2_x, row_2_y);
	addAndMakeVisible(comboBox_ActiveSensing);
	comboBox_LocalControl.setTopLeftPosition(col_2_x, row_3_y);
	addAndMakeVisible(comboBox_LocalControl);
	slider_Pedal_1_ControllerNum.setTopLeftPosition(col_2_x, row_4_y);
	addAndMakeVisible(slider_Pedal_1_ControllerNum);
	slider_Pedal_2_ControllerNum.setTopLeftPosition(col_2_x, row_5_y);
	addAndMakeVisible(slider_Pedal_2_ControllerNum);
	slider_Lever_2_ControllerNum.setTopLeftPosition(col_2_x, row_6_y);
	addAndMakeVisible(slider_Lever_2_ControllerNum);
	slider_Lever_3_ControllerNum.setTopLeftPosition(col_2_x, row_7_y);
	addAndMakeVisible(slider_Lever_3_ControllerNum);

	slider_VibratoSpeed.setTopLeftPosition(col_3_x, row_1_y);
	addAndMakeVisible(slider_VibratoSpeed);
	comboBox_VibratoWaveType.setTopLeftPosition(col_3_x, row_2_y);
	addAndMakeVisible(comboBox_VibratoWaveType);
	slider_VibratoAmplitude.setTopLeftPosition(col_3_x, row_3_y);
	addAndMakeVisible(slider_VibratoAmplitude);
	comboBox_VibratoSpeedModSource.setTopLeftPosition(col_3_x, row_4_y);
	addAndMakeVisible(comboBox_VibratoSpeedModSource);
	slider_VibratoSpeedModAmount.setTopLeftPosition(col_3_x, row_5_y);
	addAndMakeVisible(slider_VibratoSpeedModAmount);
	comboBox_VibratoAmpModSource.setTopLeftPosition(col_3_x, row_6_y);
	addAndMakeVisible(comboBox_VibratoAmpModSource);
	slider_VibratoAmpModAmount.setTopLeftPosition(col_3_x, row_7_y);
	addAndMakeVisible(slider_VibratoAmpModAmount);

	slider_GlobalTune.setTopLeftPosition(col_4_x, row_1_y);
	addAndMakeVisible(slider_GlobalTune);
	comboBox_SplitStereo.setTopLeftPosition(col_4_x, row_2_y);
	addAndMakeVisible(comboBox_SplitStereo);
	comboBox_VoiceMap.setTopLeftPosition(col_4_x, row_3_y);
	addAndMakeVisible(comboBox_VoiceMap);
	comboBox_VoiceMapEcho.setTopLeftPosition(col_4_x, row_4_y);
	addAndMakeVisible(comboBox_VoiceMapEcho);
	slider_DisplayBrightness.setTopLeftPosition(col_4_x, row_5_y);
	addAndMakeVisible(slider_DisplayBrightness);
	comboBox_SQUICK.setTopLeftPosition(col_4_x, row_6_y);
	addAndMakeVisible(comboBox_SQUICK);
	comboBox_DescriptionTooltip.setTopLeftPosition(col_4_x, row_7_y);
	addAndMakeVisible(comboBox_DescriptionTooltip);
	comboBox_CurrentChoiceTooltip.setTopLeftPosition(col_4_x, row_8_y);
	addAndMakeVisible(comboBox_CurrentChoiceTooltip);
	editorForTooltipDelay.setTopLeftPosition(col_4_x, row_9_y);
	addAndMakeVisible(editorForTooltipDelay);

	auto buttons_w{ 34 };
	btn_ShowVoiceMap.setComponentID(ID::btn_Edit.toString());
	btn_ShowVoiceMap.onClick = [this] { showVoiceMapLayer(); };
	btn_ShowVoiceMap.setBounds(406, row_9_y, buttons_w, GUI::control_h);
	addAndMakeVisible(btn_ShowVoiceMap);

	btn_Push.setComponentID(ID::btn_Push_SplitsBankAndGlobalParams.toString());
	btn_Push.onClick = [this, unexposedParams] { 
		SysExMessages::addGlobalDataMessageToOutgoingBuffers(unexposedParams->getGlobalOptions(), unexposedParams->getOutgoing_MIDI_Buffers());
	};
	btn_Push.setBounds(510, row_9_y, buttons_w, GUI::control_h);
	addAndMakeVisible(btn_Push);

	updateTooltips();

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_GlobalParameters::updateTooltips() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	btn_ShowVoiceMap.setTooltip(shouldShowDescription ? Description::buildForShowVoiceMapButton() : "");
	btn_Push.setTooltip(shouldShowDescription ? Description::buildForPushButton() : "");
}

void GUI_Layer_GlobalParameters::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_GlobalParams_png, (size_t)BinaryData::bkgrnd_GlobalParams_png, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, borderBounds.getX(), borderBounds.getY());
}

void GUI_Layer_GlobalParameters::valueChanged(Value& /*value*/) {
	updateTooltips();
}

void GUI_Layer_GlobalParameters::showVoiceMapLayer() {
	layer_VoiceMap.reset(new GUI_Layer_VoiceMap{ unexposedParams, undoManager });
	if (layer_VoiceMap != nullptr) {
		addAndMakeVisible(layer_VoiceMap.get());
		layer_VoiceMap->setBounds(getLocalBounds());
		layer_VoiceMap->grabKeyboardFocus();
	}
}

GUI_Layer_GlobalParameters::~GUI_Layer_GlobalParameters() {
	shouldShowDescriptionAsValue.removeListener(this);
}
