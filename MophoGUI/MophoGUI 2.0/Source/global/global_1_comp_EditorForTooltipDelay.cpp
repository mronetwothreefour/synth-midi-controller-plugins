#include "global_1_comp_EditorForTooltipDelay.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../descriptions/build_GlobalParamDescription.h"
#include "../midi/midi_1_ParameterChangeMessage.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace MophoConstants;
using Description = GlobalParamDescription;

EditorForTooltipDelay::EditorForTooltipDelay(UnexposedParameters* unexposedParams) :
	parameterID{ ID::tooltips_DelayInMilliseconds }
{
	tooltipDelayEditor.setComponentID(ID::label_EditLabel.toString());
	tooltipDelayEditor.setEditable(true);
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	tooltipDelayEditor.setText((String)tooltips->delayInMilliseconds() + " ms", dontSendNotification);
	tooltipDelayEditor.onEditorShow = [this, tooltips] {
		auto editor{ tooltipDelayEditor.getCurrentTextEditor() };
		if (editor != nullptr) {
			editor->setInputRestrictions(4, "0123456789");
			editor->setFont(GUI::font_Labels);
			editor->setText((String)tooltips->delayInMilliseconds());
			editor->selectAll();
		}
	};
	tooltipDelayEditor.onTextChange = [this, tooltips] {
		if (tooltipDelayEditor.getText().isNotEmpty()) 		{
			auto newValue{ tooltipDelayEditor.getText().getIntValue() };
			if (newValue < 5001)
				tooltips->setDelayInMilliseconds(newValue);
		}
		tooltipDelayEditor.setText((String)tooltips->delayInMilliseconds() + " ms", dontSendNotification);
	};

	shouldShowDescriptionValue = tooltips->getTooltipsPropertyAsValue(ID::tooltips_ShouldShowDescription);
	shouldShowDescriptionValue.addListener(this);
	updateTooltip();

	setSize(50, GUI::comboBox_h);
	tooltipDelayEditor.setBounds(getLocalBounds());
	addAndMakeVisible(tooltipDelayEditor);
}

void EditorForTooltipDelay::updateTooltip() {
	auto shouldShowDescription{ (bool)shouldShowDescriptionValue.getValue() };
	String tip{ shouldShowDescription ? Description::buildForTooltipDelay() : ""};
	tooltipDelayEditor.setTooltip(tip);
}

void EditorForTooltipDelay::valueChanged(Value& /*value*/) {
	MessageManagerLock mmLock;
	updateTooltip();
}

EditorForTooltipDelay::~EditorForTooltipDelay() {
	shouldShowDescriptionValue.removeListener(this);
}
