#include "master_MasterOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



MasterOptionsComponent::MasterOptionsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingMasterOptionsComponent{ "" },
	slider_ForSettingBasicChannel{ unexposedParams },
	comboBox_ForSelectingOmniModeEnabled{ unexposedParams },
	comboBox_ForSelectingControllersEnabled{ unexposedParams },
	comboBox_ForSelectingPatchChangesEnabled{ unexposedParams },
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
	comboBox_ForSelectingVibratoSpeedModSource{ unexposedParams, ID::master_VibratoSpeedModSource },
	sliderForSettingVibratoSpeedModAmount{ unexposedParams, ID::master_VibratoSpeedModAmount },
	comboBox_ForSelectingVibratoAmplitudeModSource{ unexposedParams, ID::master_VibratoAmplitudeModSource },
	sliderForSettingVibratoAmplitudeModAmount{ unexposedParams, ID::master_VibratoAmplitudeModAmount },
	slider_ForSettingMasterTune{ unexposedParams },
	comboBox_ForSelectingSplitStereoEnabled{ unexposedParams },
	comboBox_ForSelectingPatchMapEnabled{ unexposedParams },
	comboBox_ForSelectingPatchMapEchoEnabled{ unexposedParams },
	slider_ForSettingDisplayBrightness{ unexposedParams },
	comboBox_ForSelectingSQUICKenabled{ unexposedParams },
	comboBox_ForSelectingDescriptionTipsEnabled{ unexposedParams },
	comboBox_ForSelectingValueTipsEnabled{ unexposedParams },
	tipsDelayEditor{ "tipsDelayEditor", "" },
	button_ForShowingPatchMapComponent{ unexposedParams }
{
	button_ForClosingMasterOptionsComponent.setComponentID(ID::button_X_Master.toString());
	addAndMakeVisible(button_ForClosingMasterOptionsComponent);
	button_ForClosingMasterOptionsComponent.onClick = [this] { hideThisComponent(); };
	button_ForClosingMasterOptionsComponent.setAlwaysOnTop(true);

	slider_ForSettingBasicChannel.addListener(this);
	addAndMakeVisible(slider_ForSettingBasicChannel);

	comboBox_ForSelectingOmniModeEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingOmniModeEnabled);

	comboBox_ForSelectingControllersEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingControllersEnabled);

	comboBox_ForSelectingPatchChangesEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingPatchChangesEnabled);

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

	slider_ForSettingMasterTune.addListener(this);
	addAndMakeVisible(slider_ForSettingMasterTune);

	comboBox_ForSelectingSplitStereoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingSplitStereoEnabled);

	comboBox_ForSelectingPatchMapEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingPatchMapEnabled);

	comboBox_ForSelectingPatchMapEchoEnabled.addListener(this);
	addAndMakeVisible(comboBox_ForSelectingPatchMapEchoEnabled);

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

	addAndMakeVisible(button_ForShowingPatchMapComponent);
	button_ForShowingPatchMapComponent.onClick = [this] { showPatchMapComponent(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void MasterOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::MasterWindow_png, BinaryData::MasterWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto windowImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(windowImage, GUI::masterOptionsWindow_x, GUI::masterOptionsWindow_y);
}

void MasterOptionsComponent::resized() {
	button_ForClosingMasterOptionsComponent.setBounds(GUI::bounds_MasterOptionsComponentXbutton);
	slider_ForSettingBasicChannel.setBounds(GUI::bounds_MasterOptionsComponentSliderForBasicChannel);
	comboBox_ForSelectingOmniModeEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForOmniMode);
	comboBox_ForSelectingControllersEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForControllers);
	comboBox_ForSelectingPatchChangesEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForPatchChanges);
	comboBox_ForSelectingSysExEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSysEx);
	comboBox_ForSelectingSpilloverEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSpillover);
	comboBox_ForSelectingMIDIechoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForMIDIecho);
	comboBox_ForSelectingMIDImonoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForMIDImono);
	comboBox_ForSelectingActiveSensingEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForActiveSensing);
	comboBox_ForSelectingLocalControlEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForLocalControl);
	slider_ForSettingPedal1Controller.setBounds(GUI::bounds_MasterOptionsComponentSliderForPedal1Controller);
	slider_ForSettingPedal2Controller.setBounds(GUI::bounds_MasterOptionsComponentSliderForPedal2Controller);
	slider_ForSettingLever2Controller.setBounds(GUI::bounds_MasterOptionsComponentSliderForLever2Controller);
	slider_ForSettingLever3Controller.setBounds(GUI::bounds_MasterOptionsComponentSliderForLever3Controller);
	slider_ForSettingVibratoSpeed.setBounds(GUI::bounds_MasterOptionsComponentSliderForVibratoSpeed);
	comboBox_ForSelectingVibratoWaveType.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForVibratoWaveType);
	slider_ForSettingVibratoAmplitude.setBounds(GUI::bounds_MasterOptionsComponentSliderForVibratoAmplitude);
	comboBox_ForSelectingVibratoSpeedModSource.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForVibratoSpeedModSource);
	sliderForSettingVibratoSpeedModAmount.setBounds(GUI::bounds_MasterOptionsComponentSliderForVibratoSpeedModAmount);
	comboBox_ForSelectingVibratoAmplitudeModSource.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForVibratoAmpModSource);
	sliderForSettingVibratoAmplitudeModAmount.setBounds(GUI::bounds_MasterOptionsComponentSliderForVibratoAmplitudeModAmount);
	slider_ForSettingMasterTune.setBounds(GUI::bounds_MasterOptionsComponentSliderForMasterTune);
	comboBox_ForSelectingSplitStereoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSplitStereo);
	comboBox_ForSelectingPatchMapEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForPatchMap);
	comboBox_ForSelectingPatchMapEchoEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForPatchMapEcho);
	slider_ForSettingDisplayBrightness.setBounds(GUI::bounds_MasterOptionsComponentSliderForDisplayBrightness);
	comboBox_ForSelectingSQUICKenabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForSQUICK);
	comboBox_ForSelectingDescriptionTipsEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForDescriptionTips);
	comboBox_ForSelectingValueTipsEnabled.setBounds(GUI::bounds_MasterOptionsComponentComboBoxForValueTips);
	tipsDelayEditor.setBounds(GUI::bounds_MasterOptionsComponentTipsDelayEditor);
	button_ForShowingPatchMapComponent.setBounds(GUI::bounds_MasterOptionsComponentEditbutton);
}

