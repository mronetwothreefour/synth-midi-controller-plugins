#include "gui_Layer_VoiceNumberAndName.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "gui_Path_LEDcharacters_Singleton.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoiceNumberAndNameLayer::VoiceNumberAndNameLayer(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slider_ForVoiceNumber{ unexposedParams },
	voiceNameEditor{ "voiceNameEditor", "" }
{
	setInterceptsMouseClicks(false, true);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->addListener(this);

	slider_ForVoiceNumber.addListener(this);
	slider_ForVoiceNumber.setTooltip(generateVoiceNumberTooltipString());
	addAndMakeVisible(slider_ForVoiceNumber);

	voiceNameEditor.setComponentID(ID::label_VoiceNameEditor.toString());
	voiceNameEditor.addListener(this);
	auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
	currentVoiceOptions->addListener(this);
	voiceNameEditor.setText(currentVoiceOptions->currentVoiceName(), dontSendNotification);
	voiceNameEditor.setTooltip(generateVoiceNameTooltipString());
	addAndMakeVisible(voiceNameEditor);

	setSize(GUI::editor_w, GUI::editor_h);
}

void VoiceNumberAndNameLayer::resized() {
	slider_ForVoiceNumber.setBounds(GUI::bounds_VoiceNumberSlider);
	voiceNameEditor.setBounds(GUI::bounds_VoiceNameEditor);
}

void VoiceNumberAndNameLayer::editorShown(Label* label, TextEditor& editor) {
	if (label == &voiceNameEditor)
		editor.setInputRestrictions(params::maxVoiceNameLength, "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?<>;:.,-+*/=()'\"&%$#!_^\\|[");
}

void VoiceNumberAndNameLayer::labelTextChanged(Label* label) {
	if (label == &voiceNameEditor) {
		String labelText{ label->getText() };
		String newName(labelText.toUpperCase());
		padNameLessThan8CharactersLongWithSpaces(newName);
		voiceNameEditor.setText(newName, dontSendNotification);
		auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
		currentVoiceOptions->setCurrentVoiceName(newName);
		repaint();
	}
}

void VoiceNumberAndNameLayer::padNameLessThan8CharactersLongWithSpaces(String& name) {
	for(auto i = name.length(); i != params::maxVoiceNameLength; ++i)
		name += " ";
}

void VoiceNumberAndNameLayer::sliderValueChanged(Slider* slider) {
	if (slider == &slider_ForVoiceNumber) {
		auto currentKnobValue{ (uint8)roundToInt(slider->getValue()) };
		auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
		currentVoiceOptions->setCurrentVoiceNumber(currentKnobValue);
		slider_ForVoiceNumber.setTooltip(generateVoiceNumberTooltipString());
	}
}

String VoiceNumberAndNameLayer::generateVoiceNumberTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Selects which patch storage slot\n";
		tooltipText += "on the hardware is the target of the\n";
		tooltipText += "PUSH and PULL buttons to the left.\n";
		tooltipText += "Range: 0 to 99.";
	}
	return tooltipText;
}

String VoiceNumberAndNameLayer::generateVoiceNameTooltipString() {
	String tooltipText{ "" };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		tooltipText += "Click to edit the name of the patch (8 characters max.)\n";
		tooltipText += "The name cannot be changed via Quick Patch Edit. Use the\n";
		tooltipText += "PUSH button to send the entire patch instead.";
	}
	return tooltipText;
}

void VoiceNumberAndNameLayer::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShouldShowCurrentValue || property == ID::tooltips_ShouldShowDescription) {
		slider_ForVoiceNumber.setTooltip(generateVoiceNumberTooltipString());
		voiceNameEditor.setTooltip(generateVoiceNameTooltipString());
	}
	if (property == ID::currentVoice_Name) {
		auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
		voiceNameEditor.setText(currentVoiceOptions->currentVoiceName(), dontSendNotification);
		repaint();
	}
}

VoiceNumberAndNameLayer::~VoiceNumberAndNameLayer() {
	auto currentVoiceOptions{ unexposedParams->currentVoiceOptions_get() };
	currentVoiceOptions->removeListener(this);
	voiceNameEditor.removeListener(this);
	slider_ForVoiceNumber.removeListener(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	tooltipOptions->removeListener(this);
}
