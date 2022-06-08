#include "global_1_comp_EditorForTooltipDelay.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = GlobalParamDescription;



EditorForTooltipDelay::EditorForTooltipDelay(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	parameterID{ ID::tooltips_DelayInMilliseconds }
{
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->addListener(this);
	setComponentID(ID::label_EditLabel.toString());
	setEditable(true);
	setText((String)tooltipOptions->delayInMilliseconds() + " ms", dontSendNotification);
	onEditorShow = [this, tooltipOptions] {
		auto editor{ getCurrentTextEditor() };
		if (editor != nullptr) {
			editor->setInputRestrictions(4, "0123456789");
			editor->setFont(GUI::fontFor_Labels);
			editor->setText((String)tooltipOptions->delayInMilliseconds());
			editor->selectAll();
		}
	};
	onTextChange = [this, tooltipOptions] {
		if (getText().isNotEmpty()) 		{
			auto newValue{ getText().getIntValue() };
			if (newValue < 5001)
				tooltipOptions->setDelayInMilliseconds(newValue);
		}
		setText((String)tooltipOptions->delayInMilliseconds() + " ms", dontSendNotification);
	};

	updateTooltip();

	setSize(50, GUI::comboBox_h);
}

void EditorForTooltipDelay::updateTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescription{ tooltipOptions->shouldShowDescriptions() };
	String tipString{ shouldShowDescription ? Description::buildFor_TooltipDelay() : ""};
	setTooltip(tipString);
}

void EditorForTooltipDelay::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

EditorForTooltipDelay::~EditorForTooltipDelay() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	tooltipOptions->removeListener(this);
}
