#include "widget_PgmBank_ButtonForPullingSelectedPgmFromHardware.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../pgmData/pgmData_Constants.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPullingSelectedProgramFromHardware::ButtonForPullingSelectedProgramFromHardware(ProgramDataSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams, Label& nameEditor) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams },
	nameEditor{ nameEditor }
{
	setComponentID(ID::button_PullSelectedProgram.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingSelectedProgramFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescriptions()) {
		buttonTooltip += "Pull the data from the selected program storage slot in the\n";
		buttonTooltip += "Prophet-600 hardware and save it in the corresponding slot in\n";
		buttonTooltip += "the plugin storage bank. There will then be a prompt to name\n";
		buttonTooltip += "the program (the hardware does not store program names).";
	}
	return buttonTooltip;
}

void ButtonForPullingSelectedProgramFromHardware::onClickMethod() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < pgmData::numberOfSlotsInPgmDataBank) {
		auto pgmDataOptions{ unexposedParams->programDataOptions_get() };
		slotsComponent.pullSelectedPgmDataFromHardware();
		auto transmitTime{ pgmDataOptions->programTransmitTime() };
		callAfterDelay(transmitTime, [this, slot]
			{
				auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, slot);
				auto editor_x{ GUI::pgmNameEditorLabel_horizInset + (slot / 10 * GUI::pgmDataSlotRadioButton_w) };
				auto editor_y{ GUI::pgmDataSlotsComponent_y + (slot % 10 * GUI::pgmDataSlotRadioButton_h) };
				nameEditor.setBounds(editor_x, editor_y, GUI::pgmNameEditorLabel_w, GUI::pgmDataSlotRadioButton_h);
				nameEditor.showEditor();
			}
		);
	}
}

void ButtonForPullingSelectedProgramFromHardware::timerCallback() {
}
