#include "rndm_0_comp_AllowRepeatChoicesComboBox_MatrixModParam.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

AllowRepeatChoicesComboBox_MatrixModParam::AllowRepeatChoicesComboBox_MatrixModParam(
	int modNum, MM_Type paramType, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	modNum{ modNum },
	paramType{ paramType },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomization{ exposedParams->randomization.get() }
{
	onlyOneChoiceIsAllowedForParamAsValue = randomization->getOnlyOneChoiceIsAllowedForMatrixModParamAsValue(modNum, paramType);
	onlyOneChoiceIsAllowedForParamAsValue.addListener(this);

	StringArray choiceNamesList{};
	choiceNamesList.add("NO");
	choiceNamesList.add("YES");
	comboBox_AllowRepeatChoices.addItemList(choiceNamesList, 1);
	comboBox_AllowRepeatChoices.onChange = [this, modNum, paramType] {
		auto shouldBeAllowed{ comboBox_AllowRepeatChoices.getSelectedItemIndex() == 1 ? true : false };
		randomization->setRepeatChoicesAreAllowedForMatrixModParam(shouldBeAllowed, modNum, paramType);
	};
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescription()) {
		String tip{ "" };
		tip += "Toggles whether the current setting is allowed\n";
		tip += "when a new setting is randomly generated. If it\n";
		tip += "is not, consecutive randomization operations\n";
		tip += "can never produce the same setting. Obviously,\n";
		tip += "if there is only one allowed setting then the\n";
		tip += "same setting is always going to be produced.";
		comboBox_AllowRepeatChoices.setTooltip(tip);
	}
	comboBox_AllowRepeatChoices.setBounds(68, 0, 38, GUI::control_h);
	addAndMakeVisible(comboBox_AllowRepeatChoices);

	valueChanged(onlyOneChoiceIsAllowedForParamAsValue);

	setSize(106, 20);
}

void AllowRepeatChoicesComboBox_MatrixModParam::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_RepeatChoicesComboBox_png, BinaryData::bkgrnd_RepeatChoicesComboBox_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void AllowRepeatChoicesComboBox_MatrixModParam::valueChanged(Value& /*value*/) {
	if ((bool)onlyOneChoiceIsAllowedForParamAsValue.getValue() == true) {
		comboBox_AllowRepeatChoices.setSelectedItemIndex(1, dontSendNotification);
		setEnabled(false);
	}
	else {
		auto repeatsAreAllowed{ randomization->repeatChoicesAreAllowedForMatrixModParam(modNum, paramType) };
		comboBox_AllowRepeatChoices.setSelectedItemIndex(repeatsAreAllowed ? 1 : 0, dontSendNotification);
		setEnabled(true);
	}
}

AllowRepeatChoicesComboBox_MatrixModParam::~AllowRepeatChoicesComboBox_MatrixModParam() {
	onlyOneChoiceIsAllowedForParamAsValue.removeListener(this);
}
