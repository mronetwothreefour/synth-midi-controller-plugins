#include "global_GlobalParametersComponent.h"

#include "global_GlobalParametersConstants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_NRPNbufferWithLeadingMSBs.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



GlobalParametersComponent::GlobalParametersComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_ForClosingGlobalParameters{ "" },
	knob_ForGlobalTranspose{ unexposedParams },
	valueDisplay_ForGlobalTranspose{&knob_ForGlobalTranspose, IntToGlobalTransposeString::get() },
	knob_ForGlobalFineTune{ unexposedParams },
	valueDisplay_ForGlobalFineTune{&knob_ForGlobalFineTune, IntToFineTuneString::get() },
	knob_ForGlobalMidiChannel{ unexposedParams },
	valueDisplay_ForGlobalMidiChannel{&knob_ForGlobalMidiChannel, IntToGlobalMidiChannelString::get() },
	comboBox_ForMidiClock{ unexposedParams },
	comboBox_ForPedalMode{ unexposedParams },
	comboBox_ForVoiceChange{ unexposedParams },
	comboBox_ForParameterSend{ unexposedParams },
	displayLabel_ForParameterReceive{ unexposedParams },
	displayLabel_ForMidiControllers{ unexposedParams },
	displayLabel_ForSysEx{ unexposedParams },
	displayLabel_ForAudioOutput{ unexposedParams },
	displayLabel_ForBalanceTweak{ unexposedParams },
	toggle_ForDescriptionTooltip{ unexposedParams },
	toggle_ForCurrentSettingTooltip{ unexposedParams },
	label_ForSettingTooltipDelay{ unexposedParams }
{
	button_ForClosingGlobalParameters.setComponentID(ID::button_Close.toString());
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

	comboBox_ForVoiceChange.addListener(this);
	addAndMakeVisible(comboBox_ForVoiceChange);

	comboBox_ForParameterSend.addListener(this);
	addAndMakeVisible(comboBox_ForParameterSend);

	addAndMakeVisible(displayLabel_ForParameterReceive);
	addAndMakeVisible(displayLabel_ForMidiControllers);
	addAndMakeVisible(displayLabel_ForSysEx);
	addAndMakeVisible(displayLabel_ForAudioOutput);
	addAndMakeVisible(displayLabel_ForBalanceTweak);

	toggle_ForDescriptionTooltip.addListener(this);
	addAndMakeVisible(toggle_ForDescriptionTooltip);

	toggle_ForCurrentSettingTooltip.addListener(this);
	addAndMakeVisible(toggle_ForCurrentSettingTooltip);

	label_ForSettingTooltipDelay.addListener(this);
	addAndMakeVisible(label_ForSettingTooltipDelay);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GlobalParametersComponent::hideThisComponent() {
	setVisible(false);
}

void GlobalParametersComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::GlobalParametersBackground_png, BinaryData::GlobalParametersBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::globalParametersWindow_x, GUI::globalParametersWindow_y);
}

