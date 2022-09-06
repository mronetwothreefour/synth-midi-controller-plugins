#include "mMod_1_comp_ComboBoxForMatrixModSource.h"

#include "mMod_0_build_ChoiceName.h"
#include "../exposedParameters/ep_0_tree_MatrixModOptions.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MatrixMod.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;
using ChoiceName = MatrixModParamChoiceName;

ComboBoxForMatrixModSource::ComboBoxForMatrixModSource(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips) :
	modNum{ modNum },
	matrixModOptions{ matrixModOptions }
{
	modSourceValue = matrixModOptions->getMatrixModPropertyAsValue("matrixMod_Mod_" + (String)modNum + "_Source");
	modSourceValue.addListener(this);

	auto concise{ (bool)false };
	StringArray choiceNamesList{};
	for (auto choiceNum = (uint8)0; choiceNum != MMOD::numberOfSourceChoices; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForModSource(choiceNum, concise));
	addItemList(choiceNamesList, 1);
	setSelectedItemIndex((int)matrixModOptions->modSource(modNum), dontSendNotification);
	onChange = [this, modNum, matrixModOptions] {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		matrixModOptions->setModSource(modNum, currentChoice);
	};

	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	setSize(GUI::matrixModComboBox_w, GUI::control_h);
}

void ComboBoxForMatrixModSource::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	auto verbose{ (bool)true };
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Selects the modulation source. Matrix Mod parameters\n";
		tip += "cannot be changed via Quick Patch Edit. Use the\n";
		tip += "PUSH button to send the entire patch instead.\n";
	}
	if (shouldShowCurrentChoice) {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		tip += "Current Setting: " + ChoiceName::buildForModSource(currentChoice, verbose);
	}
	setTooltip(tip);
}

void ComboBoxForMatrixModSource::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(modSourceValue))
		setSelectedItemIndex((int)value.getValue());
	updateTooltip();
}

ComboBoxForMatrixModSource::~ComboBoxForMatrixModSource() {
	modSourceValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
}
