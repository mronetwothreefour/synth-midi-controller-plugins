#include "mMod_1_comp_SliderForMatrixModAmount.h"

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

SliderForMatrixModAmount::SliderForMatrixModAmount(int modNum, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	RotarySliderWithMouseWheelMoveOverride{ &exposedParams->undoManager },
	modNum{ modNum },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomize{ exposedParams->randomize.get() },
	randomization{ exposedParams->randomization.get() },
	textEditor{ modNum, matrixModOptions, tooltips }
{
	auto modAmountParamID{ matrixModOptions->buildMatrixModParamID(modNum, MM_Type::amount) };
	modAmountAsValue = matrixModOptions->getMatrixModPropertyAsValue(modAmountParamID);
	modAmountAsValue.addListener(this);

	setRange(0.0, (double)(MMOD::numberOfAmtChoices - 1), 1.0);
	setDoubleClickReturnValue(true, 63.0);
	setValue((double)matrixModOptions->modAmount(modNum), dontSendNotification);
	setMouseDragSensitivity(144);

	shouldShowCurrentChoiceAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice);
	shouldShowCurrentChoiceAsValue.addListener(this);
	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	textEditor.setTopLeftPosition(0, 0);
	addAndMakeVisible(textEditor);

	setSize(GUI::matrixModSlider_w, GUI::control_h);
}

void SliderForMatrixModAmount::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	auto shouldShowCurrentChoice{ (bool)shouldShowCurrentChoiceAsValue.getValue() };
	String tip{ "" };
	if (shouldShowDescription) {
		tip += "Sets whether and to what degree the selected source\n";
		tip += "modulates the selected destination. Range: -63 to +63.\n";
		tip += "0 is no modulation. Negative values invert the modulation.\n";
		tip += "Matrix Mod parameters cannot be changed via Quick Patch\n";
		tip += "Edit. Use the PUSH button to send the entire patch instead.\n";
	}
	if (shouldShowCurrentChoice) {
		auto currentChoice{ (uint8)roundToInt(getValue()) };
		tip += "Current Setting: " + ChoiceName::buildForModAmount(currentChoice);
	}
	setTooltip(tip);
}

void SliderForMatrixModAmount::paint(Graphics& g) {
	g.setColour(GUI::color_LED_Blue);
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	auto choiceNameString{ ChoiceName::buildForModAmount(currentChoice) };
	auto choiceNamePath{ LED_Path::buildLabelText(choiceNameString, GUI::matrixModSlider_w) };
	g.fillPath(choiceNamePath);
}

void SliderForMatrixModAmount::mouseDown(const MouseEvent& event) {
	if (event.mods == ModifierKeys::rightButtonModifier && randomization->transmitMethodIsQuickEdit() == false)
		randomize->randomizeMatrixModParameter(modNum, MM_Type::amount);
}

void SliderForMatrixModAmount::mouseDoubleClick(const MouseEvent& /*event*/) {
	textEditor.showEditor();
}

void SliderForMatrixModAmount::valueChanged() {
	auto currentChoice{ (uint8)roundToInt(getValue()) };
	matrixModOptions->setModAmount(modNum, currentChoice);
}

void SliderForMatrixModAmount::valueChanged(Value& value) {
	MessageManagerLock mmLock;
	if (value.refersToSameSourceAs(modAmountAsValue))
		setValue((double)value.getValue(), sendNotification);
	updateTooltip();
}

SliderForMatrixModAmount::~SliderForMatrixModAmount() {
	modAmountAsValue.removeListener(this);
	shouldShowCurrentChoiceAsValue.removeListener(this);
	shouldShowDescriptionAsValue.removeListener(this);
}
