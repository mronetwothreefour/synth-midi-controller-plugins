#include "mMod_1_comp_ComboBoxForMatrixModSource.h"

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

ComboBoxForMatrixModSource::ComboBoxForMatrixModSource(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	modNum{ modNum },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomize{ exposedParams->randomize.get() },
	randomization{ exposedParams->randomization.get() }
{
	auto modSourceParamID{ matrixModOptions->buildMatrixModParamID(modNum, MM_Type::source) };
	modSourceValue = matrixModOptions->getMatrixModPropertyAsValue(modSourceParamID);
	modSourceValue.addListener(this);

	StringArray choiceNamesList{};
	for (auto choiceNum = (uint8)0; choiceNum != MMOD::numberOfSrcChoices; ++choiceNum)
		choiceNamesList.add(ChoiceName::buildForModSource(choiceNum, ChoiceNameType::concise));
	addItemList(choiceNamesList, 1);
	setSelectedItemIndex((int)matrixModOptions->modSource(modNum), dontSendNotification);
	onChange = [this, modNum] {
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
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Selects the modulation source. Matrix Mod parameters\n";
		tip += "cannot be changed via Quick Patch Edit. Use the\n";
		tip += "PUSH button to send the entire patch instead.\n";
	}
	if (shouldShowCurrentChoice) {
		auto currentChoice{ (uint8)getSelectedItemIndex() };
		tip += "Current Setting: " + ChoiceName::buildForModSource(currentChoice, ChoiceNameType::verbose);
	}
	setTooltip(tip);
}

void ComboBoxForMatrixModSource::valueChanged(Value& value) {
	if (value.refersToSameSourceAs(modSourceValue))
		setSelectedItemIndex((int)value.getValue());
	updateTooltip();
}

void ComboBoxForMatrixModSource::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier && randomization->transmitMethodIsQuickEdit() == false)
		randomize->randomizeMatrixModParameter(modNum, MM_Type::source);
	else
		ComboBox::mouseDown(event);
}

ComboBoxForMatrixModSource::~ComboBoxForMatrixModSource() {
	modSourceValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
}
