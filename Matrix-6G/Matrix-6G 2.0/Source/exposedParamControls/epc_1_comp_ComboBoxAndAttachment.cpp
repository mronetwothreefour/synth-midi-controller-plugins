#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;

ComboBoxAndAttachment::ComboBoxAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	tooltipUpdater{ paramIndex, comboBox, exposedParams, unexposedParams }
{
	auto choiceNamesList{ info->choiceNamesListFor(paramIndex) };
	comboBox.addItemList(choiceNamesList, 1);
	addAndMakeVisible(comboBox);
	setSize(info->widthFor(paramIndex), GUI::control_h);
	comboBox.setBounds(getLocalBounds());
}

void ComboBoxAndAttachment::attachComboBoxToExposedParameter() {
	attachment.reset(new ComboBoxAttachment{ *state, info->IDfor(paramIndex).toString(), comboBox });
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
