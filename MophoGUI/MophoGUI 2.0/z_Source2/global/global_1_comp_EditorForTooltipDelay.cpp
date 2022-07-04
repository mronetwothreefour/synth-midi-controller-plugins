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
	tooltips{ unexposedParams->getTooltipsOptions() },
	parameterID{ ID::tooltips_DelayInMilliseconds }
{
	tooltips->addListener(this);
	setComponentID(ID::label_EditLabel.toString());
	setEditable(true);
	setText((String)tooltips->delayInMilliseconds() + " ms", dontSendNotification);
	onEditorShow = [this] {
		auto editor{ getCurrentTextEditor() };
		if (editor != nullptr) {
			editor->setInputRestrictions(4, "0123456789");
			editor->setFont(GUI::fontFor_Labels);
			editor->setText((String)tooltips->delayInMilliseconds());
			editor->selectAll();
		}
	};
	onTextChange = [this] {
		if (getText().isNotEmpty()) 		{
			auto newValue{ getText().getIntValue() };
			if (newValue < 5001)
				tooltips->setDelayInMilliseconds(newValue);
		}
		setText((String)tooltips->delayInMilliseconds() + " ms", dontSendNotification);
	};

	updateTooltip();

	setSize(50, GUI::comboBox_h);
}

void EditorForTooltipDelay::updateTooltip() {
	auto shouldShowDescription{ tooltips->shouldShowDescriptions() };
	String tip{ shouldShowDescription ? Description::buildFor_TooltipDelay() : ""};
	setTooltip(tip);
}

void EditorForTooltipDelay::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	if (property == ID::tooltips_ShowDescription) {
		MessageManagerLock mmLock;
		updateTooltip();
	}
}

EditorForTooltipDelay::~EditorForTooltipDelay() {
	tooltips->removeListener(this);
}
