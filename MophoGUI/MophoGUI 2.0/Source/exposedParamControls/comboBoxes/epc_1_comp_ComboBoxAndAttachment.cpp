#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_facade_ExposedParameters.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



ComboBoxAndAttachment::ComboBoxAndAttachment(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	tooltipsUpdater{ paramIndex, comboBox, exposedParams, unexposedParams }
{
	auto choiceNamesList{ exposedParams->info.choiceNamesListFor(paramIndex) };
	comboBox.addItemList(choiceNamesList, 1);
	addAndMakeVisible(comboBox);
	auto ctrlWidth{ exposedParams->info.widthFor(paramIndex) };
	auto ctrlHeight{ exposedParams->info.heightFor(paramIndex) };
	setSize(ctrlWidth, ctrlHeight);
	comboBox.setBounds(getLocalBounds());
}

void ComboBoxAndAttachment::attachComboBoxToExposedParameter() {
	attachment.reset(new ComboBoxAttachment(exposedParams->state, exposedParams->info.IDfor(paramIndex).toString(), comboBox));
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
