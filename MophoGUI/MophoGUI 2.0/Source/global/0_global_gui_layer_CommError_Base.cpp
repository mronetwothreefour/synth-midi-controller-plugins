#include "0_global_gui_layer_CommError_Base.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../midi/1_midi_GlobalParametersDataRequest.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;



GUI_Layer_CommError_Base::GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	button_Close{ "" },
	button_RequestGlobalParamsDump{ "" }
{
	button_Close.setComponentID(ID::button_Close.toString());
	button_Close.onClick = [this] { hideThisLayer(); };
	button_Close.addShortcut(KeyPress(KeyPress::escapeKey));
	addAndMakeVisible(button_Close);

	button_RequestGlobalParamsDump.setComponentID(ID::button_Retry.toString());
	button_RequestGlobalParamsDump.onClick = [this] { requestGlobalParamsDump(); };
	button_RequestGlobalParamsDump.addShortcut(KeyPress(KeyPress::returnKey));
	addAndMakeVisible(button_RequestGlobalParamsDump);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_CommError_Base::requestGlobalParamsDump() {
	auto outgoingMidiBuffers{ unexposedParams->getOutgoingMidiBuffers() };
	GlobalParametersDataRequest::addToOutgoingMidiBuffers(outgoingMidiBuffers);
	callAfterDelay(200, [this] { checkHardwareSettings(); });
}

void GUI_Layer_CommError_Base::hideThisLayer() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

void GUI_Layer_CommError_Base::timerCallback() {
}
