#include "global_GlobalOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



GlobalOptionsComponent::GlobalOptionsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingGlobalOptionsComponent{ "" },
	slider_ForSettingBasicChannel{ unexposedParams },
	comboBox_ForSelectingOmniModeEnabled{ unexposedParams },
	comboBox_ForSelectingControllersEnabled{ unexposedParams },
	comboBox_ForSelectingVoiceChangesEnabled{ unexposedParams },
	comboBox_ForSelectingSysExEnabled{ unexposedParams },
	comboBox_ForSelectingSpilloverEnabled{ unexposedParams },
	comboBox_ForSelectingMIDIechoEnabled{ unexposedParams },
	comboBox_ForSelectingMIDImonoEnabled{ unexposedParams },
	comboBox_ForSelectingActiveSensingEnabled{ unexposedParams },
	comboBox_ForSelectingLocalControlEnabled{ unexposedParams },
	slider_ForSettingPedal1Controller{ unexposedParams, 1 },
	slider_ForSettingPedal2Controller{ unexposedParams, 2 },
	slider_ForSettingLever2Controller{ unexposedParams },
	slider_ForSettingLever3Controller{ unexposedParams },
	slider_ForSettingVibratoSpeed{ unexposedParams },
	comboBox_ForSelectingVibratoWaveType{ unexposedParams },
	slider_ForSettingVibratoAmplitude{ unexposedParams },
	comboBox_ForSelectingVibratoSpeedModSource{ unexposedParams, ID::global_VibratoSpeedModSource },
	sliderForSettingVibratoSpeedModAmount{ unexposedParams, ID::global_VibratoSpeedModAmount },
	comboBox_ForSelectingVibratoAmplitudeModSource{ unexposedParams, ID::global_VibratoAmplitudeModSource },
	sliderForSettingVibratoAmplitudeModAmount{ unexposedParams, ID::global_VibratoAmplitudeModAmount },
	slider_ForSettingGlobalTune{ unexposedParams },
	comboBox_ForSelectingSplitStereoEnabled{ unexposedParams },
	comboBox_ForSelectingVoicesMapEnabled{ unexposedParams },
	comboBox_ForSelectingVoiceMapEchoEnabled{ unexposedParams },
	slider_ForSettingDisplayBrightness{ unexposedParams },
	comboBox_ForSelectingSQUICKenabled{ unexposedParams },
	comboBox_ForSelectingDescriptionTipsEnabled{ unexposedParams },
	comboBox_ForSelectingValueTipsEnabled{ unexposedParams },
	tipsDelayEditor{ "tipsDelayEditor", "" },
	button_ForShowingVoiceMapComponent{ unexposedParams },
	button_ForPushingGlobalOptionsToHardware{ unexposedParams }
{
	button_ForClosingGlobalOptionsComponent.setComponentID(ID::button_X_Global.toString());
	addAndMakeVisible(button_ForClosingGlobalOptionsComponent);
	button_ForClosingGlobalOptionsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingGlobalOptionsComponent.setAlwaysOnTop(true);

	slider_ForSettingBasicChannel.addListener(this);
	addAndMakeVisible(slider_ForSettingBasicChannel);

	comboBox_ForSelectingOmniModeEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingOmniModeEnabled);

	comboBox_ForSelectingControllersEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingControllersEnabled);

	comboBox_ForSelectingVoiceChangesEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVoiceChangesEnabled);

	comboBox_ForSelectingSysExEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSysExEnabled);

	comboBox_ForSelectingSpilloverEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSpilloverEnabled);

	comboBox_ForSelectingMIDIechoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingMIDIechoEnabled);

	comboBox_ForSelectingMIDImonoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingMIDImonoEnabled);

	comboBox_ForSelectingActiveSensingEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingActiveSensingEnabled);

	comboBox_ForSelectingLocalControlEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingLocalControlEnabled);

	slider_ForSettingPedal1Controller.addListener(this);
	addAndMakeVisible(slider_ForSettingPedal1Controller);

	slider_ForSettingPedal2Controller.addListener(this);
	addAndMakeVisible(slider_ForSettingPedal2Controller);

	slider_ForSettingLever2Controller.addListener(this);
	addAndMakeVisible(slider_ForSettingLever2Controller);

	slider_ForSettingLever3Controller.addListener(this);
	addAndMakeVisible(slider_ForSettingLever3Controller);

	slider_ForSettingVibratoSpeed.addListener(this);
	addAndMakeVisible(slider_ForSettingVibratoSpeed);

	comboBox_ForSelectingVibratoWaveType.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVibratoWaveType);

	slider_ForSettingVibratoAmplitude.addListener(this);
	addAndMakeVisible(slider_ForSettingVibratoAmplitude);

	comboBox_ForSelectingVibratoSpeedModSource.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVibratoSpeedModSource);

	sliderForSettingVibratoSpeedModAmount.addListener(this);
	addAndMakeVisible(sliderForSettingVibratoSpeedModAmount);

	comboBox_ForSelectingVibratoAmplitudeModSource.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVibratoAmplitudeModSource);

	sliderForSettingVibratoAmplitudeModAmount.addListener(this);
	addAndMakeVisible(sliderForSettingVibratoAmplitudeModAmount);

	slider_ForSettingGlobalTune.addListener(this);
	addAndMakeVisible(slider_ForSettingGlobalTune);

	comboBox_ForSelectingSplitStereoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSplitStereoEnabled);

	comboBox_ForSelectingVoicesMapEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVoicesMapEnabled);

	comboBox_ForSelectingVoiceMapEchoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingVoiceMapEchoEnabled);

	slider_ForSettingDisplayBrightness.addListener(this);
	addAndMakeVisible(slider_ForSettingDisplayBrightness);

	comboBox_ForSelectingSQUICKenabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSQUICKenabled);

	comboBox_ForSelectingDescriptionTipsEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingDescriptionTipsEnabled);

	comboBox_ForSelectingValueTipsEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingValueTipsEnabled);

	tipsDelayEditor.setComponentID(ID::label_TipsDelayEditor.toString());
	tipsDelayEditor.addListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);
	tipsDelayEditor.setText((String)tooltipOptions->delayInMilliseconds(), dontSendNotification);
	tipsDelayEditor.setTooltip(generateTipsDelayTooltipString());
	addAndMakeVisible(tipsDelayEditor);

	addAndMakeVisible(button_ForShowingVoiceMapComponent);
	button_ForShowingVoiceMapComponent.onClick = [this] { showVoicesMapComponent(); };

	addAndMakeVisible(button_ForPushingGlobalOptionsToHardware);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GlobalOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::MasterWindow_png, BinaryData::MasterWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::globalOptionsWindow_x, GUI::globalOptionsWindow_y);
}

