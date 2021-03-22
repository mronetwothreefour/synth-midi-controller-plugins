#include "widget_master_ButtonForPullingMasterOptionsFromHardware.h"

#include "../master/master_Constants.h"
#include "../midi/midi_MasterOptionsDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ButtonForPullingMasterOptionsFromHardware::ButtonForPullingMasterOptionsFromHardware(UnexposedParameters* unexposedParams) :
	BaseButtonWithOnClickAndTooltipMethods{ unexposedParams },
	unexposedParams{ unexposedParams }
{
	setComponentID(ID::button_PullMasterOptions.toString());
	setTooltip(createButtonTooltipString());
}

const String ButtonForPullingMasterOptionsFromHardware::createButtonTooltipString() {
	String buttonTooltip{ "" };
	if (unexposedParams->tooltipOptions_get()->shouldShowDescription()) {
		buttonTooltip += "Pull the master options settings from\n";
		buttonTooltip += "the hardware and apply it to the GUI.";
	}
	return buttonTooltip;
}

void ButtonForPullingMasterOptionsFromHardware::onClickMethod() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	MasterOptionsDataMessage::addRequestForMasterOptionsDataToOutgoingMidiBuffers(outgoingMidiBuffers);
}
