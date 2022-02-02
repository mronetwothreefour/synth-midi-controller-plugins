#include "widget_PgmBank_ButtonForEditingSelectedProgramName.h"

#include "../gui/gui_Constants.h"
#include "../pgmData/pgmData_Constants.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ButtonForEditingSelectedProgramName::ButtonForEditingSelectedProgramName(Label& nameEditor, ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	nameEditor{ nameEditor },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_Name.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForEditingSelectedProgramName::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Click to change the name of the selected program.\n";
		buttonTooltip += "NOTE: The Prophet-600 hardware does" + GUI::apostrophe + "t store program names.";
	}
	return buttonTooltip;
}

void ButtonForEditingSelectedProgramName::onClickMethod() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < pgmData::numberOfSlotsInPgmDataBank) {
		auto editor_x{ GUI::pgmNameEditorLabel_horizInset + (slot / 10 * GUI::pgmDataSlotRadioButton_w) };
		auto editor_y{ GUI::pgmDataSlotsComponent_y + (slot % 10 * GUI::pgmDataSlotRadioButton_h) };
		nameEditor.setBounds(editor_x, editor_y, GUI::pgmNameEditorLabel_w, GUI::pgmDataSlotRadioButton_h);
		nameEditor.showEditor();
	}
}
