#include "mMod_1_comp_ComboBoxForMatrixModDestination.h"

#include "mMod_0_build_ChoiceName.h"
#include "../constants/constants_Enum.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_MatrixMod.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using namespace Matrix_6G_Constants;
using ChoiceName = MatrixModParamChoiceName;
using MM_Type = MatrixModParamType;

ComboBoxForMatrixModDestination::ComboBoxForMatrixModDestination(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	modNum{ modNum },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomize{ exposedParams->randomize.get() },
	randomization{ exposedParams->randomization.get() }
{
	auto modDestParamID{ matrixModOptions->buildMatrixModParamID(modNum, MM_Type::destination) };
	modDestValue = matrixModOptions->getMatrixModPropertyAsValue(modDestParamID);
	modDestValue.addListener(this);

	StringArray choiceNamesList{};
	for (auto choiceNum = (uint8)0; choiceNum != MMOD::numberOfDestChoices; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForModDest(choiceNum, ChoiceNameType::concise));
	addItemList(choiceNamesList, 1);
	setSelectedItemIndex((int)matrixModOptions->modDest(modNum), dontSendNotification);
	onChange = [this, modNum] {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		matrixModOptions->setModDest(modNum, currentChoice);
	};

	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	setSize(GUI::matrixModComboBox_w, GUI::control_h);
}

void ComboBoxForMatrixModDestination::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Selects the destination parameter for modulation.\n";
		tip += "Matrix Mod parameters cannot be changed via Quick Patch Edit.\n";
		tip += "Use the PUSH button to send the entire patch instead.\n";
	}
	if (shouldShowCurrentChoice) {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		tip += "Current Setting: " + ChoiceName::buildForModDest(currentChoice, ChoiceNameType::verbose);
	}
	setTooltip(tip);
}

void ComboBoxForMatrixModDestination::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(modDestValue))
		setSelectedItemIndex((int)value.getValue());
	updateTooltip();
}

void ComboBoxForMatrixModDestination::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier && randomization->transmitMethodIsQuickEdit() == false)
		randomize->randomizeMatrixModParameter(modNum, MM_Type::destination);
	else
		ComboBox::mouseDown(event);
}

ComboBoxForMatrixModDestination::~ComboBoxForMatrixModDestination() {
	modDestValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
}
