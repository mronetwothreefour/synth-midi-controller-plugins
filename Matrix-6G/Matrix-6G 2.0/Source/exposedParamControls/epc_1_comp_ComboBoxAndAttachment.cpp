#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../gui/gui_build_LED_Path.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

ComboBoxAndAttachment::ComboBoxAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	tooltipUpdater{ paramIndex, comboBox, exposedParams, unexposedParams },
	comboBox_w{ info->widthFor(paramIndex) }
{
	auto choiceNamesList{ info->choiceNamesListFor(paramIndex) };
	comboBox.addItemList(choiceNamesList, 1);
	addAndMakeVisible(comboBox);
	setSize(comboBox_w, GUI::control_h);
	comboBox.setBounds(getLocalBounds());
}

void ComboBoxAndAttachment::paint(Graphics& g) {
	auto currentChoice{ (uint8)roundToInt(comboBox.getSelectedItemIndex()) };
	auto choiceNameString{ info->choiceNameFor(currentChoice, paramIndex) };
	auto choiceNamePath{ LED_Path::buildChoiceNameForControl(choiceNameString, comboBox_w) };
	g.setColour(GUI::color_LED_Blue);
	g.fillPath(choiceNamePath);
}

void ComboBoxAndAttachment::attachComboBoxToExposedParameter() {
	attachment.reset(new ComboBoxAttachment{ *state, info->IDfor(paramIndex).toString(), comboBox });
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