void MasterOptionsComponent::comboBoxChanged(ComboBox* comboBox) {
	auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
	auto masterOptions{ unexposedParams->masterOptions_get() };
	if (comboBox == &comboBox_ForSelectingOmniModeEnabled)
		masterOptions->setOmniModeEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingControllersEnabled)
		masterOptions->setControllersEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingPatchChangesEnabled)
		masterOptions->setPatchChangesEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSysExEnabled)
		masterOptions->setSysExEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSpilloverEnabled)
		masterOptions->setSpilloverEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDIechoEnabled)
		masterOptions->setMIDIechoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingMIDImonoEnabled)
		masterOptions->setMIDImonoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingActiveSensingEnabled)
		masterOptions->setActiveSensingEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingLocalControlEnabled)
		masterOptions->setLocalControlEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoWaveType)
		masterOptions->setVibratoWaveType(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoSpeedModSource)
		masterOptions->setVibratoSpeedModSource(currentSelection);
	if (comboBox == &comboBox_ForSelectingVibratoAmplitudeModSource)
		masterOptions->setVibratoAmplitudeModSource(currentSelection);
	if (comboBox == &comboBox_ForSelectingSplitStereoEnabled)
		masterOptions->setSplitStereoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingPatchMapEnabled)
		masterOptions->setPatchMapEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingPatchMapEchoEnabled)
		masterOptions->setPatchMapEchoEnabled(currentSelection);
	if (comboBox == &comboBox_ForSelectingSQUICKenabled)
		masterOptions->setSQUICKenabled(currentSelection);
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

void MasterOptionsComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &tipsDelayEditor) {
		editor.setInputRestrictions(matrixParams::maxTipsDelayDigits, "1234567890");
		auto tooltipsOptions{ unexposedParams->tooltipOptions_get() };
		editor.setFont(FontsMenu::fontFor_LabelEditors);
		editor.setText((String)tooltipsOptions->delayInMilliseconds());
		editor.selectAll();
	}
}

void MasterOptionsComponent::labelTextChanged(Label* label) {
	if (label == &tipsDelayEditor) {
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue >= matrixParams::minTipsDelayValue && newValue <= matrixParams::maxTipsDelayValue)
				tooltipOptions->setDelayInMilliseconds(newValue);
		}
		label->setText((String)tooltipOptions->delayInMilliseconds(), dontSendNotification);
	}
}

String MasterOptionsComponent::generateTipsDelayTooltipString() {
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

void MasterOptionsComponent::sliderValueChanged(Slider* slider) {
	auto masterOptions{ unexposedParams->masterOptions_get() };
	auto currentValue{ (uint8)roundToInt(slider->getValue()) };
	if (slider == &slider_ForSettingBasicChannel)
		masterOptions->setBasicChannel(currentValue);
	if (slider == &slider_ForSettingLever2Controller)
		masterOptions->setLever2ControllerNumber(currentValue);
	if (slider == &slider_ForSettingLever3Controller)
		masterOptions->setLever3ControllerNumber(currentValue);
	if (slider == &slider_ForSettingPedal1Controller)
		masterOptions->setPedal1ControllerNumber(currentValue);
	if (slider == &slider_ForSettingPedal2Controller)
		masterOptions->setPedal2ControllerNumber(currentValue);
	if (slider == &slider_ForSettingVibratoSpeed)
		masterOptions->setVibratoSpeed(currentValue);
	if (slider == &slider_ForSettingVibratoAmplitude)
		masterOptions->setVibratoAmplitude(currentValue);
	if (slider == &sliderForSettingVibratoSpeedModAmount)
		masterOptions->setVibratoSpeedModAmount(currentValue);
	if (slider == &sliderForSettingVibratoAmplitudeModAmount)
		masterOptions->setvibratoAmplitudeModAmount(currentValue);
	if (slider == &slider_ForSettingMasterTune)
		masterOptions->setMasterTune(currentValue);
	if (slider == &slider_ForSettingDisplayBrightness)
		masterOptions->setDisplayBrightness(currentValue);
}

void MasterOptionsComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	if (property == ID::tooltips_DelayInMilliseconds) {
		MessageManagerLock mmLock;
		tipsDelayEditor.setText(tree.getProperty(property), dontSendNotification);
		tipsDelayEditor.setTooltip(generateTipsDelayTooltipString());
	}
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		tipsDelayEditor.setTooltip(generateTipsDelayTooltipString());
	}
}

void MasterOptionsComponent::showPatchMapComponent() {
	patchMapComponent.reset(new PatchMapComponent(unexposedParams));
	if (patchMapComponent != nullptr) {
		addAndMakeVisible(patchMapComponent.get());
		patchMapComponent->setBounds(getLocalBounds());
		patchMapComponent->setAlwaysOnTop(true);
	}
}

void MasterOptionsComponent::hideThisComponent() {
	setVisible(false);
}

MasterOptionsComponent::~MasterOptionsComponent() {
	patchMapComponent = nullptr;
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
	tipsDelayEditor.removeListener(this);
	comboBox_ForSelectingValueTipsEnabled.removeListener(this);
	comboBox_ForSelectingDescriptionTipsEnabled.removeListener(this);
	comboBox_ForSelectingSQUICKenabled.removeListener(this);
	slider_ForSettingDisplayBrightness.removeListener(this);
	comboBox_ForSelectingPatchMapEchoEnabled.removeListener(this);
	comboBox_ForSelectingPatchMapEnabled.removeListener(this);
	comboBox_ForSelectingSplitStereoEnabled.removeListener(this);
	slider_ForSettingMasterTune.removeListener(this);
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
	comboBox_ForSelectingPatchChangesEnabled.removeListener(this);
	comboBox_ForSelectingControllersEnabled.removeListener(this);
	comboBox_ForSelectingOmniModeEnabled.removeListener(this);
	slider_ForSettingBasicChannel.removeListener(this);
}
