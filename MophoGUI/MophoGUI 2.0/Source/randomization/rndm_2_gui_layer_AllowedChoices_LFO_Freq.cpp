#include "rndm_2_gui_layer_AllowedChoices_LFO_Freq.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_AllowedChoices_LFO_Freq::GUI_Layer_AllowedChoices_LFO_Freq(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	repeatChoices{ paramIndex, exposedParams, unexposedParams },
	btn_Close{ unexposedParams },
	allowUnsyncedFreqToggles{ paramIndex, exposedParams, unexposedParams },
	allowPitchedFreqToggles{ paramIndex, exposedParams, unexposedParams },
	allowSyncedFreqToggles{ paramIndex, exposedParams, unexposedParams },
	btn_Randomize{ paramIndex, exposedParams, unexposedParams },
	background_x{ info->allowedChoicesBackground_x_For(paramIndex) },
	background_y{ info->allowedChoicesBackground_y_For(paramIndex) }
{
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	auto paramID{ info->IDfor(paramIndex).toString() };
	auto paramName{ info->exposedNameFor(paramIndex) };
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };

	btn_AllowAll.setComponentID(ID::btn_AllowAll.toString());
	btn_AllowAll.onClick = [this] { allowAllChoices(); };
	btn_AllowAll.addShortcut(KeyPress{ 'a', ModifierKeys::ctrlModifier, 0 });
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Click to allow all the frequencies\n";
		tip += "when generating a random setting for\n";
		tip += paramName + ".\n";
		tip += "Shortcut key: CTRL+A";
		btn_AllowAll.setTooltip(tip);
	}
	btn_AllowAll.setBounds(378, 177, GUI::btn_AllowAll_w, GUI::redButton_h);
	addAndMakeVisible(btn_AllowAll);

	repeatChoices.setTopLeftPosition(660, 181);
	addAndMakeVisible(repeatChoices);

	btn_Close.setTopLeftPosition(962, 177);
	addAndMakeVisible(btn_Close);

	toggle_Unsynced.setComponentID(ID::comp_RedToggle.toString());
	toggle_Unsynced.addListener(this);
	auto unsyncedFreqAreAllowed{ randomization->categoryIsAllowedFor_LFO_FreqParam(Category::unsynced, paramIndex) };
	toggle_Unsynced.setToggleState(unsyncedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not un-synced frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Unsynced.setTooltip(tip);
	}
	toggle_Unsynced.setBounds(422, categoryToggles_y, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_Unsynced);

	toggle_Pitched.setComponentID(ID::comp_RedToggle.toString());
	toggle_Pitched.addListener(this);
	auto pitchedFreqAreAllowed{ randomization->categoryIsAllowedFor_LFO_FreqParam(Category::pitched, paramIndex) };
	toggle_Pitched.setToggleState(pitchedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not pitched frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Pitched.setTooltip(tip);
	}
	toggle_Pitched.setBounds(651, categoryToggles_y, GUI::redToggle_diameter, GUI::redToggle_diameter);
	addAndMakeVisible(toggle_Pitched);

	toggle_Synced.setComponentID(ID::comp_RedToggle.toString());
	toggle_Synced.addListener(this);
	auto syncedFreqAreAllowed{ randomization->categoryIsAllowedFor_LFO_FreqParam(Category::synced, paramIndex) };
	toggle_Synced.setToggleState(syncedFreqAreAllowed ? true : false, dontSendNotification);
	if (shouldShowDescriptions) {
		String tip{ "" };
		tip += "Toggles whether or not synced frequencies are allowed\n";
		tip += "when a random frequency is generated for LFO " + lfoNumString + ".\n";
		tip += "at least one frequency category must always be allowed.\n";
		toggle_Synced.setTooltip(tip);
	}
	toggle_Synced.setBounds(878, categoryToggles_y, GUI::redToggle_diameter, GUI::redToggle_diameter);
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

	btn_Randomize.setTopLeftPosition(656, 436);
	addAndMakeVisible(btn_Randomize);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_AllowedChoices_LFO_Freq::paint(Graphics& g) {
	g.fillAll(GUI::color_Black.withAlpha(0.4f));
	auto controlCenter{ info->centerPointFor(paramIndex)};
	g.setColour(GUI::color_ToggleOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	g.setColour(GUI::color_Black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(GUI::color_Device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
	MemoryInputStream memInputStream{ BinaryData::lbl_LFO_FreqCategories_png, BinaryData::lbl_LFO_FreqCategories_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, 214);
}

void GUI_Layer_AllowedChoices_LFO_Freq::mouseDown(const MouseEvent& event) {
	auto clickPosition{ event.getPosition() };
	auto ctrlClicked{ ModifierKeys::leftButtonModifier + ModifierKeys::ctrlModifier };

	Rectangle<int> unsyncedLabelArea{ 436, categoryToggles_y, 79, GUI::redToggle_diameter };
	if (unsyncedLabelArea.contains(clickPosition)) {
		if (event.mods == ctrlClicked)
			makeCategoryTheOnlyOneAllowed(Category::unsynced);
		else
			toggle_Unsynced.triggerClick();
	}

	Rectangle<int> pitchedLabelArea{ 665, categoryToggles_y, 55, GUI::redToggle_diameter };
	if (pitchedLabelArea.contains(clickPosition)) {
		if (event.mods == ctrlClicked)
			makeCategoryTheOnlyOneAllowed(Category::pitched);
		else
			toggle_Pitched.triggerClick();
	}

	Rectangle<int> syncedLabelArea{ 892, categoryToggles_y, 53, GUI::redToggle_diameter };
	if (syncedLabelArea.contains(clickPosition)) {
		if (event.mods == ctrlClicked)
			makeCategoryTheOnlyOneAllowed(Category::synced);
		else
			toggle_Synced.triggerClick();
	}
}

void GUI_Layer_AllowedChoices_LFO_Freq::buttonClicked(Button* button) {
	auto clickedCategory{ Category::unsynced };
	if (button == &toggle_Pitched)
		clickedCategory = Category::pitched;
	if (button == &toggle_Synced)
		clickedCategory = Category::synced;
	if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier)
		makeCategoryTheOnlyOneAllowed(clickedCategory);
	else {
		auto categoryIsAllowed{ button->getToggleState() };
		randomization->setCategoryIsAllowedFor_LFO_FreqParam(clickedCategory, categoryIsAllowed ? true : false, paramIndex);
		if (randomization->noCategoryIsAllowedFor_LFO_FreqParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomization->setCategoryIsAllowedFor_LFO_FreqParam(clickedCategory, true, paramIndex);
			categoryIsAllowed = true;
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
	randomization->clearAllowedCategoriesFor_LFO_FreqParam(paramIndex);
	randomization->setCategoryIsAllowedFor_LFO_FreqParam(allowedCategory, true, paramIndex);
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
	randomization->allowAllChoicesFor_LFO_FreqParam(paramIndex);
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
