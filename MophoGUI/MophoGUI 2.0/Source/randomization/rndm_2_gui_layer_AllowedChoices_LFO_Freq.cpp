#include "rndm_2_gui_layer_AllowedChoices_LFO_Freq.h"

#include "rndm_0_ParamRandomizationMethods.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



GUI_Layer_AllowedChoices_LFO_Freq::GUI_Layer_AllowedChoices_LFO_Freq(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	randomizationOptions{ unexposedParams->getRandomizationOptions() },
	repeatValues{ paramIndex, unexposedParams },
	button_Close{ unexposedParams },
	allowUnsyncedFreqToggles{ paramIndex, unexposedParams },
	allowPitchedFreqToggles{ paramIndex, unexposedParams },
	allowSyncedFreqToggles{ paramIndex, unexposedParams },
	button_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ Info::get().allowedChoicesBackground_x_For(paramIndex) },
	background_y{ Info::get().allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramID{ Info::get().IDfor(paramIndex).toString() };
	auto paramName{ Info::get().exposedNameFor(paramIndex) };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };

	button_AllowAll.setComponentID(ID::button_AllowAll.toString());
	button_AllowAll.onClick = [this] { allowAllChoices(); };
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the frequencies\n";
		tip += "when generating a random setting for\n";
		tip += paramName + ".";
		button_AllowAll.setTooltip(tip);
	}
	button_AllowAll.setBounds(378, 177, GUI::button_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(button_AllowAll);

	repeatValues.setTopLeftPosition(660, 181);
	addAndMakeVisible(repeatValues);

	button_Close.setTopLeftPosition(962, 177);
	addAndMakeVisible(button_Close);

	auto categoryToggles_y{ 214 };
	toggle_Unsynced.setComponentID(ID::component_RedToggle_AllowLFO_Freq_Unsynced.toString());
	toggle_Unsynced.addListener(this);
	auto unsyncedFreqAreAllowed{ randomizationOptions->categoryIsAllowedForLFO_FreqParam(Category::unsynced, paramIndex) };
	toggle_Unsynced.setToggleState(unsyncedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not un-synced frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Unsynced.setTooltip(tip);
	}
	toggle_Unsynced.setTopLeftPosition(422, categoryToggles_y);
	addAndMakeVisible(toggle_Unsynced);

	toggle_Pitched.setComponentID(ID::component_RedToggle_AllowLFO_Freq_Pitched.toString());
	toggle_Pitched.addListener(this);
	auto pitchedFreqAreAllowed{ randomizationOptions->categoryIsAllowedForLFO_FreqParam(Category::pitched, paramIndex) };
	toggle_Pitched.setToggleState(pitchedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not pitched frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Pitched.setTooltip(tip);
	}
	toggle_Pitched.setTopLeftPosition(651, categoryToggles_y);
	addAndMakeVisible(toggle_Pitched);

	toggle_Synced.setComponentID(ID::component_RedToggle_AllowLFO_Freq_Synced.toString());
	toggle_Synced.addListener(this);
	auto syncedFreqAreAllowed{ randomizationOptions->categoryIsAllowedForLFO_FreqParam(Category::synced, paramIndex) };
	toggle_Synced.setToggleState(syncedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not synced frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Synced.setTooltip(tip);
	}
	toggle_Synced.setTopLeftPosition(878, categoryToggles_y);
	addAndMakeVisible(toggle_Synced);

	auto allowToggles_y{ 234 };
	if (unsyncedFreqAreAllowed)
		allowUnsyncedFreqToggles.restoreToggles();
	else
		allowUnsyncedFreqToggles.disableToggles();
	allowUnsyncedFreqToggles.setTopLeftPosition(378, allowToggles_y);
	addAndMakeVisible(allowUnsyncedFreqToggles);

	if (pitchedFreqAreAllowed)
		allowPitchedFreqToggles.restoreToggles();
	else
		allowPitchedFreqToggles.disableToggles();
	allowPitchedFreqToggles.setTopLeftPosition(578, allowToggles_y);
	addAndMakeVisible(allowPitchedFreqToggles);

	if (syncedFreqAreAllowed)
		allowSyncedFreqToggles.restoreToggles();
	else
		allowSyncedFreqToggles.disableToggles();
	allowSyncedFreqToggles.setTopLeftPosition(812, allowToggles_y);
	addAndMakeVisible(allowSyncedFreqToggles);

	addAndMakeVisible(button_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_LFO_Freq::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ Info::get().centerPointFor(paramIndex)};
	g.setColour(GUI::color_ToggleOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void GUI_Layer_AllowedChoices_LFO_Freq::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto clickedCategory{ Category::unsynced };
	if (button == &toggle_Pitched)
		clickedCategory = Category::pitched;
	if (button == &toggle_Synced)
		clickedCategory = Category::synced;
	if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier)
		makeCategoryTheOnlyOneAllowed(clickedCategory);
	else {
		auto categoryIsAllowed{ button->getToggleState() };
		randomizationOptions->setCategoryIsAllowedForLFO_FreqParam(clickedCategory, categoryIsAllowed ? true : false, paramIndex);
		if (randomizationOptions->noCategoryIsAllowedForLFO_FreqParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setCategoryIsAllowedForLFO_FreqParam(clickedCategory, true, paramIndex);
		}
		if (clickedCategory == Category::unsynced) {
			if (categoryIsAllowed)
				allowUnsyncedFreqToggles.restoreToggles();
			else
				allowUnsyncedFreqToggles.disableToggles();
		}
		if (clickedCategory == Category::pitched) {
			if (categoryIsAllowed)
				allowPitchedFreqToggles.restoreToggles();
			else
				allowPitchedFreqToggles.disableToggles();
		}
		if (clickedCategory == Category::synced) {
			if (categoryIsAllowed)
				allowSyncedFreqToggles.restoreToggles();
			else
				allowSyncedFreqToggles.disableToggles();
		}
	}
}

