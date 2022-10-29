#include "global_1_comp_EditorForTooltipDelay.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace Matrix_6G_Constants;
using Description = GlobalParamDescription;

EditorForTooltipDelay::EditorForTooltipDelay(UnexposedParameters* unexposedParams) {
	tooltipDelayEditor.setComponentID(ID::lbl_EditLabel.toString());
	tooltipDelayEditor.setEditable(true);
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	tooltipDelayEditor.setText((String)tooltips->delayInMilliseconds(), dontSendNotification);
	tooltipDelayEditor.onEditorShow = [this, tooltips] {
		auto editor{ tooltipDelayEditor.getCurrentTextEditor() };
		if (editor != nullptr) {
			editor->setInputRestrictions(4, "0123456789");
			editor->setText((String)tooltips->delayInMilliseconds());
			editor->selectAll();
		}
	};
	tooltipDelayEditor.onTextChange = [this, tooltips] {
		if (tooltipDelayEditor.getText().isNotEmpty()) {
			auto newValue{ tooltipDelayEditor.getText().getIntValue() };
			if (newValue < 5001)
				tooltips->setDelayInMilliseconds(newValue);
		}
		tooltipDelayEditor.setText((String)tooltips->delayInMilliseconds(), dontSendNotification);
	};

	shouldShowDescriptionAsValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionAsValue.addListener(this);
	updateTooltip();

	setSize(GUI::global_MiscControl_w, GUI::control_h);
	tooltipDelayEditor.setBounds(getLocalBounds());
	addAndMakeVisible(tooltipDelayEditor);
}

void EditorForTooltipDelay::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionAsValue.getValue() };
	String tip{ shouldShowDescription ? Description::buildForTooltipDelay() : "" };
	tooltipDelayEditor.setTooltip(tip);
}

void EditorForTooltipDelay::valueChanged(Value& /*value*/) {
	MessageManagerLock mmLock;
	updateTooltip();
}

EditorForTooltipDelay::~EditorForTooltipDelay() {
	shouldShowDescriptionAsValue.removeListener(this);
}