void GlobalOptionsComponent::resized() {
	button_ForClosingGlobalOptionsComponent.setBounds(GUI::bounds_GlobalOptionsComponentXbutton);
	slider_ForSettingBasicChannel.setBounds(GUI::bounds_GlobalOptionsComponentSliderForBasicChannel);
	comboBox_ForSelectingOmniModeEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForOmniMode);
	comboBox_ForSelectingControllersEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForControllers);
	comboBox_ForSelectingVoiceChangesEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVoiceChanges);
	comboBox_ForSelectingSysExEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForSysEx);
	comboBox_ForSelectingSpilloverEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForSpillover);
	comboBox_ForSelectingMIDIechoEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForMIDIecho);
	comboBox_ForSelectingMIDImonoEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForMIDImono);
	comboBox_ForSelectingActiveSensingEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForActiveSensing);
	comboBox_ForSelectingLocalControlEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForLocalControl);
	slider_ForSettingPedal1Controller.setBounds(GUI::bounds_GlobalOptionsComponentSliderForPedal1Controller);
	slider_ForSettingPedal2Controller.setBounds(GUI::bounds_GlobalOptionsComponentSliderForPedal2Controller);
	slider_ForSettingLever2Controller.setBounds(GUI::bounds_GlobalOptionsComponentSliderForLever2Controller);
	slider_ForSettingLever3Controller.setBounds(GUI::bounds_GlobalOptionsComponentSliderForLever3Controller);
	slider_ForSettingVibratoSpeed.setBounds(GUI::bounds_GlobalOptionsComponentSliderForVibratoSpeed);
	comboBox_ForSelectingVibratoWaveType.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVibratoWaveType);
	slider_ForSettingVibratoAmplitude.setBounds(GUI::bounds_GlobalOptionsComponentSliderForVibratoAmplitude);
	comboBox_ForSelectingVibratoSpeedModSource.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVibratoSpeedModSource);
	sliderForSettingVibratoSpeedModAmount.setBounds(GUI::bounds_GlobalOptionsComponentSliderForVibratoSpeedModAmount);
	comboBox_ForSelectingVibratoAmplitudeModSource.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVibratoAmpModSource);
	sliderForSettingVibratoAmplitudeModAmount.setBounds(GUI::bounds_GlobalOptionsComponentSliderForVibratoAmplitudeModAmount);
	slider_ForSettingGlobalTune.setBounds(GUI::bounds_GlobalOptionsComponentSliderForGlobalTune);
	comboBox_ForSelectingSplitStereoEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForSplitStereo);
	comboBox_ForSelectingVoicesMapEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVoiceMap);
	comboBox_ForSelectingVoiceMapEchoEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForVoiceMapEcho);
	slider_ForSettingDisplayBrightness.setBounds(GUI::bounds_GlobalOptionsComponentSliderForDisplayBrightness);
	comboBox_ForSelectingSQUICKenabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForSQUICK);
	comboBox_ForSelectingDescriptionTipsEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForDescriptionTips);
	comboBox_ForSelectingValueTipsEnabled.setBounds(GUI::bounds_GlobalOptionsComponentComboBoxForValueTips);
	tipsDelayEditor.setBounds(GUI::bounds_GlobalOptionsComponentTipsDelayEditor);
	button_ForShowingVoiceMapComponent.setBounds(GUI::bounds_GlobalOptionsComponentEditbutton);
	button_ForPushingGlobalOptionsToHardware.setBounds(GUI::bounds_GlobalOptionsComponentPushbutton);
}

