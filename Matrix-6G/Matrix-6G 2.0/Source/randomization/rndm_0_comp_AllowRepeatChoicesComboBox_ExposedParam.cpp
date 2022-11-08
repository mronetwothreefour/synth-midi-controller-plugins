#include "rndm_0_comp_AllowRepeatChoicesComboBox_ExposedParam.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

AllowRepeatChoicesComboBox_ExposedParam::AllowRepeatChoicesComboBox_ExposedParam(
	uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() }
{
	auto numberOfChoices{ info->numberOfChoicesFor(paramIndex) };
	if (numberOfChoices > 2) {
        onlyOneChoiceIsAllowedForParamAsValue = randomization->getOnlyOneChoiceIsAllowedForParamAsValue(paramIndex);
        onlyOneChoiceIsAllowedForParamAsValue.addListener(this);
    }

	StringArray choiceNamesList{};
	choiceNamesList.add("NO");
	choiceNamesList.add("YES");
	comboBox_AllowRepeatChoices.addItemList(choiceNamesList, 1);
	comboBox_AllowRepeatChoices.onChange = [this, paramIndex] {
		auto shouldBeAllowed{ comboBox_AllowRepeatChoices.getSelectedItemIndex() == 1 ? true : false };
		randomization->setRepeatChoicesAreAllowedForParam(shouldBeAllowed, paramIndex);
	};
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. ";
		if (numberOfChoices > 2) {
			tip += "Obviously,\n";
			tip += "if there is only one allowed setting then the\n";
			tip += "same setting is always going to be produced.";
		}
		else {
			tip += "This means\n";
			tip += "that the toggle will simply alternate between\n";
			tip += "states with every randomization.";
		}
		comboBox_AllowRepeatChoices.setTooltip(tip);
	}
	comboBox_AllowRepeatChoices.setBounds(68, 0, 38, GUI::control_h);
	addAndMakeVisible(comboBox_AllowRepeatChoices);

	if (numberOfChoices == 2) {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		comboBox_AllowRepeatChoices.setSelectedItemIndex(repeatsAreAllowed ? 1 : 0, dontSendNotification);
	}
	else
		valueChanged(onlyOneChoiceIsAllowedForParamAsValue);

	setSize(106, 20);
}

void AllowRepeatChoicesComboBox_ExposedParam::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesComboBox_png, BinaryData::bkgrnd_RepeatChoicesComboBox_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesComboBox_ExposedParam::valueChanged(Value& /*value*/) {
	if ((bool)onlyOneChoiceIsAllowedForParamAsValue.getValue() == true) {
		comboBox_AllowRepeatChoices.setSelectedItemIndex(1, dontSendNotification);
		setEnabled(false);
	}
	else {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForParam(paramIndex) };
		comboBox_AllowRepeatChoices.setSelectedItemIndex(repeatsAreAllowed ? 1 : 0, dontSendNotification);
		setEnabled(true);
	}
}

AllowRepeatChoicesComboBox_ExposedParam::~AllowRepeatChoicesComboBox_ExposedParam() {
	if (info->numberOfChoicesFor(paramIndex) > 2)
		onlyOneChoiceIsAllowedForParamAsValue.removeListener(this);
}