void GlobalParametersComponent::resized() {
	button_ForClosingGlobalParameters.setBounds(GUI::bounds_GlobalParametersCloseButton);
	knob_ForGlobalTranspose.setBounds(GUI::bounds_GlobalParametersTransposeKnob);
	valueDisplay_ForGlobalTranspose.setBounds(GUI::bounds_GlobalParametersTransposeKnob);
	knob_ForGlobalFineTune.setBounds(GUI::bounds_GlobalParametersFineTuneKnob);
	valueDisplay_ForGlobalFineTune.setBounds(GUI::bounds_GlobalParametersFineTuneKnob);
	knob_ForGlobalMidiChannel.setBounds(GUI::bounds_GlobalParametersMidiChannelKnob);
	valueDisplay_ForGlobalMidiChannel.setBounds(GUI::bounds_GlobalParametersMidiChannelKnob);
	comboBox_ForMidiClock.setBounds(GUI::bounds_GlobalParametersMidiClockComboBox);
	comboBox_ForPedalMode.setBounds(GUI::bounds_GlobalParametersPedalModeComboBox);
	comboBox_ForVoiceChange.setBounds(GUI::bounds_GlobalParametersVoiceChangeComboBox);
	comboBox_ForParameterSend.setBounds(GUI::bounds_GlobalParametersParameterSendComboBox);
	displayLabel_ForParameterReceive.setBounds(GUI::bounds_GlobalParametersParameterReceiveDisplayLabel);
	displayLabel_ForMidiControllers.setBounds(GUI::bounds_GlobalParametersMidiControllersDisplayLabel);
	displayLabel_ForSysEx.setBounds(GUI::bounds_GlobalParametersSysExDisplayLabel);
	displayLabel_ForAudioOutput.setBounds(GUI::bounds_GlobalParametersAudioOutputDisplayLabel);
	displayLabel_ForBalanceTweak.setBounds(GUI::bounds_GlobalParametersBalanceTweakDisplayLabel);
	toggle_ForDescriptionTooltip.setBounds(GUI::bounds_GlobalParametersDescriptionTooltipToggle);
	toggle_ForCurrentSettingTooltip.setBounds(GUI::bounds_GlobalParametersCurrentSettingTooltipToggle);
	label_ForSettingTooltipDelay.setBounds(GUI::bounds_GlobalParametersTooltipDelayLabel);
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
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, globalParams::nrpnType_MidiClock);
	}
	if (comboBox == &comboBox_ForPedalMode) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterReceiveType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, globalParams::nrpnType_PedalMode);
	}
	if (comboBox == &comboBox_ForVoiceChange) {
		auto isOn{ (bool)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		if (isOn)
			midiOptions->setVoiceChangeOn();
		else
			midiOptions->setVoiceChangeOff();
		sendNewValueForNRPNtypeToOutgoingMidiBuffers((uint8)isOn, globalParams::nrpnType_VoiceChange);
	}
	if (comboBox == &comboBox_ForParameterSend) {
		auto currentSelection{ (uint8)comboBox->getSelectedItemIndex() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		midiOptions->setParameterSendType(currentSelection);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentSelection, globalParams::nrpnType_ParameterSendType);
	}
}

void GlobalParametersComponent::editorShown(Label* label, TextEditor& editor) {
	if (label == &label_ForSettingTooltipDelay) {
		editor.setInputRestrictions(4, "0123456789");
		auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
		editor.setFont(FontsMenu::fontFor_Labels);
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
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, globalParams::nrpnType_GlobalTranspose);
	}
	if (slider == &knob_ForGlobalFineTune) {
		auto globalAudioOptions{ unexposedParams->globalAudioOptions_get() };
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		globalAudioOptions->setGlobalFineTune(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, globalParams::nrpnType_GlobalFineTune);
	}
	if (slider == &knob_ForGlobalMidiChannel) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		midiOptions->setHardwareReceiveChannel(currentKnobValue);
		sendNewValueForNRPNtypeToOutgoingMidiBuffers(currentKnobValue, globalParams::nrpnType_GlobalMidiChannel);
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
	outgoingMidiBuffers->addMidiBuffer(nrpnBuffer);
}

void GlobalParametersComponent::timerCallback() {
}

GlobalParametersComponent::~GlobalParametersComponent() {
	label_ForSettingTooltipDelay.removeListener(this);
	toggle_ForCurrentSettingTooltip.removeListener(this);
	toggle_ForDescriptionTooltip.removeListener(this);
	comboBox_ForParameterSend.removeListener(this);
	comboBox_ForVoiceChange.removeListener(this);
	comboBox_ForPedalMode.removeListener(this);
	comboBox_ForMidiClock.removeListener(this);
	knob_ForGlobalMidiChannel.removeListener(this);
	knob_ForGlobalFineTune.removeListener(this);
	knob_ForGlobalTranspose.removeListener(this);
}