void GlobalOptionsComponent::comboBoxChanged(ComboBox* comboBox) {
	auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
	auto globalOptions{ unexposedParams->globalOptions_get() };
	if (comboBox == &comboBox_ForSelectingOmniModeEnabled)
		globalOptions->setOmniModeEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingControllersEnabled)
		globalOptions->setControllersEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingVoiceChangesEnabled)
		globalOptions->setVoiceChangesEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSysExEnabled)
		globalOptions->setSysExEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSpilloverEnabled)
		globalOptions->setSpilloverEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDIechoEnabled)
		globalOptions->setMIDIechoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDImonoEnabled)
		globalOptions->setMIDImonoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingActiveSensingEnabled)
		globalOptions->setActiveSensingEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingLocalControlEnabled)
		globalOptions->setLocalControlEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoWaveType)
		globalOptions->setVibratoWaveType(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoSpeedModSource)
		globalOptions->setVibratoSpeedModSource(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoAmplitudeModSource)
		globalOptions->setVibratoAmplitudeModSource(currentSelection);
	if (comboBox == &comboBox_ForSelectingSplitStereoEnabled)
		globalOptions->setSplitStereoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingVoicesMapEnabled)
		globalOptions->setVoicesMapEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingVoiceMapEchoEnabled)
		globalOptions->setVoicesMapEchoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSQUICKenabled)
		globalOptions->setSQUICKenabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingDescriptionTipsEnabled) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (comboBox_ForSelectingDescriptionTipsEnabled.getSelectedItemIndex() == 1)
			tooltipOptions->setShouldShowDescription();
		else
			tooltipOptions->setShouldNotShowDescription();
	}
	if (comboBox == &comboBox_ForSelectingValueTipsEnabled) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (comboBox_ForSelectingValueTipsEnabled.getSelectedItemIndex() == 1)
			tooltipOptions->setShouldShowCurrentValue();
		else
			tooltipOptions->setShouldNotShowCurrentValue();
	}
}

void GlobalOptionsComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &tipsDelayEditor) {
		editor.setInputRestrictions(params::maxTipsDelayDigits, "1234567890");
		auto tooltipsOptions{ unexposedParams->tooltipOptions_get() };
		editor.setFont(FontsMenu::fontFor_LabelEditors);
		editor.setText((String)tooltipsOptions->delayInMilliseconds());
		editor.selectAll();
	}
}

void GlobalOptionsComponent::labelTextChanged(Label* label) {
	if (label == &tipsDelayEditor) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue >= params::minTipsDelayValue && newValue <= params::maxTipsDelayValue)
				tooltipOptions->setDelayInMilliseconds(newValue);
		}
		label->setText((String)tooltipOptions->delayInMilliseconds(), dontSendNotification);
	}
}

String GlobalOptionsComponent::generateTipsDelayTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Sets the amount of time (in milliseconds) the mouse cursor\n";
		tooltipText += "must hover over a control before a tooltip box is shown.\n";
		tooltipText += "Maximum delay: 5000 milliseconds. NOTE: Individual\n";
		tooltipText += "Master options are not immediately updated on the hard-\n";
		tooltipText += "ware. Click the PUSH button to update all options.\n";
	}
	if (tooltipOptions->shouldShowCurrentValue()) {
		auto currentValue{ (String)tooltipOptions->delayInMilliseconds() };
		tooltipText += "Current setting: " + currentValue + " milliseconds";
	}
	return tooltipText;
}