void GUI_Layer_AllowedChoices_LFO_Freq::makeCategoryTheOnlyOneAllowed(Category allowedCategory) {
	toggle_Unsynced.setToggleState(allowedCategory == Category::unsynced ? true : false, dontSendNotification);
	toggle_Pitched.setToggleState(allowedCategory == Category::pitched ? true : false, dontSendNotification);
	toggle_Synced.setToggleState(allowedCategory == Category::synced ? true : false, dontSendNotification);
	randomizationOptions->clearAllowedCategoriesForLFO_FreqParam(paramIndex);
	randomizationOptions->setCategoryIsAllowedForLFO_FreqParam(allowedCategory, true, paramIndex);
	if (allowedCategory == Category::unsynced) {
		allowUnsyncedFreqToggles.restoreToggles();
		allowPitchedFreqToggles.disableToggles();
		allowSyncedFreqToggles.disableToggles();
	}
	if (allowedCategory == Category::pitched) {
		allowUnsyncedFreqToggles.disableToggles();
		allowPitchedFreqToggles.restoreToggles();
		allowSyncedFreqToggles.disableToggles();
	}
	if (allowedCategory == Category::synced) {
		allowUnsyncedFreqToggles.disableToggles();
		allowPitchedFreqToggles.disableToggles();
		allowSyncedFreqToggles.restoreToggles();
	}
}

void GUI_Layer_AllowedChoices_LFO_Freq::allowAllChoices() {
	randomizationOptions->allowAllChoicesForLFO_FreqParam(paramIndex);
	toggle_Unsynced.setToggleState(true, dontSendNotification);
	toggle_Pitched.setToggleState(true, dontSendNotification);
	toggle_Synced.setToggleState(true, dontSendNotification);
	allowUnsyncedFreqToggles.restoreToggles();
	allowPitchedFreqToggles.restoreToggles();
	allowSyncedFreqToggles.restoreToggles();
}

GUI_Layer_AllowedChoices_LFO_Freq::~GUI_Layer_AllowedChoices_LFO_Freq() {
	toggle_Unsynced.removeListener(this);
	toggle_Pitched.removeListener(this);
	toggle_Synced.removeListener(this);
}
