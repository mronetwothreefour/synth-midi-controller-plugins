#include "randomization_RepeatValuesToggleComponentForAllStepsInSeqTrack.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RepeatValuesToggleComponentForAllStepsInSeqTrack::RepeatValuesToggleComponentForAllStepsInSeqTrack(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams }
{
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToRepeatValuesOptionsTree(this);
	toggle_AllowRepeatValues.setComponentID(ID::component_ToggleButton_AllowRepeatValuesFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum);
	auto onlyOneValueIsAllowed{ randomizationOptions->onlyOneValueIsAllowedForAllStepsInSeqTrack(trackNum) };
	if (onlyOneValueIsAllowed) {
		toggle_AllowRepeatValues.setToggleState(true, dontSendNotification);
		toggle_AllowRepeatValues.setEnabled(false);
	}
	else {
		auto repeatValuesAreAllowed{ randomizationOptions->repeatValuesAreAllowedForAllStepsInSeqTrack(trackNum) };
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
		knobTooltip += "will never produce the same value. Obviously,\n";
		knobTooltip += "if there is only one allowed value then repeat\n";
		knobTooltip += "values must also be allowed.";
		toggle_AllowRepeatValues.setTooltip(knobTooltip);
	}

	setSize(GUI::randomizationRepeatValuesComponents_w, GUI::randomizationRepeatValuesComponents_h);
}

void RepeatValuesToggleComponentForAllStepsInSeqTrack::paint(Graphics& g) {
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationRepeatValuesTogglesBackground_png, BinaryData::RandomizationRepeatValuesTogglesBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void RepeatValuesToggleComponentForAllStepsInSeqTrack::resized() {
	toggle_AllowRepeatValues.setBounds(0, 0, GUI::toggle_diameter, GUI::toggle_diameter);
}

void RepeatValuesToggleComponentForAllStepsInSeqTrack::buttonClicked(Button* button) {
	if (button->getComponentID() == ID::component_ToggleButton_AllowRepeatValuesFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto repeatValuesAreAllowed{ button->getToggleState() };
		if (repeatValuesAreAllowed)
			randomizationOptions->setRepeatValuesAreAllowedForAllStepsInSeqTrack(trackNum);
		else
			randomizationOptions->setRepeatValuesAreNotAllowedForAllStepsInSeqTrack(trackNum);
	}
}

void RepeatValuesToggleComponentForAllStepsInSeqTrack::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == ID::randomization_OnlyOneValueIsAllowedFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto onlyOneValueIsAllowed{ randomizationOptions->onlyOneValueIsAllowedForAllStepsInSeqTrack(trackNum) };
		if (onlyOneValueIsAllowed) {
			toggle_AllowRepeatValues.setToggleState(true, dontSendNotification);
			toggle_AllowRepeatValues.setEnabled(false);
		}
		else {
			auto repeatValuesAreAllowed{ randomizationOptions->repeatValuesAreAllowedForAllStepsInSeqTrack(trackNum) };
			toggle_AllowRepeatValues.setToggleState(repeatValuesAreAllowed, dontSendNotification);
			toggle_AllowRepeatValues.setEnabled(true);
		}
	}
}

RepeatValuesToggleComponentForAllStepsInSeqTrack::~RepeatValuesToggleComponentForAllStepsInSeqTrack() {
	toggle_AllowRepeatValues.removeListener(this);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromRepeatValuesOptionsTree(this);
}
