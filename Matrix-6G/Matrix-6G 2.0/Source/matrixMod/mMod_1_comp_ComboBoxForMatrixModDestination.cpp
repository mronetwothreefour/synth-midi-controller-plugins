#include "mMod_1_comp_ComboBoxForMatrixModDestination.h"

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

ComboBoxForMatrixModDestination::ComboBoxForMatrixModDestination(int modNum, MatrixModOptions* matrixModOptions, TooltipsOptions* tooltips) :
	modNum{ modNum },
	matrixModOptions{ matrixModOptions }
{
	modDestValue = matrixModOptions->getMatrixModPropertyAsValue("matrixMod_Mod_" + (String)modNum + "_Dest");
	modDestValue.addListener(this);

	auto concise{ (bool)false };
	StringArray choiceNamesList{};
	for (auto choiceNum = (uint8)0; choiceNum != MMOD::numberOfDestChoices; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForModDest(choiceNum, concise));
	addItemList(choiceNamesList, 1);
	setSelectedItemIndex((int)matrixModOptions->modDest(modNum), dontSendNotification);
	onChange = [this, modNum, matrixModOptions] {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		matrixModOptions->setModDest(modNum, currentChoice);
	};

	shouldShowCurrentChoiceValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceValue.addListener(this);
	shouldShowDescriptionValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionValue.addListener(this);
	updateTooltip();

	setSize(GUI::matrixModComboBox_w, GUI::control_h);
}

void ComboBoxForMatrixModDestination::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceValue.getValue() };
	const auto verbose{ (bool)true };
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Selects the destination parameter for modulation.\n";
		tip += "Matrix Mod parameters cannot be changed via Quick Patch Edit.\n";
		tip += "Use the PUSH button to send the entire patch instead.\n";
	}
	if (shouldShowCurrentChoice) {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		tip += "Current Setting: " + ChoiceName::buildForModDest(currentChoice, verbose);
	}
	setTooltip(tip);
}

void ComboBoxForMatrixModDestination::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(modDestValue))
		setSelectedItemIndex((int)value.getValue());
	updateTooltip();
}

ComboBoxForMatrixModDestination::~ComboBoxForMatrixModDestination() {
	modDestValue.removeListener(this);
	shouldShowCurrentChoiceValue.removeListener(this);
	shouldShowDescriptionValue.removeListener(this);
}
