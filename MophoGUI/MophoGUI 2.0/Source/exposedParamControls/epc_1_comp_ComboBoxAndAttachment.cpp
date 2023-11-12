#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../exposedParameters/ep_3_facade_ExposedParameters.h"

using namespace MophoConstants;

ComboBoxAndAttachment::ComboBoxAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	state{ exposedParams->state.get() },
	info{ exposedParams->info.get() },
	tooltipUpdater{ paramIndex, comboBox, exposedParams, tooltips }
{
	auto choiceNamesList{ info->choiceNamesListFor(paramIndex) };
	comboBox.addItemList(choiceNamesList, 1);
	addAndMakeVisible(comboBox);
	auto ctrlWidth{ info->widthFor(paramIndex) };
	auto ctrlHeight{ info->heightFor(paramIndex) };
	setSize(ctrlWidth, ctrlHeight);
	comboBox.setBounds(getLocalBounds());
}

void ComboBoxAndAttachment::attachComboBoxToExposedParameter() {
	attachment.reset(new ComboBoxAttachment{ *state, info->IDfor(paramIndex).toString(), comboBox });
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
