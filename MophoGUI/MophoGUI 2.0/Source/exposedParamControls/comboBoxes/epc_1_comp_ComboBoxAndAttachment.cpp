#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../../constants/constants_Identifiers.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ComboBoxAndAttachment::ComboBoxAndAttachment(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	info{ unexposedParams->getInfoForExposedParameters() },
	tooltipsUpdater{ paramIndex, comboBox, exposedParams, unexposedParams }
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
	attachment.reset(new ComboBoxAttachment(*exposedParams, info->IDfor(paramIndex).toString(), comboBox));
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
