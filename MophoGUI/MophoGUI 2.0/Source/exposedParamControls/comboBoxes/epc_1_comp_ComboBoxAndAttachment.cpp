#include "epc_1_comp_ComboBoxAndAttachment.h"

#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



ComboBoxAndAttachment::ComboBoxAndAttachment(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	exposedParams{ exposedParams },
	tooltipsUpdater{ paramIndex, comboBox, exposedParams, unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto choiceNamesList{ info.choiceNamesListFor(paramIndex) };
	comboBox.addItemList(choiceNamesList, 1);
	addAndMakeVisible(comboBox);
	auto ctrlWidth{ info.widthFor(paramIndex) };
	auto ctrlHeight{ info.heightFor(paramIndex) };
	setSize(ctrlWidth, ctrlHeight);
	comboBox.setBounds(getLocalBounds());
}

void ComboBoxAndAttachment::attachComboBoxToExposedParameter() {
	attachment.reset(new ComboBoxAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), comboBox));
}

void ComboBoxAndAttachment::deleteAttachmentBeforeComboBoxToPreventMemLeak() {
	attachment = nullptr;
}