void GlobalOptionsComponent::sliderValueChanged(Slider* slider) {
	auto globalOptions{ unexposedParams->globalOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingBasicChannel)
		globalOptions->setBasicChannel(currentValue);
	if (slider == &slider_ForSettingLever2Controller)
		globalOptions->setLever2ControllerNumber(currentValue);
	if (slider == &slider_ForSettingLever3Controller)
		globalOptions->setLever3ControllerNumber(currentValue);
	if (slider == &slider_ForSettingPedal1Controller)
		globalOptions->setPedal1ControllerNumber(currentValue);
	if (slider == &slider_ForSettingPedal2Controller)
		globalOptions->setPedal2ControllerNumber(currentValue);
	if (slider == &slider_ForSettingVibratoSpeed)
		globalOptions->setVibratoSpeed(currentValue);
	if (slider == &slider_ForSettingVibratoAmplitude)
		globalOptions->setVibratoAmplitude(currentValue);
	if (slider == &sliderForSettingVibratoSpeedModAmount)
		globalOptions->setVibratoSpeedModAmount(currentValue);
	if (slider == &sliderForSettingVibratoAmplitudeModAmount)
		globalOptions->setVibratoAmplitudeModAmount(currentValue);
	if (slider == &slider_ForSettingGlobalTune)
		globalOptions->setGlobalTune(currentValue);
	if (slider == &slider_ForSettingDisplayBrightness)
		globalOptions->setDisplayBrightness(currentValue);
}

void GlobalOptionsComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::tooltips_DelayInMilliseconds) {
		MessageManagerLock mmLock;
		tipsDelayEditor.setText(tree.getProperty(property), dontSendNotification);
		tipsDelayEditor.setTooltip(generateTipsDelayTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		tipsDelayEditor.setTooltip(generateTipsDelayTooltipString());
	}
}

void GlobalOptionsComponent::showVoicesMapComponent() {
	voicesMapComponent.reset(new VoicesMapComponent(unexposedParams));
	if (voicesMapComponent != nullptr) {
		addAndMakeVisible(voicesMapComponent.get());
		voicesMapComponent->setBounds(getLocalBounds());
		voicesMapComponent->setAlwaysOnTop(true);
	}
}

void GlobalOptionsComponent::hideThisComponent() {
	setVisible(false);
}

GlobalOptionsComponent::~GlobalOptionsComponent() {
	voicesMapComponent = nullptr;
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	tipsDelayEditor.removeListener(this);
	comboBox_ForSelectingValueTipsEnabled.removeListener(this);
	comboBox_ForSelectingDescriptionTipsEnabled.removeListener(this);
	comboBox_ForSelectingSQUICKenabled.removeListener(this);
	slider_ForSettingDisplayBrightness.removeListener(this);
	comboBox_ForSelectingVoiceMapEchoEnabled.removeListener(this);
	comboBox_ForSelectingVoicesMapEnabled.removeListener(this);
	comboBox_ForSelectingSplitStereoEnabled.removeListener(this);
	slider_ForSettingGlobalTune.removeListener(this);
	sliderForSettingVibratoAmplitudeModAmount.removeListener(this);
	sliderForSettingVibratoSpeedModAmount.removeListener(this);
	comboBox_ForSelectingVibratoAmplitudeModSource.removeListener(this);
	comboBox_ForSelectingVibratoSpeedModSource.removeListener(this);
	slider_ForSettingVibratoAmplitude.removeListener(this);
	comboBox_ForSelectingVibratoWaveType.removeListener(this);
	slider_ForSettingVibratoSpeed.removeListener(this);
	slider_ForSettingLever3Controller.removeListener(this);
	slider_ForSettingLever2Controller.removeListener(this);
	slider_ForSettingPedal2Controller.removeListener(this);
	slider_ForSettingPedal1Controller.removeListener(this);
	comboBox_ForSelectingLocalControlEnabled.removeListener(this);
	comboBox_ForSelectingActiveSensingEnabled.removeListener(this);
	comboBox_ForSelectingMIDImonoEnabled.removeListener(this);
	comboBox_ForSelectingMIDIechoEnabled.removeListener(this);
	comboBox_ForSelectingSpilloverEnabled.removeListener(this);
	comboBox_ForSelectingSysExEnabled.removeListener(this);
	comboBox_ForSelectingVoiceChangesEnabled.removeListener(this);
	comboBox_ForSelectingControllersEnabled.removeListener(this);
	comboBox_ForSelectingOmniModeEnabled.removeListener(this);
	slider_ForSettingBasicChannel.removeListener(this);
}
