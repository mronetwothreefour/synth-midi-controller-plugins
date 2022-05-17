#include "randomization_RepeatValuesToggleComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RepeatValuesToggleComponent::RepeatValuesToggleComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType != RandomizationOptionsType::none);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToRepeatValuesOptionsTree(this);
	auto paramID{ info.IDfor(paramIndex).toString() };
	toggle_AllowRepeatValues.setComponentID(ID::component_ToggleButton_AllowRepeatValuesFor_.toString() + paramID);
	auto onlyOneValueIsAllowed{ randomizationOptions->onlyOneValueIsAllowedForParam_z(paramIndex) };
	if (onlyOneValueIsAllowed) {
		toggle_AllowRepeatValues.setToggleState(true, dontSendNotification);
		toggle_AllowRepeatValues.setEnabled(false);
	}
	else {
		auto repeatValuesAreAllowed{ randomizationOptions->repeatValuesAreAllowedForParam(paramIndex) };
		toggle_AllowRepeatValues.setToggleState(repeatValuesAreAllowed, dontSendNotification);
	}
	toggle_AllowRepeatValues.addListener(this);
	addAndMakeVisible(toggle_AllowRepeatValues);
	toggle_AllowRepeatValues.setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	if (shouldShowDescriptions) {
		String knobTooltip{ "" };
		knobTooltip += "Toggles whether repeat values are allowed\n";
		knobTooltip += "when a new value is randomly generated. If\n";
		knobTooltip += "they are not, consecutive randomizations\n";
		knobTooltip += "will never produce the same value. ";
		if (optionsType != RandomizationOptionsType::toggles) {
			knobTooltip += "Obviously,\n";
			knobTooltip += "if there is only one allowed value then repeat\n";
			knobTooltip += "values must also be allowed.";
		}
		else {
			knobTooltip += "In effect,\n";
			knobTooltip += "the toggle will simply alternate between\n";
			knobTooltip += "off and on with every randomization.";
		}
		toggle_AllowRepeatValues.setTooltip(knobTooltip);
	}

	setSize(GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
}

void RepeatValuesToggleComponent::paint(Graphics& g) {
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationRepeatValuesTogglesBackground_png, BinaryData::RandomizationRepeatValuesTogglesBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void RepeatValuesToggleComponent::resized() {
	toggle_AllowRepeatValues.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
}

void RepeatValuesToggleComponent::buttonClicked(Button* button) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (button->getComponentID() == ID::component_ToggleButton_AllowRepeatValuesFor_.toString() + paramID) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto repeatValuesAreAllowed{ button->getToggleState() };
		if (repeatValuesAreAllowed)
			randomizationOptions->setRepeatValuesAreAllowedForParam(paramIndex);
		else
			randomizationOptions->setRepeatValuesAreNotAllowedForParam(paramIndex);
	}
}

void RepeatValuesToggleComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (propertyID.toString() == ID::randomization_OnlyOneValueIsAllowedFor_.toString() + paramID) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto onlyOneValueIsAllowed{ randomizationOptions->onlyOneValueIsAllowedForParam(paramIndex) };
		if (onlyOneValueIsAllowed) {
			toggle_AllowRepeatValues.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatValues.setEnabled(false);
		}
		else {
			auto repeatValuesAreAllowed{ randomizationOptions->repeatValuesAreAllowedForParam(paramIndex) };
			toggle_AllowRepeatValues.setToggleState(repeatValuesAreAllowed, dontSendNotification);
			toggle_AllowRepeatValues.setEnabled(true);
		}
	}
}

RepeatValuesToggleComponent::~RepeatValuesToggleComponent() {
	toggle_AllowRepeatValues.removeListener(this);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromRepeatValuesOptionsTree(this);
}
